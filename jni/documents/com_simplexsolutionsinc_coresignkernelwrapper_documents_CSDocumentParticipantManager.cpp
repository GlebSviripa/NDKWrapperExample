/*
 * com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager.cpp
 *
 *  Created on: 8 мая 2015
 *      Author: gleb
 */
#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager.h"

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getPtrJNI(
		JNIEnv *, jobject)
{
	return 0;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_destroy(
		JNIEnv *env, jobject manager)
{
	jclass c = env->GetObjectClass(manager);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(manager, getPtr);
	delete reinterpret_cast<CS::DocumentParticipantManager::Ptr*>(ptr);
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getParticipantCount(
		JNIEnv *env, jobject manager)
{
	jclass c = env->GetObjectClass(manager);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(manager, getPtr);
	CS::DocumentParticipantManager::Ptr nativeManager = *reinterpret_cast<CS::DocumentParticipantManager::Ptr*>(ptr);
	return nativeManager->getParticipantCount();

}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getParticipant
  (JNIEnv *env, jobject manager, jlong jid, jobject resultCodeObject)
{
	jobject result;
	jclass c = env->GetObjectClass(manager);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(manager, getPtr);
	CS::DocumentParticipantManager::Ptr nativeManager = *reinterpret_cast<CS::DocumentParticipantManager::Ptr*>(ptr);
	CS::DocumentParticipant *participant = new  CS::DocumentParticipant;
	int resultCode = (int)nativeManager->getParticipant(jid, *participant);

	jclass cP = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentParticipant");
	jmethodID constructor;
	constructor = env->GetMethodID(cP, "<init>", "(J)V");
	result = env->NewObject(cP, constructor, (long long)participant);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return result;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getParticipantAtIndex(
		JNIEnv *env, jobject manager, jint index, jobject resultCodeObject)
{
	jobject result;
	jclass c = env->GetObjectClass(manager);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(manager, getPtr);
	CS::DocumentParticipantManager::Ptr nativeManager = *reinterpret_cast<CS::DocumentParticipantManager::Ptr*>(ptr);
	CS::DocumentParticipant *participant = new  CS::DocumentParticipant;
	int resultCode = (int)nativeManager->getParticipantAtIndex(index, *participant);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	jclass cP = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentParticipant");
	jmethodID constructor;
	constructor = env->GetMethodID(cP, "<init>", "(J)V");
	result = env->NewObject(cP, constructor, (long long)participant);


	env->CallVoidMethod(resultCodeObject, setCode, resultCode);


	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_addParticipant(
		JNIEnv *env, jobject manager, jobject participant, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(manager);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(manager, getPtr);
	CS::DocumentParticipantManager::Ptr nativeManager = *reinterpret_cast<CS::DocumentParticipantManager::Ptr*>(ptr);

	jclass cP = env->GetObjectClass(participant);
	jmethodID getPtrP = env->GetMethodID(cP, "getPtr", "()J");
	jlong ptrP = env->CallLongMethod(participant, getPtrP);
	long long lptrP = (long long) ptrP;
	CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(lptrP);
	int resultCode = (int)nativeManager->addParticipant(*nativeParticipant);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);


}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_insertParticipantAtIndex(
		JNIEnv *env, jobject manager, jobject participant, jint index, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(manager);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(manager, getPtr);
	CS::DocumentParticipantManager::Ptr nativeManager = *reinterpret_cast<CS::DocumentParticipantManager::Ptr*>(ptr);

	jclass cP = env->GetObjectClass(participant);
	jmethodID getPtrP = env->GetMethodID(cP, "getPtr", "()J");
	jlong ptrP = env->CallLongMethod(participant, getPtrP);
	long long lptrP = (long long) ptrP;
	CS::DocumentParticipant *nativeParticipant = reinterpret_cast<CS::DocumentParticipant*>(lptrP);
	int resultCode = (int)nativeManager->insertParticipantAtIndex(*nativeParticipant, index);
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_removeParticipantAtIndex(
		JNIEnv *env, jobject manager, jint index, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(manager);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(manager, getPtr);
	CS::DocumentParticipantManager::Ptr nativeManager = *reinterpret_cast<CS::DocumentParticipantManager::Ptr*>(ptr);
	int resultCode = (int)nativeManager->removeParticipantAtIndex(index);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);



}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_moveParticipant(
		JNIEnv *env, jobject manager, jint oldIndex, jint newIndex, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(manager);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(manager, getPtr);
	CS::DocumentParticipantManager::Ptr nativeManager = *reinterpret_cast<CS::DocumentParticipantManager::Ptr*>(ptr);
	int resultCode = (int)nativeManager->moveParticipant(oldIndex, newIndex);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);


}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getNextColor
  (JNIEnv *env, jobject manager) {
	jclass c = env->GetObjectClass(manager);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(manager, getPtr);
	CS::DocumentParticipantManager::Ptr nativeManager = *reinterpret_cast<CS::DocumentParticipantManager::Ptr*>(ptr);
	CS::Color color = nativeManager->getNextColor();
	jclass cColor = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/CSColor");
	jmethodID constructor;

	constructor = env->GetMethodID(cColor, "<init>", "(IIII)V");
	jobject result = env->NewObject(cColor, constructor, color.alpha, color.red, color.green, color.blue);
	return result;
}
