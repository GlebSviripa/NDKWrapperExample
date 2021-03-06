/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage */

#ifndef _Included_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
#define _Included_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_init
  (JNIEnv *, jclass);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_destroy
  (JNIEnv *, jclass);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    hasInitials
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_hasInitials
  (JNIEnv *, jclass);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    getInitialsPath
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_getInitialsPath
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    setInitialsPath
 * Signature: (Ljava/lang/String;Ljava/lang/String;Lcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_setInitialsPath
  (JNIEnv *, jclass, jstring, jstring, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    getInitialsPreviewPath
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_getInitialsPreviewPath
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    hasSignature
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_hasSignature
  (JNIEnv *, jclass);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    getSignaturePath
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_getSignaturePath
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    setSignaturePath
 * Signature: (Ljava/lang/String;Ljava/lang/String;Lcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)V
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_setSignaturePath
  (JNIEnv *, jclass, jstring, jstring, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    getSignaturePreviewPath
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_getSignaturePreviewPath
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    addListener
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/listeners/CSListenerAdapter;)Lcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_addListener
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage
 * Method:    removeListener
 * Signature: (Lcom/simplexsolutionsinc/coresignkernelwrapper/listeners/CSListenerAdapter;)Lcom/simplexsolutionsinc/coresignkernelwrapper/CSResult;
 */
JNIEXPORT void JNICALL Java_com_simplexsolutionsinc_coresignkernelwrapper_CSLegalsStorage_removeListener
  (JNIEnv *, jclass, jobject, jobject);
#ifdef __cplusplus
}
#endif
#endif
