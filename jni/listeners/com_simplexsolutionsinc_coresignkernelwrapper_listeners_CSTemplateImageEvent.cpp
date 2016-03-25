/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateImageEvent.cpp
 *
 *  Created on: 20 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateImageEvent.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateImageEvent_getImagePath(
		JNIEnv *env, jobject event)
{

	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::TemplateImageEvent *nativeEvent = reinterpret_cast<CS::TemplateImageEvent*>(lptr);


	CS::String a = nativeEvent->getImage();
		jstring result = env->NewStringUTF((const char*)a.c_str());
		return result;
}
