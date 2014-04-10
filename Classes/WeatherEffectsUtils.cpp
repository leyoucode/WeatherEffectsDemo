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
void WeatherEffectsUtils::doThunderShowerDayTime()
{
    CCScene *scene = ThunderShowerDayTime::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 雷阵雨晚上
void WeatherEffectsUtils::doThunderShowerNight()
{
    CCScene *scene = ThunderShowerNight::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

// 大雨白天
void WeatherEffectsUtils::doHeavyRainDayTime()
{
    CCScene *scene = HeavyRainDayTime::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 大雨晚上
void WeatherEffectsUtils::doHeavyRainNight(){
    CCScene *scene = HeavyRainNight::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 小雨白天
void WeatherEffectsUtils::doLightRainDayTime()
{
    CCScene *scene = LightRainDayTime::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 小雨晚上
void WeatherEffectsUtils::doLightRainNight()
{
    CCScene *scene = LightRainNight::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//大雪白天
void WeatherEffectsUtils::doHeavySnowDayTime()
{
    CCScene *scene = HeavySnowDayTime::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//大雪晚上
void WeatherEffectsUtils::doHeavySnowNight(){
    CCScene *scene = HeavySnowNight::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//小雪白天
void WeatherEffectsUtils::doLightSnowDayTime()
{
    CCScene *scene = LightSnowDayTime::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//小雪晚上
void WeatherEffectsUtils::doLightSnowNight()
{
    CCScene *scene = LightSnowNight::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

//晴天晚上
void WeatherEffectsUtils::doSunnyNight()
{
    CCScene *scene = SunnyNight::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//晴天白天
void WeatherEffectsUtils::doSunnyDayTime()
{
    
    CCScene *scene = SunnyDayTime::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//多云白天
void WeatherEffectsUtils::doCloudyDayTime()
{
    CCScene *scene = CloudyDayTime::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//多云晚上
void WeatherEffectsUtils::doCloudyNight()
{
    CCScene *scene = CloudyNight::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

//大风白天
void WeatherEffectsUtils::doWindyDayTime()
{
    CCScene *scene = WindyDayTime::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}

//大风晚上
void WeatherEffectsUtils::doWindyNight()
{

}