LOCAL_PATH := $(call my-dir)
REPO_PATH := /home/gleb/workspace/simplex-common-android
WRAPPER_SRC := $(REPO_PATH)/CoreSignMain/CoreSignKernelWrapper/jni
KERNEL_SRC_PATH := /home/gleb/workspace/CoreSign-Kernel
include $(CLEAR_VARS)
LIB_PATH := /home/gleb/workspace/CoreSignKernel_Libs/libs
JNI_DIR := $(LOCAL_PATH)

include $(CLEAR_VARS)
SQLITE := $(LIB_PATH)/sqlite/lib/$(TARGET_ARCH_ABI)
LOCAL_MODULE := libsqlite
LOCAL_SRC_FILES := $(SQLITE)/libsqlite.a
include $(PREBUILT_STATIC_LIBRARY)


include $(CLEAR_VARS)
OPEN_SSL := $(LIB_PATH)/openssl/lib/$(TARGET_ARCH_ABI)
LOCAL_MODULE := libssl
LOCAL_SRC_FILES := $(OPEN_SSL)/libssl.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
PROTOBUF := $(LIB_PATH)/protobuf/lib/$(TARGET_ARCH_ABI)
LOCAL_MODULE := libprotobuf
LOCAL_SRC_FILES := $(PROTOBUF)/libprotobuf.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
CURL := $(LIB_PATH)/c-url/lib/$(TARGET_ARCH_ABI)
LOCAL_MODULE := libcurl
LOCAL_SRC_FILES := $(CURL)/libcurl.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
CRYSTAX := $(LIB_PATH)/crystax/libs/$(TARGET_ARCH_ABI)
LOCAL_MODULE := libcrystax
LOCAL_SRC_FILES := $(CRYSTAX)/libcrystax.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
KERNEL := $(LIB_PATH)/$(TARGET_ARCH_ABI)
LOCAL_MODULE := libCoreSignKernel
LOCAL_SRC_FILES := $(KERNEL)/libCoreSignKernel.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_CFLAGS +=-D__GXX_EXPERIMENTAL_CXX0X__

                    
PROJECT_INCLUDES :=  /home/gleb/workspace/CoreSignKernel_Libs/libs

PROTOBUF_HEADERS_PATH := $(PROJECT_INCLUDES)/protobuf/include
##SQLCIPHER_HEADERS_PATH := $(PROJECT_INCLUDES)/sqlcipher/include \
##                            $(PROJECT_INCLUDES)/sqlcipher/include/sqlcipher
OPENSSL_HEADERS_PATH := $(PROJECT_INCLUDES)/openssl/include
SDSQL_LITE_HEADERS_PATH := $(PROJECT_INCLUDES)/sdsqlite
CoreSign_Proto_HEADERS_PATH := /home/gleb/workspace/CoreSign-Kernel/CoreSign-Proto
CoreSign_Network_HEADERS_PATH := /home/gleb/workspace/CoreSign-Kernel/CoreSign-Network
CoreSign_Encyption_HEADERS_PATH := /home/gleb/workspace/CoreSign-Kernel/CoreSign-Encryption
CURL_HEADERS_PATH := $(PROJECT_INCLUDES)/c-url/include
CRYSTAX_HEADERS_PATH := $(PROJECT_INCLUDES)/crystax/include

NDK_PATH :=  /home/gleb/bin/crystax-ndk-10.1.0/crystax-ndk-10.1.0

LOCAL_C_INCLUDES := $(PROTOBUF_HEADERS_PATH) \
		    $(OPENSSL_HEADERS_PATH) \
                    $(SQLCIPHER_HEADERS_PATH) \
		    $(SDSQL_LITE_HEADERS_PATH) \
		    $(CoreSign_Proto_HEADERS_PATH) \
			$(CoreSign_Proto_HEADERS_PATH)/protobuf/coresign/cpp \
            $(CoreSign_Proto_HEADERS_PATH)/coresign_types \
			$(CoreSign_Encyption_HEADERS_PATH) \
		    $(CURL_HEADERS_PATH) \
			$(CoreSign_Network_HEADERS_PATH)/ \
			$(CoreSign_Network_HEADERS_PATH)/Asio/asio/include \
			$(CoreSign_Network_HEADERS_PATH)/coresign-network \
		    /home/gleb/workspace/CoreSign-Kernel/libs/json/src \
	   	    /home/gleb/workspace/CoreSign-Kernel/include \
            /home/gleb/workspace/CoreSign-Kernel/src/ \
			/home/gleb/workspace/CoreSign-Kernel/src/Models \
			/home/gleb/workspace/CoreSign-Kernel/src/Documents \
			/home/gleb/workspace/CoreSign-Kernel/src/Files \
			/home/gleb/workspace/CoreSign-Kernel/src/Session \
			/home/gleb/workspace/CoreSign-Kernel/src/Storage \
			/home/gleb/workspace/CoreSign-Kernel/include/Base \
			/home/gleb/workspace/CoreSign-Kernel/include/Events \
			/home/gleb/workspace/CoreSign-Kernel/include/Annotations \
			/home/gleb/workspace/CoreSign-Kernel/include/Documents \
			/home/gleb/workspace/CoreSign-Kernel/include/Session \
		    /home/gleb/workspace/CoreSign-Kernel/CoreSign-Proto \
		    /home/gleb/workspace/CoreSign-Kernel/libs/sqlcipher/include \
		    /home/gleb/workspace/CoreSign-Kernel/libs/sdsqlite \
			/home/gleb/workspace/CoreSign-Kernel/libs/fileutils \
            /home/gleb/workspace/CoreSign-Kernel/libs/include/Remote \
			/home/gleb/workspace/CoreSign-Kernel/libs \
		    $(CRYSTAX_HEADERS_PATH)

