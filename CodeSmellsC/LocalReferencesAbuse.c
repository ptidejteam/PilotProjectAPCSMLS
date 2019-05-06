#include <jni.h>
#include <stdio.h>

#include "..\CodeSmellsJNI\bin\codeSmellsJava_LocalReferencesAbuse.h"

jint JNICALL Java_codeSmellsJava_LocalReferencesAbuse_goThroughArray
(JNIEnv *env, jobject thisObject, jobjectArray anArray) {
	jsize length = (*env)->GetArrayLength(env, anArray);
	for (int i=0; i < length; i++) {
		jobject element = (*env)->GetObjectArrayElement(env, anArray,i);
		if((*env)->ExceptionOccurred(env)) { break;}
	}
	return 0;
}
