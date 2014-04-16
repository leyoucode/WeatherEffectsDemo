#include "cocos2d.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#import "ThunderShowerDayTime.h"
#import "ThunderShowerNight.h"
#import "HeavyRainDayTime.h"
#import "HeavyRainNight.h"
#import "LightRainDayTime.h"
#import "LightRainNight.h"
#import "HeavySnowDayTime.h"
#import "HeavySnowNight.h"
#import "LightSnowDayTime.h"
#import "LightSnowNight.h"
#import "SunnyNight.h"
#import "SunnyDayTime.h"
#import "CloudyDayTime.h"
#import "CloudyNight.h"
#import "WindyDayTime.h"
#import "WindyNight.h"

//#define CLASS_NAME "com/test/jni/JniTestHelper"

using namespace cocos2d;

extern "C"
{

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
	// 大雨白天
	void Java_com_essilorchina_weather_CallWeatherEffects_doHeavyRainDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
			CCScene *scene = HeavyRainDayTime::scene();
		    HeavyRainDayTime *layer  = (HeavyRainDayTime*)scene->getChildByTag(LAYER_TAG);
		    layer->isPlaySound = isPlaySound;
		    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
	}
	// 大雨晚上
	void Java_com_essilorchina_weather_CallWeatherEffects_doHeavyRainNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
			CCScene *scene = HeavyRainNight::scene();
		    HeavyRainNight *layer  = (HeavyRainNight*)scene->getChildByTag(LAYER_TAG);
		    layer->isPlaySound = isPlaySound;
		    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
	}
	// 小雨白天
	void Java_com_essilorchina_weather_CallWeatherEffects_doLightRainDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
		 	 CCScene *scene = LightRainDayTime::scene();
		    LightRainDayTime *layer  = (LightRainDayTime*)scene->getChildByTag(LAYER_TAG);
		    layer->isPlaySound = isPlaySound;
		    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
	}
	//小雨晚上
	void Java_com_essilorchina_weather_CallWeatherEffects_doLightRainNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
			CCScene *scene = LightRainNight::scene();
		    LightRainNight *layer  = (LightRainNight*)scene->getChildByTag(LAYER_TAG);
		    layer->isPlaySound = isPlaySound;
		    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
	}

	//============雪天=================
	//大雪白天
	void Java_com_essilorchina_weather_CallWeatherEffects_doHeavySnowDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
			CCScene *scene = HeavySnowDayTime::scene();
		    HeavySnowDayTime *layer  = (HeavySnowDayTime*)scene->getChildByTag(LAYER_TAG);
		    layer->isPlaySound = isPlaySound;
		    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
	}
	//大雪晚上
	void Java_com_essilorchina_weather_CallWeatherEffects_doHeavySnowNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
			CCScene *scene = HeavySnowNight::scene();
		    HeavySnowNight *layer  = (HeavySnowNight*)scene->getChildByTag(LAYER_TAG);
		    layer->isPlaySound = isPlaySound;
		    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
	}
	//小雪白天
	void Java_com_essilorchina_weather_CallWeatherEffects_doLightSnowDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
			CCScene *scene = LightSnowDayTime::scene();
		    LightSnowDayTime *layer  = (LightSnowDayTime*)scene->getChildByTag(LAYER_TAG);
		    layer->isPlaySound = isPlaySound;
		    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
	}
	//小雪晚上
	void Java_com_essilorchina_weather_CallWeatherEffects_doLightSnowNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
			CCScene *scene = LightSnowNight::scene();
		    LightSnowNight *layer  = (LightSnowNight*)scene->getChildByTag(LAYER_TAG);
		    layer->isPlaySound = isPlaySound;
		    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
	}
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
	 //============多云=================
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
	//============ 大风================
	//大风白天
	void Java_com_essilorchina_weather_CallWeatherEffects_doWindyDayTime(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
			CCScene *scene = WindyDayTime::scene();
		    WindyDayTime *layer  = (WindyDayTime*)scene->getChildByTag(LAYER_TAG);
		    layer->isPlaySound = isPlaySound;
		    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
	}
	//大风晚上
	void Java_com_essilorchina_weather_CallWeatherEffects_doWindyNight(JNIEnv *env, jobject thiz, jboolean isPlaySound)
	{
	}
}
