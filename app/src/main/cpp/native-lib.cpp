#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_pm_nativeapp01_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}



//New Java String from a Given C String
extern "C" JNIEXPORT jstring JNICALL
Java_com_pm_nativeapp01_MainActivity_JavaStringFromC(
        JNIEnv *env, jobject /* this */) {
    jstring javaString;
    javaString = env->NewStringUTF("Hello World!");
    return javaString;
}
