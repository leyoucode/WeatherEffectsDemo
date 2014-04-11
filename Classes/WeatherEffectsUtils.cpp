//
//  WeatherEffectsUtils.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/8/14.
//
//

#include "WeatherEffectsUtils.h"
#import "cocos2d.h"
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


USING_NS_CC;

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

// 大雨白天
void WeatherEffectsUtils::doHeavyRainDayTime(bool isPlaySound)
{
    CCScene *scene = HeavyRainDayTime::scene();
    HeavyRainDayTime *layer  = (HeavyRainDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 大雨晚上
void WeatherEffectsUtils::doHeavyRainNight(bool isPlaySound){
    CCScene *scene = HeavyRainNight::scene();
    HeavyRainNight *layer  = (HeavyRainNight*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 小雨白天
void WeatherEffectsUtils::doLightRainDayTime(bool isPlaySound)
{
    CCScene *scene = LightRainDayTime::scene();
    LightRainDayTime *layer  = (LightRainDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 小雨晚上
void WeatherEffectsUtils::doLightRainNight(bool isPlaySound)
{
    CCScene *scene = LightRainNight::scene();
    LightRainNight *layer  = (LightRainNight*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//大雪白天
void WeatherEffectsUtils::doHeavySnowDayTime(bool isPlaySound)
{
    CCScene *scene = HeavySnowDayTime::scene();
    HeavySnowDayTime *layer  = (HeavySnowDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//大雪晚上
void WeatherEffectsUtils::doHeavySnowNight(bool isPlaySound){
    CCScene *scene = HeavySnowNight::scene();
    HeavySnowNight *layer  = (HeavySnowNight*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//小雪白天
void WeatherEffectsUtils::doLightSnowDayTime(bool isPlaySound)
{
    CCScene *scene = LightSnowDayTime::scene();
    LightSnowDayTime *layer  = (LightSnowDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//小雪晚上
void WeatherEffectsUtils::doLightSnowNight(bool isPlaySound)
{
    CCScene *scene = LightSnowNight::scene();
    LightSnowNight *layer  = (LightSnowNight*)scene->getChildByTag(LAYER_TAG);
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
//晴天白天
void WeatherEffectsUtils::doSunnyDayTime(bool isPlaySound)
{
    
    CCScene *scene = SunnyDayTime::scene();
    SunnyDayTime *layer  = (SunnyDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
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

//大风白天
void WeatherEffectsUtils::doWindyDayTime(bool isPlaySound)
{
    CCScene *scene = WindyDayTime::scene();
    WindyDayTime *layer  = (WindyDayTime*)scene->getChildByTag(LAYER_TAG);
    layer->isPlaySound = isPlaySound;
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

//大风晚上
void WeatherEffectsUtils::doWindyNight(bool isPlaySound)
{

}