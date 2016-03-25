package com.simplexsolutionsinc.coresignkernelwrapper;

import com.simplexsolutionsinc.coresignkernelwrapper.listeners.CSListenerAdapter;

public class CSLegalsStorage
{

	public static native void init();

	public static native void destroy();

	public static native boolean hasInitials();

	public static native String getInitialsPath(CSResult result);

	public static native void setInitialsPath(String path, String previewPath, CSResult result);

	public static native String getInitialsPreviewPath(CSResult result);

	public static native boolean hasSignature();

	public static native String getSignaturePath(CSResult result);

	public static native void setSignaturePath(String path, String previewPath, CSResult result);

	public static native String getSignaturePreviewPath(CSResult result);

	// Interface

	public static native void addListener(CSListenerAdapter listenerAdapter, CSResult result);

	public static native void removeListener(CSListenerAdapter listenerAdapter, CSResult result);

}
