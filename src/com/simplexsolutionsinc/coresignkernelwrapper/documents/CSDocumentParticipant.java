package com.simplexsolutionsinc.coresignkernelwrapper.documents;

import com.simplexsolutionsinc.coresignkernelwrapper.CSColor;


public class CSDocumentParticipant
{

	// status
	public static final int Uknown_Participant = 0;
	public static final int Waiting = 1;
	public static final int Signing = 2;
	public static final int Sent = 3;

	// role
	public static final int Unknown_Role = 0;
	public static final int Author = 1;
	public static final int Observer = 2;
	public static final int Signer = 3;

	long ptr;

	public CSDocumentParticipant(long _ptr)
	{
		ptr = _ptr;
	}
	
	public CSDocumentParticipant()
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

	// getters
	public native long getId();
	public native void setId(long id);

	public native int getStatus();
	//public native void setStatus(int status);

	public native int getRole();
	public native void setRole(int role);

	public native CSColor getColor();
	public native void setColor(int a, int r, int g, int b);

}
