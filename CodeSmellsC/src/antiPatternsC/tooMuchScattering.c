#include <jni.h>
#include <stdio.h>

#include "..\..\..\CodeSmellsJNI\bin\headers\antiPatternsJava_tooMuchScattering_RGB888Image.h"
#include "..\..\..\CodeSmellsJNI\bin\headers\antiPatternsJava_tooMuchScattering_YUV420Image.h"
#include "..\..\..\CodeSmellsJNI\bin\headers\antiPatternsJava_tooMuchScattering_YUV444Image.h"

void copyWidthHeight(JNIEnv *env, jclass imageClass, jobject thisImage,
		jobject image) {
	const char *fields[] = { "width", "height" };
	int i;
	for (i = 0; i < 2; i++) {
		jfieldID field = (*env)->GetFieldID(env, imageClass, fields[i], "I");
		jint value = (*env)->GetIntField(env, thisImage, field);
		(*env)->SetIntField(env, image, field, value);
	}
}

JNIEXPORT jobject JNICALL Java_antiPatternsJava_tooMuchScattering_RGB888Image_toYuv420(
		JNIEnv *env, jobject thisImage) {
	jclass imageClass = (*env)->FindClass(env,
			"antiPatternsJava/tooMuchScattering/YUV420Image");
	jobject image = (*env)->AllocObject(env, imageClass);
	copyWidthHeight(env, imageClass, thisImage, image); // transform RGB888 to YUV420 format ...
	return image;
}

JNIEXPORT jobject JNICALL Java_antiPatternsJava_tooMuchScattering_RGB888Image_toYuv444(
		JNIEnv *env, jobject thisImage) {
	jclass imageClass = (*env)->FindClass(env,
			"antiPatternsJava/tooMuchScattering/YUV444Image");
	jobject image = (*env)->AllocObject(env, imageClass);
	copyWidthHeight(env, imageClass, thisImage, image); // transform RGB888 to YUV444 format ...
	return image;
}

JNIEXPORT jobject JNICALL Java_antiPatternsJava_tooMuchScattering_YUV420Image_toRgb888(
		JNIEnv *env, jobject thisImage) {
	jclass imageClass = (*env)->FindClass(env,
			"antiPatternsJava/tooMuchScattering/RGB888Image");
	jobject image = (*env)->AllocObject(env, imageClass);
	copyWidthHeight(env, imageClass, thisImage, image); // transform YUV420 to RGB888 format ...
	return image;
}

JNIEXPORT jobject JNICALL Java_antiPatternsJava_tooMuchScattering_YUV420Image_toYuv444(
		JNIEnv *env, jobject thisImage) {
	jclass imageClass = (*env)->FindClass(env,
			"antiPatternsJava/tooMuchScattering/YUV444Image");
	jobject image = (*env)->AllocObject(env, imageClass);
	copyWidthHeight(env, imageClass, thisImage, image); // transform YUV420 to YUV444 format ...
	return image;
}

JNIEXPORT jobject JNICALL Java_antiPatternsJava_tooMuchScattering_YUV444Image_toRgb888(
		JNIEnv *env, jobject thisImage) {
	jclass imageClass = (*env)->FindClass(env,
			"antiPatternsJava/tooMuchScattering/RGB888Image");
	jobject image = (*env)->AllocObject(env, imageClass);
	copyWidthHeight(env, imageClass, thisImage, image); // transform YUV444 to RGB888 format ...
	return image;
}

JNIEXPORT jobject JNICALL Java_antiPatternsJava_tooMuchScattering_YUV444Image_toYuv420(
		JNIEnv *env, jobject thisImage) {
	jclass imageClass = (*env)->FindClass(env,
			"antiPatternsJava/tooMuchScattering/YUV420Image");
	jobject image = (*env)->AllocObject(env, imageClass);
	copyWidthHeight(env, imageClass, thisImage, image); // transform YUV444 to YUV420 format ...
	return image;
}
