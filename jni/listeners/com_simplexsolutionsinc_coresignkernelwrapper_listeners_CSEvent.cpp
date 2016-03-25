/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSEvent.cpp
 *
 *  Created on: 19 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSEvent.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSEvent_getPtrJNI(
		JNIEnv *env, jobject event)
{
	return 0;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSEvent_destroy(
		JNIEnv *env, jobject event)
{
	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);

	delete reinterpret_cast<CS::Event*>(ptr);
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSEvent_getEventType
  (JNIEnv *env, jobject event)
{
	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::Event *nativeEvent = reinterpret_cast<CS::Event*>(lptr);
	return (int)nativeEvent->getType();
}

