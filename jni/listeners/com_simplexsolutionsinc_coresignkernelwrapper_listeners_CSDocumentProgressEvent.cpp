/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentProgressEvent.cpp
 *
 *  Created on: 20 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentProgressEvent.h"


#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jfloat JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentProgressEvent_getProgress(
		JNIEnv *env, jobject event)
{
	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::DocumentProgressEvent *nativeEvent = reinterpret_cast<CS::DocumentProgressEvent*>(lptr);

	return nativeEvent->getProgress();
}
