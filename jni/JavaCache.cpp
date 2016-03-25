#include "JavaCache.h"
#include <memory>
#include <pthread.h>


static JavaVM* mJVM = 0;

static pthread_key_t pthread_key;
jclass eventClass = NULL;
jclass eventDocumentClass = NULL;
jmethodID listenerHandleEvent = NULL;

static void detach_current_thread (void *env) {
    mJVM->DetachCurrentThread();
}
extern "C" jint JNI_OnLoad(JavaVM *vm, void *reserved)
{

	JavaVMAttachArgs attachArgs;
	    attachArgs.version = JNI_VERSION_1_6;
	    attachArgs.name = ">>>NativeThread__Any";
	    attachArgs.group = NULL;
	    JNIEnv* env;
	    if (vm->AttachCurrentThread(&env, &attachArgs) != JNI_OK) {
	        LOGI("AttachCurrentThread != JNI_OK");
	        env = NULL;
	    }
	    jclass tmpEventClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/listeners/CSEvent");
	    eventClass = (jclass)env->NewGlobalRef(tmpEventClass);
	    tmpEventClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/listeners/CSDocumentEvent");
	    eventDocumentClass = (jclass)env->NewGlobalRef(tmpEventClass);

	    jclass tmpListenerAdapterClass = env->FindClass("com/simplexsolutionsinc/coresignkernelwrapper/listeners/CSListenerAdapter");
	    listenerHandleEvent = env->GetMethodID(tmpListenerAdapterClass, "handleEvent", "(Lcom/simplexsolutionsinc/coresignkernelwrapper/listeners/CSEvent;)V");
	    LOGI("FIND CLASS");
	return JNI_VERSION_1_6;
}
JavaCache::JavaCache(JNIEnv* pJniEnv)
{
    if(mJVM==0){
        LOGI("init mJVM");
        pJniEnv->GetJavaVM(&mJVM);
        LOGI("pthread_key_create");
        pthread_key_create(&pthread_key, detach_current_thread);

        LOGI("init global defines");
        JNIEnv* jniEnv = getJNIEnv();
    }
}


JavaVM* const JavaCache::getJVM()
{
    return mJVM;
}

JNIEnv* const JavaCache::getJNIEnv()
{
    JNIEnv *env;
    if ((env = (JNIEnv*)pthread_getspecific(pthread_key)) == NULL) {
        LOGI("getJNIEnv() attach to current thread");
        env = getJniEnv(getJVM());
        if(env){
            LOGI("attach successful!");
        }
        pthread_setspecific(pthread_key, env);
    }
    return env;
}

JNIEnv* JavaCache::getJniEnv(JavaVM* mJVM)
{
    JavaVMAttachArgs attachArgs;
    attachArgs.version = JNI_VERSION_1_6;
    attachArgs.name = ">>>NativeThread__Any";
    attachArgs.group = NULL;
    JNIEnv* env;
    if (mJVM->AttachCurrentThread(&env, &attachArgs) != JNI_OK) {
        LOGI("AttachCurrentThread != JNI_OK");
        env = NULL;
    }
    return env;
}
