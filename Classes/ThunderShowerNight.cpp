//
//  ThinderShowerNight.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#include "ThunderShowerNight.h"
#import "WeatherEffectsUtils.h"
#import "SimpleAudioEngine.h"

USING_NS_CC;

CCScene* ThunderShowerNight::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    ThunderShowerNight *layer = ThunderShowerNight::create();
    layer->setTag(LAYER_TAG);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ThunderShowerNight::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    
    winSize = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    //background image
    bgTexture = CCTextureCache::sharedTextureCache()->addImage("ld_bg_rain_night.jpg");
    this->moveBackgroundSprite(NULL);
    
    scale = winSize.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    CCParticleSystemQuad *rainEffect = CCParticleSystemQuad::create("rain.plist");
    rainEffect->setPosition(ccp(winSize.width/2-30, winSize.height));
    rainEffect->setScale(scale);
    this->addChild(rainEffect);
    
    thunderlight1 = CCSprite::create("thunderlight1.png");
    thunderlight1->setPosition(ccp(winSize.width/2+50,winSize.height-(120*scale)));
    thunderlight1->setOpacity(0);
    thunderlight1->setRotation(20);
    this->addChild(thunderlight1);
    
    thunderlight2 = CCSprite::create("thunderlight2.png");
    thunderlight2->setPosition(ccp(winSize.width/2+75,winSize.height-(120*scale)));
    thunderlight2->setOpacity(0);
    thunderlight2->setRotation(38);
    this->addChild(thunderlight2);
    //执行闪电效果
    CCDelayTime *delayTime10 = CCDelayTime::create(15);
    CCCallFuncN *lightCallFunc = CCCallFuncN::create(this, callfuncN_selector(ThunderShowerNight::showThunderLight));
    this->runAction(CCRepeatForever::create(CCSequence::create(delayTime10,lightCallFunc,NULL)));
    
    
    //云朵图片1
    CCSprite *cloud1Sprite = CCSprite::create("dark_clouds_1.png");
    cloud1Sprite->setPosition(ccp(winSize.width/2, winSize.height-50));
    cloud1Sprite->setScale(scale);
    cloud1Sprite->setOpacity(103.0);
    this->addChild(cloud1Sprite);
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)winSize.width/10,ccp(winSize.width+cloud1Sprite->getTextureRect().getMaxX(), winSize.height-100) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerNight::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
    
    //云朵图片2
    CCSprite *cloud2Sprite = CCSprite::create("dark_clouds_2.png");
    cloud2Sprite->setPosition(ccp(0, winSize.height-100));
    cloud2Sprite->setScale(scale);
    cloud2Sprite->setOpacity(103.0);
    this->addChild(cloud2Sprite);
    //云层2移动
    CCFiniteTimeAction* cloud2ActionMove = CCMoveTo::create( (float)winSize.width/6,ccp(winSize.width+cloud2Sprite->getTextureRect().getMaxX(), winSize.height-100) );
    CCFiniteTimeAction* cloud2ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerNight::cloudy2SpriteMoveFinished));
    cloud2Sprite->runAction( CCSequence::create(cloud2ActionMove,cloud2ActionMoveDone, NULL) );
    
    //云朵图片3
    CCSprite *cloud3Sprite = CCSprite::create("dark_clouds_3.png");
    cloud3Sprite->setPosition(ccp(winSize.width/2*-1, winSize.height-150));
    cloud3Sprite->setScale(scale);
    cloud3Sprite->setOpacity(103.0);
    this->addChild(cloud3Sprite);
    //云层3移动
    CCFiniteTimeAction* cloud3ActionMove = CCMoveTo::create( (float)winSize.width/4,ccp(winSize.width+cloud3Sprite->getTextureRect().getMaxX(), winSize.height-100) );
    CCFiniteTimeAction* cloud3ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerNight::cloudy3SpriteMoveFinished));
    cloud3Sprite->runAction( CCSequence::create(cloud3ActionMove,cloud3ActionMoveDone, NULL) );
    
    //云朵图片4
    CCSprite *cloud4Sprite = CCSprite::create("dark_clouds_4.png");
    cloud4Sprite->setPosition(ccp(winSize.width*-1, winSize.height-200));
    cloud4Sprite->setScale(scale);
    cloud4Sprite->setOpacity(103.0);
    this->addChild(cloud4Sprite);
    //云层4移动
    CCFiniteTimeAction* cloud4ActionMove = CCMoveTo::create( (float)winSize.width/8,ccp(winSize.width+cloud4Sprite->getTextureRect().getMaxX(), winSize.height-100) );
    CCFiniteTimeAction* cloud4ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerNight::cloudy4SpriteMoveFinished));
    cloud4Sprite->runAction( CCSequence::create(cloud4ActionMove,cloud4ActionMoveDone, NULL) );
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("rain.wav");
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("thunder.wav");
    
    return true;
}

