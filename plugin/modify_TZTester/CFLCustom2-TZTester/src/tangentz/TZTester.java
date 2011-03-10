package tangentz;
import java.util.HashMap;
import java.util.Map;
import com.topcoder.client.contestant.ProblemComponentModel;
import com.topcoder.shared.language.Language;
import com.topcoder.shared.problem.*;


/**
 * @author TangentZ
 *
 * This tester class is for C++ only.  It is based on PopsProcessor which is written for Java.
 * It reads in all the given examples for a problem and generates the equivalent C++ code
 * to test all the cases.  The accumulated running time is 8 seconds, but it is easy to
 * selectively run a specific case only.
 *
 * This tester will define three tags that can be embedded within PopsEdit/FileEdit code template:
 *	$WRITERCODE$ - place holder for writer code - will be blank if none found
 *	$PROBLEM$ - place holder for problem description as plain text
 *	// $RUNTEST$ - place holder for where to put the code that starts the test
 *	$TESTCODE$ - place holder for where to put the test code
 */
public class TZTester
{
	// Map used to store my tags
	private HashMap<String,String> m_Tags = new HashMap<String,String>();

	// Constants
	private static final String k_WRITERCODE = "$WRITERCODE$";
	private static final String k_PROBLEM    = "$PROBLEM$";
	private static final String k_RUNTEST    = "$RUNTEST$";
	private static final String k_TESTCODE   = "$TESTCODE$";
	private static final String k_VERSION    = "\n// Powered by TZTester 1.01 [25-Feb-2003] : <cafelier&naoya_t>-custom";

	// Cut tags
	private static final String k_BEGINCUT   = "// BEGIN CUT HERE";
	private static final String k_ENDCUT	 = "// END CUT HERE";

	// Problem-related variables
	private ProblemComponentModel m_Problem   = null;
	private Language			  m_Language  = null;
	
	/**
	 * PreProcess the source code
	 * 
	 * First determines if it is saved code, writer code, or nothing and stores it in $WRITERCODE$ tag
	 * Secondly builds a main method with default test cases
	 */
	public String preProcess(String Source, ProblemComponentModel Problem, Language Lang, Renderer Render)
	{
		// Set defaults for the tags in case we exit out early
		m_Tags.put(k_WRITERCODE, "");
		m_Tags.put(k_PROBLEM,    "");
		m_Tags.put(k_RUNTEST,    "// *** WARNING *** $RUNTEST$ is not supported by this customized TZTester.");
		m_Tags.put(k_TESTCODE,   "");

		// If there is source and the source is NOT equal to the default solution, return it
		if( Source.length()>0 && !Source.equals(Problem.getDefaultSolution()) )
			return Source;

		// Check to see if the component has any signature 
		if( !Problem.hasSignature() )
		{
			m_Tags.put(k_TESTCODE, "// *** WARNING *** Problem has no signature defined for it");
			return "";
		}
		
		// Get the test cases
		TestCase[] TestCases = Problem.getTestCases();

		// Check to see if test cases are defined
		if( TestCases==null || TestCases.length==0 )
		{
			m_Tags.put(k_TESTCODE, "// *** WARNING *** No test cases defined for this problem");
			return "";
		}

		// Re-initialize the tags
		m_Tags.clear();
		m_Tags.put(k_WRITERCODE, Problem.getDefaultSolution());
		try { m_Tags.put(k_PROBLEM, Render.toHTML(m_Language)); } catch (Exception Ex) { }

		m_Problem  = Problem;
		m_Language = Lang;

		// Generate the test cases
		generate_test_code();
		return "";
	}

	/**
	 * This method will cut the test methods above out
	 */
	public String postProcess(String Source, Language Lang)
	{
		// Insert a version string
		return Source + k_VERSION;
	}

	/**
	 * This method will return my tags.  This method is ALWAYS called after preProcess()
	 * 
	 * @return a map of my tags
	 */
	public Map getUserDefinedTags()
	{
		return m_Tags;
	}

	/**
	 * This method will generate the code for the test cases.
	 */
	private void generate_test_code()
	{
		DataType[] ParamTypes = m_Problem.getParamTypes();
		DataType ReturnType   = m_Problem.getReturnType();
		TestCase[] Cases	  = m_Problem.getTestCases();
		StringBuffer Code = new StringBuffer();

		// <<thanks to naoya_t>> Generate the timer function
		Code.append("#include <ctime>\n");
		Code.append("double start_time; string timer()\n");
		Code.append(" { ostringstream os; os << \" (\" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << \" msec)\"; return os.str(); }\n");

		// Generate the vector output function
		Code.append("template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)\n");
		Code.append(" { os << \"{ \";\n");
		Code.append("   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)\n");
		Code.append("   os << \'\\\"\' << *it << \'\\\"\' << (it+1==v.end() ? \"\" : \", \"); os << \" }\"; return os; }\n");

		// Generate the verification function
		generate_verification_code(Code, ReturnType);

		// <<modified by cafelier>> : new test code template
		Code.append("#define CASE(N) {cerr << \"Test Case #\" << N << \"...\" << flush; start_time=clock();\n");
		Code.append("#define END	 ");
		generate_verifier_call(Code, ParamTypes, ReturnType, Cases[0]);
		Code.append("}\n");
		Code.append("int main(){\n\n");

		// Generate the individual test cases
		for(int i=0; i<Cases.length; ++i)
			generate_test_case(i, Code, ParamTypes, ReturnType, Cases[i]);
		Code.append("\n}\n");

		// Insert the cut tags
		Code.insert(0, k_BEGINCUT+"\n");
		Code.append(k_ENDCUT);

		// Replace $TESTCODE$
		m_Tags.put(k_TESTCODE, Code.toString());
	}

