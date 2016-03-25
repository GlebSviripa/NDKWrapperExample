package com.simplexsolutionsinc.coresignkernelwrapper;

import android.graphics.RectF;

public class KernelRect
{

	public double w,h,x,y;
	
	public KernelRect(double _x, double _y, double _w, double _h)
	{
		w = _w;
		y = _y;
		x = _x;
		h = _h;
	}
	
	public RectF toRectF()
	{
		return new RectF((float)x,(float)y,(float)w,(float)h);
	}
}
