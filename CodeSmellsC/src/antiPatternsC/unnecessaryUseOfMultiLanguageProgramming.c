#include <jni.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\antiPatternsJava_unnecessaryUseOfMultiLanguageProgramming_UserFactory.h"

JNIEXPORT jobject JNICALL Java_antiPatternsJava_unnecessaryUseOfMultiLanguageProgramming_UserFactory_createUser(
		JNIEnv *env, jobject thisObject, jstring name, jdouble balance) {
	// Create the object of the class User
	jclass userClass = (*env)->FindClass(env,
			"antiPatternsJava/unnecessaryUseOfMultiLanguageProgramming/User");
	jobject newUser = (*env)->AllocObject(env, userClass);
	// Get the User fields to be set jfieldID
	jfieldID nameField = (*env)->GetFieldID(env, userClass, "name",
			"Ljava/lang/String;");
	jfieldID balanceField = (*env)->GetFieldID(env, userClass, "balance", "D");
	(*env)->SetObjectField(env, newUser, nameField, name);
	(*env)->SetDoubleField(env, newUser, balanceField, balance);
	return newUser;
}
