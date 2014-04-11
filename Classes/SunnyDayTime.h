//
//  SunnyDayTime.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/9/14.
//
//

#ifndef WeatherEffectsDemo_SunnyDayTime_h
#define WeatherEffectsDemo_SunnyDayTime_h

#include "cocos2d.h"
#import "WeatherEffectsUtils.h"

class SunnyDayTime : public cocos2d::CCLayer
{
public:
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    void onExit();
    void onEnterTransitionDidFinish();
    
    // implement the "static node()" method manually
    CREATE_FUNC(SunnyDayTime);
    
private:
    
    int sunSpriteOpacity;
    
    bool isSunSpriteOpacityAdd;
    
    virtual void changeSunAlpha();
    
     virtual void bgSpriteMoveFinished();
    
    virtual void playBirdcall(CCNode *node);
};

#endif
