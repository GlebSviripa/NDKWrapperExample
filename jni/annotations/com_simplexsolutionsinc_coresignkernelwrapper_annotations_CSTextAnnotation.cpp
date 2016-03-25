/*
 * com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSTextAnnotation.cpp
 *
 *  Created on: 15 мая 2015
 *      Author: gleb
 */

#include "com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSTextAnnotation.h"

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>

using namespace std;

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSTextAnnotation_getText(
		JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	long long lptr = (long long)ptr;
	std::shared_ptr<CS::TextAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::TextAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));


	CS::String text = nativeAnnotation->getText();
	jstring result = env->NewStringUTF((const char*)text.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSTextAnnotation_setText(
		JNIEnv *env, jobject annotation, jstring jtetxt)
{
	string text = string(env->GetStringUTFChars(jtetxt, 0));

	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	long long lptr = (long long)ptr;
	std::shared_ptr<CS::TextAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::TextAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));

	nativeAnnotation->setText(text);
}

JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSTextAnnotation_getFont(
		JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	long long lptr = (long long)ptr;

	std::shared_ptr<CS::TextAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::TextAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));
	CS::String font = nativeAnnotation->getFont();
	jstring result = env->NewStringUTF((const char*)font.c_str());
	return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSTextAnnotation_setFont(
		JNIEnv *env, jobject annotation, jstring jfont)
{
	string font = string(env->GetStringUTFChars(jfont, 0));

	jclass c = env->GetObjectClass(annotation);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(annotation, getPtr);
	long long lptr = (long long)ptr;

	std::shared_ptr<CS::TextAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::TextAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));

	nativeAnnotation->setFont(font);
}

JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSTextAnnotation_getColor(
		JNIEnv *env, jobject annotation)
{
	jclass c = env->GetObjectClass(annotation);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(annotation, getPtr);
		long long lptr = (long long)ptr;

		std::shared_ptr<CS::TextAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::TextAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));

		CS::Color color = nativeAnnotation->getTextColor();
			jclass cColor = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/CSColor");
			jmethodID constructor;

			constructor = env->GetMethodID(cColor, "<init>", "(BBBB)V");
			jobject result = env->NewObject(cColor, constructor, color.alpha, color.red, color.green, color.blue);
			return result;
}

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSTextAnnotation_setColor(
		JNIEnv *env, jobject annotation, jint a, jint r, jint g, jint b)
{
	jclass c = env->GetObjectClass(annotation);
		jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
		jlong ptr = env->CallLongMethod(annotation, getPtr);
		long long lptr = (long long)ptr;

		std::shared_ptr<CS::TextAnnotation> nativeAnnotation = std::dynamic_pointer_cast<CS::TextAnnotation>(*reinterpret_cast<CS::Annotation::Ptr*>(lptr));

		CS::Color color;
		color.alpha = (CS::Byte)a;
		color.red = (CS::Byte)r;
		color.green = (CS::Byte)g;
		color.blue = (CS::Byte)b;

		nativeAnnotation->setTextColor(color);
}
