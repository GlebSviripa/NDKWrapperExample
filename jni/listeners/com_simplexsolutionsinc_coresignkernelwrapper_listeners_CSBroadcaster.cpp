/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSBroadcaster.cpp
 *
 *  Created on: 11 марта 2016
 *      Author: gleb
 */

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSBroadcaster.h"
#include <CoreSignKernel.hpp>
#include <ProtoEventer.h>

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSBroadcaster_addListener(
		JNIEnv *env, jclass, jobject listener, jobject resultCodeObject) {
	jclass c = env->GetObjectClass(listener);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(listener, getPtr);
	long long lptr = (long long) ptr;
	CS::Listener::Ptr *nativeListener =
			reinterpret_cast<CS::Listener::Ptr*>(lptr);
	int resultCode = (int) ProtoEventer::getInstance().addListener(
			*nativeListener);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSBroadcaster_removeListener(
		JNIEnv *env, jclass, jobject listener, jobject resultCodeObject) {
	jclass c = env->GetObjectClass(listener);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(listener, getPtr);
	long long lptr = (long long) ptr;
	CS::Listener::Ptr *nativeListener =
			reinterpret_cast<CS::Listener::Ptr*>(lptr);
	int resultCode = (int) ProtoEventer::getInstance().removeListener(
			*nativeListener);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}
