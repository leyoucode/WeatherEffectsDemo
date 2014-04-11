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
    layer->setTag(LAYER_TAG);
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
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    
    CCSprite *bgSprite = CCSprite::create("ld_bg_fine_day_night.jpg");
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
    CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this,callfuncN_selector(SunnyNight::bgSpriteMoveFinished));
    bgSprite->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );
    
    float scale = size.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    CCParticleSystemQuad *rainEffect = CCParticleSystemQuad::create("stars.plist");
    rainEffect->setPosition(ccp(size.width/2-30, size.height));
    rainEffect->setScale(scale);
    
    CCSprite *star1Sprite = CCSprite::create("star_flicker8.png");
    star1Sprite->setScale(scale);
    star1Sprite->setPosition(ccp(size.width/2+20, size.height - 30));
    this->addChild(star1Sprite);
    CCFadeIn *star1SpriteFadeIn = CCFadeIn::create(2);
    CCFadeOut *star1SpriteFadeOut = CCFadeOut::create(2);
    star1Sprite->runAction(CCRepeatForever::create( CCSequence::create(star1SpriteFadeIn, star1SpriteFadeOut, NULL)));
    
    CCSprite *star2Sprite = CCSprite::create("star_flicker8.png");
    star2Sprite->setScale(scale);
    star2Sprite->setPosition(ccp(size.width-80, size.height - 140));
    this->addChild(star2Sprite);
    CCFadeIn *star2SpriteFadeIn = CCFadeIn::create(1);
    CCFadeOut *star2SpriteFadeOut = CCFadeOut::create(1);
    star2Sprite->runAction(CCRepeatForever::create( CCSequence::create(star2SpriteFadeIn, star2SpriteFadeOut, NULL)));
    
    CCSprite *star3Sprite = CCSprite::create("star_flicker8.png");
    star3Sprite->setScale(scale);
    star3Sprite->setPosition(ccp(30, size.height - 60));
    this->addChild(star3Sprite);
    CCFadeIn *star3SpriteFadeIn = CCFadeIn::create(3);
    CCFadeOut *star3SpriteFadeOut = CCFadeOut::create(3);
    star3Sprite->runAction(CCRepeatForever::create( CCSequence::create(star3SpriteFadeIn, star3SpriteFadeOut, NULL)));
    
    CCSprite *star4Sprite = CCSprite::create("star_flicker8.png");
    star4Sprite->setScale(scale);
    star4Sprite->setPosition(ccp(size.width/2, size.height - 80));
    this->addChild(star4Sprite);
    CCFadeIn *star4SpriteFadeIn = CCFadeIn::create(4);
    CCFadeOut *star4SpriteFadeOut = CCFadeOut::create(4);
    star4Sprite->runAction(CCRepeatForever::create( CCSequence::create(star4SpriteFadeIn, star4SpriteFadeOut, NULL)));
    
    CCSprite *star5Sprite = CCSprite::create("star_flicker8.png");
    star5Sprite->setScale(scale);
    star5Sprite->setPosition(ccp(20, size.height - 180));
    this->addChild(star5Sprite);
    CCFadeIn *star5SpriteFadeIn = CCFadeIn::create(1);
    CCFadeOut *star5SpriteFadeOut = CCFadeOut::create(1);
    star5Sprite->runAction(CCRepeatForever::create( CCSequence::create(star5SpriteFadeIn, star5SpriteFadeOut, NULL)));
    
    CCSprite *star6Sprite = CCSprite::create("star_flicker8.png");
    star6Sprite->setScale(scale);
    star6Sprite->setPosition(ccp(100, size.height - 160));
    this->addChild(star6Sprite);
    CCFadeIn *star6SpriteFadeIn = CCFadeIn::create(3);
    CCFadeOut *star6SpriteFadeOut = CCFadeOut::create(3);
    star6Sprite->runAction(CCRepeatForever::create( CCSequence::create(star6SpriteFadeIn, star6SpriteFadeOut, NULL)));
    
    CCSprite *star7Sprite = CCSprite::create("star_flicker8.png");
    star7Sprite->setScale(scale);
    star7Sprite->setPosition(ccp(size.width-100, size.height - 250));
    this->addChild(star7Sprite);
    CCFadeIn *star7SpriteFadeIn = CCFadeIn::create(2);
    CCFadeOut *star7SpriteFadeOut = CCFadeOut::create(2);
    star7Sprite->runAction(CCRepeatForever::create( CCSequence::create(star7SpriteFadeIn, star7SpriteFadeOut, NULL)));
    
    
    CCSprite *star8Sprite = CCSprite::create("star_flicker8.png");
    star8Sprite->setScale(scale);
    star8Sprite->setPosition(ccp(size.width-150, size.height - 160));
    this->addChild(star8Sprite);
    CCFadeIn *star8SpriteFadeIn = CCFadeIn::create(1);
    CCFadeOut *star8SpriteFadeOut = CCFadeOut::create(1);
    star8Sprite->runAction(CCRepeatForever::create( CCSequence::create(star8SpriteFadeIn, star8SpriteFadeOut, NULL)));
    
    CCSprite *star9Sprite = CCSprite::create("star_flicker8.png");
    star9Sprite->setScale(scale);
    star9Sprite->setPosition(ccp(size.width/2, size.height - 200));
    this->addChild(star9Sprite);
    CCFadeIn *star9SpriteFadeIn = CCFadeIn::create(2);
    CCFadeOut *star9SpriteFadeOut = CCFadeOut::create(1);
    star9Sprite->runAction(CCRepeatForever::create( CCSequence::create(star9SpriteFadeIn, star9SpriteFadeOut, NULL)));
    
    CCSprite *star10Sprite = CCSprite::create("star_flicker8.png");
    star10Sprite->setScale(scale);
    star10Sprite->setPosition(ccp(size.width-20, size.height - 20));
    this->addChild(star10Sprite);
    CCFadeIn *star10SpriteFadeIn = CCFadeIn::create(3);
    CCFadeOut *star10SpriteFadeOut = CCFadeOut::create(2);
    star10Sprite->runAction(CCRepeatForever::create( CCSequence::create(star10SpriteFadeIn, star10SpriteFadeOut, NULL)));
    
    CCSprite *star11Sprite = CCSprite::create("star_flicker8.png");
    star11Sprite->setScale(scale);
    star11Sprite->setPosition(ccp(size.width-30, size.height - 45));
    this->addChild(star11Sprite);
    CCFadeIn *star11SpriteFadeIn = CCFadeIn::create(3);
    CCFadeOut *star11SpriteFadeOut = CCFadeOut::create(2);
    star11Sprite->runAction(CCRepeatForever::create( CCSequence::create(star11SpriteFadeIn, star11SpriteFadeOut, NULL)));
    
    CCSprite *star12Sprite = CCSprite::create("star_flicker8.png");
    star12Sprite->setScale(scale);
    star12Sprite->setPosition(ccp(50, size.height - 20));
    this->addChild(star12Sprite);
    CCFadeIn *star12SpriteFadeIn = CCFadeIn::create(1);
    CCFadeOut *star12SpriteFadeOut = CCFadeOut::create(1);
    star12Sprite->runAction(CCRepeatForever::create( CCSequence::create(star12SpriteFadeIn, star12SpriteFadeOut, NULL)));
    
    
