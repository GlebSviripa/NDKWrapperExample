package com.simplexsolutionsinc.coresignkernelwrapper.annotations;

public class CSAnnotationID
{

	long ptr;
	public CSAnnotationID(long _ptr)
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
		destroy();
	}

}
