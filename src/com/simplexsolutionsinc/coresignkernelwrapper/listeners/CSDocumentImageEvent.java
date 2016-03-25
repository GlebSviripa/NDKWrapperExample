package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

public class CSDocumentImageEvent extends CSDocumentEvent
{
	public static final int DocumentPreviewReady               = 73;  // DocumentImageEvent

	public CSDocumentImageEvent(long _ptr)
	{
		super(_ptr);
		
	}
	
	public native String getImagePath();

}
