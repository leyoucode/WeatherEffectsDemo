//
//  Sunny.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/9/14.
//
//

#include "SunnyNight.h"
#import "WeatherEffectsUtils.h"

USING_NS_CC;

CCScene* SunnyNight::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SunnyNight *layer = SunnyNight::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SunnyNight::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCSprite *bgSprite = CCSprite::create("ld_bg_fine_day_night.jpg");
    bgSprite->setScaleX(2);
    
    // position the sprite on the center of the screen
    bgSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(bgSprite, 0);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    float scale = size.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
//    CCSprite *star1Sprite = CCSprite::create("star_flicker8.png");
//    star1Sprite->setScale(scale);
//    star1Sprite->setPosition(ccp(visibleSize.width/2-20, visibleSize.height/2-30));
//    this->addChild(star1Sprite);
//    
//    CCSprite *star2Sprite = CCSprite::create("star_flicker8.png");
//    star2Sprite->setScale(scale);
//    star2Sprite->setPosition(ccp(visibleSize.width/2-30, visibleSize.height/2-54));
//    this->addChild(star2Sprite);
//    
    CCSprite *star3Sprite = CCSprite::create("star_flicker16.png");
    star3Sprite->setScale(scale);
    star3Sprite->setPosition(ccp(visibleSize.width/2+10, visibleSize.height/2+20));
    this->addChild(star3Sprite);
    
    CCSprite *star4Sprite = CCSprite::create("star_flicker8.png");
    star4Sprite->setScale(scale);
    star4Sprite->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    this->addChild(star4Sprite);
    
    CCFadeIn *fadeIn = CCFadeIn::create(2);
    CCFadeOut *fadeOut = CCFadeOut::create(2);
    
    CCSequence* pActSeq = CCSequence::create(fadeIn, fadeOut, NULL);
//    star1Sprite->runAction(CCRepeatForever::create( pActSeq));
//     star2Sprite->runAction(CCRepeatForever::create( pActSeq));
     star3Sprite->runAction(CCRepeatForever::create( pActSeq));
     star4Sprite->runAction(CCRepeatForever::create( pActSeq));
    
    return true;
}
