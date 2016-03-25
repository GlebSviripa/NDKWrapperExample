/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_DocumentAnnotationEvent.cpp
 *
 *  Created on: 20 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentAnnotationEvent.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentAnnotationEvent_getAnnotationID(
		JNIEnv *env, jobject event)
{
	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::DocumentAnnotationEvent *nativeEvent = reinterpret_cast<CS::DocumentAnnotationEvent*>(lptr);

	CS::Annotation::ID *id = new CS::Annotation::ID(nativeEvent->getAnnotationID());
	jclass cI = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSAnnotationID");
	jmethodID constructor;
	constructor = env->GetMethodID(cI, "<init>", "(J)V");
	jobject result = env->NewObject(cI, constructor, (long) id);
	return result;
}