LOCAL_MODULE    := CoreSignKernelWrapper

LOCAL_SRC_FILES += JavaCache.cpp

##SESSION
LOCAL_SRC_FILES += session/com_simplexsolutionsinc_coresignkernelwrapper_session_CSServer.cpp
LOCAL_SRC_FILES += session/com_simplexsolutionsinc_coresignkernelwrapper_session_CSSession.cpp
LOCAL_SRC_FILES += session/com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionConfig.cpp
LOCAL_SRC_FILES += session/com_simplexsolutionsinc_coresignkernelwrapper_session_CSSessionCredentials.cpp
LOCAL_SRC_FILES += session/com_simplexsolutionsinc_coresignkernelwrapper_session_CSUserKeys.cpp
LOCAL_SRC_FILES += session/com_simplexsolutionsinc_coresignkernelwrapper_session_CSUser.cpp


##LEGALS_STORAGE
LOCAL_SRC_FILES += com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage.cpp

##DOCUMENTS
LOCAL_SRC_FILES += documents/com_simplexsolutionsinc_coresignkernelwrapper_documents_CSByNameDocumentFilter.cpp
LOCAL_SRC_FILES += documents/com_simplexsolutionsinc_coresignkernelwrapper_documents_CSBySignerDocumentFilter.cpp
LOCAL_SRC_FILES += documents/com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocument.cpp
LOCAL_SRC_FILES += documents/com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentID.cpp
LOCAL_SRC_FILES += documents/com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentContent.cpp
LOCAL_SRC_FILES += documents/com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentManager.cpp
LOCAL_SRC_FILES += documents/com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipant.cpp
LOCAL_SRC_FILES += documents/com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager.cpp
LOCAL_SRC_FILES += documents/com_simplexsolutionsinc_coresignkernelwrapper_documents_CSPDF.cpp

##ANNOTATIONS
LOCAL_SRC_FILES += annotations/com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotation.cpp
LOCAL_SRC_FILES += annotations/com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationID.cpp
LOCAL_SRC_FILES += annotations/com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSAnnotationStore.cpp
LOCAL_SRC_FILES += annotations/com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSCheckboxAnnotation.cpp
LOCAL_SRC_FILES += annotations/com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSDateAnnotation.cpp
LOCAL_SRC_FILES += annotations/com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSInitialsAnnotation.cpp
LOCAL_SRC_FILES += annotations/com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSSignatureAnnotation.cpp
LOCAL_SRC_FILES += annotations/com_simplexsolutionsinc_coresignkernelwrapper_annotations_CSTextAnnotation.cpp


##TEMPLATES
LOCAL_SRC_FILES += templates/com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplate.cpp
LOCAL_SRC_FILES += templates/com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateAuthor.cpp
LOCAL_SRC_FILES += templates/com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateFilter.cpp
LOCAL_SRC_FILES += templates/com_simplexsolutionsinc_coresignkernelwrapper_templates_CSByAuthorTemplateFilter.cpp
LOCAL_SRC_FILES += templates/com_simplexsolutionsinc_coresignkernelwrapper_templates_CSStringQueryTemplateFilter.cpp
LOCAL_SRC_FILES += templates/com_simplexsolutionsinc_coresignkernelwrapper_templates_CSCompositeTemplateFilter.cpp
LOCAL_SRC_FILES += templates/com_simplexsolutionsinc_coresignkernelwrapper_templates_CSTemplateManager.cpp

##PROVIDERS
LOCAL_SRC_FILES += providers/com_simplexsolutionsinc_coresignkernelwrapper_providers_CSSessionCredentialsProviderAdapter.cpp
LOCAL_SRC_FILES += providers/com_simplexsolutionsinc_coresignkernelwrapper_providers_CSDocumentPreviewAdapter.cpp

##LISTENERS
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentImageEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentParticipantEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentProgressEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentResultEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSLegalsEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSListenerAdapter.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSSessionEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateImageEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateProgressEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSTemplateResultEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSDocumentAnnotationEvent.cpp
LOCAL_SRC_FILES += listeners/com_simplexsolutionsinc_coresignkernelwrapper_listeners_CSBroadcaster.cpp

LOCAL_LDFLAGS += -llog
LOCAL_STATIC_LIBRARIES := 	libsqlite \
							libssl \
							libcrypto \
                            libprotobuf \
							libcurl \
							libcrystax
							  
							
LOCAL_SHARED_LIBRARIES := libCoreSignKernel
##						  libdatabase_sqlcipher \
##                          libsqlcipher_android
##			    		  libstlport_shared
			    		  
			      

include $(BUILD_SHARED_LIBRARY)
