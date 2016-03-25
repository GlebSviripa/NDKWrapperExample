/*
 * com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig.cpp
 *
 *  Created on: 5 мая 2015
 *      Author: gleb
 */

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_getDeviceCode
  (JNIEnv *env, jobject config)
{
		jclass c = env->GetObjectClass(config);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(config, getPtr);
		long long lptr = (long long)ptr;
		CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
		string a = nativeConfig->deviceCode;
		jstring result = env->NewStringUTF(a.c_str());
		return result;
}
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_setDeviceCode
  (JNIEnv *env, jobject config , jstring code )
{
	string devCode = string(env->GetStringUTFChars(code, 0));
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long)ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	nativeConfig->deviceCode = devCode;
}
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_getDeviceName
  (JNIEnv *env, jobject config)
{
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long)ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	string a = nativeConfig->deviceName;
	jstring result = env->NewStringUTF(a.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_setDeviceName
  (JNIEnv *env, jobject config, jstring name)
{
	string devName = string(env->GetStringUTFChars(name, 0));
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long)ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	nativeConfig->deviceName = devName;

}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_getTempStoragePath
  (JNIEnv *env, jobject config)
{
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long) ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	string a = nativeConfig->tempStoragePath;
	jstring result = env->NewStringUTF(a.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_setTempStoragePath
  (JNIEnv *env, jobject config, jstring path)
{
	string tempPath = string(env->GetStringUTFChars(path, 0));
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long) ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	nativeConfig->tempStoragePath = tempPath;
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_getPermanentStoragePath
  (JNIEnv *env, jobject config)
{
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long) ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	string a = nativeConfig->permanentStoragePath;
	jstring result = env->NewStringUTF(a.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_setPermanentStoragePath
  (JNIEnv *env, jobject config, jstring path)
{
	string permanentPath = string(env->GetStringUTFChars(path, 0));
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long) ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	nativeConfig->permanentStoragePath = permanentPath;
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_getBundlePath
  (JNIEnv *env, jobject config)
{
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long) ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	string a = nativeConfig->bundlePath;
	jstring result = env->NewStringUTF(a.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_setBundlePath
  (JNIEnv *env, jobject config, jstring path)
{
	string permanentPath = string(env->GetStringUTFChars(path, 0));
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long) ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	nativeConfig->bundlePath = permanentPath + "/cacert.pem";
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_getCSSessionConfigJNI
  (JNIEnv *, jobject)
{
	CS::Session::Config *config = new CS::Session::Config;
	jlong result = (long long)config;
	return result;
}



JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig_destroy
  (JNIEnv *env, jobject object)
{
	jclass c = env->GetObjectClass(object);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(object, getPtr);
	delete reinterpret_cast<CS::Session::Config*>(ptr);
}

