/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateProgressEvent.cpp
 *
 *  Created on: 20 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateProgressEvent.h"


#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jfloat JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateProgressEvent_getProgress(
		JNIEnv *env, jobject event)
{
	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::TemplateProgressEvent *nativeEvent = reinterpret_cast<CS::TemplateProgressEvent*>(lptr);

	return nativeEvent->getProgress();
}
