package com.simplexsolutionsinc.coresignkernelwrapper.documents;

import com.simplexsolutionsinc.coresignkernelwrapper.CSResult;
import com.simplexsolutionsinc.coresignkernelwrapper.listeners.CSListenerAdapter;
import com.simplexsolutionsinc.coresignkernelwrapper.providers.CSDocumentPreviewProvider;
import com.simplexsolutionsinc.coresignkernelwrapper.session.CSSessionConfig;

public class CSDocumentManager
{

	public final static int Success = 0;
	public final static int ErrorInternal = 1;
	public final static int ErrorNotLoggedIn = 2;
	public final static int ErrorNotSyncing = 3;
	public final static int ErrorCantGetDocumentIDs = 4;
	public final static int ErrorInvalidDocumentID = 5;
	public final static int ErrorCantCreateDocument = 6;
	public final static int ErrorInvalidPDF = 7;
	public final static int ErrorInvalidTemplateID = 8;
	public final static int ErrorTemplateNotFetchedYet = 9;
	public final static int ErrorInvalidDocument = 10;
	public final static int ErrorDocumentIsReadOnly = 11;
	public final static int ErrorCantSaveDocument = 12;
	public final static int ErrorCantFinishSigning = 13;
	public final static int ErrorInvalidSharedID = 14;
	
	public CSDocumentManager()
	{
	}

	public static native CSDocumentManager init();

	public static native CSDocumentID[] getDocumentsIds(CSResult result);

	public static native CSDocumentID[] getDocumentsIds(CSDocumentFilter filter, CSResult result);

	public static native CSDocument getDocument(CSDocumentID id, CSResult result);

	public static native CSDocumentID createDocument(CSPDF pdf, int numberOfPages, CSResult result);

	public static native CSDocumentID cloneDocument(CSDocumentID id, CSResult result);

	public static native void removeDocument(CSDocumentID id, CSResult result);

	public static native void saveDocument(CSDocument document, CSDocumentPreviewProvider previewProvider,
			CSResult result);

	public static native void finishSigningDocument(CSDocumentID id, CSResult result);

	public static native String requestShareIdForDocument(CSDocumentID id, CSResult result);

	public static native CSDocumentID requestDocumentForShareId(String id, CSResult result);

	public static native void cleanCache();

	// Interface

	public static native void addListener(CSListenerAdapter listenerAdapter, CSResult result);

	public static native void removeListener(CSListenerAdapter listenerAdapter, CSResult result);

}