	/**
	 * This method will generate the code for verifying test cases.
	 */
	private void generate_verification_code(StringBuffer Code, DataType ReturnType)
	{
		String TypeString = ReturnType.getDescriptor(m_Language);

		// <<modified by cafelier>> : new test code template
		Code.append("void verify_case(const " + TypeString + "& Expected, const " + TypeString + "& Received) {\n");

		// Print "PASSED" or "FAILED" based on the result
		// <<modified by naoya_t>> : double precision
		if (TypeString.equals("double")) {
			Code.append(" double diff = Expected - Received; if (diff < 0) diff = -diff;");
			Code.append(" bool ok = (diff < 1e-9);\n");
		} else {
			Code.append(" bool ok = (Expected == Received);\n");
		}
		Code.append(" if(ok) cerr << \"PASSED\" << timer() << endl; ");
		Code.append(" else { cerr << \"FAILED\" << timer() << endl;\n ");

		if (ReturnType.getDimension() == 0)
		{
			Code.append("cerr << \"\\to: \\\"\" << Expected << \'\\\"\' << endl ");
			Code.append("<< \"\\tx: \\\"\" << Received << \'\\\"\' << endl; }");
		}
		else
		{
			Code.append("cerr << \"\\to: \" << Expected << endl ");
			Code.append("<< \"\\tx: \" << Received << endl; }");
		}

		Code.append(" }\n");
	}

	/**
	 * This method will generate the code for one test case.
	 */
	private void generate_test_case(int Index, StringBuffer Code, DataType[] ParamTypes, DataType ReturnType, TestCase Case)
	{
		String[] Inputs = Case.getInput();
		String Output = Case.getOutput();
		String Desc = ReturnType.getDescription();

		/*
		 * Generate code for setting up individual test cases
		 * and calling the method with these parameters.
		*/

		// <<modified by cafelier>> : new test code template
		Code.append("CASE("+Index+")\n");

		// Generate each input variable separately
		for (int I = 0; I < Inputs.length; ++I) {
			Code.append("\t");
			generate_parameter(I, Code, ParamTypes[I], Inputs[I]);
			Code.append("\n");
		}

		// Generate the output variable as the last variable
		Code.append("\t");
		generate_parameter(-1, Code, ReturnType, Output);
		Code.append("\n");
		Code.append("END\n");
	}

	private void generate_verifier_call(StringBuffer Code, DataType[] ParamTypes, DataType ReturnType, TestCase Case)
	{
		String[] Inputs = Case.getInput();
		String Output = Case.getOutput();
		String Desc = ReturnType.getDescription();

		Code.append("verify_case(_, "
		  + m_Problem.getClassName() + "()." + m_Problem.getMethodName() + "(");
		for(int i=0; i<Inputs.length; ++i)
		{
			Code.append( m_Problem.getParamNames()[i] );
			if( i < Inputs.length-1 )
				Code.append(", ");
		}
		Code.append("));");
	}

	/**
	 * This method will generate the required parameter as a unique variable.
	 */
	private void generate_parameter(int Index, StringBuffer Code, DataType ParamType, String Input)
	{
		// <<modified by cafelier>> : named parameters
		String Name = (Index==-1 ? "_" : m_Problem.getParamNames()[Index]);

		String Desc = ParamType.getBaseName();

		if (ParamType.getDimension() == 0)
		{
			// Just a scalar value, simply initialize it at declaration (long integers need an 'L' tagged on)
			if (Desc.equals("long") || Desc.equals("Long"))
				Code.append(ParamType.getDescriptor(m_Language) + " " + Name + " = " + Input + "LL; ");
			else
				Code.append(ParamType.getDescriptor(m_Language) + " " + Name + " = " + Input + "; ");
		}
		else
		{
			  // <<modified by cafelier>> : empty array
			  if( Input.matches("^[\\s\\{\\}]*$") )
			  {
				Code.append(ParamType.getDescriptor(m_Language) + " " + Name + "; ");
			  }
			  else
			  {
				// Arrays need to be converted to vector<type> before passing
				Code.append(ParamType.getBaseName().toLowerCase() + " " + Name + "_[] = " + Input + ";\n\t");
				Code.append("  "+ParamType.getDescriptor(m_Language) + " " + Name + "(" + Name + "_, " + Name + "_+sizeof("+Name+"_)/sizeof(*"+Name+"_)); ");
			  }
		}
	}
}
