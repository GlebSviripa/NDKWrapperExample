/*
 * com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentID.cpp
 *
 *  Created on: 22 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentID.h"

#include <android/log.h>
#include <memory>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentID_destroy(
		JNIEnv *env, jobject id)
{
	/*jclass c = env->GetObjectClass(id);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(id, getPtr);

	delete reinterpret_cast<CS::Document::ID*>(ptr);*/
}
