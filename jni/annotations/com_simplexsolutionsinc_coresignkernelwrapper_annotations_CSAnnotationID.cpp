/*
 * com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationID.cpp
 *
 *  Created on: 11 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationID.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationID_destroy(
		JNIEnv *env, jobject id)
{
	jclass c = env->GetObjectClass(id);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(id, getPtr);

	delete reinterpret_cast<CS::Annotation::ID*>(ptr);
}
