package com.simplexsolutionsinc.coresignkernelwrapper.session;


public class CSSessionConfig
{

	long ptr;

	public CSSessionConfig(long _ptr)
	{
		ptr = _ptr;
	}

	public CSSessionConfig()
	{
		ptr = getCSSessionConfigJNI();
	}
	
	public CSSessionConfig(String devCode, String devName, String tempStorage, String permanentStorage, String bundlePath)
	{
		this();
		setDeviceCode(devCode);
		setDeviceName(devName);
		setTempStoragePath(tempStorage);
		setPermanentStoragePath(permanentStorage);
		setBundlePath(bundlePath);
	}

	public long getPtr()
	{
		return ptr;
	}

	//kernel jni methods
	public native String getDeviceCode();
	public native void setDeviceCode(String devCode);

	public native String getDeviceName();
	public native void setDeviceName(String devName);

	public native String getTempStoragePath();
	public native void setTempStoragePath(String tempStorage);

	public native String getPermanentStoragePath();
	public native void setPermanentStoragePath(String permanentStorage);
	
	public native String getBundlePath();
	public native void setBundlePath(String bundle);
	
	//wrapper jni methods
	public native long getCSSessionConfigJNI();
	
	public native void destroy();
	
	@Override
	protected void finalize() throws Throwable
	{
		
		super.finalize();
		destroy();
	}

}
