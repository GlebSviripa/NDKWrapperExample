#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include "CSDocumentPreviewProviderImpl.h"
#include "com_simplexsolutionsinc_coresignkernelwrapper_providers_CSDocumentPreviewAdapter.h"


using namespace std;

static jclass documentClass;
//TODO:: rewrite java part
CS::Image CSDocumentPreviewProviderImpl::previewForDocument(const CS::Document::Ptr& inDocument) const noexcept
{
    JNIEnv* env = JavaCache::getJNIEnv();
    if(env == NULL)
    {

    }


    jmethodID documentConstructor = env->GetMethodID(documentClass, "<init>", "(J)V");
    CS::Document::Ptr *document = new CS::Document::Ptr(inDocument);

    jobject jDocument = env->NewObject(documentClass, documentConstructor, (long long)document);
    LOGI("jobject jDocument = env->NewObject");
    if(jCSDocumentPreviewProviderAdapter == NULL)
    {
    	LOGI("jO == null");
    }
	jclass documentPreviewAdapterClass = env->GetObjectClass(jCSDocumentPreviewProviderAdapter);

    jmethodID previewForDocumentMID = env->GetMethodID(documentPreviewAdapterClass, "previewForDocument", "(Lcom/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocument;)Ljava/lang/String;");
    jstring jImagePath = (jstring)env->CallObjectMethod(jCSDocumentPreviewProviderAdapter, previewForDocumentMID, jDocument);

    const jsize len = env->GetStringUTFLength(jImagePath);
    const char* strChars = env->GetStringUTFChars(jImagePath, (jboolean *)0);
    std::string imagePath(strChars, len);
    env->ReleaseStringUTFChars(jImagePath, strChars);
    return imagePath;


}

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_providers_CSDocumentPreviewAdapter
 * Method:    getPtrJNI
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_providers_CSDocumentPreviewAdapter_getPtrJNI
  (JNIEnv *env, jobject jCSDocumentPreviewProviderAdapter)
  {
    jobject jCSDocumentPreviewProviderAdapterRef = env->NewGlobalRef(jCSDocumentPreviewProviderAdapter);
    CSDocumentPreviewProviderImpl *documentPreviewProvider = new CSDocumentPreviewProviderImpl(jCSDocumentPreviewProviderAdapterRef);
    jlong result = (long long) documentPreviewProvider;
    return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_providers_CSDocumentPreviewAdapter
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_providers_CSDocumentPreviewAdapter_destroy
  (JNIEnv *env, jobject jCSDocumentPreviewProviderAdapter)
  {
	jclass c = env->GetObjectClass(jCSDocumentPreviewProviderAdapter);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(jCSDocumentPreviewProviderAdapter, getPtr);

	delete reinterpret_cast<CS::DocumentPreviewProvider*>(ptr);
  }

JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_providers_CSDocumentPreviewAdapter_init
  (JNIEnv *pJniEnv, jclass cls, jclass cDocument)
{
	documentClass = (jclass)JavaCache::getJNIEnv()->NewGlobalRef(cDocument);
}

