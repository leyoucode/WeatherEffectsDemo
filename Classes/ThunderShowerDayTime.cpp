//
//  RainScene.cpp
//  helloword
//
//  Created by liu wei on 4/6/14.
//  Copyright 2014 __MyCompanyName__. All rights reserved.
//

#include "ThunderShowerDayTime.h"
#import "WeatherEffectsUtils.h"
#import "SimpleAudioEngine.h"

USING_NS_CC;

CCScene* ThunderShowerDayTime::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    ThunderShowerDayTime *layer = ThunderShowerDayTime::create();
    layer->setTag(LAYER_TAG);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ThunderShowerDayTime::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    
    CCSprite *bgSprite = CCSprite::create("ld_bg_rain_day_time.jpg");
    float bgSpritespx = bgSprite->getTextureRect().getMaxX();
    float bgSpritespy = bgSprite->getTextureRect().getMaxY();
    // position the sprite on the center of the screen
    bgSprite->setPosition(ccp(0,size.height/2));
    bgSprite->setScaleX(size.width/bgSpritespx*2);
    bgSprite->setScaleY(size.height/bgSpritespy);
    // add the sprite as a child to this layer
    this->addChild(bgSprite, 0);
    
    //背景移动
    CCFiniteTimeAction* actionMove = CCMoveTo::create( (float)size.width/4,ccp(size.width, size.height/2) );
    CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerDayTime::bgSpriteMoveFinished));
    bgSprite->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );
    
    float scale = size.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    CCParticleSystemQuad *rainEffect = CCParticleSystemQuad::create("rain.plist");
    rainEffect->setPosition(ccp(size.width/2-30, size.height));
    rainEffect->setScale(scale);
    this->addChild(rainEffect);
    
//    CCParticleSystemQuad *cloudEffect = CCParticleSystemQuad::create("clouds.plist");
//    cloudEffect->setPosition(ccp(0,size.height+65));
//    cloudEffect->setScale(scale);
//    this->addChild(cloudEffect);
//    
//    
//    CCParticleSystemQuad *light1Effect = CCParticleSystemQuad::create("light1.plist");
//    light1Effect->setPosition(ccp(size.width/2,size.height));
//    light1Effect->setScale(scale);
//    this->addChild(light1Effect);
//    light1Effect->setVisible(false);
//    
//    CCActionInterval *light1DelayTime = CCDelayTime::create(10);
//    CCActionInstant *light1callFunc = CCCallFuncN::create(this, callfuncN_selector(ThunderShowerDayTime::lightPreShow));
//    light1Effect->runAction(CCRepeatForever::create(CCSequence::create(light1DelayTime,light1callFunc,NULL)));
//    
//    CCParticleSystemQuad *light2Effect = CCParticleSystemQuad::create("light2.plist");
//    light2Effect->setPosition(ccp(size.width/2,size.height));
//    light2Effect->setScale(scale);
//    this->addChild(light2Effect);
//    light2Effect->setVisible(false);
//    
//    CCActionInterval *light2DelayTime = CCDelayTime::create(10);
//    CCActionInstant *light2callFunc = CCCallFuncN::create(this, callfuncN_selector(ThunderShowerDayTime::lightPreShow));
//    light2Effect->runAction(CCRepeatForever::create(CCSequence::create(light2DelayTime,light2callFunc,NULL)));
    
    //云朵图片1
    CCSprite *cloud1Sprite = CCSprite::create("dark_clouds_1.png");
    cloud1Sprite->setPosition(ccp(size.width/2, size.height-50));
    cloud1Sprite->setScale(scale);
    this->addChild(cloud1Sprite);
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+cloud1Sprite->getTextureRect().getMaxX(), size.height-100) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
    
    //云朵图片2
    CCSprite *cloud2Sprite = CCSprite::create("dark_clouds_2.png");
    cloud2Sprite->setPosition(ccp(size.width/2-150, size.height-50));
    cloud2Sprite->setScale(scale);
    this->addChild(cloud2Sprite);
    //云层2移动
    CCFiniteTimeAction* cloud2ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+cloud2Sprite->getTextureRect().getMaxX(), size.height-100) );
    CCFiniteTimeAction* cloud2ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerDayTime::cloudy2SpriteMoveFinished));
    cloud2Sprite->runAction( CCSequence::create(cloud2ActionMove,cloud2ActionMoveDone, NULL) );
    
    //云朵图片3
    CCSprite *cloud3Sprite = CCSprite::create("dark_clouds_3.png");
    cloud3Sprite->setPosition(ccp(size.width/2-300, size.height-50));
    cloud3Sprite->setScale(scale);
    this->addChild(cloud3Sprite);
    //云层3移动
    CCFiniteTimeAction* cloud3ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+cloud3Sprite->getTextureRect().getMaxX(), size.height-100) );
    CCFiniteTimeAction* cloud3ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerDayTime::cloudy3SpriteMoveFinished));
    cloud3Sprite->runAction( CCSequence::create(cloud3ActionMove,cloud3ActionMoveDone, NULL) );
    
    //云朵图片4
    CCSprite *cloud4Sprite = CCSprite::create("dark_clouds_4.png");
    cloud4Sprite->setPosition(ccp(size.width/2-450, size.height-50));
    cloud4Sprite->setScale(scale);
    this->addChild(cloud4Sprite);
    //云层4移动
    CCFiniteTimeAction* cloud4ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+cloud4Sprite->getTextureRect().getMaxX(), size.height-100) );
    CCFiniteTimeAction* cloud4ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerDayTime::cloudy4SpriteMoveFinished));
    cloud4Sprite->runAction( CCSequence::create(cloud4ActionMove,cloud4ActionMoveDone, NULL) );
    
    return true;
}

void ThunderShowerDayTime::lightPreShow(CCNode *node)
{
    CCLOG("lightPreShow");
    CCParticleSystemQuad *light1Effect = (CCParticleSystemQuad*)node;
    bool lightIsVisible = light1Effect->isVisible();
    if (lightIsVisible) {
        light1Effect ->setVisible(false);
    }else{
    light1Effect ->setVisible(true);
        if (isPlaySound) {
            CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(
                                                                         "thunder.wav");
        }
    }
}

void ThunderShowerDayTime::bgSpriteMoveFinished()
{
    WeatherEffectsUtils::doThunderShowerDayTime(isPlaySound);
}

void ThunderShowerDayTime::onExit()
{
    if (isPlaySound) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopAllEffects();
    }
}

void ThunderShowerDayTime::onEnterTransitionDidFinish()
{
    if (isPlaySound) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
                                                                              "rain.wav", true);
    }
    
}

///////////////////////////////

void ThunderShowerDayTime::cloudy1SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-50));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+bgSpritespx, size.height-50) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

void ThunderShowerDayTime::cloudy2SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-50));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+bgSpritespx, size.height-50) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

void ThunderShowerDayTime::cloudy3SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-50));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+bgSpritespx, size.height-50) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

void ThunderShowerDayTime::cloudy4SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-50));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+bgSpritespx, size.height-50) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}
