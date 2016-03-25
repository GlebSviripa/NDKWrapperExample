#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate.h"

using namespace std;

JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_getPtrJNI
  (JNIEnv *env, jobject jTemplate)
  {
	return 0;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_destroy
  (JNIEnv *env, jobject jTemplate)
  {

  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    getId
 * Signature: ()Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateID;
 */
JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_getId
  (JNIEnv *env, jobject jTemplate)
  {
	jclass c = env->GetObjectClass(jTemplate);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplate, getPtr);
	long long lptr = (long long) ptr;
	CS::Template *templateObj = reinterpret_cast<CS::Template*>(lptr);
	CS::Template::ID *id = new CS::Template::ID(templateObj->getID());
	jclass csTemplateIDClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateID");
	jmethodID constructor;
	constructor = env->GetMethodID(csTemplateIDClass, "<init>", "(J)V");
	jobject result = env->NewObject(csTemplateIDClass, constructor, (long) id);
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    getName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_getName
  (JNIEnv *env, jobject jTemplate)
  {
	jclass c = env->GetObjectClass(jTemplate);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplate, getPtr);
	long long lptr = (long long)ptr;
	CS::Template *templateObj = reinterpret_cast<CS::Template*>(lptr);

	CS::String a = templateObj->getName();
	jstring result = env->NewStringUTF((const char*)a.c_str());
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    getTemplateAuthor
 * Signature: ()Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateAuthor;
 */
JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_getTemplateAuthor
  (JNIEnv *env, jobject jTemplate)
  {
	jclass c = env->GetObjectClass(jTemplate);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplate, getPtr);
	long long lptr = (long long) ptr;
	CS::Template *templateObj = reinterpret_cast<CS::Template*>(lptr);

	CS::Template::Author *author = new CS::Template::Author(templateObj->getAuthor());

	jclass csTemplateAuthorClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateAuthor");
	jmethodID constructor;
	constructor = env->GetMethodID(csTemplateAuthorClass, "<init>", "(J)V");
	jobject result = env->NewObject(csTemplateAuthorClass, constructor, (long) author);
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    getCreationDateMilis
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_getCreationDateMilis
  (JNIEnv *env, jobject jTemplate)
  {
    jclass c = env->GetObjectClass(jTemplate);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplate, getPtr);
	long long lptr = (long long)ptr;
	CS::Template *templateObj = reinterpret_cast<CS::Template*>(lptr);
    return templateObj->getCreationDate();
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    getUpdateDateMilis
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_getUpdateDateMilis
  (JNIEnv *env, jobject jTemplate)
  {
	jclass c = env->GetObjectClass(jTemplate);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplate, getPtr);
	long long lptr = (long long)ptr;
	CS::Template *templateObj = reinterpret_cast<CS::Template*>(lptr);
	return templateObj->getUpdateDate();
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    getFetchingProgress
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_getFetchingProgress
  (JNIEnv *env, jobject jTemplate)
  {
	jclass c = env->GetObjectClass(jTemplate);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplate, getPtr);
	long long lptr = (long long) ptr;
	CS::Template *templateObj = reinterpret_cast<CS::Template*>(lptr);
	return templateObj->getFetchingProgress();
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    getPreviewPath
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_getPreviewPath
  (JNIEnv *env, jobject jTemplate)
  {
	jclass c = env->GetObjectClass(jTemplate);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplate, getPtr);
	long long lptr = (long long)ptr;
	CS::Template *templateObj = reinterpret_cast<CS::Template*>(lptr);
	CS::String *temp;
	templateObj->getPreview(*temp);
	jstring result = env->NewStringUTF((const char*)(*temp).c_str());
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    fetch
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_fetch
  (JNIEnv *env, jobject jTemplate)
  {
	jclass c = env->GetObjectClass(jTemplate);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplate, getPtr);
	long long lptr = (long long)ptr;
	CS::Template *templateObj = reinterpret_cast<CS::Template*>(lptr);
	templateObj->fetch();
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate
 * Method:    fetchPreview
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate_fetchPreview
  (JNIEnv *env, jobject jTemplate)
  {
	jclass c = env->GetObjectClass(jTemplate);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplate, getPtr);
	long long lptr = (long long)ptr;
	CS::Template *templateObj = reinterpret_cast<CS::Template*>(lptr);
	templateObj->fetchPreview();
  }
