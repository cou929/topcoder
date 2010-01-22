// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 

package com.topcoder.shared.problem;

import com.topcoder.shared.netCommon.CSReader;
import com.topcoder.shared.netCommon.CSWriter;
import java.io.IOException;
import java.io.ObjectStreamException;

// Referenced classes of package com.topcoder.shared.problem:
//            BaseElement, Element, ProblemComponent

public class TestCase extends BaseElement
    implements Element
{

    public TestCase()
    {
    }

    public TestCase(String as[], String s, boolean flag)
    {
        this(as, s, null, flag);
    }

    public TestCase(String as[], String s, Element element, boolean flag)
    {
        this(as, s, element, flag, false);
    }

    public TestCase(String as[], String s, Element element, boolean flag, boolean flag1)
    {
        input = as;
        output = s;
        annotation = element;
        example = flag;
        systemTest = flag1;
        if(element == null)
            text = "";
        else
            text = element.toXML();
        output = ProblemComponent.decodeXML(output);
        for(int i = 0; i < input.length; i++)
            input[i] = ProblemComponent.decodeXML(input[i]);

    }

    public TestCase(String as[], Element element, boolean flag)
    {
        this(as, "UNKNOWN-OUTPUT10291821323", element, flag);
    }

    public void customWriteObject(CSWriter cswriter)
        throws IOException
    {
        cswriter.writeObjectArray(input);
        cswriter.writeString(output);
        cswriter.writeObject(annotation);
        cswriter.writeBoolean(example);
        cswriter.writeBoolean(systemTest);
    }

    public void customReadObject(CSReader csreader)
        throws IOException, ObjectStreamException
    {
        Object aobj[] = csreader.readObjectArray();
        output = csreader.readString();
        annotation = (Element)csreader.readObject();
        example = csreader.readBoolean();
        systemTest = csreader.readBoolean();
        input = new String[aobj.length];
        for(int i = 0; i < aobj.length; i++)
            input[i] = (String)aobj[i];

        if(annotation == null)
            text = "";
        else
            text = annotation.toXML();
    }

    public boolean isExample()
    {
        return example;
    }

    public void setExample(boolean flag)
    {
        example = flag;
    }

    public String[] getInput()
    {
        return input;
    }

    public void setOutput(String s)
    {
        output = s;
    }

    public String getOutput()
    {
        return output;
    }

    public Element getAnnotation()
    {
        return annotation;
    }

    public boolean isSystemTest()
    {
        return systemTest;
    }

    public void setSystemTest(boolean flag)
    {
        systemTest = flag;
    }

    public String toXML()
    {
        StringBuffer stringbuffer = new StringBuffer(256);
        stringbuffer.append("<test-case");
        if(example)
            stringbuffer.append(" example=\"1\"");
        if(systemTest)
            stringbuffer.append(" systemTest=\"1\"");
        stringbuffer.append('>');
        for(int i = 0; i < input.length; i++)
        {
            stringbuffer.append("<input>");
            stringbuffer.append(ProblemComponent.encodeXML(input[i]));
            stringbuffer.append("</input>");
        }

        stringbuffer.append("<output>");
        stringbuffer.append(ProblemComponent.encodeXML(output));
        stringbuffer.append("</output>");
        if(text != null && !text.equals(""))
            stringbuffer.append(ProblemComponent.handleTextElement("annotation", annotation));
        stringbuffer.append("</test-case>");
        return stringbuffer.toString();
    }

    public boolean equals(Object obj)
    {
        if(obj == null || !(obj instanceof TestCase))
        {
            return false;
        } else
        {
            TestCase testcase = (TestCase)obj;
            return toXML().equals(testcase.toXML());
        }
    }

    private String input[];
    private String output;
    private String text;
    private Element annotation;
    private boolean example;
    private boolean systemTest;
}
