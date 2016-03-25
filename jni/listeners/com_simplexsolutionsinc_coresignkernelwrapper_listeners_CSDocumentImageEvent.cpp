/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentImageEvent.cpp
 *
 *  Created on: 20 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentImageEvent.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentImageEvent_getImagePath(
		JNIEnv *env, jobject event)
{
	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::DocumentImageEvent *nativeEvent = reinterpret_cast<CS::DocumentImageEvent*>(lptr);


	CS::String a = nativeEvent->getImage();
	jstring result = env->NewStringUTF((const char*)a.c_str());
	return result;
}
