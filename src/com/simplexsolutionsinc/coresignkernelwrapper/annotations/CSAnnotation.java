package com.simplexsolutionsinc.coresignkernelwrapper.annotations;

import com.simplexsolutionsinc.coresignkernelwrapper.CSResult;
import com.simplexsolutionsinc.coresignkernelwrapper.KernelRect;

public class CSAnnotation
{

	public static final int SIGNATURE = 1;
	public static final int INITIALS = 2;
	public static final int FREEPAINT = 6;
	public static final int TEXT = 3;
	public static final int DATE = 4;
	public static final int CHECKBOX = 5;

	long ptr;

	public CSAnnotation(long _ptr)
	{
		ptr = _ptr;
	}

	public CSAnnotation()
	{
		ptr = getPtrJNI();
	}

	public long getPtr()
	{
		return ptr;
	}

	public native long getPtrJNI();

	public native void destroy();

	@Override
	protected void finalize() throws Throwable
	{

		super.finalize();
		destroy();
	}

	public native int getAnnotationType();

	public native CSAnnotationID getID();

	public native KernelRect getFrame();

	public native void setFrame(double x, double y, double w, double h);

	public native boolean isPlaceholder();

	public native long getOwner();

	public native void setOwner(long id);

	public native boolean canUndo();

	public native boolean canRedo();

	public native int undo(CSResult result);

	public native int redo(CSResult result);
	
	public native boolean isEditable();

	public native boolean isContentEditable();
	
}
