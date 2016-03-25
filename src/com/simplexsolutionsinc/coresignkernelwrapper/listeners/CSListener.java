package com.simplexsolutionsinc.coresignkernelwrapper.listeners;


public interface CSListener {

	public int[] getEventTypes();

	public void handleEvent(CSEvent event);

}
