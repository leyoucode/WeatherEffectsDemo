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
    
    winSize = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    //background image
    bgTexture = CCTextureCache::sharedTextureCache()->addImage("ld_bg_fine_day_night.jpg");
    this->moveBackgroundSprite(NULL);
    
    
    float scale = winSize.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    CCParticleSystemQuad *starEffect = CCParticleSystemQuad::create("stars.plist");
    starEffect->setPosition(ccp(winSize.width/2-30, winSize.height));
    starEffect->setScale(scale);
    this->addChild(starEffect);
    
    //月亮精灵
    CCSprite *moonSprite = CCSprite::create("moon.png");
    //moonSprite->setScale(scale);
    moonSprite->setPosition(ccp(winSize.width-moonSprite->getContentSize().width-50, winSize.height - moonSprite->getContentSize().height-50));
    moonSprite->setRotation(-20);
    this->addChild(moonSprite);

    //月亮若隐若现效果
    CCFadeTo *fadeToMix = CCFadeTo::create(1, 200);//0 – totally transparent, 255 – opaque
    CCFadeTo *fadeToMax = CCFadeTo::create(1, 255);
    CCActionInterval *sunFadeDelayTime = CCDelayTime::create(4);
    moonSprite->runAction(CCRepeatForever::create(CCSequence::create(sunFadeDelayTime,fadeToMix,fadeToMax,NULL)));
    
    //流星
    CCSprite *meteor = CCSprite::create("meteor.png");
    meteor->setScale(scale);
    meteor->setRotation(-45);
    meteor->setPosition(ccp(winSize.width*1.4,winSize.height));
    this->addChild(meteor);
    
    CCMoveTo *meteorMove = CCMoveTo::create(4, ccp(-100, 100));
    CCDelayTime *meteorDelayTime = CCDelayTime::create(10);
    CCCallFuncN *meteorCallFunc = CCCallFuncN::create(this, callfuncN_selector(SunnyNight::meteorMoveDone));
    
    meteor->runAction(CCSequence::create(meteorDelayTime,meteorMove,meteorCallFunc,NULL));
    
    
    return true;
}

void SunnyNight::meteorMoveDone(CCNode *node)
{
    CCSprite *meteor = (CCSprite*)node;
    meteor->setPosition(ccp(winSize.width*1.4,winSize.height));
    CCMoveTo *meteorMove = CCMoveTo::create(4, ccp(-100, 100));
    CCDelayTime *meteorDelayTime = CCDelayTime::create(10);
    CCCallFuncN *meteorCallFunc = CCCallFuncN::create(this, callfuncN_selector(SunnyNight::meteorMoveDone));
    
    meteor->runAction(CCSequence::create(meteorDelayTime,meteorMove,meteorCallFunc,NULL));
    
}

//当背景图片移动完毕 再次切换到当前场景
void SunnyNight::moveBackgroundSprite(CCNode *sender)
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
    CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this,callfuncN_selector(SunnyNight::moveBackgroundSprite));
    bgSprite->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );
}
