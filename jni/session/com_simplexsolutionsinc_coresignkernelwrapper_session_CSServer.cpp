/*
 * com_simplexsolutionsinc_coresignkernelwrapper_session_CSServer.cpp
 *
 *  Created on: 6 мая 2015
 *      Author: gleb
 */
#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "com_simplexsolutionsinc_coresignkernelwrapper_session_CSServer.h"
#include <CoreSignKernel.hpp>

using namespace std;
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSServer_getAddress
  (JNIEnv *env, jobject server )
{
	jclass c = env->GetObjectClass(server);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(server, getPtr);
	long long lptr = (long long) ptr;
	CS::SessionCredentials::Server *nativeServer = reinterpret_cast<CS::SessionCredentials::Server*>(lptr);
	string a = nativeServer->address;
	jstring result = env->NewStringUTF(a.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSServer_setAddress
  (JNIEnv *env, jobject server, jstring address)
{
	string devAddres = string(env->GetStringUTFChars(address, 0));
	jclass c = env->GetObjectClass(server);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(server, getPtr);
	long long lptr = (long long) ptr;
	CS::SessionCredentials::Server *nativeServer = reinterpret_cast<CS::SessionCredentials::Server*>(lptr);
	nativeServer->address = devAddres;
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSServer_getPort
  (JNIEnv *env, jobject server)
{
	jclass c = env->GetObjectClass(server);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(server, getPtr);
	long long lptr = (long long) ptr;
	CS::SessionCredentials::Server *nativeServer = reinterpret_cast<CS::SessionCredentials::Server*>(lptr);
	jint result = nativeServer->port;
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSServer_setPort
  (JNIEnv *env, jobject server, jint port)
{
		int devPort = (int)port;
		jclass c = env->GetObjectClass(server);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(server, getPtr);
		long long lptr = (long long) ptr;
		CS::SessionCredentials::Server *nativeServer = reinterpret_cast<CS::SessionCredentials::Server*>(lptr);
		nativeServer->port = devPort;
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSServer_getPtrJNI
  (JNIEnv *, jobject)
{
	CS::SessionCredentials::Server *config = new CS::SessionCredentials::Server;
	jlong result = (long long) config;
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSServer_destroy
  (JNIEnv *env, jobject server)
{
	jclass c = env->GetObjectClass(server);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(server, getPtr);

	delete reinterpret_cast<CS::SessionCredentials::Server*>(ptr);
}
