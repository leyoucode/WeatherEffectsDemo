//
//  WindyDayTime.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#include "WindyDayTime.h"
#import "WeatherEffectsUtils.h"

USING_NS_CC;

CCScene* WindyDayTime::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    WindyDayTime *layer = WindyDayTime::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool WindyDayTime::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    //background image
    CCSprite *bgSprite = CCSprite::create("bg_na.jpg");
    float bgSpritespx = bgSprite->getTextureRect().getMaxX();
    float bgSpritespy = bgSprite->getTextureRect().getMaxY();
    // position the sprite on the center of the screen
    bgSprite->setPosition(ccp(size.width/2,size.height/2));
    bgSprite->setScaleX(size.width/bgSpritespx);
    bgSprite->setScaleY(size.height/bgSpritespy);
    // add the sprite as a child to this layer
    this->addChild(bgSprite, 0);
    
    float scale = size.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    //风车叶子图片
    CCSprite *windmillSprite = CCSprite::create("na_windmill.png");
    windmillSprite->setScale(scale);
    float windmillX = size.width / (320.0f / 120.0f);
    float windmillY = size.height / (480.0f / 290.0f);
    
    windmillSprite->setPosition(ccp(windmillX, windmillY));
    this->addChild(windmillSprite);
    
    CCFiniteTimeAction *rot1 = CCRotateTo::create(20.0f, 180);
    CCFiniteTimeAction *rot2 = CCRotateTo::create(20.0f, 360);
    //太阳光柱旋转动画
    windmillSprite->runAction(CCRepeatForever::create(CCSequence::create(rot1,rot2,NULL)));
    
    
    return true;
}

