package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

public class CSDocumentProgressEvent extends CSDocumentEvent
{

	public static final int DocumentContentFetchingProgress    = 71;  // DocumentProgressEvent
	
	public CSDocumentProgressEvent(long _ptr)
	{
		super(_ptr);
		
	}
	
	public native float getProgress();

}
