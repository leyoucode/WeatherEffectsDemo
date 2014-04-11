//
//  CloudyDayTime.cpp
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#include "CloudyDayTime.h"
#import "WeatherEffectsUtils.h"

USING_NS_CC;

CCScene* CloudyDayTime::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    CloudyDayTime *layer = CloudyDayTime::create();
    layer->setTag(LAYER_TAG);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CloudyDayTime::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    //background image
    CCSprite *bgSprite = CCSprite::create("ld_bg_cloudy_day_time.jpg");
    float bgSpritespx = bgSprite->getTextureRect().getMaxX();
    float bgSpritespy = bgSprite->getTextureRect().getMaxY();
    // position the sprite on the center of the screen
    bgSprite->setPosition(ccp(0,size.height/2));
    bgSprite->setScaleX(size.width/bgSpritespx*2);
    bgSprite->setScaleY(size.height/bgSpritespy);
    // add the sprite as a child to this layer
    this->addChild(bgSprite, 0);
    
    //背景移动
    CCFiniteTimeAction* bgActionMove = CCMoveTo::create( (float)size.width/3,ccp(size.width, size.height/2) );
    CCFiniteTimeAction* bgActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(CloudyDayTime::bgSpriteMoveFinished));
    bgSprite->runAction( CCSequence::create(bgActionMove,bgActionMoveDone, NULL) );
    
    float scale = size.width / 320.0f;//缩放比率 因为我是按照320*480设计的粒子效果
    
    //云朵图片1
    CCSprite *cloud1Sprite = CCSprite::create("overcast_cloud1.png");
    cloud1Sprite->setPosition(ccp(size.width/2, size.height-100));
    cloud1Sprite->setScale(scale);
    this->addChild(cloud1Sprite);
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+cloud1Sprite->getTextureRect().getMaxX(), size.height-100) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(CloudyDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
    
    //云朵图片2
    CCSprite *cloud2Sprite = CCSprite::create("overcast_cloud2.png");
    cloud2Sprite->setPosition(ccp(size.width/2-150, size.height-100));
    cloud2Sprite->setScale(scale);
    this->addChild(cloud2Sprite);
    //云层2移动
    CCFiniteTimeAction* cloud2ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+cloud2Sprite->getTextureRect().getMaxX(), size.height-100) );
    CCFiniteTimeAction* cloud2ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(CloudyDayTime::cloudy2SpriteMoveFinished));
    cloud2Sprite->runAction( CCSequence::create(cloud2ActionMove,cloud2ActionMoveDone, NULL) );

    //云朵图片3
    CCSprite *cloud3Sprite = CCSprite::create("overcast_cloud1.png");
    cloud3Sprite->setPosition(ccp(size.width/2-300, size.height-100));
    cloud3Sprite->setScale(scale);
    this->addChild(cloud3Sprite);
    //云层3移动
    CCFiniteTimeAction* cloud3ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+cloud3Sprite->getTextureRect().getMaxX(), size.height-100) );
    CCFiniteTimeAction* cloud3ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(CloudyDayTime::cloudy3SpriteMoveFinished));
    cloud3Sprite->runAction( CCSequence::create(cloud3ActionMove,cloud3ActionMoveDone, NULL) );

    //云朵图片4
    CCSprite *cloud4Sprite = CCSprite::create("overcast_cloud2.png");
    cloud4Sprite->setPosition(ccp(size.width/2-450, size.height-100));
    cloud4Sprite->setScale(scale);
    this->addChild(cloud4Sprite);
    //云层4移动
    CCFiniteTimeAction* cloud4ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+cloud4Sprite->getTextureRect().getMaxX(), size.height-100) );
    CCFiniteTimeAction* cloud4ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(CloudyDayTime::cloudy4SpriteMoveFinished));
    cloud4Sprite->runAction( CCSequence::create(cloud4ActionMove,cloud4ActionMoveDone, NULL) );

    return true;
}

void CloudyDayTime::cloudy1SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-100));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+bgSpritespx, size.height-100) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(CloudyDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

void CloudyDayTime::cloudy2SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-100));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+bgSpritespx, size.height-100) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(CloudyDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

void CloudyDayTime::cloudy3SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-100));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/5,ccp(size.width+bgSpritespx, size.height-100) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(CloudyDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

void CloudyDayTime::cloudy4SpriteMoveFinished(CCNode *sender)
{
    CCSprite *cloud1Sprite = (CCSprite *)sender;
    float bgSpritespx = cloud1Sprite->getTextureRect().getMaxX();
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    cloud1Sprite->setPosition(ccp(size.width-bgSpritespx-bgSpritespx, size.height-100));
    //云层1移动
    CCFiniteTimeAction* cloud1ActionMove = CCMoveTo::create( (float)size.width/8,ccp(size.width+bgSpritespx, size.height-100) );
    CCFiniteTimeAction* cloud1ActionMoveDone = CCCallFuncN::create( this,callfuncN_selector(CloudyDayTime::cloudy1SpriteMoveFinished));
    cloud1Sprite->runAction( CCSequence::create(cloud1ActionMove,cloud1ActionMoveDone, NULL) );
}

//当背景图片移动完毕 再次切换到当前场景
void CloudyDayTime::bgSpriteMoveFinished()
{
    WeatherEffectsUtils::doCloudyDayTime(isPlaySound);
}

