package com.simplexsolutionsinc.coresignkernelwrapper.session;

import com.simplexsolutionsinc.coresignkernelwrapper.CSResult;
import com.simplexsolutionsinc.coresignkernelwrapper.listeners.CSListenerAdapter;
import com.simplexsolutionsinc.coresignkernelwrapper.providers.CSSessionCredentialsProvider;
import com.simplexsolutionsinc.coresignkernelwrapper.providers.CSSessionCredentialsProviderAdapter;

public class CSSession
{
	//States
	public static final int Empty = 0;
	public static final int LoggedIn = 1;
	public static final int Syncing = 2;
		
	//Results
	public static final int Success = 0;
	public static final int ErrorInternal = 1;
	public static final int ErrorNotLoggedIn = 2;
	public static final int ErrorAlreadyLoggedIn = 3;
	public static final int ErrorLoggedInAsAnotherUser = 4;
	public static final int ErrorCantAccessStorage = 5;
	public static final int ErrorCantFindUserInfo = 6;
	public static final int ErrorCantSaveUserInfo = 7;
	public static final int ErrorInvalidUserCredentials = 8;
	public static final int ErrorNotSyncing = 9;
	
	public CSSession()
	{
	}

	public static native void init();

	public static native void destroy();

	public static native int getState();

	public static native CSSessionCredentials getCredentials(CSResult result);

	public static native CSSessionCredentialsProviderAdapter getCredentialsProvider();

	public static native void setCredentialsProvider(CSSessionCredentialsProviderAdapter provider);

	public static native CSSessionConfig getConfig();

	public static native void setConfig(CSSessionConfig config);

	public static native long getCurrentUserId();

	public static native boolean hasCriticalTasks();

	public static native CSSession getInstance();

	public static native void login(CSUser user, String password, CSResult result);

	public static native void logout(CSResult result);

	public static native void startSync(CSResult result);

	public static native void stopSync(CSResult result);

	public static native void suspend();

	public static native void resume();
	
	//Interface
	
	public static native void addListener(CSListenerAdapter listenerAdapter, CSResult result);
	public static native void removeListener(CSListenerAdapter listenerAdapter, CSResult result);

}
