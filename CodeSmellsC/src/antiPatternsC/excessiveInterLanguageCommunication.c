#include <jni.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\antiPatternsJava_ExcessiveInterLanguageCommunication_excessiveInterLanguageCommunication.h"

JNIEXPORT jint JNICALL Java_antiPatternsJava_excessiveInterLanguageCommunication_ExcessiveInterLanguageCommunication_square(
		JNIEnv*env, jobject obj, jint n) {
	return n * n;
}
