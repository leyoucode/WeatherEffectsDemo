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

// 雷阵雨
void WeatherEffectsUtils::doThunderShower()
{
    cocos2d::CCScene *scene = ThunderShower::scene();
    cocos2d::CCDirector::sharedDirector()->replaceScene(cocos2d::CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
// 阵雨
void WeatherEffectsUtils::doShower()
{
    cocos2d::CCScene *scene = Shower::scene();
    cocos2d::CCDirector::sharedDirector()->replaceScene(cocos2d::CCTransitionCrossFade::create(TRANSACTION_DURATION, scene));
}
//小，中雨
void WeatherEffectsUtils::doLightRain()
{
    
}
//大雨
void WeatherEffectsUtils::doHeavyRain()
{
    
}