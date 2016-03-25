package com.simplexsolutionsinc.coresignkernelwrapper.templates;


public class CSCompositeTemplateFilter extends CSTemplateFilter {

    long ptr;

    public CSCompositeTemplateFilter(long _ptr) {
        ptr = _ptr;
    }

    public CSCompositeTemplateFilter(CSTemplateFilter[] filters) {
        ptr = init(filters);
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

    public native CSTemplateFilter[] getFilters();

    public native long init(CSTemplateFilter[] filters);
}
