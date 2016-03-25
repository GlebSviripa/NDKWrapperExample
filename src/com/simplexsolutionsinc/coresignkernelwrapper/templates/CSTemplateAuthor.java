package com.simplexsolutionsinc.coresignkernelwrapper.templates;

public class CSTemplateAuthor {

    long ptr;

    public CSTemplateAuthor(long _ptr) {
        ptr = _ptr;
    }

    public CSTemplateAuthor() {
        ptr = getPtrJNI();
    }

    // wrapper methods
    public long getPtr() {
        return ptr;
    }

    public native long getPtrJNI();

    public native void destroy();

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        destroy();
    }

    //kernel methods

    public native CSTemplateAuthorID getId();

	public native String getCompanyName();

}
