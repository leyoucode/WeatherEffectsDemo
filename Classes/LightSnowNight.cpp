//
//  LightSnowNight.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#include "LightSnowNight.h"
#import "WeatherEffectsUtils.h"
#import "SimpleAudioEngine.h"

USING_NS_CC;

CCScene* LightSnowNight::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    LightSnowNight *layer = LightSnowNight::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LightSnowNight::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    
    CCSprite *bgSprite = CCSprite::create("ld_bg_snow_night.jpg");//
    float bgSpritespx = bgSprite->getTextureRect().getMaxX();
    float bgSpritespy = bgSprite->getTextureRect().getMaxY();
    // position the sprite on the center of the screen
    bgSprite->setPosition(ccp(0,size.height/2));
    bgSprite->setScaleX(size.width/bgSpritespx*2);
    bgSprite->setScaleY(size.height/bgSpritespy);
    // add the sprite as a child to this layer
    this->addChild(bgSprite, 0);
    
    //背景移动
    CCFiniteTimeAction* actionMove = CCMoveTo::create( (float)size.width/3,ccp(size.width, size.height/2) );
    CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this,callfuncN_selector(LightSnowNight::bgSpriteMoveFinished));
    bgSprite->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );
    
    float scale = size.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    CCParticleSystemQuad *snowEffect = CCParticleSystemQuad::create("light_snow.plist");
    snowEffect->setPosition(ccp(size.width/2-30, size.height));
    //rainEffect->setAnchorPoint(Point(0,0));
    snowEffect->setScale(scale);
    
    this->addChild(snowEffect);
    
    return true;
}

void LightSnowNight::bgSpriteMoveFinished()
{
    WeatherEffectsUtils::doLightSnowNight();
}

void LightSnowNight::onExit()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopAllEffects();
}

void LightSnowNight::onEnterTransitionDidFinish()
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
                                                                          "windy.mp3", true);
}
