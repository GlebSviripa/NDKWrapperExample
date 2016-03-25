#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_templates_CSStringQueryTemplateFilter.h"

using namespace std;

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSStringQueryTemplateFilter
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSStringQueryTemplateFilter_destroy
  (JNIEnv *env, jobject jFilter)
  {

  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSStringQueryTemplateFilter
 * Method:    getQuery
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSStringQueryTemplateFilter_getQuery
  (JNIEnv *env, jobject jFilter)
  {
	jclass c = env->GetObjectClass(jFilter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jFilter, getPtr);
	long long lptr = (long long)ptr;
	CS::ByQueryTemplateFilter *templateFilter = reinterpret_cast<CS::ByQueryTemplateFilter*>(lptr);

	CS::String a = templateFilter->getQuery();
	jstring result = env->NewStringUTF((const char*)a.c_str());
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSStringQueryTemplateFilter
 * Method:    init
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSStringQueryTemplateFilter_init
  (JNIEnv *env, jobject jFilter, jstring jQuery)
  {
    const jsize len = env->GetStringUTFLength(jQuery);
    const char* strChars = env->GetStringUTFChars(jQuery, (jboolean *)0);
    std::string query(strChars, len);
    env->ReleaseStringUTFChars(jQuery, strChars);

	CS::ByQueryTemplateFilter *filter = new CS::ByQueryTemplateFilter(query);
	jlong result = (long long) filter;
	return result;
  }
