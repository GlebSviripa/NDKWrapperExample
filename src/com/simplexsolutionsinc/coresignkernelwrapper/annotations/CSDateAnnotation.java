package com.simplexsolutionsinc.coresignkernelwrapper.annotations;

import com.simplexsolutionsinc.coresignkernelwrapper.CSColor;

public class CSDateAnnotation extends CSAnnotation {

	public CSDateAnnotation(long ptr)
	{
		super(ptr);
	}
	/**
	 * 
	 * @return time in milliseconds (it converts from seconds inside native code)
	 */
	public native long getDate();

	/**
	 * 
	 * @param date time in milliseconds (it converts in seconds inside native code)
	 */
	public native void setDate(long date);

	public native String getFont();

	public native void setFont(String font);

	public native CSColor getColor();

	public native void setColor(int a, int r, int g, int b);

}
