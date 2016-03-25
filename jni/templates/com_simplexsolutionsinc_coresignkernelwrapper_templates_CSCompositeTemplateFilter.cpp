#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_templates_CSCompositeTemplateFilter.h"

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSCompositeTemplateFilter
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSCompositeTemplateFilter_destroy
  (JNIEnv *env, jobject jFilter)
  {

  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSCompositeTemplateFilter
 * Method:    getFilters
 * Signature: ()[Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateFilter;
 */
JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSCompositeTemplateFilter_getFilters
  (JNIEnv *env, jobject jFilter)
  {
	jclass c = env->GetObjectClass(jFilter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jFilter, getPtr);
	long long lptr = (long long) ptr;
	CS::CompositeTemplateFilter *templateFilter = reinterpret_cast<CS::CompositeTemplateFilter*>(lptr);

	auto filters = templateFilter->getFilters();
	int size = filters.size();

    jclass cf;
    jmethodID constructor;
	jobject element;
	cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateFilter");
	jobjectArray result = (jobjectArray)env->NewObjectArray(size, cf, NULL);
	for (int i = 0; i < size; i++)
	{
	    auto curTemplateFilter = filters[i].get();
	    switch (curTemplateFilter->getType())
        {
            case CS::TemplateFilter::Type::ByAuthor:
            {
                // create specific java obj
                cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSByAuthorTemplateFilter");
                constructor = env->GetMethodID(cf, "<init>", "(J)V");
		        element = env->NewObject(cf, constructor, (long long)curTemplateFilter);
		        env->SetObjectArrayElement(result, i, element);
                break;
            }
            case CS::TemplateFilter::Type::ByQuery:
            {
                // create specific java obj
                cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSStringQueryTemplateFilter");
                constructor = env->GetMethodID(cf, "<init>", "(J)V");
		        element = env->NewObject(cf, constructor, (long long)curTemplateFilter);
		        env->SetObjectArrayElement(result, i, element);
                break;
            }
            case CS::TemplateFilter::Type::Composite:
            {
                // create specific java obj
                cf = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSCompositeTemplateFilter");
                constructor = env->GetMethodID(cf, "<init>", "(J)V");
		        element = env->NewObject(cf, constructor, (long long)curTemplateFilter);
		        env->SetObjectArrayElement(result, i, element);
                break;
            }
        }
	}
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSCompositeTemplateFilter
 * Method:    init
 * Signature: ([Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateFilter;)J
 */
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSCompositeTemplateFilter_init
  (JNIEnv *env, jobject jFilter, jobjectArray jFiltersArray)
  {
	jclass c = env->GetObjectClass(jFilter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jFilter, getPtr);
	long long lptr = (long long) ptr;
	CS::CompositeTemplateFilter *templateFilter = reinterpret_cast<CS::CompositeTemplateFilter*>(lptr);

	int size = env->GetArrayLength(jFiltersArray);
	auto filters = templateFilter->getFilters();
	for (int i = 0; i < size; i++)
	{
		jobject o = env->GetObjectArrayElement(jFiltersArray, i);
		jclass cf = env->GetObjectClass(o);

		jmethodID getOPtr = env->GetMethodID(cf, "getPtr", "()J");
		jlong optr = env->CallLongMethod(o, getOPtr);
		long long olptr = (long long)optr;
	    CS::TemplateFilter *curTemplateFilter = reinterpret_cast<CS::TemplateFilter*>(optr);

		filters.emplace_back(CS::TemplateFilter::Ptr(curTemplateFilter));
	}
  }

