/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentParticipantEvent.cpp
 *
 *  Created on: 20 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentParticipantEvent.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentParticipantEvent_getParticipantID(
		JNIEnv *env, jobject event)
{
	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::DocumentParticipantEvent *nativeEvent = reinterpret_cast<CS::DocumentParticipantEvent*>(lptr);

	return nativeEvent->getParticipantID();
}
