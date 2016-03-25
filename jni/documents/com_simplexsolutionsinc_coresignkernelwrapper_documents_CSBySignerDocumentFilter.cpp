/*
 * com_simplexsolutionsinc_coresignkernelwrapper_documents_CSBySignerDocumentFilter.cpp
 *
 *  Created on: 13 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_documents_CSBySignerDocumentFilter.h"


#include <android/log.h>
#include <memory>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSBySignerDocumentFilter_destroy(
		JNIEnv *env, jobject filter)
{
	jclass c = env->GetObjectClass(filter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(filter, getPtr);

	delete reinterpret_cast<CS::BySignerDocumentFilter*>(ptr);
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSBySignerDocumentFilter_init(
		JNIEnv *env, jobject filter, jint type)
{
	CS::BySignerDocumentFilter *nativeFilter = new CS::BySignerDocumentFilter(static_cast<CS::BySignerDocumentFilter::Signer>(type));
	jlong result = (long long) nativeFilter;
	return result;
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSBySignerDocumentFilter_getSignerType(
		JNIEnv *env, jobject filter)
{

	jclass c = env->GetObjectClass(filter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(filter, getPtr);

	CS::BySignerDocumentFilter *nativeFilter = reinterpret_cast<CS::BySignerDocumentFilter*>(ptr);

	return (int)nativeFilter->getSigner();

}
