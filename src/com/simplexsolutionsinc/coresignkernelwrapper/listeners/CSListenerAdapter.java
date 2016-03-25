package com.simplexsolutionsinc.coresignkernelwrapper.listeners;


public class CSListenerAdapter implements CSListener
{

	CSListener listener;
	long ptr;
	
	public CSListenerAdapter(CSListener _listener)
	{
		listener = _listener;
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

	@Override
	public int[] getEventTypes()
	{
		
		return listener.getEventTypes();
	}

	@Override
	public void handleEvent(CSEvent event)
	{
		listener.handleEvent(event);
		
	}

}
