package com.simplexsolutionsinc.coresignkernelwrapper.templates;

public class CSTemplate {

    long ptr;

    public CSTemplate(long _ptr) {
        ptr = _ptr;
    }

    public CSTemplate() {
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

    public native CSTemplateID getId();

    public native String getName();

    public native CSTemplateAuthor getTemplateAuthor();

    public native int getCreationDateMilis();

    public native int getUpdateDateMilis();

    public native float getFetchingProgress();

    public native String getPreviewPath();

    public native void fetch();

    public native void fetchPreview();

}
