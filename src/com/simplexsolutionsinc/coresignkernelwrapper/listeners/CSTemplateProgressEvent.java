package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

public class CSTemplateProgressEvent extends CSTemplateEvent
{

	public CSTemplateProgressEvent(long _ptr)
	{
		super(_ptr);
		
	}
	
	public native float getProgress();

}
