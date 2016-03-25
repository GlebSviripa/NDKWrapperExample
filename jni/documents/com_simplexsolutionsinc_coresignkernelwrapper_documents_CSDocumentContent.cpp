/*
 * com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentContent.cpp
 *
 *  Created on: 11 мая 2015
 *      Author: gleb
 */


#include "com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentContent.h"
#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
using namespace std;
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentContent_getPtrJNI
  (JNIEnv *, jobject)
{
		return 0;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentContent_destroy
  (JNIEnv *env, jobject content)
{
	jclass c = env->GetObjectClass(content);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(content, getPtr);
	delete reinterpret_cast<CS::DocumentContent::Ptr*>(ptr);
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentContent_getPDF(
		JNIEnv *env, jobject content)
{

	jclass c = env->GetObjectClass(content);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(content, getPtr);
	CS::DocumentContent::Ptr nativeContent = *reinterpret_cast<CS::DocumentContent::Ptr*>(ptr);

	CS::PDF *pdf = new CS::PDF(nativeContent->getPDF());
	jclass cP = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSPDF");
	jmethodID constructor;
	constructor = env->GetMethodID(cP, "<init>", "(J)V");
	jobject result = env->NewObject(cP, constructor, (long long) pdf);
	return result;
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentContent_getNumberOfPages
  (JNIEnv *env, jobject content)
{
	jclass c = env->GetObjectClass(content);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(content, getPtr);
	CS::DocumentContent::Ptr nativeContent = *reinterpret_cast<CS::DocumentContent::Ptr*>(ptr);

	return nativeContent->getNumberOfPages();
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentContent_getAnnotationStore
  (JNIEnv *env, jobject content)
{
	jclass c = env->GetObjectClass(content);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(content, getPtr);
	CS::DocumentContent::Ptr nativeContent = *reinterpret_cast<CS::DocumentContent::Ptr*>(ptr);

	CS::AnnotationStore::Ptr *store = new CS::AnnotationStore::Ptr();
	*store = nativeContent->annotationStore();


	jclass cI = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSAnnotationStore");
	jmethodID constructor;
	constructor = env->GetMethodID(cI, "<init>", "(J)V");
	jobject result = env->NewObject(cI, constructor, (long long) store);
	return result;
}
