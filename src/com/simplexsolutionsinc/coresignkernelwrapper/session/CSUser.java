package com.simplexsolutionsinc.coresignkernelwrapper.session;

import android.util.Log;

public class CSUser
{

	long ptr;

	public CSUser()
	{
		ptr = getPtrJNI();
	}
	
	public CSUser(long _ptr)
	{
		ptr = _ptr;
	}
	
	public CSUser(long id, CSUserKeys keys)
	{
		this();
		setUserID(id);
		setKeys(keys);
	}


	public native long getUserID();
	public native void setUserID(long id);
	
	public native CSUserKeys getKeys();
	public native void setKeys(CSUserKeys keys);
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
}
