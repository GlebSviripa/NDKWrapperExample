#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateFilter.h"

using namespace std;

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateFilter
 * Method:    getType
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateFilter_getType
  (JNIEnv *env, jobject jTemplateFilter)
  {
    jclass c = env->GetObjectClass(jTemplateFilter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jTemplateFilter, getPtr);
	long long lptr = (long long)ptr;
	CS::TemplateFilter *templateFilter = reinterpret_cast<CS::TemplateFilter*>(lptr);
    return static_cast<jint>(templateFilter->getType());
  }