/*
 * com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage.cpp
 *
 *  Created on: 7 мая 2015
 *      Author: gleb
 */

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_init
  (JNIEnv *, jclass)
{
	CS::LegalsStorage::getInstance();
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_destroy
  (JNIEnv *, jclass)
{

}

JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_hasInitials
  (JNIEnv *, jclass)
{
	return CS::LegalsStorage::getInstance().hasInitials();
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_getInitialsPath
  (JNIEnv *env, jclass, jobject resultCodeObject)
{
	CS::String *path = new CS::String;
	int resultCode = (int)CS::LegalsStorage::getInstance().getInitials(*path);
	jstring jpath = env->NewStringUTF((const char *)path->c_str());

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return jpath;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_setInitialsPath
  (JNIEnv *env, jclass, jstring jpath, jstring jpreviewPath, jobject resultCodeObject)
{
	string path = string(env->GetStringUTFChars(jpath, 0));
	string previewPath = string(env->GetStringUTFChars(jpreviewPath, 0));
	int resultCode = (int)CS::LegalsStorage::getInstance().setInitials(path, previewPath);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_getInitialsPreviewPath
  (JNIEnv *env, jclass, jobject resultCodeObject)
{
	CS::String *path = new CS::String;
	int resultCode = (int)CS::LegalsStorage::getInstance().getInitialsPreview(*path);
	jstring jpath = env->NewStringUTF((const char*)path->c_str());

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return jpath;
}


JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_hasSignature
  (JNIEnv *, jclass)
{
	return CS::LegalsStorage::getInstance().hasSignature();
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_getSignaturePath
  (JNIEnv *env, jclass, jobject resultCodeObject)
{
	CS::String *path = new CS::String;
	int resultCode = (int)CS::LegalsStorage::getInstance().getSignature(*path);
	jstring jpath = env->NewStringUTF((const char*)path->c_str());

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return jpath;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_setSignaturePath
  (JNIEnv *env, jclass, jstring jpath, jstring jpreviewPath, jobject resultCodeObject)
{
	string path = string(env->GetStringUTFChars(jpath, 0));
	string previewPath = string(env->GetStringUTFChars(jpreviewPath, 0));
	int resultCode = (int)CS::LegalsStorage::getInstance().setSignature(path, previewPath);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_getSignaturePreviewPath
  (JNIEnv *env, jclass, jobject resultCodeObject)
{
	CS::String *path = new CS::String;
	int resultCode = (int)CS::LegalsStorage::getInstance().getSignaturePreview(*path);
	jstring jpath = env->NewStringUTF((const char*)path->c_str());

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return jpath;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_addListener
  (JNIEnv *env, jclass, jobject listener, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(listener);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(listener, getPtr);
		long long lptr = (long long)ptr;
		CS::Listener::Ptr *nativeListener = reinterpret_cast<CS::Listener::Ptr*>(lptr);
		int resultCode = (int)CS::LegalsStorage::getInstance().addListener(*nativeListener);

		jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_removeListener
  (JNIEnv *env, jclass, jobject listener, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(listener);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(listener, getPtr);
		long long lptr = (long long)ptr;
		CS::Listener::Ptr *nativeListener = reinterpret_cast<CS::Listener::Ptr*>(lptr);
		int resultCode = (int)CS::LegalsStorage::getInstance().removeListener(*nativeListener);

		jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}
