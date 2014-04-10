//
//  WeatherEffectsUtils.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/8/14.
//
//

#include "WeatherEffectsUtils.h"
#import "cocos2d.h"
#import "ThunderShower.h"
#import "Shower.h"
#import "SunnyNight.h"
#import "SunnyDayTime.h"

USING_NS_CC;

// 雷阵雨
void WeatherEffectsUtils::doThunderShower()
{
    CCScene *scene = ThunderShower::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 阵雨
void WeatherEffectsUtils::doShower()
{
    CCScene *scene = Shower::scene();
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//小，中雨
void WeatherEffectsUtils::doLightRain()
{
    
}
//大雨
void WeatherEffectsUtils::doHeavyRain()
{
    
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