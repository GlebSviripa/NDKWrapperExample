package com.simplexsolutionsinc.coresignkernelwrapper.templates;

public class CSTemplateAuthorID {

    long ptr;
    public CSTemplateAuthorID(long _ptr)
    {
        ptr = _ptr;
    }

    public long getPtr()
    {
        return ptr;
    }

    public native long getPtrJNI();

    public native void destroy();

    @Override
    protected void finalize() throws Throwable
    {
        super.finalize();
        destroy();
    }


}
