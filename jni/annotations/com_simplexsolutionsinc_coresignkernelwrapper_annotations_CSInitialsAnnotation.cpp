/*
 * com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSInitialsAnnotation.cpp
 *
 *  Created on: 15 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSInitialsAnnotation.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSInitialsAnnotation_getInitialsPath(
		JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	long long lptr = (long long)ptr;
	std::shared_ptr<CS::InitialsAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::InitialsAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));


	CS::String path = nativeAnnotation->getInitials();
	jstring result = env->NewStringUTF((const char*)path.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSInitialsAnnotation_setInitialsPath(
		JNIEnv *env, jobject annotation, jstring jpath)
{

	string path = string(env->GetStringUTFChars(jpath, 0));

	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	long long lptr = (long long)ptr;
	std::shared_ptr<CS::InitialsAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::InitialsAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));

	nativeAnnotation->setInitials(path);
}
