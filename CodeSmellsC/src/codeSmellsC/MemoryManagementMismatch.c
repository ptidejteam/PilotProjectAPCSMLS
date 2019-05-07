#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_MemoryManagementMismatch.h"

JNIEXPORT void JNICALL Java_codeSmellsJava_MemoryManagementMismatch_printStringInC(
		JNIEnv *env, jobject thisObj, jstring inJNIStr) {
	const char *inCStr = (*env)->GetStringUTFChars(env, inJNIStr, NULL);
	printf("In C, the received string is: %s\n", inCStr);
}
