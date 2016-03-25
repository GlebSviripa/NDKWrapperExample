package com.simplexsolutionsinc.coresignkernelwrapper.annotations;


public class CSInitialsAnnotation extends CSAnnotation
{


	public CSInitialsAnnotation(long ptr)
	{
		super(ptr);
	}
	public native String getInitialsPath();
	
	public native void setInitialsPath(String path);

}
