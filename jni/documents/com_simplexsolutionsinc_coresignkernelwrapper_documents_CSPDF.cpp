/*
 * com_simplexsolutionsinc_coresignkernelwrapper_documents_CSPDF.cpp
 *
 *  Created on: 11 мая 2015
 *      Author: gleb
 */

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_documents_CSPDF.h"
using namespace std;
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSPDF_getPtrJNI(
		JNIEnv *, jobject)
{
	CS::PDF *pdf = new CS::PDF;
	jlong result = (long long) pdf;
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSPDF_destroy(
		JNIEnv *env, jobject pdf)
{
	jclass c = env->GetObjectClass(pdf);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(pdf, getPtr);

	delete reinterpret_cast<CS::PDF*>(ptr);
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSPDF_getPassword(
		JNIEnv *env, jobject pdf)
{
		jclass c = env->GetObjectClass(pdf);
			jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
			jlong ptr = env->CallLongMethod(pdf, getPtr);
			long long lptr = (long long)ptr;
			CS::PDF *nativePDF = reinterpret_cast<CS::PDF*>(lptr);
			string a = nativePDF->password;
			jstring result = env->NewStringUTF(a.c_str());
			return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSPDF_setPassword(
		JNIEnv *env, jobject PDF, jstring jpassword)
{
	string password = string(env->GetStringUTFChars(jpassword, 0));
			jclass c = env->GetObjectClass(PDF);
			jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
			jlong ptr = env->CallLongMethod(PDF, getPtr);
			long long lptr = (long long)ptr;
			CS::PDF *nativePDF = reinterpret_cast<CS::PDF*>(lptr);
			nativePDF->password = password;
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSPDF_getPath(
		JNIEnv *env, jobject pdf)
{
	jclass c = env->GetObjectClass(pdf);
				jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
				jlong ptr = env->CallLongMethod(pdf, getPtr);
				long long lptr = (long long)ptr;
				CS::PDF *nativePDF = reinterpret_cast<CS::PDF*>(lptr);
				string a = nativePDF->filePath;
				jstring result = env->NewStringUTF(a.c_str());
				return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSPDF_setPath(
		JNIEnv *env, jobject PDF, jstring jpath)
{
	string path = string(env->GetStringUTFChars(jpath, 0));
			jclass c = env->GetObjectClass(PDF);
			jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
			jlong ptr = env->CallLongMethod(PDF, getPtr);
			long long lptr = (long long)ptr;
			CS::PDF *nativePDF = reinterpret_cast<CS::PDF*>(lptr);
			nativePDF->filePath = path;
}
