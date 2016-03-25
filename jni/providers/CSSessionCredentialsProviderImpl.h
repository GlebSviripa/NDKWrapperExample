#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "SessionCredentialsProvider.hpp"

class CSSessionCredentialsProviderImpl:public CS::SessionCredentialsProvider
{
private:
    jobject jCSSessionCredentialsProviderAdapter;
public:

    CS::SessionCredentials getCredentials(const CS::User::ID& inUserID,  const CS::SessionCredentialsProvider::RequestReason inRequestReason) const noexcept override;
    CSSessionCredentialsProviderImpl(jobject _jCSSessionCredentialsProviderAdapter)
    {
        jCSSessionCredentialsProviderAdapter = _jCSSessionCredentialsProviderAdapter;
    }

    ~CSSessionCredentialsProviderImpl() {}
};
