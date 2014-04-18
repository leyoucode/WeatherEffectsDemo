//
//  LightSnowDayTime.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#include "SnowDayTime.h"
#import "WeatherEffectsUtils.h"
#import "SimpleAudioEngine.h"

USING_NS_CC;

CCScene* SnowDayTime::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SnowDayTime *layer = SnowDayTime::create();
    layer->setTag(LAYER_TAG);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SnowDayTime::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->setKeypadEnabled(true);

    winSize = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    //background image
    bgTexture = CCTextureCache::sharedTextureCache()->addImage("ld_bg_snow_day_time.jpg");
    this->moveBackgroundSprite(NULL);
    
    float scale = winSize.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    CCParticleSystemQuad *snowEffect = CCParticleSystemQuad::create("snow.plist");
    snowEffect->setPosition(ccp(winSize.width/2-30, winSize.height));
    //rainEffect->setAnchorPoint(Point(0,0));
    snowEffect->setScale(scale);
    
    this->addChild(snowEffect);
    
    if (isPlaySound) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("windy.mp3");
    }
    return true;
}

//移动背景图片
void SnowDayTime::moveBackgroundSprite(CCNode *sender)
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
    CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this,callfuncN_selector(SnowDayTime::moveBackgroundSprite));
    bgSprite->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );
    
}

void SnowDayTime::onExit()
{
    if (isPlaySound) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    }
}

void SnowDayTime::onEnterTransitionDidFinish()
{
    if (isPlaySound) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
                                                                              "windy.mp3", true);
    }
}
void SnowDayTime::keyBackClicked(){
    CCLog("Android- KeyBackClicked!");
    WeatherEffectsUtils::android_back_click();
}

void SnowDayTime::keyMenuClicked(){
    CCLog("Android- keyMenuClicked!");
    WeatherEffectsUtils::android_menu_click();
}