#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_templates_CSByAuthorTemplateFilter.h"

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSByAuthorTemplateFilter
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSByAuthorTemplateFilter_destroy
  (JNIEnv *env, jobject jFilter)
  {

  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSByAuthorTemplateFilter
 * Method:    getAuthor
 * Signature: ()Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateAuthor;
 */
JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSByAuthorTemplateFilter_getAuthor
  (JNIEnv *env, jobject jFilter)
  {
	jclass c = env->GetObjectClass(jFilter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jFilter, getPtr);
	long long lptr = (long long) ptr;
	CS::ByAuthorTemplateFilter *templateFilter = reinterpret_cast<CS::ByAuthorTemplateFilter*>(lptr);

	CS::Template::Author *author = new CS::Template::Author(templateFilter->getAuthor());

	jclass csTemplateAuthorClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateAuthor");
	jmethodID constructor;
	constructor = env->GetMethodID(csTemplateAuthorClass, "<init>", "(J)V");
	jobject result = env->NewObject(csTemplateAuthorClass, constructor, (long) author);
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSByAuthorTemplateFilter
 * Method:    init
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateAuthor;)J
 */
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSByAuthorTemplateFilter_init
  (JNIEnv *env, jobject jFilter, jobject jCSTemplateAuthor)
  {
	jclass c = env->GetObjectClass(jCSTemplateAuthor);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jCSTemplateAuthor, getPtr);
	long long lptr = (long long) ptr;
	CS::Template::Author *author = reinterpret_cast<CS::Template::Author*>(lptr);

	CS::ByAuthorTemplateFilter *filter = new CS::ByAuthorTemplateFilter(*author);
	jlong result = (long long) filter;
	return result;
  }