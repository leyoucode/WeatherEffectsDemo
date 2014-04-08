#include "cocos2d.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include "test.h"
#include "JniTest.h"

//#define CLASS_NAME "com/test/jni/JniTestHelper"

using namespace cocos2d;

extern "C"
{

void Java_com_weather_effect_CallWeather_doRain(JNIEnv *env, jobject thiz, jstring packageName)
{
    const char *pkgName = env->GetStringUTFChars(packageName, NULL);
    doRain(pkgName);
    env->ReleaseStringUTFChars(packageName, pkgName);
}

}
