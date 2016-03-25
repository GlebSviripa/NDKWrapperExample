/*
 * com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager.cpp
 *
 *  Created on: 12 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include <unistd.h>
#include <BaseID.hpp>

//#include <jemalloc.h>

using namespace std;

JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_getDocumentsIds__Lcom_simplexsolutionsinc_coresignkernelwrapper_CSResult_2
  (JNIEnv *env, jclass, jobject resultCodeObject)
{

	//JNIEnv *env = JavaCache::getJNIEnv();
	LOGI("getDocumentsIds start");
	jobjectArray result;
	jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentID");
	jmethodID constructor;
	constructor = env->GetMethodID(cf, "<init>", "(J)V");
	vector<CS::Document::ID> v;

	CS::DocumentManager::getInstance();
	int resultCode = 1;
	resultCode = (int)CS::DocumentManager::getInstance().getDocumentIDs(v);

	int size = v.size();
	result = (jobjectArray)env->NewObjectArray(size, cf, NULL);


	for (int i = 0; i < size; i++)
	{
		CS::Document::ID *id = new CS::Document::ID(v[i]);
		jobject element = env->NewObject(cf, constructor, (long long)id);
		env->SetObjectArrayElement(result, i, element);
	}


	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");

	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return result;
}

JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_getDocumentsIds__Lcom_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentFilter_2Lcom_simplexsolutionsinc_coresignkernelwrapper_CSResult_2
  (JNIEnv *env, jclass, jobject filter, jobject resultCodeObject)
{


	jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentID");
	jclass c = env->GetObjectClass(filter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(filter, getPtr);
	long long lptr = (long long) ptr;

	CS::DocumentFilter *nativeFilter = reinterpret_cast<CS::DocumentFilter*>(lptr);

	jclass classResult = env->GetObjectClass(resultCodeObject);

	jobjectArray result;
	jmethodID constructor;
	constructor = env->GetMethodID(cf, "<init>", "(J)V");
	vector<CS::Document::ID> v;
	int resultCode = (int)CS::DocumentManager::getInstance().getDocumentIDs(*nativeFilter, v);
	int size = v.size();
	result = (jobjectArray)env->NewObjectArray(size, cf, NULL);
	for (int i = 0; i < size; i++)
	{
		CS::Document::ID *id = new CS::Document::ID(v[i]);
		jobject element = env->NewObject(cf, constructor, (long long)id);
		env->SetObjectArrayElement(result, i, element);
	}


	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return result;

}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_getDocument
  (JNIEnv *env, jclass, jobject id, jobject resultCodeObject)
{

	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(id);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(id, getPtr);
	long long lptr = (long long) ptr;

	LOGI("CS::Document::ID *nativeID ptr %lli", lptr);
	//CS::Document::ID *nativeID = reinterpret_cast<CS::Document::ID*>(lptr);
	CS::Document::ID *nativeID = (CS::Document::ID*)(lptr);
	LOGI("%s", CS::BaseID::toString(nativeID->data).c_str());



	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");


	jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocument");
	if(cf == NULL)
	{
		LOGI("CF OTSTOY");
	}
	jmethodID constructor;

	constructor = env->GetMethodID(cf, "<init>", "(J)V");
	if(constructor == NULL)
		{
			LOGI("constructor OTSTOY");
		}
	CS::Document::Ptr* doc = new CS::Document::Ptr;
	LOGI("int resultCode = (int)CS::DocumentManager");
	int resultCode = (int)CS::DocumentManager::getInstance().getDocument(*nativeID, *doc);
	LOGI("long long docPtr = (long long)doc");
	long long docPtr = (long long)doc;
	LOGI("jobject result = env->NewObject");
	jobject result = env->NewObject(cf, constructor, (long long)docPtr);
	LOGI("env->CallVoidMethod");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return result;

}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_createDocument
  (JNIEnv *env, jclass, jobject pdf, jint numberOfPages, jobject resultCodeObject)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(pdf);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(pdf, getPtr);
	long long lptr = (long long) ptr;

	CS::PDF* nativePDF = reinterpret_cast<CS::PDF*>(lptr);

	CS::Document::ID* nativeID = new CS::Document::ID();
	long long nativeID_ptr = (long long)nativeID;
	LOGI("CREATE_DOCUMENT_JNI nativeID PTR [%lli]", nativeID_ptr);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	jclass classID = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentID");
	jmethodID constructor;
	constructor = env->GetMethodID(classID, "<init>", "(J)V");
	jobject result = env->NewObject(classID, constructor, nativeID_ptr);
	int resultCode = (int)CS::DocumentManager::getInstance().createDocument(*nativePDF, (uint32_t)numberOfPages, *nativeID);
	//int resultCode = (int)CS::DocumentManager::getInstance().createDocument(cache_pdf, (uint32_t)numberOfPages, cache_id);
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return result;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_cloneDocument
  (JNIEnv *env, jclass, jobject id, jobject resultCodeObject)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(id);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(id, getPtr);
	long long lptr = (long long) ptr;

	CS::Document::ID *nativeID = reinterpret_cast<CS::Document::ID*>(lptr);

	CS::Document::ID *cloneID = new CS::Document::ID;

	int resultCode = (int)CS::DocumentManager::getInstance().cloneDocument(*nativeID, *cloneID);
	jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentID");
	jmethodID constructor;
	constructor = env->GetMethodID(cf, "<init>", "(J)V");
	jobject result = env->NewObject(cf, constructor, (long long)cloneID);


	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);


	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_removeDocument
  (JNIEnv *env, jclass, jobject id, jobject resultCodeObject)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(id);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(id, getPtr);
	long long lptr = (long long) ptr;

	CS::Document::ID *nativeID = reinterpret_cast<CS::Document::ID*>(lptr);

	int resultCode = (int)CS::DocumentManager::getInstance().removeDocument(*nativeID);

	jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);



}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_saveDocument
  (JNIEnv *env, jclass, jobject document, jobject previewProvider, jobject resultCodeObject)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	long long lptr = (long long) ptr;

	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(lptr);

	jclass classResult = env->GetObjectClass(resultCodeObject);
			jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");

	jclass cp = env->GetObjectClass(previewProvider);
	jmethodID getPtrP = env->GetMethodID(cp, "getPtr", "()J");
	jlong ptrp = env->CallLongMethod(previewProvider, getPtrP);
	long long lptrp = (long long) ptrp;

	CS::DocumentPreviewProvider *nativeProvider = reinterpret_cast<CS::DocumentPreviewProvider*>(lptrp);


	int resultCode = (int)CS::DocumentManager::getInstance().saveDocument(nativeDocument, *nativeProvider);


		env->CallVoidMethod(resultCodeObject, setCode, resultCode);



}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_finishSigningDocument
  (JNIEnv *env, jclass, jobject id, jobject resultCodeObject)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(id);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(id, getPtr);
		long long lptr = (long long) ptr;

		CS::Document::ID *nativeID = reinterpret_cast<CS::Document::ID*>(lptr);

		int resultCode = (int)CS::DocumentManager::getInstance().finishSigningDocument(*nativeID);

		jclass classResult = env->GetObjectClass(resultCodeObject);
			jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
			env->CallVoidMethod(resultCodeObject, setCode, resultCode);



}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_requestShareIdForDocument
  (JNIEnv *env, jclass, jobject id, jobject resultCodeObject)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(id);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(id, getPtr);
	long long lptr = (long long) ptr;

	CS::Document::ID *nativeID = reinterpret_cast<CS::Document::ID*>(lptr);
	CS::String shareID;
	int resultCode = (int)CS::DocumentManager::getInstance().requestShareIDForDocument(*nativeID, shareID);

	jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);


	jstring result = env->NewStringUTF((const char*)shareID.c_str());
	return result;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_requestDocumentForShareId
  (JNIEnv *env, jclass, jstring jid, jobject resultCodeObject)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	string shareid = string(env->GetStringUTFChars(jid, 0));
	CS::Document::ID *ID = new CS::Document::ID;
	int resultCode = (int)CS::DocumentManager::getInstance().requestDocumentForShareID(shareid, *ID);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentID");
	jmethodID constructor;
	constructor = env->GetMethodID(cf, "<init>", "(J)V");
	jobject result = env->NewObject(cf, constructor, (long long)ID);

	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_cleanCache
  (JNIEnv *, jclass)
{

	CS::DocumentManager::getInstance().cleanCache();
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_addListener
  (JNIEnv *env, jclass, jobject listener, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(listener);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(listener, getPtr);
	long long lptr = (long long)ptr;
	CS::Listener::Ptr *nativeListener = reinterpret_cast<CS::Listener::Ptr*>(lptr);
	int resultCode = (int)CS::DocumentManager::getInstance().addListener(*nativeListener);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}


JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager_removeListener
  (JNIEnv *env, jclass, jobject listener, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(listener);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(listener, getPtr);
	long long lptr = (long long)ptr;
	CS::Listener::Ptr *nativeListener = reinterpret_cast<CS::Listener::Ptr*>(lptr);
	int resultCode = (int)CS::DocumentManager::getInstance().removeListener(*nativeListener);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}
