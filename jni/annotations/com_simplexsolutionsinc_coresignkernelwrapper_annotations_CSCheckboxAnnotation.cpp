/*
 * com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSCheckboxAnnotation.cpp
 *
 *  Created on: 15 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSCheckboxAnnotation.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSCheckboxAnnotation_getState(
		JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	long long lptr = (long long)ptr;
	std::shared_ptr<CS::CheckboxAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::CheckboxAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));
	return (int)nativeAnnotation->getState();
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSCheckboxAnnotation_setState(
		JNIEnv *env, jobject annotation, jint state)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	long long lptr = (long long)ptr;
	std::shared_ptr<CS::CheckboxAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::CheckboxAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));
	nativeAnnotation->setState((CS::CheckboxAnnotation::State)state);
}
