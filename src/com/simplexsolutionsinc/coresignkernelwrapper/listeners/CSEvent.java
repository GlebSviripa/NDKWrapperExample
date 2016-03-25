package com.simplexsolutionsinc.coresignkernelwrapper.listeners;


public class CSEvent
{
	long ptr;
	
	public CSEvent(long _ptr)
	{
		ptr = _ptr;
	}
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
		//destroy();
	}
	
	public native int getEventType();


}
