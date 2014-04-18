//
//  WeatherEffectsUtils.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/8/14.
//
//

#include "WeatherEffectsUtils.h"
//#include <jni.h>
//#include "platform/android/jni/JniHelper.h"
#import "cocos2d.h"
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


USING_NS_CC;

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//#import "CallWeatherEffects.h"
//#endif

//============================================================晴天=================

//晴天白天
void WeatherEffectsUtils::doSunnyDayTime(bool isPlaySound)
{
    
    CCScene *scene = SunnyDayTime::scene();
    SunnyDayTime *layer  = (SunnyDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

//晴天晚上
void WeatherEffectsUtils::doSunnyNight(bool isPlaySound)
{
    CCScene *scene = SunnyNight::scene();
    SunnyNight *layer  = (SunnyNight*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

//============================================================雨天=================

// 雷阵雨白天
void WeatherEffectsUtils::doThunderShowerDayTime(bool isPlaySound)
{
    CCScene *scene = ThunderShowerDayTime::scene();
    ThunderShowerDayTime *layer  = (ThunderShowerDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 雷阵雨晚上
void WeatherEffectsUtils::doThunderShowerNight(bool isPlaySound)
{
    CCScene *scene = ThunderShowerNight::scene();
    ThunderShowerNight *layer  = (ThunderShowerNight*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

// 雨白天
void WeatherEffectsUtils::doRainDayTime(bool isPlaySound)
{
    CCScene *scene = RainDayTime::scene();
    RainDayTime *layer  = (RainDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 雨晚上
void WeatherEffectsUtils::doRainNight(bool isPlaySound)
{
    CCScene *scene = RainNight::scene();
    RainNight *layer  = (RainNight*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

 //============================================================雪天=================

//雪白天
void WeatherEffectsUtils::doSnowDayTime(bool isPlaySound)
{
    CCScene *scene = SnowDayTime::scene();
    SnowDayTime *layer  = (SnowDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//雪晚上
void WeatherEffectsUtils::doSnowNight(bool isPlaySound)
{
    CCScene *scene = SnowNight::scene();
    SnowNight *layer  = (SnowNight*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

//============================================================多云 =================

//多云白天
void WeatherEffectsUtils::doCloudyDayTime(bool isPlaySound)
{
    CCScene *scene = CloudyDayTime::scene();
    CloudyDayTime *layer  = (CloudyDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//多云晚上
void WeatherEffectsUtils::doCloudyNight(bool isPlaySound)
{
    CCScene *scene = CloudyNight::scene();
    CloudyNight *layer  = (CloudyNight*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

void WeatherEffectsUtils::android_back_click()
{
//	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) //判断当前是否为Android平台
//            JniMethodInfo minfo;//定义Jni函数信息结构体
//            bool isHave = JniHelper::getStaticMethodInfo(minfo,"com/essilorchina/weather/CallWeatherEffects","back", "()V");
//            if(isHave){
//                CCLog("jni:android_back_click");
//                minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
//            }else{
//                CCLog("jni:android_back_click not found");
//            }
//	#endif
}
void WeatherEffectsUtils::android_menu_click()
{
//    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) //判断当前是否为Android平台
//        JniMethodInfo minfo;//定义Jni函数信息结构体
//        bool isHave = JniHelper::getStaticMethodInfo(minfo,"com/essilorchina/weather/CallWeatherEffects","menu", "()V");
//        if(isHave){
//            CCLog("jni:android_menu_click");
//            minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
//        }else{
//            CCLog("jni:android_menu_click not found");
//        }
//    #endif
}
