package com.simplexsolutionsinc.coresignkernelwrapper.documents;

public class CSBySignerDocumentFilter extends CSDocumentFilter
{
	public static final int Whoever = 0;
	public static final int Me = 1;
	public static final int Partner = 2;

	long ptr;

	/*public CSBySignerDocumentFilter(long _ptr)
	{
		ptr = _ptr;
	}*/

	public CSBySignerDocumentFilter(int signer)
	{
		ptr = init(signer);
	}

	/**
	 * call this method in JNI
	 */
	public long getPtr()
	{
		return ptr;
	}


	public native void destroy();

	@Override
	protected void finalize() throws Throwable
	{
		
		super.finalize();
		destroy();
	}

	//kernel methods
	
	public native long init(long signer);
	public native int getSignerType();

	@Override
	public int getType() {
		
		return CSDocumentFilter.BySigner;
	}


}
