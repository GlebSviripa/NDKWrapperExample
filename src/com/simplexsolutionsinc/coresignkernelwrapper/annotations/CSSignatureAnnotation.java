package com.simplexsolutionsinc.coresignkernelwrapper.annotations;


public class CSSignatureAnnotation extends CSAnnotation
{

	public CSSignatureAnnotation(long ptr)
	{
		super(ptr);
	}
	public native String getSignaturePath();
	public native void setSignaturePath(String path);

}
