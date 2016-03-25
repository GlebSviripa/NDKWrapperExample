package com.simplexsolutionsinc.coresignkernelwrapper.session;

public class CSServer
{
	long ptr;
	public CSServer(long _ptr)
	{
		ptr = _ptr;
	}
	public CSServer()
	{
		ptr = getPtrJNI(); 
	}

	public CSServer(String _address, int _port)
	{
		this();
		setAddress(_address);
		setPort(_port);
	}

	public native String getAddress();

	public native void setAddress(String address);

	public native int getPort();

	public native void setPort(int port);

	
	public long getPtr()
	{
		return ptr;
	}
	
	public native long getPtrJNI();

	public native void destroy();

	@Override
	protected void finalize() throws Throwable
	{
		
		super.finalize();
		destroy();
	}
}
