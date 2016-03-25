/*
 * com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore.cpp
 *
 *  Created on: 14 мая 2015
 *      Author: gleb
 */


#include "com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_getPtrJNI(
		JNIEnv *env, jobject)
{
	return 0;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_destroy(
		JNIEnv *env, jobject store)
{
	jclass c = env->GetObjectClass(store);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(store, getPtr);

	delete reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);
}

JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_canUndo(
		JNIEnv *env, jobject store)
{
	jclass c = env->GetObjectClass(store);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(store, getPtr);
	CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);
	return nativeAnnotationStore->canUndo();
}

JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_canRedo(
		JNIEnv *env, jobject store)
{
	jclass c = env->GetObjectClass(store);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(store, getPtr);
		CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);
		return nativeAnnotationStore->canRedo();
}

JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_getAnnotationIDsForPage(
		JNIEnv *env, jobject store, jint page, jobject resultCodeObject)
{
	jobjectArray result;

	jclass c = env->GetObjectClass(store);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(store, getPtr);
	CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);

	jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSAnnotationID");
	jmethodID constructor;
	constructor = env->GetMethodID(cf, "<init>", "(J)V");
	vector<CS::Annotation::ID> v;

	int resultCode = (int)nativeAnnotationStore->getAnnotationIDsForPage(page, v);

	int size = v.size();
	result = (jobjectArray)env->NewObjectArray(size, cf, NULL);

	for (int i = 0; i < size; i++)
	{
		CS::Annotation::ID *id = new CS::Annotation::ID(v[i]);
		jobject element = env->NewObject(cf, constructor, (long long)id);
		env->SetObjectArrayElement(result, i, element);
	}

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
	return result;
}

JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_getPlaceholderIDsForUser(
		JNIEnv *env, jobject store, jlong id, jboolean includeAnonymousUser)
{
	jobjectArray result;

	jclass c = env->GetObjectClass(store);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(store, getPtr);
	CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);

	jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSAnnotationID");
	jmethodID constructor;
	constructor = env->GetMethodID(cf, "<init>", "(J)V");
	vector<CS::Annotation::ID> v;

	v = nativeAnnotationStore->getPlaceholderIDsForUser(id, includeAnonymousUser);

	int size = v.size();
	result = (jobjectArray)env->NewObjectArray(size, cf, NULL);

	for (int i = 0; i < size; i++)
	{
		CS::Annotation::ID *id = new CS::Annotation::ID(v[i]);
		jobject element = env->NewObject(cf, constructor, (long long)id);
		env->SetObjectArrayElement(result, i, element);
	}
	return result;
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_getPageForAnnotation(
		JNIEnv *env, jobject store, jobject id, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(store);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(store, getPtr);
	CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);

	jclass cID = env->GetObjectClass(id);
	jmethodID getPtrID = env->GetMethodID(cID, "getPtr", "()J");
	jlong ptrID = env->CallLongMethod(id, getPtrID);
	long long lptrID= (long long)ptrID;
	CS::Annotation::ID *nativeAnnotationID = reinterpret_cast<CS::Annotation::ID*>(lptrID);
	unsigned int result;
	int resultCode = (int)nativeAnnotationStore->getPageForAnnotation(*nativeAnnotationID, result);

	jclass classResult = env->GetObjectClass(resultCodeObject);
						jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
						env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return result;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_getAnnotation(
		JNIEnv *env, jobject store, jobject id, jobject resultCodeObject)
{



	jclass c = env->GetObjectClass(store);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(store, getPtr);
	CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");

	jclass cID = env->GetObjectClass(id);
	jmethodID getPtrID = env->GetMethodID(cID, "getPtr", "()J");
	jlong ptrID = env->CallLongMethod(id, getPtrID);
	long long lptrID= (long long)ptrID;
	CS::Annotation::ID *nativeAnnotationID = reinterpret_cast<CS::Annotation::ID*>(lptrID);

	CS::Annotation::Ptr *annotation = new CS::Annotation::Ptr();

	int resultCode = (int)nativeAnnotationStore->getAnnotation(*nativeAnnotationID, *annotation);
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
	jclass cAnnotation;
	switch(annotation->get()->getType())
	{
	case CS::Annotation::Type::Text:
		cAnnotation = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSTextAnnotation");
		break;
	case CS::Annotation::Type::Checkbox:
			cAnnotation = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSCheckboxAnnotation");
			break;
	case CS::Annotation::Type::Date:
			cAnnotation = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSDateAnnotation");
			break;
	case CS::Annotation::Type::Signature:
			cAnnotation = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSSignatureAnnotation");
			break;
	case CS::Annotation::Type::Initials:
				cAnnotation = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSInitialsAnnotation");
				break;
	default:
		cAnnotation = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSAnnotation");
		break;

	}

	jmethodID constructor;

	constructor = env->GetMethodID(cAnnotation, "<init>", "(J)V");
	jobject result = env->NewObject(cAnnotation, constructor, (long long)annotation);




	return result;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_createAnnotationOnPage(
		JNIEnv *env, jobject store, jint jtype, jint page, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(store);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(store, getPtr);


	CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);
	CS::Annotation::ID *id = new CS::Annotation::ID();

	jclass cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSAnnotationID");
	jmethodID constructor;
	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	constructor = env->GetMethodID(cf, "<init>", "(J)V");



	jobject result = env->NewObject(cf, constructor, (long long)id);



	int resultCode = (int)nativeAnnotationStore->createAnnotationOnPage((CS::Annotation::Type)jtype, page, *id);
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

	return result;

}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_removeAnnotation(
		JNIEnv *env, jobject store, jobject id, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(store);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(store, getPtr);
	CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);

	jclass cID = env->GetObjectClass(id);
	jmethodID getPtrID = env->GetMethodID(cID, "getPtr", "()J");
	jlong ptrID = env->CallLongMethod(id, getPtrID);
	long long lptrID= (long long)ptrID;
	CS::Annotation::ID *nativeAnnotationID = reinterpret_cast<CS::Annotation::ID*>(lptrID);

	int resultCode = (int)nativeAnnotationStore->removeAnnotation(*nativeAnnotationID);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);

}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_undo(
		JNIEnv *env, jobject store, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(store);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(store, getPtr);
		CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);
		int resultCode = (int)nativeAnnotationStore->undo();

		jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);

}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore_redo(
		JNIEnv *env, jobject store, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(store);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(store, getPtr);
	CS::AnnotationStore::Ptr nativeAnnotationStore = *reinterpret_cast<CS::AnnotationStore::Ptr*>(ptr);
	int resultCode = (int)nativeAnnotationStore->redo();

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);


}
