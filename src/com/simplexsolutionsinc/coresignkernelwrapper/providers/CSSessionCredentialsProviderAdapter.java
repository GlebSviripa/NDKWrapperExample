package com.simplexsolutionsinc.coresignkernelwrapper.providers;

import com.simplexsolutionsinc.coresignkernelwrapper.session.CSSessionCredentials;

public class CSSessionCredentialsProviderAdapter implements CSSessionCredentialsProvider {

    CSSessionCredentialsProvider providerImpl;

    long ptr;

    public CSSessionCredentialsProviderAdapter(CSSessionCredentialsProvider providerImpl) {
        this.providerImpl = providerImpl;
        ptr = getPtrJNI();
    }

    public static native void init();
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

    /*
    Signature: (J;I)Lcom/simplexsolutionsinc/coresignkernelwrapper/session/CSSessionCredentials;
     */
    @Override
    public CSSessionCredentials getCredentials(long id, int requestReason) {
        return providerImpl.getCredentials(id, requestReason);
    }
}
