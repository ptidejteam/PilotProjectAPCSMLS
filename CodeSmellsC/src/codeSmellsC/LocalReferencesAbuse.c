#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_LocalReferencesAbuse.h"

jint JNICALL Java_codeSmellsJava_LocalReferencesAbuse_isAnyElementNull(
		JNIEnv *env, jobject thisObject, jobjectArray anArray) {
	jsize length = (*env)->GetArrayLength(env, anArray);
	int i;
	for (i = 0; i < length; i++) {
		jobject element = (*env)->GetObjectArrayElement(env, anArray, i);
		jobject element2 = (*env)->GetObjectArrayElement(env, anArray, i);
		(*env)->DeleteLocalRef(env, element2);
		if ((*env)->ExceptionOccurred(env)) {
			(*env)->ExceptionClear();
			return -1;
		}
		if (element == NULL) {
			return 1;
		}
	}
	return 0;
}
