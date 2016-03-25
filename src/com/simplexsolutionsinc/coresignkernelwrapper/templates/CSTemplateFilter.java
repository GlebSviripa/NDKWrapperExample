package com.simplexsolutionsinc.coresignkernelwrapper.templates;

public abstract class CSTemplateFilter {
    public static class Type {
        public static final int empty = 0;
        public static final int byAuthor = 1;
        public static final int byQuery = 2;
        public static final int сomposite = 3;
    }

    long ptr;

    public long getPtr() {
        return ptr;
    }

    public abstract void destroy();

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        destroy();
    }

    //kernel methods

    public native int getType();

}
