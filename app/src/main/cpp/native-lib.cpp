#include <jni.h>
#include <string>
#include <sys/system_properties.h>
#include "libyuv.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_conanproject_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    char value[92] = {0};
    if (__system_property_get("ro.product.cpu.abi", value) > 0) {
        hello.append(" abi:").append(value);
    }

    hello.append(" libyuv version:").append(std::to_string(LIBYUV_VERSION));
    return env->NewStringUTF(hello.c_str());
}