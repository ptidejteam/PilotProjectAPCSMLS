/*
 * Source:
 * https://stackoverflow.com/questions/10617735/in-jni-how-do-i-cache-the-class-methodid-and-fieldids-per-ibms-performance-r/13940735
 */

#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\codeSmellsJava_PassingExcessiveObjects.h"

/**************************************************************
 * Static Global Variables to cache Java Class and Method IDs
 **************************************************************/
static jclass JC_PassingExcessiveObjects;
static jfieldID JMID_PEO_a;
static jfieldID JMID_PEO_b;
static jfieldID JMID_PEO_c;
static jfieldID JMID_PEO_d;
static jfieldID JMID_PEO_e;
static jfieldID JMID_PEO_f;

/**************************************************************
 * Declare JNI_VERSION for use in JNI_Onload/JNI_OnUnLoad
 **************************************************************/
static jint JNI_VERSION = JNI_VERSION_1_8;

/**************************************************************
 * Initialize the static Class and Method Id variables
 **************************************************************/
jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	JNIEnv* env;
	if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION) != JNI_OK) {
		return JNI_ERR;
	}

	jclass tempLocalClassRef;

	tempLocalClassRef = (*env)->FindClass(env,
			"codeSmellsJava/PassingExcessiveObjects");
	if ((*env)->ExceptionCheck(env)) {
		return JNI_ERR;
	}

	JC_PassingExcessiveObjects = (jclass) (*env)->NewGlobalRef(env,
			tempLocalClassRef);

	(*env)->DeleteLocalRef(env, tempLocalClassRef);

	JMID_PEO_a = (*env)->GetFieldID(env, JC_PassingExcessiveObjects, "a", "I");
	JMID_PEO_b = (*env)->GetFieldID(env, JC_PassingExcessiveObjects, "b", "I");
	JMID_PEO_c = (*env)->GetFieldID(env, JC_PassingExcessiveObjects, "c", "I");
	JMID_PEO_d = (*env)->GetFieldID(env, JC_PassingExcessiveObjects, "d", "I");
	JMID_PEO_e = (*env)->GetFieldID(env, JC_PassingExcessiveObjects, "e", "I");
	JMID_PEO_f = (*env)->GetFieldID(env, JC_PassingExcessiveObjects, "f", "I");
	if ((*env)->ExceptionCheck(env)) {
		return JNI_ERR;
	}

	return JNI_VERSION;
}

/**************************************************************
 * Destroy the global static Class Id variables
 **************************************************************/
void JNI_OnUnload(JavaVM *vm, void *reserved) {
	JNIEnv* env;
	(*vm)->GetEnv(vm, (void**) &env, JNI_VERSION);
	(*env)->DeleteGlobalRef(env, JC_PassingExcessiveObjects);
}

jint JNICALL Java_codeSmellsJava_PassingExcessiveObjects_sumValues(JNIEnv* env,
		jobject obj, jobject allValues) {
	jint avalue = (*env)->GetIntField(env, allValues, JMID_PEO_a);
	jint bvalue = (*env)->GetIntField(env, allValues, JMID_PEO_b);
	jint cvalue = (*env)->GetIntField(env, allValues, JMID_PEO_c);
	jint dvalue = (*env)->GetIntField(env, allValues, JMID_PEO_d);
	jint evalue = (*env)->GetIntField(env, allValues, JMID_PEO_e);
	jint fvalue = (*env)->GetIntField(env, allValues, JMID_PEO_f);
	return avalue + bvalue + cvalue + dvalue + evalue + fvalue;
}
