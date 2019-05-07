#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_NotUsingRelativePath.h"

jint JNICALL Java_codeSmellsJava_NotUsingRelativePath_distance(JNIEnv *env,
		jobject thisObject, jint time, jint speed) {
	return time * speed;
}
