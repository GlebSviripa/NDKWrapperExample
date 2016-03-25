/*
 * com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials.cpp
 *
 *  Created on: 6 мая 2015
 *      Author: gleb
 */

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_getRpcSession(
		JNIEnv *env, jobject credentials)
{
	jclass c = env->GetObjectClass(credentials);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(credentials, getPtr);
	long long lptr = (long long) ptr;
	CS::SessionCredentials *nativeCredentials = reinterpret_cast<CS::SessionCredentials*>(lptr);
	string a = nativeCredentials->rpcSession;
	jstring result = env->NewStringUTF(a.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_setRpcSession(
		JNIEnv *env, jobject credentials, jstring session)
{
	string rpcSession = string(env->GetStringUTFChars(session, 0));
	jclass c = env->GetObjectClass(credentials);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(credentials, getPtr);
	long long lptr = (long long) ptr;
	CS::SessionCredentials *nativeCredentials = reinterpret_cast<CS::SessionCredentials*>(lptr);
	nativeCredentials->rpcSession = rpcSession;
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_getEventSession(
		JNIEnv *env, jobject credentials)
{
	jclass c = env->GetObjectClass(credentials);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(credentials, getPtr);
	long long lptr = (long long) ptr;
	CS::SessionCredentials *nativeCredentials = reinterpret_cast<CS::SessionCredentials*>(lptr);
	string a = nativeCredentials->eventSession;
	jstring result = env->NewStringUTF(a.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_setEventSession(
		JNIEnv *env, jobject credentials, jstring session)
{
	string eventSession = string(env->GetStringUTFChars(session, 0));
	jclass c = env->GetObjectClass(credentials);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(credentials, getPtr);
	long long lptr = (long long) ptr;
	CS::SessionCredentials *nativeCredentials = reinterpret_cast<CS::SessionCredentials*>(lptr);
	nativeCredentials->eventSession = eventSession;
}

JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_getRpcServers(
		JNIEnv *env, jobject credentials)
{

	jclass c = env->GetObjectClass(credentials);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(credentials, getPtr);
	long long lptr = (long long) ptr;
	CS::SessionCredentials *nativeCredentials = reinterpret_cast<CS::SessionCredentials*>(lptr);

	jobjectArray result;
	jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/session/CSServer");
	jmethodID constructor;
	constructor = env->GetMethodID(cf, "<init>", "(J)V");
	int size = nativeCredentials->rpcServers.size();

	result = (jobjectArray)env->NewObjectArray(size, cf, NULL);
	for (int i = 0; i < size; i++)
	{
		CS::SessionCredentials::Server *server = new CS::SessionCredentials::Server(nativeCredentials->rpcServers[i]);
		jobject element = env->NewObject(cf, constructor, (long long)server);
		env->SetObjectArrayElement(result, i, element);
	}
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_setRpcServers(
		JNIEnv *env, jobject credentials, jobjectArray array)
{
	jclass c = env->GetObjectClass(credentials);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(credentials, getPtr);
	long long lptr = (long long) ptr;
	CS::SessionCredentials *nativeCredentials = reinterpret_cast<CS::SessionCredentials*>(lptr);

	int size = env->GetArrayLength(array);
	for (int i = 0; i < size; i++)
	{
		jobject o = env->GetObjectArrayElement(array, i);
		jclass cf = env->GetObjectClass(o);

		jmethodID getPtr = env->GetMethodID(cf, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(o, getPtr);
		long long lptr = (long long)ptr;
		CS::SessionCredentials::Server *server = reinterpret_cast<CS::SessionCredentials::Server*>(lptr);

		nativeCredentials->rpcServers.push_back(*server);
	}
}

JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_getEventServers(
		JNIEnv *env, jobject credentials)
{
	jclass c = env->GetObjectClass(credentials);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(credentials, getPtr);
		long long lptr = (long long) ptr;
		CS::SessionCredentials *nativeCredentials = reinterpret_cast<CS::SessionCredentials*>(lptr);

		jobjectArray result;
		jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/session/CSServer");
		jmethodID constructor;
		constructor = env->GetMethodID(cf, "<init>", "(J)V");
		int size = nativeCredentials->eventServers.size();

		result = (jobjectArray)env->NewObjectArray(size, cf, NULL);
		for (int i = 0; i < size; i++)
		{
			CS::SessionCredentials::Server *server = new CS::SessionCredentials::Server(nativeCredentials->eventServers[i]);
			jobject element = env->NewObject(cf, constructor, (long long)server);
			env->SetObjectArrayElement(result, i, element);
		}
		return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_setEventServers(
		JNIEnv *env, jobject credentials, jobjectArray array)
{
	jclass c = env->GetObjectClass(credentials);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(credentials, getPtr);
		long long lptr = (long long) ptr;
		CS::SessionCredentials *nativeCredentials = reinterpret_cast<CS::SessionCredentials*>(lptr);

		int size = env->GetArrayLength(array);
		for (int i = 0; i < size; i++)
		{
			jobject o = env->GetObjectArrayElement(array, i);
			jclass cf = env->GetObjectClass(o);

			jmethodID getPtr = env->GetMethodID(cf, "getPtr", "()J");
			jlong ptr = env->CallLongMethod(o, getPtr);
			long long lptr = (long long)ptr;
			CS::SessionCredentials::Server *server = reinterpret_cast<CS::SessionCredentials::Server*>(lptr);

			nativeCredentials->eventServers.push_back(*server);
		}
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_getCSCredentialsJNI(
		JNIEnv *, jobject)
{
	CS::SessionCredentials *credentials = new CS::SessionCredentials;
	jlong result = (long long)credentials;
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials_destroy(
		JNIEnv *env, jobject credentials)
{
	jclass c = env->GetObjectClass(credentials);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(credentials, getPtr);

	delete reinterpret_cast<CS::SessionCredentials*>(ptr);
}
