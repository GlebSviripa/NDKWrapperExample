package com.simplexsolutionsinc.coresignkernelwrapper.templates;

public class CSByAuthorTemplateFilter extends CSTemplateFilter {

    long ptr;

    public CSByAuthorTemplateFilter(long _ptr) {
        ptr = _ptr;
    }

    public CSByAuthorTemplateFilter(CSTemplateAuthor csTemplateAuthor) {
        ptr = init(csTemplateAuthor);
    }

    /**
     * call this method in JNI
     */
    public long getPtr() {
        return ptr;
    }

    /**
     * call this method in empty constructor
     */
    public native void destroy();

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        destroy();
    }

    //kernel methods

    public native CSTemplateAuthor getAuthor();

    public native long init(CSTemplateAuthor csTemplateAuthor);
}