void ThunderShowerNight::showThunderLight(CCNode *node)
{
    
    if (isPlaySound) {
        thunderSound  = CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("thunder.wav", false);
    }
    
    CCFadeIn *light1FadeIn = CCFadeIn::create(0.1f);
    CCFadeOut *light1FadeOut = CCFadeOut::create(0.1f);
    CCDelayTime *light1delayTime = CCDelayTime::create(0.1);
    
    CCFadeIn *light1FadeIn2 = CCFadeIn::create(0.2f);
    CCFadeOut *light1FadeOut2 = CCFadeOut::create(0.5f);
    CCDelayTime *light1delayTime2 = CCDelayTime::create(1);
    
    CCMoveTo *light1Move = CCMoveTo::create(winSize.width/2/8, ccp(winSize.width,winSize.height-(130*scale)));
    CCCallFunc *light1MoveDone = CCCallFunc::create(this, callfunc_selector(ThunderShowerNight::showThunderLightDone1));
    
    thunderlight1->runAction(CCSpawn::create(CCSequence::create(light1FadeIn,light1delayTime,light1FadeOut,light1FadeIn2,light1delayTime2,light1FadeOut2,NULL),CCSequence::create(light1Move,light1MoveDone,NULL),NULL));
    
    CCFadeIn *light2FadeIn = CCFadeIn::create(0.2f);
    CCFadeOut *light2FadeOut = CCFadeOut::create(0.2f);
    CCDelayTime *light2delayTime = CCDelayTime::create(0.1);
    
    CCFadeIn *light2FadeIn2 = CCFadeIn::create(0.2f);
    CCFadeOut *light2FadeOut2 = CCFadeOut::create(0.5f);
    CCDelayTime *light2delayTime2 = CCDelayTime::create(1);
    
    CCMoveTo *light2Move = CCMoveTo::create(winSize.width/2/8, ccp(winSize.width,winSize.height-(130*scale)));
    CCCallFunc *light2MoveDone = CCCallFunc::create(this, callfunc_selector(ThunderShowerNight::showThunderLightDone2));
    thunderlight2->runAction(CCSpawn::create(CCSequence::create(light2FadeIn,light2delayTime,light2FadeOut,light2FadeIn2,light2delayTime2,light2FadeOut2,NULL),CCSequence::create(light2Move,light2MoveDone,NULL),NULL));
    
}
void ThunderShowerNight::showThunderLightDone1()
{
    thunderlight1->setPosition(ccp(winSize.width/2+50,winSize.height-(120*scale)));
    thunderlight1->setOpacity(0);
}
void ThunderShowerNight::showThunderLightDone2()
{
    thunderlight2->setPosition(ccp(winSize.width/2+75,winSize.height-(120*scale)));
    thunderlight2->setOpacity(0);
}

void ThunderShowerNight::moveBackgroundSprite(CCNode *sender)
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
    CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerNight::moveBackgroundSprite));
    bgSprite->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );
}

void ThunderShowerNight::onExit()
{
    if (isPlaySound) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect(thunderSound);
    }
}

void ThunderShowerNight::onEnterTransitionDidFinish()
{
    if (isPlaySound) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
                                                                              "rain.wav", true);
    }
    
}

///////////////////////////////

void ThunderShowerNight::cloudy1SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-50));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+bgSpritespx, size.height-50) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerNight::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

void ThunderShowerNight::cloudy2SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-50));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+bgSpritespx, size.height-50) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerNight::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

void ThunderShowerNight::cloudy3SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-50));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+bgSpritespx, size.height-50) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerNight::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

void ThunderShowerNight::cloudy4SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-50));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+bgSpritespx, size.height-50) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(ThunderShowerNight::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}
