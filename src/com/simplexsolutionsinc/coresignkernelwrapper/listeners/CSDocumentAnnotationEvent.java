package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

import com.simplexsolutionsinc.coresignkernelwrapper.annotations.CSAnnotationID;

public class CSDocumentAnnotationEvent extends CSDocumentEvent
{

	public static final int DocumentAnnotationAdded            = 76;  // DocumentAnnotationEvent
	public static final int DocumentAnnotationChanged          = 77;  // DocumentAnnotationEvent
	public static final int DocumentAnnotationRemoved          = 78;  // DocumentAnnotationEvent
	
	public CSDocumentAnnotationEvent(long _ptr)
	{
		super(_ptr);
		
	}
	
	public native CSAnnotationID getAnnotationID();

}
