/*
 * com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument.cpp
 *
 *  Created on: 8 мая 2015
 *      Author: gleb
 */
#include <android/log.h>
#include <stdio.h>
#include <memory>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument.h"


using namespace std;

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getPtrJNI(
		JNIEnv *, jobject)
{
	return 0;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_destroy(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();

	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);

	delete reinterpret_cast<CS::Document::Ptr*>(ptr);
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getId(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);
	CS::Document::ID *id = new CS::Document::ID(nativeDocument->getID());
	jclass cID = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentID");
	jmethodID constructor;
	constructor = env->GetMethodID(cID, "<init>", "(J)V");
	jobject result = env->NewObject(cID, constructor, (long long) id);
	return result;
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getName(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);

	CS::String tempStr = nativeDocument->getName();
	return env->NewStringUTF(tempStr.c_str());
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_setName
  (JNIEnv *env, jobject document, jstring jname)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	string name = string(env->GetStringUTFChars(jname, 0));
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);
	nativeDocument->setName(name);
	//env->ReleaseStringUTFChars(jname, name.c_str());
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getAuthor
  (JNIEnv *env, jobject document)
{
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);

	CS::DocumentParticipant *participant = new  CS::DocumentParticipant(nativeDocument->getAuthor());


	jclass cP = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentParticipant");
	jmethodID constructor;
	constructor = env->GetMethodID(cP, "<init>", "(J)V");
	jobject result = env->NewObject(cP, constructor, (long long)participant);
	return result;
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getNote(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);

	CS::String tempStr = nativeDocument->getNote();
	return  env->NewStringUTF(tempStr.c_str());
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_setNote(
		JNIEnv *env, jobject document, jstring jnote)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	string note = string(env->GetStringUTFChars(jnote, 0));
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);
	nativeDocument->setNote(note);
	//env->ReleaseStringUTFChars(jnote, note.c_str());
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getState(
		JNIEnv *env, jobject document)
{
	jclass c = env->GetObjectClass(document);
				jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
				jlong ptr = env->CallLongMethod(document, getPtr);
				CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);
				return (int)nativeDocument->getState();
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getCreationDateMilis(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);
	return nativeDocument->getCreationDate() * 1000;
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getUpdateDateMilis(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);
	return nativeDocument->getUpdateDate() * 1000;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getContent(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);

	CS::DocumentContent::Ptr *content = new CS::DocumentContent::Ptr();
	*content = nativeDocument->content();
	jclass cM = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentContent");
	jmethodID constructor;
	constructor = env->GetMethodID(cM, "<init>", "(J)V");
	jobject result = env->NewObject(cM, constructor, (long long) content);
	return result;

}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getParticipantManager(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);

	CS::DocumentParticipantManager::Ptr *manager = new CS::DocumentParticipantManager::Ptr();
	*manager = nativeDocument->participantManager();
	//__GXX_EXPERIMENTAL_CXX0X__

	jclass cM = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentParticipantManager");
	jmethodID constructor;
	constructor = env->GetMethodID(cM, "<init>", "(J)V");
	jobject result = env->NewObject(cM, constructor, (long long) manager);
	return result;
}


JNIEXPORT jfloat JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getContentFetchingProgress(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);
	return nativeDocument->getContentFetchingProgress();
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_getPreviewPath(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);

	CS::String temp;
	int resCode = (int)nativeDocument->getPreview(temp);
	jstring result = env->NewStringUTF(temp.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_fetchPreview(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);
	nativeDocument->fetchPreview();

}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument_fetchContent(
		JNIEnv *env, jobject document)
{
	//JNIEnv *env = JavaCache::getJNIEnv();
	jclass c = env->GetObjectClass(document);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(document, getPtr);
	CS::Document::Ptr nativeDocument = *reinterpret_cast<CS::Document::Ptr*>(ptr);
	nativeDocument->fetchContent();
}
