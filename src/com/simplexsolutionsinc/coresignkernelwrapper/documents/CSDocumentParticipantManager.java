package com.simplexsolutionsinc.coresignkernelwrapper.documents;

import com.simplexsolutionsinc.coresignkernelwrapper.CSColor;
import com.simplexsolutionsinc.coresignkernelwrapper.CSResult;

public class CSDocumentParticipantManager
{

	public final static int Success = 0;
	public final static int ErrorNoAccessRights = 1;
	public final static int ErrorInvalidParticipantRole = 2;
	public final static int ErrorParticipantNotFound = 3;
	public final static int ErrorParticipantAlreadyExists = 4;
	public final static int ErrorIndexOutOfRange = 5;
	
	long ptr;
	
	public CSDocumentParticipantManager(long _ptr)
	{
		ptr = _ptr;
	}
	
	/**
	 * This constructor is not for using from code, it's only for c++ implementation. Use CSDocumentManager.getPrticipantManager()
	 */
	@Deprecated
	public CSDocumentParticipantManager()
	{
		ptr = getPtrJNI();
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
	
	public native int getParticipantCount();
	
	public native CSDocumentParticipant getParticipant(long id, CSResult result);
	
	public native CSDocumentParticipant getParticipantAtIndex(int index, CSResult result);
	
	public native void addParticipant(CSDocumentParticipant participant, CSResult result);
	
	public native void insertParticipantAtIndex(CSDocumentParticipant participant, int index, CSResult result);
	
	public native void removeParticipantAtIndex(int index, CSResult result);
	
	public native void moveParticipant(int currentIndex, int newIndex, CSResult result);
	
	public native CSColor getNextColor();

}
