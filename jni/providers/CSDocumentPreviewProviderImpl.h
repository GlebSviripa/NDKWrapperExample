#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include "DocumentPreviewProvider.hpp"

class CSDocumentPreviewProviderImpl:public CS::DocumentPreviewProvider
{
private:
    jobject jCSDocumentPreviewProviderAdapter;
public:

    CS::Image previewForDocument(const CS::Document::Ptr& inDocument) const noexcept override;

    CSDocumentPreviewProviderImpl(jobject _jCSDocumentPreviewProviderAdapter)
    {
        jCSDocumentPreviewProviderAdapter = _jCSDocumentPreviewProviderAdapter;
    }

    ~CSDocumentPreviewProviderImpl() {}
};
