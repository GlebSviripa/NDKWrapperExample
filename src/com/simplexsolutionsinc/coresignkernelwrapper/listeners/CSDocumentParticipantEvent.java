package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

public class CSDocumentParticipantEvent extends CSDocumentEvent
{

	public static final int DocumentParticipantAdded           = 79;  // DocumentParticipantEvent
	public static final int DocumentParticipantChanged         = 80;  // DocumentParticipantEvent
	public static final int DocumentParticipantRemoved         = 81;  // DocumentParticipantEvent
	
	public CSDocumentParticipantEvent(long _ptr)
	{
		super(_ptr);
		
	}
	
	public native long getParticipantID();

}
