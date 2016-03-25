/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateEvent.cpp
 *
 *  Created on: 20 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateEvent.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateEvent_getTemplateID(
		JNIEnv *env, jobject event)
{
	jclass c = env->GetObjectClass(event);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(event, getPtr);
	long long lptr = (long long) ptr;
	CS::TemplateEvent *nativeEvent = reinterpret_cast<CS::TemplateEvent*>(lptr);


	CS::Template::ID *id = new CS::Template::ID(nativeEvent->getTemplateID());
	jclass cID = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateID");
	jmethodID constructor;
	constructor = env->GetMethodID(cID, "<init>", "(J)V");
	jobject result = env->NewObject(cID, constructor, (long) id);
	return result;

}
