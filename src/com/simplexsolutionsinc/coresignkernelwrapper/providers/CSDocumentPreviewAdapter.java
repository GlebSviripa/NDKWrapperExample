package com.simplexsolutionsinc.coresignkernelwrapper.providers;

import com.simplexsolutionsinc.coresignkernelwrapper.documents.CSDocument;

public class CSDocumentPreviewAdapter implements CSDocumentPreviewProvider
{

	CSDocumentPreviewProvider providerImpl;

	long ptr;

	public CSDocumentPreviewAdapter(CSDocumentPreviewProvider providerImpl)
	{
		this.providerImpl = providerImpl;
		ptr = getPtrJNI();
	}
	
	public static native void init(Class<CSDocument> c);

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

	/*
	 * Signature:
	 * (Lcom/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentID
	 * ;)Ljava/lang/String;
	 */
	@Override
	public String previewForDocument(CSDocument document)
	{
		return providerImpl.previewForDocument(document);
	}

}
