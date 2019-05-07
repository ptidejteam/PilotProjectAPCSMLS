#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_NotSecuringLibraries.h"

jint JNICALL Java_codeSmellsJava_NotSecuringLibraries_distance(JNIEnv *env,
		jobject thisObject, jint time, jint speed) {
	return time * speed;
}
