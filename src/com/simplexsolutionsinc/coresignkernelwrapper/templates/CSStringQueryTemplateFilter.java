package com.simplexsolutionsinc.coresignkernelwrapper.templates;


public class CSStringQueryTemplateFilter extends CSTemplateFilter {

    long ptr;

    public CSStringQueryTemplateFilter(long _ptr) {
        ptr = _ptr;
    }

    public CSStringQueryTemplateFilter(String query) {
        ptr = init(query);
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

    public native String getQuery();

    public native long init(String query);
}
