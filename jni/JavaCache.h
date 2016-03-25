#pragma once
#include <jni.h>
#include <android/log.h>
#include <CoreSignKernel.hpp>
#define LOG_TAG "JavaCache"
#define LOGI(x...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG,x)
#define printf(...) __android_log_print(ANDROID_LOG_DEBUG, "TAG", __VA_ARGS__);

extern jclass eventClass;
extern jclass eventDocumentClass;
extern jmethodID listenerHandleEvent;
class JavaCache
{
public:

    JavaCache(JNIEnv* pJniEnv);
    static JavaVM* const getJVM();
    static JNIEnv* const getJNIEnv();
    static JNIEnv* getJniEnv(JavaVM* mJVM);

   /* static jobject convertCLTaskToJTask(CLTask& task);
    static jobject convertCLTaskPtrToJTask(CLTaskPtr task);
    static CLTask convertJTaskToCLTask(jobject jTask);
    static jobject convertCLTaskListToJTaskList(CLTaskList& list);
    static CLTaskList convertJTaskListToCLTaskList(jobject jTaskList);
    static jobject convertCLCredentialsToJCredentials(const CLCredentials& credentials);
    static CLCredentials convertJCredentialsToCLCredentials(jobject jCredentials);
    static void convertJExtAuthCredentialsToExtAuthCredentials(jobject jExtAuthCredentials, ExtAuthCredentials& extAuthCredentials);*/
//    static jobject convertCUserInfoToJCUserInfo(const CUserInfo& cUserInfo);
//private:
};
