//
//  SunnyDayTime.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/9/14.
//
//

#include "SunnyDayTime.h"
#import "WeatherEffectsUtils.h"
#import "SimpleAudioEngine.h"

USING_NS_CC;

CCScene* SunnyDayTime::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SunnyDayTime *layer = SunnyDayTime::create();
    layer->setTag(LAYER_TAG);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SunnyDayTime::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    winSize = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    //background image
    bgTexture = CCTextureCache::sharedTextureCache()->addImage("ld_bg_fine_day.jpg");
    this->moveBackgroundSprite(NULL);
    
    float scale = winSize.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    //太阳图片
    CCSprite *sunSprite = CCSprite::create("sun_small.png");
    sunSprite->setTag(1);
    sunSprite->setScale(scale);
    sunSprite->setPosition(ccp(winSize.width- sunSprite->getTextureRect().getMaxX(), winSize.height- sunSprite->getTextureRect().getMaxY()));
    this->addChild(sunSprite);
    //太阳若隐若现效果
    CCFadeTo *fadeToMix = CCFadeTo::create(1, 200);//0 – totally transparent, 255 – opaque
    CCFadeTo *fadeToMax = CCFadeTo::create(1, 255);
    CCActionInterval *sunFadeDelayTime = CCDelayTime::create(4);
    sunSprite->runAction(CCRepeatForever::create(CCSequence::create(sunFadeDelayTime,fadeToMix,fadeToMax,NULL)));

    //太阳光柱图片
    CCSprite *sunshineSprite = CCSprite::create("sunshine.png");
    sunshineSprite->setScale(scale);
    sunshineSprite->setPosition(ccp(winSize.width- sunSprite->getTextureRect().getMaxX(), winSize.height- sunSprite->getTextureRect().getMaxY()));
    this->addChild(sunshineSprite);
    sunshineSprite->setOpacity(0);
    
    //太阳光柱旋转动画
    CCFadeOut * fadeOut=CCFadeOut::create(5.0f);
    CCFadeIn * fadeIn=CCFadeIn::create(5.0f);
    CCActionInterval *sunshineFadeDelayTime1 = CCDelayTime::create(40);
    CCActionInterval *sunshineFadeDelayTime2 = CCDelayTime::create(130);
    
    CCRotateBy* actionSpin = CCRotateBy::create(180.0f,360);
    sunshineSprite->runAction(CCRepeatForever::create(CCSpawn::create(CCSequence::create(actionSpin,NULL),CCSequence::create(fadeIn,sunshineFadeDelayTime1,fadeOut,sunshineFadeDelayTime2,NULL),NULL)));
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("bird.wav");//欲加载鸟鸣声
    return true;
}

//移动背景图片
void SunnyDayTime::moveBackgroundSprite(CCNode *sender)
{

    int zorder = 0;
    
    if (sender != NULL) {
        zorder = sender->getZOrder();
        sender->runAction(CCSequence::create(CCFadeOut::create(4),CCRemoveSelf::create(),NULL));
    }
    
    //创建背景精灵
    CCSprite *bgSprite = CCSprite::createWithTexture(bgTexture);
    float bgSpritespx = bgTexture->getContentSize().width;
    float bgSpritespy = bgTexture->getContentSize().height;
    //设置精灵位置
    bgSprite->setPosition(ccp(0,winSize.height/2));
    bgSprite->setScaleX(winSize.width/bgSpritespx*2);//宽度放大2倍
    bgSprite->setScaleY(winSize.height/bgSpritespy);
    
    this->addChild(bgSprite, zorder-1);
    
    CCFiniteTimeAction* actionMove = CCMoveTo::create( (float)winSize.width/BACKGROUND_MOVE_SPEED,ccp(winSize.width, winSize.height/2) );
    CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this,callfuncN_selector(SunnyDayTime::moveBackgroundSprite));
    bgSprite->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );
    
}


void SunnyDayTime::onExit()
{
    if (isPlaySound) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect(birdSound);
    }
}

void SunnyDayTime::onEnterTransitionDidFinish()
{
    if (isPlaySound) {
        CCActionInterval *birdcallDelayTime = CCDelayTime::create(10);
        CCActionInstant *birdcallcallFunc = CCCallFuncN::create(this, callfuncN_selector(SunnyDayTime::playBirdcall));
        this->runAction(CCRepeatForever::create(CCSequence::create(birdcallcallFunc,birdcallDelayTime,NULL)));
    }
}

void SunnyDayTime::playBirdcall(CCNode *node)
{
    
       birdSound = CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("bird.wav", false);
   
}