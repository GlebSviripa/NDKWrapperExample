package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

public class CSSessionEvent extends CSEvent
{
	public static final int SessionStateChanged = 1;
	public static final int SessionUserPasswordChanged = 2;
	public static final int SessionCriticalTasksCompleted = 3;

	public CSSessionEvent(long _ptr)
	{
		super(_ptr);
		
	}

}
