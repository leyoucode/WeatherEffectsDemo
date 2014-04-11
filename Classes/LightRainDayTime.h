//
//  LightRainDayTime.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#ifndef WeatherEffectsDemo_LightRainDayTime_h
#define WeatherEffectsDemo_LightRainDayTime_h

#include "cocos2d.h"

class LightRainDayTime : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    void onExit();
    void onEnterTransitionDidFinish();
    
    virtual void bgSpriteMoveFinished();
    
    // implement the "static node()" method manually
    CREATE_FUNC(LightRainDayTime);
};


#endif
