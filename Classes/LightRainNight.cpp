//
//  LightRainNight.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#include "LightRainNight.h"
#import "WeatherEffectsUtils.h"
#import "SimpleAudioEngine.h"

USING_NS_CC;

CCScene* LightRainNight::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    LightRainNight *layer = LightRainNight::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LightRainNight::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCSprite *bgSprite = CCSprite::create("ld_bg_rain_night.jpg");
    bgSprite->setScaleX(2);
    
    // position the sprite on the center of the screen
    bgSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(bgSprite, 0);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    float scale = size.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    CCParticleSystemQuad *rainEffect = CCParticleSystemQuad::create("light_rain.plist");
    //emitter1->setStartColor(ccc4f(1,0,0,1));
    //emitter1->setBlendAdditive(false);
    
    rainEffect->setPosition(ccp(size.width/2-30, size.height));
    //rainEffect->setAnchorPoint(Point(0,0));
    rainEffect->setScale(scale);
    
    this->addChild(rainEffect);
    
    CCParticleSystemQuad *cloudEffect = CCParticleSystemQuad::create("clouds.plist");
    cloudEffect->setPosition(ccp(0,size.height+65));
    cloudEffect->setScale(scale);
    this->addChild(cloudEffect);
    
    return true;
}

void LightRainNight::bgSpriteMoveFinished()
{
    WeatherEffectsUtils::doLightRainDayTime();
}

void LightRainNight::onExit()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopAllEffects();
}
void LightRainNight::onEnterTransitionDidFinish()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
                                                                          "rain.wav", true);
}