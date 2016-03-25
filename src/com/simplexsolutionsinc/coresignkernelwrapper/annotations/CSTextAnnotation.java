package com.simplexsolutionsinc.coresignkernelwrapper.annotations;

import com.simplexsolutionsinc.coresignkernelwrapper.CSColor;

public class CSTextAnnotation extends CSAnnotation {

	public CSTextAnnotation(long ptr)
	{
		super(ptr);
	}
	public native String getText();

	public native void setText(String text);

	public native String getFont();

	public native void setFont(String font);

	public native CSColor getColor();

	public native void setColor(int a, int r, int g, int b);

}
