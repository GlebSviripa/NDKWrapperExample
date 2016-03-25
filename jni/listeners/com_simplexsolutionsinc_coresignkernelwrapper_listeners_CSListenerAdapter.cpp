/*
 * com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSListenerAdapter.cpp
 *
 *  Created on: 18 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSListenerAdapter.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

#include <Listener.hpp>
#include "CSListenerImpl.h"

using namespace std;

CS::Listener::EventTypes CSListenerImpl::getEventTypes() const noexcept
{

	JNIEnv* env = JavaCache::getJNIEnv();

	jclass csListenerAdapterClass = env->GetObjectClass(jCSListener);
	LOGI("csListenerAdapterGetEventTypes start");
	jmethodID csListenerAdapterGetEventTypes = env->GetMethodID(
			csListenerAdapterClass, "getEventTypes", "()[I");

	jintArray array = (jintArray) env->CallObjectMethod(jCSListener,
			csListenerAdapterGetEventTypes);

	int *s = env->GetIntArrayElements(array, 0);

	vector<CS::Event::Type> result;
	int size = env->GetArrayLength(array);
	for (int i = 0; i < size; i++) {
		CS::Event::Type element = (CS::Event::Type) s[i];
		result.push_back(element);
	}
	LOGI("csListenerAdapterGetEventTypes finish");

	return result;

}

void CSListenerImpl::handleEvent(const CS::Event& inEvent) noexcept
{
	int type = inEvent.getType();
	JNIEnv* env = JavaCache::getJNIEnv();
	jclass csEventClass;
	if(type >= 64 && type <= 75)
	{
		csEventClass = eventDocumentClass;
	}
	else
	{
		csEventClass = eventClass;
	}

	jmethodID csEventConstructor = env->GetMethodID(csEventClass, "<init>","(J)V");
	jclass csListenerAdapterClass = env->GetObjectClass(jCSListener);
	jmethodID csListenerHandleEvent = listenerHandleEvent;
	jobject jCSEvent = env->NewObject(csEventClass, csEventConstructor,(long long) &inEvent);
	env->CallVoidMethod(jCSListener, csListenerHandleEvent, jCSEvent);
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSListenerAdapter_getPtrJNI(
		JNIEnv *env, jobject jCSListener) {
	jobject jCSListenerImplRef = env->NewGlobalRef(jCSListener);
	CSListenerImpl::Ptr *listener = new CSListenerImpl::Ptr(
			new CSListenerImpl(jCSListenerImplRef));

	jlong result = (long long) listener;
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSListenerAdapter_destroy(
		JNIEnv *env, jobject listener) {
	jclass c = env->GetObjectClass(listener);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(listener, getPtr);
	delete reinterpret_cast<CSListenerImpl::Ptr*>(ptr);
}
