//
//  RainScene.cpp
//  helloword
//
//  Created by liu wei on 4/6/14.
//  Copyright 2014 __MyCompanyName__. All rights reserved.
//

#include "ThunderShower.h"
#import "WeatherEffectsUtils.h"

USING_NS_CC;

CCScene* ThunderShower::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    ThunderShower *layer = ThunderShower::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ThunderShower::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCSprite *bgSprite = CCSprite::create("bg_rain_night.jpg");
    bgSprite->setScaleX(2);
    
    // position the sprite on the center of the screen
    bgSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(bgSprite, 0);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    float scale = size.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    CCParticleSystemQuad *rainEffect = CCParticleSystemQuad::create("rain.plist");
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
    
    
    CCParticleSystemQuad *light1Effect = CCParticleSystemQuad::create("light1.plist");
    light1Effect->setPosition(ccp(size.width/2,size.height));
    light1Effect->setScale(scale);
    this->addChild(light1Effect);
    
    CCParticleSystemQuad *light2Effect = CCParticleSystemQuad::create("light2.plist");
    light2Effect->setPosition(ccp(size.width/2,size.height));
    light2Effect->setScale(scale);
    this->addChild(light2Effect);
    
    
    
    // Determine speed of the target
    
    
//    // Create the actions
//    CCFiniteTimeAction* actionMove =
//    CCMoveTo::create( (float)size.width/35,
//                     ccp(size.width, size.height/2) );
//    CCFiniteTimeAction* actionMoveDone =
//    CCCallFuncN::create( this,
//                        callfuncN_selector(RainScene::bgSpriteMoveFinished));
//    bgSprite->runAction( CCSequence::create(actionMove,
//                                          actionMoveDone, NULL) );
    
    return true;
}

void ThunderShower::bgSpriteMoveFinished()
{
    CCLOG("background image move finished");
    
    WeatherEffectsUtils::doThunderShower();
}
