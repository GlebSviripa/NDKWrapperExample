#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor.h"

using namespace std;

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor
 * Method:    getPtrJNI
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor_getPtrJNI
  (JNIEnv *env, jobject jTemplateAuthor)
  {
	CS::Template::Author *templateAuthor = new CS::Template::Author;
	jlong result = (long long) templateAuthor;
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor_destroy
  (JNIEnv *env, jobject jTemplateAuthor)
  {

  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor
 * Method:    getId
 * Signature: ()Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateAuthorID;
 */
JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor_getId
  (JNIEnv *env, jobject jTemplateAuthor)
  {
	jclass c = env->GetObjectClass(jTemplateAuthor);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplateAuthor, getPtr);
	long long lptr = (long long) ptr;
	CS::Template::Author *templateAuthor = reinterpret_cast<CS::Template::Author*>(lptr);
	CS::Template::Author::ID *id = new CS::Template::Author::ID(templateAuthor->id);
	jclass csTemplateAuthorClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateAuthor");
	jmethodID constructor;
	constructor = env->GetMethodID(csTemplateAuthorClass, "<init>", "(J)V");
	jobject result = env->NewObject(csTemplateAuthorClass, constructor, (long) id);
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor
 * Method:    getCompanyName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor_getCompanyName
  (JNIEnv *env, jobject jTemplateAuthor)
  {
	jclass c = env->GetObjectClass(jTemplateAuthor);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplateAuthor, getPtr);
	long long lptr = (long long)ptr;
	CS::Template::Author *templateAuthor = reinterpret_cast<CS::Template::Author*>(lptr);
	string a = templateAuthor->companyName;
	jstring result = env->NewStringUTF(a.c_str());
	return result;
  }