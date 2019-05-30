/*
 * Source:
 * https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html
 */

#include <jni.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_AssumingSelfMultiLanguageReturnValues.h"

JNIEXPORT void JNICALL Java_codeSmellsJava_AssumingSelfMultiLanguageReturnValues_callMethodOutputFromClass(
		JNIEnv *env, jobject obj) {
	jclass clazz = (*env)->FindClass(env,
			"codeSmellsJava/AssumingSelfMultiLanguageReturnValues");
	jmethodID method = (*env)->GetStaticMethodID(env, clazz, "output", "()V"); // Method not existing
	(*env)->CallStaticVoidMethod(env, clazz, method, NULL);
}
