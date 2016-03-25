#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "com_simplexsolutionsinc_coresignkernelwrapper_providers_CSSessionCredentialsProviderAdapter.h"
#include <CoreSignKernel.hpp>
#include "CSSessionCredentialsProviderImpl.h"

using namespace std;

CS::SessionCredentials CSSessionCredentialsProviderImpl::getCredentials(const CS::User::ID& inUserID, const CS::SessionCredentialsProvider::RequestReason inRequestReason) const noexcept
{
    JNIEnv* env = JavaCache::getJNIEnv();

    jint jRequestReason = static_cast<jint>(inRequestReason);

	jclass sessionProviderAdapterClass = env->GetObjectClass(jCSSessionCredentialsProviderAdapter);
    jmethodID getCredentialsMID = env->GetMethodID(sessionProviderAdapterClass, "getCredentials", "(JI)Lcom/simplexsolutionsinc/coresignkernelwrapper/session/CSSessionCredentials;");
    jobject jSessionCredentials = env->CallObjectMethod(jCSSessionCredentialsProviderAdapter, getCredentialsMID, (jlong)inUserID, jRequestReason);

    jclass sessionCredentialsClass = env->GetObjectClass(jSessionCredentials);
    jmethodID getPtrSessionCredentials = env->GetMethodID(sessionCredentialsClass, "getPtr", "()J");
    jlong ptrSessionCredentials = env->CallLongMethod(jSessionCredentials, getPtrSessionCredentials);
    long long lptrSessionCredentials = (long long) ptrSessionCredentials;
    CS::SessionCredentials *sessionCredentialsObj = reinterpret_cast<CS::SessionCredentials*>(lptrSessionCredentials);

    return *sessionCredentialsObj;
}

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_providers_CSSessionCredentialsProviderAdapter
 * Method:    getPtrJNI
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_providers_CSSessionCredentialsProviderAdapter_getPtrJNI
  (JNIEnv *env, jobject jSessionProviderAdapter)
  {
    jobject jSessionProviderAdapterRef = env->NewGlobalRef(jSessionProviderAdapter);
    CSSessionCredentialsProviderImpl *sessionCredentialsProvider = new CSSessionCredentialsProviderImpl(jSessionProviderAdapterRef);
    jlong result = (long long) sessionCredentialsProvider;
    return result;
  }

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_providers_CSSessionCredentialsProviderAdapter
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_providers_CSSessionCredentialsProviderAdapter_destroy
  (JNIEnv *env, jobject provider)
  {
	jclass c = env->GetObjectClass(provider);
	jmethodID getPtr = env->GetMethodID(c, "getPtr", "()J");
	jlong ptr = env->CallLongMethod(provider, getPtr);

	delete reinterpret_cast<CS::SessionCredentialsProvider*>(ptr);
  }
