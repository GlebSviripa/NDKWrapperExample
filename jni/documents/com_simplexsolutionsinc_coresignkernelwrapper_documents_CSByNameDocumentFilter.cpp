/*
 * com_simplexsolutionsinc_coresignkernelwrapper_documents_CSByNameDocumentFilter.cpp
 *
 *  Created on: 13 мая 2015
 *      Author: gleb
 */

#include <android/log.h>
#include <memory>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_documents_CSByNameDocumentFilter.h"

using namespace std;

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSByNameDocumentFilter_destroy(
		JNIEnv *env, jobject filter)
{
	jclass c = env->GetObjectClass(filter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(filter, getPtr);

	delete reinterpret_cast<CS::DocumentFilter*>(ptr);
}


JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSByNameDocumentFilter_init(
		JNIEnv *env, jobject filter, jstring jname)
{
	string name = string(env->GetStringUTFChars(jname, 0));

	CS::ByNameDocumentFilter *nativeFilter = new CS::ByNameDocumentFilter(name);

	jlong result = (long long) nativeFilter;
	return result;
}


JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSByNameDocumentFilter_getDocumentName(
		JNIEnv *env, jobject filter)
{
	jclass c = env->GetObjectClass(filter);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(filter, getPtr);
		long long lptr = (long long) ptr;

		CS::ByNameDocumentFilter *nativeFilter = reinterpret_cast<CS::ByNameDocumentFilter*>(lptr);


		CS::String name =nativeFilter->getDocumentName();
		jstring result = env->NewStringUTF((const char*)name.c_str());
		return result;
}