//
    CCSprite *moonSprite = CCSprite::create("moon_3_4.png");
    moonSprite->setTag(1);
    moonSpriteOpacity = moonSprite->getOpacity();
    moonSprite->setScale(scale);
    moonSprite->setPosition(ccp(size.width-100, size.height - 80));
    this->addChild(moonSprite);
    
    //月亮若隐若现效果
    this->schedule(schedule_selector(SunnyNight::changeMoonAlpha), 0.1f);
    
    return true;
}

//当背景图片移动完毕 再次切换到当前场景
void SunnyNight::bgSpriteMoveFinished()
{
    WeatherEffectsUtils::doSunnyNight(isPlaySound);
}

//改变太阳图片的Alpha值 实现太阳若影若现的效果
void SunnyNight::changeMoonAlpha()
{
    
    CCSprite  *sunSprite = (CCSprite*)this->getChildByTag(1);
    //0 – totally transparent, 255 – opaque
    
    if (isMoonSpriteOpacityAdd) {
        moonSpriteOpacity = moonSpriteOpacity + 10;
    }else{
        moonSpriteOpacity = moonSpriteOpacity - 10;
    }
    
    if (moonSpriteOpacity >= 255) {
        moonSpriteOpacity = 255;
        isMoonSpriteOpacityAdd = false;
    }else if(moonSpriteOpacity <= 220){
        moonSpriteOpacity = 220;
        isMoonSpriteOpacityAdd = true;
    }
    sunSprite -> setOpacity(moonSpriteOpacity);
    
}
