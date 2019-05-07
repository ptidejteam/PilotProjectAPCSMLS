#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_LocalReferencesAbuse.h"

jint JNICALL Java_codeSmellsJava_LocalReferencesAbuse_isAnyElementNull(
		JNIEnv *env, jobject thisObject, jobjectArray anArray) {
	jsize length = (*env)->GetArrayLength(env, anArray);
	for (int i = 0; i < length; i++) {
		jobject element = (*env)->GetObjectArrayElement(env, anArray, i);
		if ((*env)->ExceptionOccurred(env)) {
			return -1;
		}
		if (element == NULL) {
			return 1;
		}
	}
	return 0;
}
