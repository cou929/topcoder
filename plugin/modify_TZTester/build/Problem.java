// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 

package com.topcoder.shared.problem;

import com.topcoder.shared.netCommon.*;
import java.io.*;

// Referenced classes of package com.topcoder.shared.problem:
//            BaseElement, Element, ProblemComponent, WebService, 
//            ProblemConstants

public class Problem extends BaseElement
    implements Element, Serializable, CustomSerializable
{

    public final String getCacheKey()
    {
        return "Problem." + problemId;
    }

    public Problem()
    {
        problemComponents = new ProblemComponent[0];
        problemId = -1;
        name = "";
        problemTypeID = -1;
        problemText = "";
        webServices = new WebService[0];
    }

    public static String getCacheKey(int i)
    {
        return "Problem." + i;
    }

    public void customWriteObject(CSWriter cswriter)
        throws IOException
    {
        cswriter.writeInt(problemComponents.length);
        for(int i = 0; i < problemComponents.length; i++)
            cswriter.writeObject(problemComponents[i]);

        cswriter.writeInt(problemId);
        cswriter.writeString(name);
        cswriter.writeInt(problemTypeID);
        cswriter.writeString(problemText);
        cswriter.writeObjectArray(webServices);
    }

    public void customReadObject(CSReader csreader)
        throws IOException, ObjectStreamException
    {
        int i = csreader.readInt();
        problemComponents = new ProblemComponent[i];
        for(int j = 0; j < i; j++)
            problemComponents[j] = (ProblemComponent)csreader.readObject();

        problemId = csreader.readInt();
        name = csreader.readString();
        problemTypeID = csreader.readInt();
        problemText = csreader.readString();
        Object aobj[] = csreader.readObjectArray();
        if(aobj == null)
            aobj = new Object[0];
        webServices = new WebService[aobj.length];
        for(int k = 0; k < aobj.length; k++)
            webServices[k] = (WebService)aobj[k];

    }

    public void setProblemId(int i)
    {
        problemId = i;
    }

    public int getProblemId()
    {
        return problemId;
    }

    public Object clone()
    {
        Problem problem = new Problem();
        problem.setProblemId(problemId);
        problem.setProblemText(problemText);
        problem.setProblemComponents(problemComponents);
        return problem;
    }

    public void setName(String s)
    {
        name = s;
    }

    public String getName()
    {
        return name;
    }

    public String getProblemText()
    {
        return problemText;
    }

    public void setProblemText(String s)
    {
        problemText = s;
    }

    public ProblemComponent[] getProblemComponents()
    {
        return problemComponents;
    }

    public void setProblemComponents(ProblemComponent aproblemcomponent[])
    {
        problemComponents = aproblemcomponent;
    }

    public ProblemComponent getPrimaryComponent()
    {
        for(int i = 0; i < problemComponents.length; i++)
            if(problemComponents[i].getComponentTypeID() == ProblemConstants.MAIN_COMPONENT)
                return problemComponents[i];

        return null;
    }

    public int getProblemTypeID()
    {
        return problemTypeID;
    }

    public void setProblemTypeID(int i)
    {
        problemTypeID = i;
    }

    public ProblemComponent getComponent(int i)
    {
        if(i >= problemComponents.length)
            return null;
        else
            return problemComponents[i];
    }

    public String toString()
    {
        StringBuffer stringbuffer = new StringBuffer(1000);
        stringbuffer.append("(com.topcoder.shared.problem.Problem) [");
        stringbuffer.append("problemComponents = ");
        if(problemComponents == null)
        {
            stringbuffer.append("null");
        } else
        {
            stringbuffer.append("{");
            for(int i = 0; i < problemComponents.length; i++)
                stringbuffer.append(problemComponents[i].toString() + ",");

            stringbuffer.append("}");
        }
        stringbuffer.append(", ");
        stringbuffer.append("problemId = ");
        stringbuffer.append(problemId);
        stringbuffer.append(", ");
        stringbuffer.append("name = ");
        if(name == null)
            stringbuffer.append("null");
        else
            stringbuffer.append(name.toString());
        stringbuffer.append(", ");
        stringbuffer.append("problemTypeID = ");
        stringbuffer.append(problemTypeID);
        stringbuffer.append(", ");
        stringbuffer.append("problemText = ");
        if(problemText == null)
            stringbuffer.append("null");
        else
            stringbuffer.append(problemText.toString());
        stringbuffer.append(", ");
        stringbuffer.append("]");
        return stringbuffer.toString();
    }

    public boolean isValid()
    {
        boolean flag = true;
        for(int i = 0; i < problemComponents.length; i++)
            flag = flag && problemComponents[i].isValid();

        return flag;
    }

    public void setWebServices(WebService awebservice[])
    {
        webServices = awebservice;
    }

    public WebService[] getWebServices()
    {
        return webServices;
    }

    public String toXML()
    {
        StringBuffer stringbuffer = new StringBuffer();
        return stringbuffer.toString();
    }

    private ProblemComponent problemComponents[];
    private int problemId;
    private String name;
    private int problemTypeID;
    private String problemText;
    private WebService webServices[];
}
