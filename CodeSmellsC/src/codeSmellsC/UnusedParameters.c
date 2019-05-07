#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_UnusedParameters.h"

jint JNICALL Java_codeSmellsJava_UnusedParameters_distance(JNIEnv *env,
		jobject thisObject, jint time, jint speed, jint acceleration,
		jint fuelVolume) {
	return time * speed;
}
