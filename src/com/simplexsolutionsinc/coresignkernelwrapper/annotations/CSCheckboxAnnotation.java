package com.simplexsolutionsinc.coresignkernelwrapper.annotations;


public class CSCheckboxAnnotation extends CSAnnotation
{
	public CSCheckboxAnnotation(long ptr)
	{
		super(ptr);
	}
	public static final int Undetermined = 0;
	public static final int Checked = 1;
	public static final int Unchecked = 2;

	public native int getState();
	public native void setState(int state);

}
