// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class NoOrderOfOperations {
   public:
   int evaluate(string expr)
  {
    int i;
    int ope1, ope2;

    ope1 = expr[0] - '0';

    for (i=1; i<expr.size(); i+=2)
      {
	ope2 = expr[i+1] - '0';
	if (expr[i] == '+')
	  ope1 = ope1 + ope2;
	else if (expr[i] == '-')
	  ope1 = ope1 - ope2;
	else if (expr[i] == '*')
	  ope1 = ope1 * ope2;
	else if (expr[i] == '/')
	  ope1 = ope1 / ope2;
      }
    return ope1;
   }

   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "3+5*7"; int Arg1 = 56; verify_case(0, Arg1, evaluate(Arg0)); }
	void test_case_1() { string Arg0 = "4-8*9*1"; int Arg1 = -36; verify_case(1, Arg1, evaluate(Arg0)); }
	void test_case_2() { string Arg0 = "0"; int Arg1 = 0; verify_case(2, Arg1, evaluate(Arg0)); }
	void test_case_3() { string Arg0 = "1*2*3*4*5*6*7*8*9"; int Arg1 = 362880; verify_case(3, Arg1, evaluate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
NoOrderOfOperations ___test;
___test.run_test(-1);
}
// END CUT HERE 
