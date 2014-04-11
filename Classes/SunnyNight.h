//
//  Sunny.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/9/14.
//
//

#ifndef WeatherEffectsDemo_SunnyNight_h
#define WeatherEffectsDemo_SunnyNight_h

#include "cocos2d.h"
#import "WeatherEffectsUtils.h"

class SunnyNight : public cocos2d::CCLayer
{
public:
    
    //是否播放声音
    bool isPlaySound;
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();

    // implement the "static node()" method manually
    CREATE_FUNC(SunnyNight);
    
private:
    
    int moonSpriteOpacity;
    
    bool isMoonSpriteOpacityAdd;
    
    virtual void changeMoonAlpha();
    
    virtual void bgSpriteMoveFinished();
};
#endif
