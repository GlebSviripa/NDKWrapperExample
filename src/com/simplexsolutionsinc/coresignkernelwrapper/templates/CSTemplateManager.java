package com.simplexsolutionsinc.coresignkernelwrapper.templates;

import com.simplexsolutionsinc.coresignkernelwrapper.CSResult;
import com.simplexsolutionsinc.coresignkernelwrapper.listeners.CSListenerAdapter;

public class CSTemplateManager
{

	private static CSTemplateManager instance;
	long ptr;

	public static synchronized CSTemplateManager getInstance()
	{
		if (instance == null)
		{
			instance = new CSTemplateManager();
		}
		return instance;
	}

	private CSTemplateManager()
	{
		ptr = getPtrJNI();
	}

	// wrapper methods
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

	// kernel methods

	public native CSTemplateAuthor[] getTemplateAuthors();

	public native CSTemplateID[] getTemplateIDs();

	public native CSTemplateID[] getTemplateIDs(CSTemplateFilter filter);

	public native CSTemplate getTemplate(CSTemplateID id);

	public native void cleanCache();

	// Interface

	public native void addListener(CSListenerAdapter listenerAdapter, CSResult result);

	public native void removeListener(CSListenerAdapter listenerAdapter, CSResult result);

}
