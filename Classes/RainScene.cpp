//
//  RainScene.cpp
//  helloword
//
//  Created by liu wei on 4/6/14.
//  Copyright 2014 __MyCompanyName__. All rights reserved.
//

#include "RainScene.h"

USING_NS_CC;

CCScene* RainScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    RainScene *layer = RainScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    CCParticleSystemQuad *emitter1 = CCParticleSystemQuad::create("rain2.plist");
    //emitter1->setStartColor(ccc4f(1,0,0,1));
    //emitter1->setBlendAdditive(false);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize(); // 屏幕大小
    emitter1->setPosition(ccp(size.width, size.height));
    scene->addChild(emitter1);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool RainScene::init()
{
    
    
    return true;
}
