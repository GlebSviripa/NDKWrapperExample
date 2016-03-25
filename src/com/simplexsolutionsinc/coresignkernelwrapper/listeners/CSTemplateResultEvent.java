package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

import com.simplexsolutionsinc.coresignkernelwrapper.CSResult;

public class CSTemplateResultEvent extends CSTemplateEvent
{

	public CSTemplateResultEvent(long _ptr)
	{
		super(_ptr);
		
	}
	
	public native CSResult getResult();

}
