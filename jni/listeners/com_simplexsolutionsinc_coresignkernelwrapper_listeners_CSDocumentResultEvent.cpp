/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentResultEvent.cpp
 *
 *  Created on: 20 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentResultEvent.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentResultEvent_getResult(
		JNIEnv *env, jobject event)
{
	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::DocumentResultEvent *nativeEvent = reinterpret_cast<CS::DocumentResultEvent*>(lptr);

	int  code = (int)nativeEvent->getResult();
	jclass cResult = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/CSResult");
	jmethodID constructorResult;
	constructorResult = env->GetMethodID(cResult, "<init>", "(J)V");
	jobject result = env->NewObject(cResult, constructorResult, (int) code);
	return result;
}
