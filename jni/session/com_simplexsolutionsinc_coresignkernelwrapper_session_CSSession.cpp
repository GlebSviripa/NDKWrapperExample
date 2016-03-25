/*
 * com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession.cpp
 *
 *  Created on: 4 мая 2015
 *      Author: gleb
 */

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession.h"
#include <CoreSignKernel.hpp>
#include <sstream>

using namespace std;


JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_init(
		JNIEnv* pJniEnv, jclass cls)
{
	static JavaCache javaCacheObj(pJniEnv);
	CS::Session::getInstance();

	return;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_destroy(
		JNIEnv *, jclass)
{

}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_getState
  (JNIEnv *, jclass)
{
	CS::Session::State state = CS::Session::getInstance().getState();
	jint result = (int)state;
	return result;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_getCredentials
  (JNIEnv *env, jclass, jobject resultCodeObject)
{

	CS::SessionCredentials *credentials = new CS::SessionCredentials;
	jobject result = NULL;
	int resultCode = (int)CS::Session::getInstance().getCredentials(*credentials);
	if(resultCode == (int)CS::Session::Result::Success)
	{



			jclass c = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/session/CSCredentials");
			if (c == 0) {
				__android_log_print(ANDROID_LOG_VERBOSE, "FIND CLASS", "NULL");
			         }else
			         {
			        	 __android_log_print(ANDROID_LOG_VERBOSE, "FIND CLASS", "YES");
			        	 jmethodID constructor;
			        	 constructor = env->GetMethodID(c, "<init>", "(J)V");
			        	 result = env->NewObject(c, constructor, (long)credentials);
			         }
	}
	else
	{
		delete credentials;
	}

	jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);
	return result;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_getCredentialsProvider
  (JNIEnv *env, jclass)
{
	jobject result = NULL;
	CS::SessionCredentialsProvider *provider = CS::Session::getInstance().getCredentialsProvider();
	jclass c = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/session/CSCredentialsProvider");
	if (c == 0) {
					__android_log_print(ANDROID_LOG_VERBOSE, "FIND CLASS", "NULL");
				         }else
				         {
				        	 __android_log_print(ANDROID_LOG_VERBOSE, "FIND CLASS", "YES");
				        	 jmethodID constructor;
				        	 constructor = env->GetMethodID(c, "<init>", "(J)V");
				        	 result = env->NewObject(c, constructor, (long long)provider);
				         }
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_setCredentialsProvider
  (JNIEnv *env, jclass, jobject provider)
{
	jclass c = env->GetObjectClass(provider);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(provider, getPtr);
	long long lptr = (long long)ptr;
	CS::SessionCredentialsProvider *nativeProvider = reinterpret_cast<CS::SessionCredentialsProvider*>(lptr);
	CS::Session::getInstance().setCredentialsProvider(nativeProvider);

	//TODO: integrate provider
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_getConfig
  (JNIEnv *env, jclass)
{
	jobject result = NULL;
	CS::Session::Config *config = new CS::Session::Config;
	*config = CS::Session::getInstance().getConfig();

	jclass c = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/session/CSSessionConfig");
	if (c == 0) {
						__android_log_print(ANDROID_LOG_VERBOSE, "FIND CLASS", "NULL");
					         }else
					         {
					        	 __android_log_print(ANDROID_LOG_VERBOSE, "FIND CLASS", "YES");
					        	 jmethodID constructor;
					        	 constructor = env->GetMethodID(c, "<init>", "(J)V");
					        	 result = env->NewObject(c, constructor, (long long)config);
					         }
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_setConfig
  (JNIEnv *env, jclass, jobject config)
{
	jclass c = env->GetObjectClass(config);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(config, getPtr);
	long long lptr = (long long)ptr;
	CS::Session::Config *nativeConfig = reinterpret_cast<CS::Session::Config*>(lptr);
	CS::Session::getInstance().setConfig(*nativeConfig);
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_getCurrentUserId
  (JNIEnv *env, jclass)
{
	long long int userID;
	int resultCode = (int)CS::Session::getInstance().getCurrentUserID(userID);
	jlong result = userID;
	return result;
}

JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_hasCriticalTasks
  (JNIEnv *, jclass)
{
	jboolean result = CS::Session::getInstance().hasCriticalTasks();
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_login
  (JNIEnv *env, jclass, jobject user, jstring password, jobject resultCodeObject)
{

	jclass c = env->GetObjectClass(user);
			jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
			jlong ptr = env->CallLongMethod(user, getPtr);
			long long lptr = (long long) ptr;

			CS::User *nativeUser = reinterpret_cast<CS::User*>(lptr);
	string devPassword = string(env->GetStringUTFChars(password, 0));

	int resultCode = (int)CS::Session::getInstance().logIn(*nativeUser, devPassword);
	jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);

}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_logout
  (JNIEnv *env, jclass, jobject resultCodeObject)
{
	int resultCode = (int)CS::Session::getInstance().logOut();
	jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_startSync
  (JNIEnv *env, jclass, jobject resultCodeObject)
{
	int resultCode = (int)CS::Session::getInstance().startSync();
	jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_stopSync
  (JNIEnv *env, jclass, jobject resultCodeObject)
{
	int resultCode = (int)CS::Session::getInstance().stopSync();
	jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_suspend
  (JNIEnv *, jclass)
{
	CS::Session::getInstance().suspend();
}
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_resume
  (JNIEnv *, jclass)
{
	CS::Session::getInstance().resume();
}


JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_addListener
  (JNIEnv *env, jclass, jobject listener, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(listener);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(listener, getPtr);
	long long lptr = (long long)ptr;
	CS::Listener::Ptr *nativeListener = reinterpret_cast<CS::Listener::Ptr*>(lptr);
	int resultCode = (int)CS::Session::getInstance().addListener(*nativeListener);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}


JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession_removeListener
  (JNIEnv *env, jclass, jobject listener, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(listener);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(listener, getPtr);
	long long lptr = (long long)ptr;
	CS::Listener::Ptr *nativeListener = reinterpret_cast<CS::Listener::Ptr*>(lptr);
	int resultCode = (int)CS::Session::getInstance().removeListener(*nativeListener);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}
