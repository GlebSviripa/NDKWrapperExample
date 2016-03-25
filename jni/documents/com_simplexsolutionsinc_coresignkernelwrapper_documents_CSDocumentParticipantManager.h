/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager */

#ifndef _Included_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
#define _Included_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    getPtrJNI
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getPtrJNI
  (JNIEnv *, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_destroy
  (JNIEnv *, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    getParticipantCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getParticipantCount
  (JNIEnv *, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    getParticipant
 * Signature: (JLcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)Lcom/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentParticipant;
 */
JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getParticipant
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    getParticipantAtIndex
 * Signature: (I)Lcom/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentParticipant;
 */
JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getParticipantAtIndex
  (JNIEnv *, jobject, jint, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    addParticipant
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentParticipant;Lcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_addParticipant
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    insertParticipantAtIndex
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/documents/CSDocumentParticipant;ILcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_insertParticipantAtIndex
  (JNIEnv *, jobject, jobject, jint, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    removeParticipantAtIndex
 * Signature: (ILcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_removeParticipantAtIndex
  (JNIEnv *, jobject, jint, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    moveParticipant
 * Signature: (IILcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_moveParticipant
  (JNIEnv *, jobject, jint, jint, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager
 * Method:    getNextColor
 * Signature: ()Lcom/simplexsolutionsinc/coresignkernelwrapper/CSColor;
 */
JNIEXPORT jobject JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_documents_CSDocumentParticipantManager_getNextColor
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif