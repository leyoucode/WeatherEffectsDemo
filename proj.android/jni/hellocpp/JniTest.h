#ifndef JNI_TEST_H
#define JNI_TEST_H

#include "cocos2d.h"
#include "ThunderShower.h"

using namespace cocos2d;

void doRain(const char *packageName)
{
    CCLog("packageName: %s", packageName);

    cocos2d::CCScene *scene = ThunderShower::scene();

     cocos2d::CCDirector::sharedDirector()->replaceScene(cocos2d::CCTransitionCrossFade::create(1.2f, scene));

}

#endif
