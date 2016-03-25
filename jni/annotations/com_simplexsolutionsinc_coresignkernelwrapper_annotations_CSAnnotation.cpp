/*
 * com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation.cpp
 *
 *  Created on: 11 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation.h"
#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_getPtrJNI(
		JNIEnv *, jobject)
{
	return 0;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_destroy(
		JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);

	delete reinterpret_cast<CS::Annotation::Ptr*>(ptr);
}

JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_getAnnotationType(
		JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
				jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
				jlong ptr = env->CallLongMethod(annotation, getPtr);
				CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);

				return (int)nativeAnnotation->getType();
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_getID(
		JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(annotation, getPtr);
		CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
		CS::Annotation::ID *id = new CS::Annotation::ID(nativeAnnotation->getID());
		jclass cI = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/annotations/CSAnnotationID");
		jmethodID constructor;
		constructor = env->GetMethodID(cI, "<init>", "(J)V");
		jobject result = env->NewObject(cI, constructor, (long long) id);
		return result;
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_getFrame
  (JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
			jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
			jlong ptr = env->CallLongMethod(annotation, getPtr);
			CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
			LOGI("CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);");
			CS::Rect *rect = new CS::Rect(nativeAnnotation->getFrame());
			LOGI("CS::Rect *rect = new CS::Rect(nativeAnnotation->getFrame());");
			jclass cRect = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/KernelRect");
			jmethodID constructor;
			constructor = env->GetMethodID(cRect, "<init>", "(DDDD)V");

			double height = rect->height;
			double left   = rect->left;
			double width  = rect->width;
			double top   = rect->top;
			jobject result = env->NewObject(cRect, constructor, left, top, width, height);
			return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_setFrame
  (JNIEnv *env, jobject annotation, jdouble x, jdouble y, jdouble w, jdouble h)
{
	jclass c = env->GetObjectClass(annotation);
				jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
				jlong ptr = env->CallLongMethod(annotation, getPtr);
				CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
				CS::Rect *rect = new CS::Rect;
				rect->height = h;
				rect->width = w;
				rect->left = x;
				rect->top = y;
				nativeAnnotation->setFrame(*rect);
}

JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_isPlaceholder
  (JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
	LOGI("PTR: [%lli]", ptr);
	return nativeAnnotation->isPlaceholder();
}

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_getOwner
  (JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
					jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
					jlong ptr = env->CallLongMethod(annotation, getPtr);
					CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
					jlong result = nativeAnnotation->getOwner();
					return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_setOwner
  (JNIEnv *env, jobject annotation, jlong id)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
	nativeAnnotation->setOwner(id);
}

JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_canUndo
  (JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
	return nativeAnnotation->canUndo();
}

JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_canRedo
  (JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
	return nativeAnnotation->canRedo();
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_undo
  (JNIEnv *env, jobject annotation, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
	int resultCode = (int)nativeAnnotation->undo();

	jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_redo
  (JNIEnv *env, jobject annotation, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
	int resultCode = (int)nativeAnnotation->redo();

	jclass classResult = env->GetObjectClass(resultCodeObject);
		jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
		env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}

JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_isEditable
  (JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
	LOGI("PTR: [%lli]", ptr);
	return nativeAnnotation->isEditable();
}

JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation_isContentEditable
  (JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	CS::Annotation::Ptr nativeAnnotation = *reinterpret_cast<CS::Annotation::Ptr*>(ptr);
	LOGI("PTR: [%lli]", ptr);
	return nativeAnnotation->isContentEditable();
}
