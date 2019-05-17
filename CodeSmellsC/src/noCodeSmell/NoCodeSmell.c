#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\noCodeSmell_NoCodeSmell.h"

/****************************************** Sayhello ******************************/

JNIEXPORT jstring JNICALL Java_noCodeSmell_NoCodeSmell_sayHello(JNIEnv *env,
		jobject thisObj, jstring inJNIStr) {
	// Step 1: Convert the JNI String (jstring) into C-String (char*)
	const char *inCStr = (*env)->GetStringUTFChars(env, inJNIStr, NULL);
	//  if (NULL == inCSt) return NULL;

	// Step 2: Perform its intended operations
	printf("In C, the received string is: %s\n", inCStr);
	(*env)->ReleaseStringUTFChars(env, inJNIStr, inCStr);  // release resources

	// Prompt user for a C-string
	char outCStr[128];
	printf("Enter a String: ");
	scanf("%s", outCStr);    // not more than 127 characters

	// Step 3: Convert the C-string (char*) into JNI String (jstring) and return
	return (*env)->NewStringUTF(env, outCStr);
}

/****************************************** Average ******************************/
JNIEXPORT jdouble JNICALL Java_noCodeSmell_NoCodeSmell_average(JNIEnv *env,
		jobject thisObj, jint n1, jint n2) {
	jdouble result;
	printf("In C, the numbers are %ld and %ld\n", n1, n2);
	result = ((jdouble) n1 + n2) / 2.0;
	return result;
}

/****************************************** AccessValue ******************************/

JNIEXPORT void JNICALL Java_noCodeSmell_NoCodeSmell_modifyInstanceVariable(
		JNIEnv *env, jobject thisObj) {
	// Get a reference to this object's class
	jclass thisClass = (*env)->GetObjectClass(env, thisObj);

	// int
	// Get the Field ID of the instance variables "number"
	jfieldID fidNumber = (*env)->GetFieldID(env, thisClass, "number", "I");
	if (NULL == fidNumber)
		return;

	// Get the int given the Field ID
	jint number = (*env)->GetIntField(env, thisObj, fidNumber);
	printf("In C, the int is %ld\n", number);

	// Change the variable
	number = 99;
	(*env)->SetIntField(env, thisObj, fidNumber, number);

	// Get the Field ID of the instance variables "message"
	jfieldID fidMessage = (*env)->GetFieldID(env, thisClass, "message",
			"Ljava/lang/String;");
	if (NULL == fidMessage)
		return;

	// String
	// Get the object given the Field ID
	jstring message = (*env)->GetObjectField(env, thisObj, fidMessage);

	// Create a C-string with the JNI String
	const char *cStr = (*env)->GetStringUTFChars(env, message, NULL);
	if (NULL == cStr)
		return;

	printf("In C, the string is %s\n", cStr);
	(*env)->ReleaseStringUTFChars(env, message, cStr);

	// Create a new C-string and assign to the JNI string
	message = (*env)->NewStringUTF(env, "Hello from C");
	if (NULL == message)
		return;

	// modify the instance variables
	(*env)->SetObjectField(env, thisObj, fidMessage, message);
}
// nanomsg, libcurl

/************************** Array *****************************/

JNIEXPORT jdoubleArray JNICALL Java_noCodeSmell_NoCodeSmell_sumAndAverage(
		JNIEnv *env, jobject thisObj, jintArray inJNIArray) {
	// Step 1: Convert the incoming JNI jintarray to C's jint[]
	jint *inCArray = (*env)->GetIntArrayElements(env, inJNIArray, NULL);
	if (NULL == inCArray)
		return NULL;
	jsize length = (*env)->GetArrayLength(env, inJNIArray);

	// Step 2: Perform its intended operations
	jint sum = 0;
	int i;
	for (i = 0; i < length; i++) {
		sum += inCArray[i];
	}
	jdouble average = (jdouble) sum / length;
	(*env)->ReleaseIntArrayElements(env, inJNIArray, inCArray, 0); // release resources

	jdouble outCArray[] = { sum, average };

	// Step 3: Convert the C's Native jdouble[] to JNI jdoublearray, and return
	jdoubleArray outJNIArray = (*env)->NewDoubleArray(env, 2);  // allocate
	if (NULL == outJNIArray)
		return NULL;
	(*env)->SetDoubleArrayRegion(env, outJNIArray, 0, 2, outCArray);  // copy
	return outJNIArray;
}
