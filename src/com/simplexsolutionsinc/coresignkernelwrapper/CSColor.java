package com.simplexsolutionsinc.coresignkernelwrapper;

import android.graphics.Color;

public class CSColor
{
	public int a, r, g, b;
	public CSColor(int _a, int _r, int _g, int _b)
	{
		a = _a;
		r = _r;
		g = _g;
		b = _b;
	}
	
	public int[] getNativeColor()
	{
		return new int[]{r, g, b, a};
	}
	
	public int getAndroidColor()
	{
		int c = Color.argb(a, r, g, b);
		
		return c;
	}
	
	public int getAndroidColorWithAlpha()
	{
		int c = Color.argb(100, r, g, b);
		
		return c;
	}
	
	public int getA()
	{
		return a;
	}

	public int getR()
	{
		return r;
	}
	
	public int getG()
	{
		return g;
	}
	
	public int getB()
	{
		return b;
	}
}
