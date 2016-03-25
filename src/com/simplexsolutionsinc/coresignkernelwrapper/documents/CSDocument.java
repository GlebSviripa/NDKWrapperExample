package com.simplexsolutionsinc.coresignkernelwrapper.documents;

import android.util.Log;

import com.simplexsolutionsinc.coresignkernelwrapper.CSResult;

public class CSDocument
{
	public class State
	{
		public static final int Prepare = 0;
		public static final int Fill = 1;
		public static final int Complete = 2;
	}

	public class ContentFetchingState
	{
		public static final int NotFetching = 0;
		public static final int Fetching = 1;
		public static final int Fetched = 2;
	}
	
	public static final int Success = 0;
	public static final int ErrorInternal = 1;
	public static final int ErrorNoAccessRights = 2;
	public static final int ErrorDocumentAlreadyMarkedAsRead = 3;
	public static final int ErrorPreviewAlreadyFetched = 4;
	public static final int ErrorPreviewNotFetchedYet = 5;
	public static final int ErrorContentAlreadyFetched = 6;
	public static final int ErrorContentNotFetchedYet = 7;

	long ptr;

	public CSDocument(long _ptr)
	{
		ptr = _ptr;
		Log.v("CSDocument JAVA", "Constructor: " + ptr);
	}

	/**
	 * This constructor has been deprecated. Use CSDocumentManager.getDocument()
	 */
	@Deprecated
	public CSDocument()
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

		Log.v("Document PTR on Finalize", "" + Long.toHexString(getPtr()));
		destroy();
		super.finalize();

	}

	// kernel methods
	// getters
	public native CSDocumentID getId();

	public native String getName();

	public native CSDocumentParticipant getAuthor();

	public native void setName(String name);

	public native String getNote();

	public native void setNote(String note);

	public native int getState();

	public native int getCreationDateMilis();

	public native long getUpdateDateMilis();

	public native CSDocumentContent getContent();

	public native CSDocumentParticipantManager getParticipantManager();

	public native float getContentFetchingProgress();

	public native String getPreviewPath();

	public native void fetchPreview(CSResult result);

	public native void fetchContent(CSResult result);
}
