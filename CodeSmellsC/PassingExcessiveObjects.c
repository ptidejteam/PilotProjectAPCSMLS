// Source: https://www.ibm.com/developerworks/library/j-jni/index.html

#include <jni.h>
#include <stdio.h>

#include "..\CodeSmellsJNI\bin\codeSmellsJava_PassingExcessiveObjects.h"

jint JNICALL Java_codeSmellsJava_PassingExcessiveObjects_sumValues(JNIEnv* env,
		jobject obj, jobject allValues) {
	jclass cls = (*env)->GetObjectClass(env, allValues);
	jfieldID a = (*env)->GetFieldID(env, cls, "a", "I");
	jfieldID b = (*env)->GetFieldID(env, cls, "b", "I");
	jfieldID c = (*env)->GetFieldID(env, cls, "c", "I");
	jfieldID d = (*env)->GetFieldID(env, cls, "d", "I");
	jfieldID e = (*env)->GetFieldID(env, cls, "e", "I");
	jfieldID f = (*env)->GetFieldID(env, cls, "f", "I");
	jint avalue = (*env)->GetIntField(env, allValues, a);
	jint bvalue = (*env)->GetIntField(env, allValues, b);
	jint cvalue = (*env)->GetIntField(env, allValues, c);
	jint dvalue = (*env)->GetIntField(env, allValues, d);
	jint evalue = (*env)->GetIntField(env, allValues, e);
	jint fvalue = (*env)->GetIntField(env, allValues, f);
	return avalue + bvalue + cvalue + dvalue + evalue + fvalue;
}
