package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

public class CSTemplateImageEvent extends CSTemplateEvent
{

	public CSTemplateImageEvent(long _ptr)
	{
		super(_ptr);
		
	}
	
	public native String getImagePath();

}
