package com.simplexsolutionsinc.coresignkernelwrapper.documents;

import android.util.Log;

public class CSDocumentID
{
	long ptr;
	public CSDocumentID(long _ptr)
	{
		ptr = _ptr;
		Log.v("CSDocumentID JAVA", "Constructor: " + ptr);
	}
	
	public long getPtr()
	{
		Log.v("CSDocumentID JAVA", "getPTR: " + ptr);
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
