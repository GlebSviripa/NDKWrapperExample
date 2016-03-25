/*
 * com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys.cpp
 *
 *  Created on: 6 мая 2015
 *      Author: gleb
 */

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys_getPublicKey(
		JNIEnv *env, jobject keys)
{
	jclass c = env->GetObjectClass(keys);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(keys, getPtr);
		long long lptr = (long long) ptr;
		CS::User::Keys *nativeKeys = reinterpret_cast<CS::User::Keys*>(lptr);
		string a = nativeKeys->publicKey;
		jstring result = env->NewStringUTF(a.c_str());
		return result;
}
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys_setPublicKey(
		JNIEnv *env, jobject keys, jstring key)
{
	string devKey = string(env->GetStringUTFChars(key, 0));
		jclass c = env->GetObjectClass(keys);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(keys, getPtr);
		long long lptr = (long long) ptr;
		CS::User::Keys *nativeKeys = reinterpret_cast<CS::User::Keys*>(lptr);
		nativeKeys->publicKey = devKey;

}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys_getPrivateKey(
		JNIEnv *env, jobject keys)
{
	jclass c = env->GetObjectClass(keys);
			jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
			jlong ptr = env->CallLongMethod(keys, getPtr);
			long long lptr = (long long) ptr;
			CS::User::Keys *nativeKeys = reinterpret_cast<CS::User::Keys*>(lptr);
			string a = nativeKeys->privateKey;
			jstring result = env->NewStringUTF(a.c_str());
			return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys_setPrivateKey(
		JNIEnv *env, jobject keys, jstring key)
{
	string devKey = string(env->GetStringUTFChars(key, 0));
			jclass c = env->GetObjectClass(keys);
			jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
			jlong ptr = env->CallLongMethod(keys, getPtr);
			long long lptr = (long long) ptr;
			CS::User::Keys *nativeKeys = reinterpret_cast<CS::User::Keys*>(lptr);
			nativeKeys->privateKey = devKey;


}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys_getPrivateKeySalt(
		JNIEnv *env, jobject keys)
{
	jclass c = env->GetObjectClass(keys);
				jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
				jlong ptr = env->CallLongMethod(keys, getPtr);
				long long lptr = (long long) ptr;
				CS::User::Keys *nativeKeys = reinterpret_cast<CS::User::Keys*>(lptr);
				string a = nativeKeys->privateKeySalt;
				jstring result = env->NewStringUTF(a.c_str());
				return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys_setPrivateKeySalt(
		JNIEnv *env, jobject keys, jstring salt)
{
	string devSalt = string(env->GetStringUTFChars(salt, 0));
			jclass c = env->GetObjectClass(keys);
			jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
			jlong ptr = env->CallLongMethod(keys, getPtr);
			long long lptr = (long long) ptr;
			CS::User::Keys *nativeKeys = reinterpret_cast<CS::User::Keys*>(lptr);
			nativeKeys->privateKeySalt = devSalt;

}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys_getPtrJNI(
		JNIEnv *env, jobject)
{
	CS::User::Keys *config = new CS::User::Keys;
		jlong result = (long long) config;
		return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys_destroy(
		JNIEnv *env, jobject keys)
{
	jclass c = env->GetObjectClass(keys);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(keys, getPtr);

	delete reinterpret_cast<CS::User::Keys*>(ptr);
}
