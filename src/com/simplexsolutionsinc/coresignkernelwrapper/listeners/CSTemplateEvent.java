package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

import com.simplexsolutionsinc.coresignkernelwrapper.templates.CSTemplateID;

public class CSTemplateEvent extends CSEvent
{

	public CSTemplateEvent(long _ptr)
	{
		super(_ptr);
		
	}

	public native CSTemplateID getTemplateID();

}
