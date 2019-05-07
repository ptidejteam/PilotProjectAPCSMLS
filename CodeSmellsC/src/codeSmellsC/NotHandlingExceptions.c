/*
 * Source:
 * https://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html
 */

#include <jni.h>
#include <stdio.h>
#include <string.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_NotHandlingExceptions.h"

JNIEXPORT jchar JNICALL Java_codeSmellsJava_NotHandlingExceptions_getCharField(
		JNIEnv *env, jobject obj, jstring fieldName) {
	jclass objectClass;
	jfieldID fieldID;
	jchar result = 0;
	objectClass = (*env)->GetObjectClass(env, obj);
	const char *name = (*env)->GetStringUTFChars(env, fieldName, NULL);
	fieldID = (*env)->GetFieldID(env, objectClass, name, "C");
	(*env)->ReleaseStringUTFChars(env, fieldName, name);
	result = (*env)->GetCharField(env, obj, fieldID);
	return result;
}
