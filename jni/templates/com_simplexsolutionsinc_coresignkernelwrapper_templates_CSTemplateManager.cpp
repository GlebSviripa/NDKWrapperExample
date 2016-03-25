#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager.h"

using namespace std;

static CS::TemplateManager &templateManager = CS::TemplateManager::getInstance();

/*
Result getTemplateAuthors(Authors& outAuthors) const noexcept;
Result getTemplateIDs(IDs& outIDs) const noexcept;
Result getTemplateIDs(const TemplateFilter& inFilter, IDs& outIDs) const noexcept;

Result getTemplate(const Template::ID& inTemplateID, Template::Ptr& outTemplatePtr) const noexcept;


void cleanCache() noexcept;
*/

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager
 * Method:    getPtrJNI
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager_getPtrJNI
  (JNIEnv *env, jobject jTemplateManager)
  {
	jlong result = (long long) &templateManager;
	return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager_destroy
  (JNIEnv *env, jobject jTemplateManager)
  {

  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager
 * Method:    getTemplateAuthors
 * Signature: ()[Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateAuthor;
 */
JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager_getTemplateAuthors
  (JNIEnv *env, jobject jTemplateManager)
  {
	jclass templateManagerClass = env->GetObjectClass(jTemplateManager);
	jmethodID getPtrTemplateManager = env->GetMethodID(templateManagerClass, "getPtr", "()J");
	jlong ptrTemplateManager = env->CallLongMethod(jTemplateManager, getPtrTemplateManager);
	long long lptrTemplateManager = (long long) ptrTemplateManager;
	CS::TemplateManager *templateManagerObj = reinterpret_cast<CS::TemplateManager*>(lptrTemplateManager);

    CS::TemplateManager::Authors authors;
    auto result = templateManagerObj->getTemplateAuthors(authors);

    if(result==CS::TemplateManager::Result::Success)
    {
        jclass templateAuthorClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateAuthor");
        jmethodID templateAuthorConstructor = env->GetMethodID(templateAuthorClass, "<init>", "(J)V");

        int size = authors.size();
	    jobjectArray result = (jobjectArray)env->NewObjectArray(size, templateAuthorClass, NULL);
        for (int i = 0; i < size; i++)
        {
            CS::Template::Author curTemplateAuthor = authors[i];
            CS::Template::Author *templateAuthor = new CS::Template::Author(curTemplateAuthor);
            jobject jTemplateAuthor = env->NewObject(templateAuthorClass, templateAuthorConstructor, (long long)templateAuthor);

            env->SetObjectArrayElement(result, i, jTemplateAuthor);
        }
        return result;
    }
    return NULL;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager
 * Method:    getTemplateIDs
 * Signature: ()[Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateID;
 */
JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager_getTemplateIDs__
  (JNIEnv *env, jobject jTemplateManager)
  {
	jclass templateManagerClass = env->GetObjectClass(jTemplateManager);
	jmethodID getPtrTemplateManager = env->GetMethodID(templateManagerClass, "getPtr", "()J");
	jlong ptrTemplateManager = env->CallLongMethod(jTemplateManager, getPtrTemplateManager);
	long long lptrTemplateManager = (long long) ptrTemplateManager;
	CS::TemplateManager *templateManagerObj = reinterpret_cast<CS::TemplateManager*>(lptrTemplateManager);

    CS::TemplateManager::IDs templateIDs;
    auto result = templateManagerObj->getTemplateIDs(templateIDs);
    if(result==CS::TemplateManager::Result::Success)
    {
        jclass templateIDClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateID");
        jmethodID templateIDConstructor = env->GetMethodID(templateIDClass, "<init>", "(J)V");

        int size = templateIDs.size();
	    jobjectArray result = (jobjectArray)env->NewObjectArray(size, templateIDClass, NULL);
        for (int i = 0; i < size; i++)
        {
            CS::Template::ID curTemplateID = templateIDs[i];
            CS::Template::ID *templateID = new CS::Template::ID(curTemplateID);
            jobject jTemplateID = env->NewObject(templateIDClass, templateIDConstructor, (long long)templateID);

            env->SetObjectArrayElement(result, i, jTemplateID);
        }
        return result;
    }
    return NULL;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager
 * Method:    getTemplateIDs
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateFilter;)[Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateID;
 */
JNIEXPORT jobjectArray JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager_getTemplateIDs__Lcom_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateFilter_2
  (JNIEnv *env, jobject jTemplateManager, jobject jFilter)
  {
	jclass templateManagerClass = env->GetObjectClass(jTemplateManager);
	jmethodID getPtrTemplateManager = env->GetMethodID(templateManagerClass, "getPtr", "()J");
	jlong ptrTemplateManager = env->CallLongMethod(jTemplateManager, getPtrTemplateManager);
	long long lptrTemplateManager = (long long) ptrTemplateManager;
	CS::TemplateManager *templateManagerObj = reinterpret_cast<CS::TemplateManager*>(lptrTemplateManager);

	jclass templateFilterClass = env->GetObjectClass(jFilter);
	jmethodID getPtrTemplateFilter = env->GetMethodID(templateFilterClass, "getPtr", "()J");
	jlong ptrTemplateFilter = env->CallLongMethod(jFilter, getPtrTemplateFilter);
	long long lptrTemplateFilter = (long long) ptrTemplateFilter;
	CS::TemplateFilter *templateFilterObj = reinterpret_cast<CS::TemplateFilter*>(lptrTemplateFilter);

    CS::TemplateManager::IDs templateIDs;
    auto result = templateManagerObj->getTemplateIDs(*templateFilterObj, templateIDs);
    if(result==CS::TemplateManager::Result::Success)
    {
        jclass templateIDClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateID");
        jmethodID templateIDConstructor = env->GetMethodID(templateIDClass, "<init>", "(J)V");

        int size = templateIDs.size();
	    jobjectArray result = (jobjectArray)env->NewObjectArray(size, templateIDClass, NULL);
        for (int i = 0; i < size; i++)
        {
            CS::Template::ID curTemplateID = templateIDs[i];
            CS::Template::ID *templateID = new CS::Template::ID(curTemplateID);
            jobject jTemplateID = env->NewObject(templateIDClass, templateIDConstructor, (long long)templateID);

            env->SetObjectArrayElement(result, i, jTemplateID);
        }
        return result;
    }
    return NULL;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager
 * Method:    getTemplate
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplateID;)Lcom/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplate;
 */
JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager_getTemplate
  (JNIEnv *env, jobject jTemplateManager, jobject jTemplateID)
  {
	jclass templateManagerClass = env->GetObjectClass(jTemplateManager);
	jmethodID getPtrTemplateManager = env->GetMethodID(templateManagerClass, "getPtr", "()J");
	jlong ptrTemplateManager = env->CallLongMethod(jTemplateManager, getPtrTemplateManager);
	long long lptrTemplateManager = (long long) ptrTemplateManager;
	CS::TemplateManager *templateManagerObj = reinterpret_cast<CS::TemplateManager*>(lptrTemplateManager);

	jclass templateIDClass = env->GetObjectClass(jTemplateID);
	jmethodID getPtrTemplateID = env->GetMethodID(templateIDClass, "getPtr", "()J");
	jlong ptrTemplateID = env->CallLongMethod(jTemplateID, getPtrTemplateID);
	long long lptrTemplateID = (long long) ptrTemplateID;
	CS::Template::ID *templateIDObj = reinterpret_cast<CS::Template::ID*>(lptrTemplateID);

    CS::Template::Ptr templatePtr;

    auto result = templateManagerObj->getTemplate(*templateIDObj, templatePtr);

    jclass templateClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/templates/CSTemplate");
    jmethodID templateConstructor = env->GetMethodID(templateClass, "<init>", "(J)V");
    jobject jTemplate = env->NewObject(templateIDClass, templateConstructor, (long long)templatePtr.get());
    return jTemplate;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager
 * Method:    cleanCache
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager_cleanCache
  (JNIEnv *env, jobject jTemplateManager)
  {
	jclass templateManagerClass = env->GetObjectClass(jTemplateManager);
	jmethodID getPtrTemplateManager = env->GetMethodID(templateManagerClass, "getPtr", "()J");
	jlong ptrTemplateManager = env->CallLongMethod(jTemplateManager, getPtrTemplateManager);
	long long lptrTemplateManager = (long long) ptrTemplateManager;
	CS::TemplateManager *templateManagerObj = reinterpret_cast<CS::TemplateManager*>(lptrTemplateManager);
	templateManagerObj->cleanCache();
  }

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSTemplateManager_addListener
  (JNIEnv *env, jclass, jobject listener, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(listener);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(listener, getPtr);
	long long lptr = (long long)ptr;
	CS::Listener::Ptr *nativeListener = reinterpret_cast<CS::Listener::Ptr*>(lptr);
	int resultCode = (int)CS::TemplateManager::getInstance().addListener(*nativeListener);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}


JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_session_CSTemplateManager_removeListener
  (JNIEnv *env, jclass, jobject listener, jobject resultCodeObject)
{
	jclass c = env->GetObjectClass(listener);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(listener, getPtr);
	long long lptr = (long long)ptr;
	CS::Listener::Ptr *nativeListener = reinterpret_cast<CS::Listener::Ptr*>(lptr);
	int resultCode = (int)CS::TemplateManager::getInstance().removeListener(*nativeListener);

	jclass classResult = env->GetObjectClass(resultCodeObject);
	jmethodID setCode = env->GetMethodID(classResult, "setCode", "(I)V");
	env->CallVoidMethod(resultCodeObject, setCode, resultCode);
}
