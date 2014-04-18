#include "cocos2d.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#import "ThunderShowerDayTime.h"
#import "ThunderShowerNight.h"
#import "RainDayTime.h"
#import "RainNight.h"
#import "SnowDayTime.h"
#import "SnowNight.h"
#import "SunnyNight.h"
#import "SunnyDayTime.h"
#import "CloudyDayTime.h"
#import "CloudyNight.h"

//#define CLASS_NAME "com/test/jni/JniTestHelper"

using namespace cocos2d;

extern "C"
{

//============晴天=================
//晴天白天
void Java_com_essilorchina_weather_CallWeatherEffects_doSunnyDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
		CCScene *scene = SunnyDayTime::scene();
		SunnyDayTime *layer  = (SunnyDayTime*)scene->getChildByTag(LAYER_TAG);
		layer->isPlaySound = isPlaySound;
		CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//晴天晚上
void Java_com_essilorchina_weather_CallWeatherEffects_doSunnyNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
			CCScene *scene = SunnyNight::scene();
			SunnyNight *layer  = (SunnyNight*)scene->getChildByTag(LAYER_TAG);
			layer->isPlaySound = isPlaySound;
			CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

//============雨天=================
// 雷阵雨白天
void Java_com_essilorchina_weather_CallWeatherEffects_doThunderShowerDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
	CCScene *scene = ThunderShowerDayTime::scene();
	ThunderShowerDayTime *layer  = (ThunderShowerDayTime*)scene->getChildByTag(LAYER_TAG);
	layer->isPlaySound = isPlaySound;
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 雷阵雨晚上
void Java_com_essilorchina_weather_CallWeatherEffects_doThunderShowerNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
	CCScene *scene = ThunderShowerNight::scene();
	ThunderShowerNight *layer  = (ThunderShowerNight*)scene->getChildByTag(LAYER_TAG);
	layer->isPlaySound = isPlaySound;
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 雨白天
void Java_com_essilorchina_weather_CallWeatherEffects_doRainDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
	CCScene *scene = RainDayTime::scene();
	RainDayTime *layer  = (RainDayTime*)scene->getChildByTag(LAYER_TAG);
	layer->isPlaySound = isPlaySound;
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 雨晚上
void Java_com_essilorchina_weather_CallWeatherEffects_doRainNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
	CCScene *scene = RainNight::scene();
	RainNight *layer  = (RainNight*)scene->getChildByTag(LAYER_TAG);
	layer->isPlaySound = isPlaySound;
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}


//============雪天=================
//雪白天
void Java_com_essilorchina_weather_CallWeatherEffects_doSnowDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
	CCScene *scene = SnowDayTime::scene();
	SnowDayTime *layer  = (SnowDayTime*)scene->getChildByTag(LAYER_TAG);
	layer->isPlaySound = isPlaySound;
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//雪晚上
void Java_com_essilorchina_weather_CallWeatherEffects_doSnowNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
	CCScene *scene = SnowNight::scene();
	SnowNight *layer  = (SnowNight*)scene->getChildByTag(LAYER_TAG);
	layer->isPlaySound = isPlaySound;
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

//============多云 =================
//多云白天
void Java_com_essilorchina_weather_CallWeatherEffects_doCloudyDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
	CCScene *scene = CloudyDayTime::scene();
	CloudyDayTime *layer  = (CloudyDayTime*)scene->getChildByTag(LAYER_TAG);
	layer->isPlaySound = isPlaySound;
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//多云晚上
void Java_com_essilorchina_weather_CallWeatherEffects_doCloudyNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
{
	CCScene *scene = CloudyNight::scene();
	CloudyNight *layer  = (CloudyNight*)scene->getChildByTag(LAYER_TAG);
	layer->isPlaySound = isPlaySound;
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
}
