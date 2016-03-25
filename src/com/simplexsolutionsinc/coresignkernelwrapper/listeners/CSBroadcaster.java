package com.simplexsolutionsinc.coresignkernelwrapper.listeners;

import com.simplexsolutionsinc.coresignkernelwrapper.CSResult;

public class CSBroadcaster
{
	//Interface
	
		public static native void addListener(CSListenerAdapter listenerAdapter, CSResult result);
		public static native void removeListener(CSListenerAdapter listenerAdapter, CSResult result);


}
