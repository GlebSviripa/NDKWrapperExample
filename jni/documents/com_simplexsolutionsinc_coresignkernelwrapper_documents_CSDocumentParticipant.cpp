/*
 * com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant.cpp
 *
 *  Created on: 8 мая 2015
 *      Author: gleb
 */
#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant.h"

using namespace std;

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_getPtrJNI(
		JNIEnv *, jobject)
{
	CS::DocumentParticipant *participant = new CS::DocumentParticipant;
		jlong result = (long long) participant;
		return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_destroy(
		JNIEnv *env, jobject participant)
{
	jclass c = env->GetObjectClass(participant);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(participant, getPtr);

	delete reinterpret_cast<CS::DocumentParticipant*>(ptr);
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_getId(
		JNIEnv *env, jobject participant)
{
	jclass c = env->GetObjectClass(participant);
					jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
					jlong ptr = env->CallLongMethod(participant, getPtr);
					long long lptr = (long long)ptr;
					CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(lptr);
					return nativeParticipant->userID;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_setId(
		JNIEnv *env, jobject participant, jlong id)
{
	jclass c = env->GetObjectClass(participant);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(participant, getPtr);
	CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(ptr);
	nativeParticipant->userID = (long long)id;
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_getStatus(
		JNIEnv *env, jobject participant)
{
	jclass c = env->GetObjectClass(participant);
						jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
						jlong ptr = env->CallLongMethod(participant, getPtr);
						long long lptr = (long long)ptr;
						CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(lptr);
						return (int)nativeParticipant->status;
}


JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_setStatus
 (JNIEnv *env, jobject participant, jint status)
{
	jclass c = env->GetObjectClass(participant);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(participant, getPtr);
	CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(ptr);
	nativeParticipant->status = (CS::DocumentParticipant::Status)status;
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_getRole(
		JNIEnv *env, jobject participant)
{
	jclass c = env->GetObjectClass(participant);
							jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
							jlong ptr = env->CallLongMethod(participant, getPtr);
							long long lptr = (long long)ptr;
							CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(lptr);
							return (int)nativeParticipant->role;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_setRole
  (JNIEnv *env, jobject participant, jint role)
{
	jclass c = env->GetObjectClass(participant);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(participant, getPtr);
	CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(ptr);
	nativeParticipant->role = (CS::DocumentParticipant::Role)role;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_getColor(
		JNIEnv *env, jobject participant)
{
	jclass c = env->GetObjectClass(participant);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(participant, getPtr);
	long long lptr = (long long)ptr;
	CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(lptr);
	CS::Color color = nativeParticipant->color;
	jclass cColor = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/CSColor");
	jmethodID constructor;
	constructor = env->GetMethodID(cColor, "<init>", "(IIII)V");
	jobject result = env->NewObject(cColor, constructor, color.alpha, color.red, color.green, color.blue);
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant_setColor
  (JNIEnv *env, jobject participant, jint a, jint r, jint g, jint b)
{
	CS::Color color;
	color.alpha = (CS::Byte)a;
	color.red = (CS::Byte)r;
	color.green = (CS::Byte)g;
	color.blue = (CS::Byte)b;

	jclass c = env->GetObjectClass(participant);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(participant, getPtr);
	CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(ptr);

	nativeParticipant->color = color;


}
