package com.simplexsolutionsinc.coresignkernelwrapper.documents;

import android.util.Log;

import com.simplexsolutionsinc.coresignkernelwrapper.annotations.CSAnnotationStore;

public class CSDocumentContent
{

	long ptr;

	/**
	 * Don't use this constructor. Use CSDocument.getContent();
	 */
	public CSDocumentContent(long _ptr)
	{
		Log.v("CONTENT PTR CONSTRUCTOR", _ptr + "");
		ptr = _ptr;
	}

	/**
	 * This constructor is deprecated. Use CSDocument.getContent();
	 */
	@Deprecated
	public CSDocumentContent()
	{
		ptr = getPtrJNI();
	}
	public long getPtr()
	{
		Log.v("CONTENT PTR method", ptr + "");
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

	// getters
	public native CSPDF getPDF();

	public native int getNumberOfPages();

	public native CSAnnotationStore getAnnotationStore();

}
