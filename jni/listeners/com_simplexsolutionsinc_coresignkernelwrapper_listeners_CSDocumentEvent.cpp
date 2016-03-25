/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentEvent.cpp
 *
 *  Created on: 20 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentEvent.h"
#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentEvent_getDocumentID(
		JNIEnv *env, jobject event)
{
	LOGI("jclass c = env->GetObjectClass(event)");
	jclass c = env->GetObjectClass(event);
	LOGI("jmethodID getPtr = env->GetMethodID(c, ");
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	LOGI("jlong ptr = env->CallLongMethod(event, getPtr);");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::DocumentEvent *nativeEvent = reinterpret_cast<CS::DocumentEvent*>(lptr);

	CS::Document::ID *id = new CS::Document::ID(nativeEvent->getDocumentID());
	LOGI("jclass cID = env->FindClass");
	jclass cID = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentID");
	if(cID == NULL)
	{
		LOGI("OTSTOY");
	}
	jmethodID constructor;
	LOGI("constructor = env->GetMethodID");
	constructor = env->GetMethodID(cID, "<init>", "(J)V");
	LOGI("jobject result = env->NewObject");
	jobject result = env->NewObject(cID, constructor, (long long) id);
	return result;
}
