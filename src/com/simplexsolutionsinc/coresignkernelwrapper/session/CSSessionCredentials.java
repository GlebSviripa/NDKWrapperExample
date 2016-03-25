package com.simplexsolutionsinc.coresignkernelwrapper.session;


public class CSSessionCredentials
{
	private long ptr;

	public CSSessionCredentials(long _ptr)
	{
		ptr = _ptr;
	}
	
	public CSSessionCredentials()
	{
		ptr = getCSCredentialsJNI();
	}
	
	public long getPtr()
	{
		return ptr;
	}

	
	//kernel jni methods
	public native String getRpcSession();
	public native void setRpcSession(String session);
	
	public native String getEventSession();
	public native void setEventSession(String session);
	
	public native CSServer[] getRpcServers();
	public native void setRpcServers(CSServer[] servers);
	
	public native CSServer[] getEventServers();
	public native void setEventServers(CSServer[] servers);


	
	//wrapper jni methods
	public native long getCSCredentialsJNI();

	public native void destroy();

	@Override
	protected void finalize() throws Throwable
	{
		
		super.finalize();
		destroy();
	}

}
