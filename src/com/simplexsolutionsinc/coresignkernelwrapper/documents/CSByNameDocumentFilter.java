package com.simplexsolutionsinc.coresignkernelwrapper.documents;

public class CSByNameDocumentFilter extends CSDocumentFilter {

	long ptr;
	
	public CSByNameDocumentFilter(long _ptr)
	{
		ptr = _ptr;
	}
	
	public CSByNameDocumentFilter(String documentName) {
		ptr = init(documentName);
	}
	
	/**
	 * call this method in JNI
	 */
	public long getPtr()
	{
		return ptr;
	}

	/**
	 * call this method in empty constructor
	 */

	public native void destroy();

	@Override
	protected void finalize() throws Throwable
	{
		
		super.finalize();
		destroy();
	}
	
	//kernel methods

	public native long init(String documentName);
	public native String getDocumentName();

	@Override
	public int getType() {

		return CSDocumentFilter.ByName;
	}


}
