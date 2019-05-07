#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_HardCodingLibraries.h"

jint JNICALL Java_codeSmellsJava_HardCodingLibraries_distance(JNIEnv *env,
		jobject thisObject, jint time, jint speed) {
	return time * speed;
}
