#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_NotCachingObjectsElements_User.h"

static jint lastGroup = 0;

JNIEXPORT void JNICALL Java_codeSmellsJava_NotCachingObjectsElements_00024User_setGroup(
		JNIEnv *env, jobject user, jint group) {
	jclass userClass = (*env)->FindClass(env,
			"codeSmellsJava/NotCachingObjectsElements$User");
	jfieldID field = (*env)->GetFieldID(env, userClass, "group", "I");
	(*env)->SetIntField(env, user, field, group);
	lastGroup = group;
}

JNIEXPORT void JNICALL Java_codeSmellsJava_NotCachingObjectsElements_00024User_checkGroup(
		JNIEnv *env, jobject user) {
	jclass userClass = (*env)->FindClass(env,
			"codeSmellsJava/NotCachingObjectsElements$User");
	jfieldID field = (*env)->GetFieldID(env, userClass, "group", "I");
	jint group = (*env)->GetIntField(env, user, field);
	if (group == lastGroup)
		printf("User from group %ld: last group\n", group);
	else
		printf("User from group %ld: not last group\n", group);
}
