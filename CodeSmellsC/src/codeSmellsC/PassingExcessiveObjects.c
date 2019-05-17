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
static jclass JC_PassingExcessiveObjects_User;
static jfieldID JMID_PEO_brutto;
static jfieldID JMID_PEO_federal;
static jfieldID JMID_PEO_state;

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
			"codeSmellsJava/PassingExcessiveObjects$User");
	if ((*env)->ExceptionCheck(env)) {
		return JNI_ERR;
	}

	JC_PassingExcessiveObjects_User = (jclass) (*env)->NewGlobalRef(env,
			tempLocalClassRef);

	(*env)->DeleteLocalRef(env, tempLocalClassRef);

	JMID_PEO_brutto = (*env)->GetFieldID(env, JC_PassingExcessiveObjects_User,
			"bruttoSalary", "I");
	JMID_PEO_federal = (*env)->GetFieldID(env, JC_PassingExcessiveObjects_User,
			"federalTax", "I");
	JMID_PEO_state = (*env)->GetFieldID(env, JC_PassingExcessiveObjects_User,
			"stateTax", "I");

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
	(*env)->DeleteGlobalRef(env, JC_PassingExcessiveObjects_User);
}

jint JNICALL Java_codeSmellsJava_PassingExcessiveObjects_getNettoSalary(
		JNIEnv *env, jobject obj, jobject user) {
	jint brutto = (*env)->GetIntField(env, user, JMID_PEO_brutto);
	jint federal = (*env)->GetIntField(env, user, JMID_PEO_federal);
	jint state = (*env)->GetIntField(env, user, JMID_PEO_state);
	return brutto - federal - state;
}
