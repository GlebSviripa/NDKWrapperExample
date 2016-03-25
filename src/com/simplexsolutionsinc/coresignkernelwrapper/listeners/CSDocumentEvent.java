package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

import com.simplexsolutionsinc.coresignkernelwrapper.documents.CSDocumentID;

public class CSDocumentEvent extends CSEvent
{

	public static final int DocumentAdded                      = 64;  // DocumentEvent
	public static final int DocumentRemoved                    = 65;  // DocumentEvent
	public static final int DocumentSynced                     = 66;  // DocumentEvent
	public static final int DocumentSent                       = 67;  // DocumentEvent
	public static final int DocumentNameChanged                = 68;  // DocumentEvent
	public static final int DocumentPDFChanged                 = 69;  // DocumentEvent
	public static final int DocumentContentReady               = 70;  // DocumentEvent
	public static final int DocumentPreviewChanged             = 75;  // DocumentEvent
	
	public CSDocumentEvent(long _ptr)
	{
		super(_ptr);
		
	}

	public native CSDocumentID getDocumentID();
	
}
