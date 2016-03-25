/*
 * com_simplexsolutionsinc_coresignkernelwrapper_session_CSUser.cpp
 *
 *  Created on: 29 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_session_CSUser.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include <Users/User.hpp>

using namespace std;

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUser_getUserID(
		JNIEnv *env, jobject user)
{
	jclass c = env->GetObjectClass(user);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(user, getPtr);
	CS::User *nativeUser = reinterpret_cast<CS::User*>(ptr);
	return (jlong)nativeUser->id;

}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUser_setUserID(
		JNIEnv *env, jobject user, jlong id)
{
	jclass c = env->GetObjectClass(user);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(user, getPtr);
	CS::User *nativeUser = reinterpret_cast<CS::User*>(ptr);
	nativeUser->id = (CS::User::ID)id;


}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUser_getKeys(
		JNIEnv *env, jobject user)
{
	jclass c = env->GetObjectClass(user);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(user, getPtr);
	CS::User *nativeUser = reinterpret_cast<CS::User*>(ptr);

	CS::User::Keys *keys = new CS::User::Keys(nativeUser->keys);
	jclass cID = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/session/CSUserKeys");
	jmethodID constructor;
	constructor = env->GetMethodID(cID, "<init>", "(J)V");
	jobject result = env->NewObject(cID, constructor, (long long) keys);
	return result;


}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUser_setKeys(
		JNIEnv *env, jobject user, jobject keys)
{
	jclass c = env->GetObjectClass(user);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(user, getPtr);
	CS::User *nativeUser = reinterpret_cast<CS::User*>(ptr);

	jclass ck = env->GetObjectClass(keys);
	jmethodID getPtrk = env->GetMethodID(ck, "getPtr", "()J");
	jlong ptrk = env->CallLongMethod(keys, getPtrk);
	CS::User::Keys *nativeKeys = reinterpret_cast<CS::User::Keys*>(ptrk);
	nativeUser->keys = *nativeKeys;
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUser_getPtrJNI(
		JNIEnv *, jobject)
{
	CS::User *user = new CS::User;
	jlong result = (long long) user;
	return result;
}
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSUser_destroy(
		JNIEnv *env, jobject user)
{
	jclass c = env->GetObjectClass(user);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(user, getPtr);
	CS::User *nativeUser = reinterpret_cast<CS::User*>(ptr);
	delete nativeUser;
}
