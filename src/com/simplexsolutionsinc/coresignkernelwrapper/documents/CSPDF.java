package com.simplexsolutionsinc.coresignkernelwrapper.documents;

import android.util.Log;

public class CSPDF
{

	long ptr;

	public CSPDF(long _ptr)
	{
		ptr = _ptr;
	}
	
	public CSPDF()
	{
		ptr = getPtrJNI();
		Log.v("PDF PTR on Create", "" + Long.toHexString(ptr));
	}

	public long getPtr()
	{
		Log.v("PDF PTR on Get", "" + Long.toHexString(ptr));
		return ptr;
	}

	public native long getPtrJNI();

	public native void destroy();

	@Override
	protected void finalize() throws Throwable
	{

		Log.v("PDF PTR on Finalize", "" + Long.toHexString(ptr));
		destroy();
		super.finalize();
		
	}

	public native String getPassword();
	public native void setPassword(String password);

	public native String getPath();
	public native void setPath(String path);

}
