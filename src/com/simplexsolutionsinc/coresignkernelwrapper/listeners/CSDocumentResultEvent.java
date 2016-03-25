package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

import com.simplexsolutionsinc.coresignkernelwrapper.CSResult;

public class CSDocumentResultEvent extends CSDocumentEvent
{

	public static final int DocumentContentFetchingFailed      = 72;  // DocumentResultEvent
	public static final int DocumentPreviewFetchingFailed      = 74;  // DocumentResultEvent
	public CSDocumentResultEvent(long _ptr)
	{
		super(_ptr);
		
	}
	
	public native CSResult getResult();

}
