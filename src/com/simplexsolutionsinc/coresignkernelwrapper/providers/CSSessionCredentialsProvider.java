package com.simplexsolutionsinc.coresignkernelwrapper.providers;

import com.simplexsolutionsinc.coresignkernelwrapper.session.CSSessionCredentials;

public interface CSSessionCredentialsProvider {

    public static class RequestReason {
        public static final int LoggingIn = 0;
        public static final int SessionExpired = 1;
    }

    public CSSessionCredentials getCredentials(long id, int requestReason);

}
