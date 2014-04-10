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
    
    //CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    //CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    //background image
    CCSprite *bgSprite = CCSprite::create("bg_na.jpg");
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
    CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this,callfuncN_selector(WindyDayTime::bgSpriteMoveFinished));
    bgSprite->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );
    
    float scale = size.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    //太阳图片
    CCSprite *sunSprite = CCSprite::create("sun_small.png");
    sunSprite->setTag(1);
    sunSprite->setScale(scale);
    sunSprite->setPosition(ccp(size.width- 100, size.height- 100));
    sunSpriteOpacity = sunSprite->getOpacity();
    this->addChild(sunSprite);
    //太阳若隐若现效果
    this->schedule(schedule_selector(WindyDayTime::changeSunAlpha), 0.1f);
    
    //太阳光柱图片
    CCSprite *sunshineSprite = CCSprite::create("sunshine.png");
    sunshineSprite->setScale(scale);
    sunshineSprite->setPosition(ccp(size.width- 100, size.height- 100));
    this->addChild(sunshineSprite);
    
    CCFiniteTimeAction *rot1 = CCRotateTo::create(26.0f, 180);
    CCFiniteTimeAction *rot2 = CCRotateTo::create(26.0f, 360);
    CCFadeOut * fadeOut=CCFadeOut::create(13.0f);
    CCFadeIn * fadeIn=CCFadeIn::create(13.0f);
    //太阳光柱旋转动画
    sunshineSprite->runAction(CCRepeatForever::create(CCSequence::create(rot1,rot2,NULL)));
    //太阳光柱淡入淡出
    sunshineSprite->runAction(CCRepeatForever::create(CCSequence::create(fadeOut,fadeIn,NULL)));
    
    return true;
}

//当背景图片移动完毕 再次切换到当前场景
void WindyDayTime::bgSpriteMoveFinished()
{
    WeatherEffectsUtils::doSunnyDayTime();
}


//改变太阳图片的Alpha值 实现太阳若影若现的效果
void WindyDayTime::changeSunAlpha()
{
    
    CCSprite  *sunSprite = (CCSprite*)this->getChildByTag(1);
    //0 – totally transparent, 255 – opaque
    
    if (isSunSpriteOpacityAdd) {
        sunSpriteOpacity = sunSpriteOpacity + 1;
    }else{
        sunSpriteOpacity = sunSpriteOpacity - 1;
    }
    
    if (sunSpriteOpacity >= 255) {
        sunSpriteOpacity = 255;
        isSunSpriteOpacityAdd = false;
    }else if(sunSpriteOpacity <= 220){
        sunSpriteOpacity = 220;
        isSunSpriteOpacityAdd = true;
    }
    sunSprite -> setOpacity(sunSpriteOpacity);
    
}