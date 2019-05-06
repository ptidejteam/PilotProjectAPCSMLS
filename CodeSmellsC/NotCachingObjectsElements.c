// Source: https://www.ibm.com/developerworks/library/j-jni/index.html

#include <jni.h>
#include <stdio.h>

#include "..\CodeSmellsJNI\bin\codeSmellsJava_NotCachingObjectsElements.h"

jint JNICALL Java_codeSmellsJava_NotCachingObjectsElements_sumValues(
		JNIEnv* env, jobject obj) {
	jclass cls = (*env)->GetObjectClass(env, obj);
	jfieldID a = (*env)->GetFieldID(env, cls, "a", "I");
	jfieldID b = (*env)->GetFieldID(env, cls, "b", "I");
	jfieldID c = (*env)->GetFieldID(env, cls, "c", "I");
	jfieldID d = (*env)->GetFieldID(env, cls, "d", "I");
	jfieldID e = (*env)->GetFieldID(env, cls, "e", "I");
	jfieldID f = (*env)->GetFieldID(env, cls, "f", "I");
	jint avalue = (*env)->GetIntField(env, obj, a);
	jint bvalue = (*env)->GetIntField(env, obj, b);
	jint cvalue = (*env)->GetIntField(env, obj, c);
	jint dvalue = (*env)->GetIntField(env, obj, d);
	jint evalue = (*env)->GetIntField(env, obj, e);
	jint fvalue = (*env)->GetIntField(env, obj, f);
	return avalue + bvalue + cvalue + dvalue + evalue + fvalue;
}
