//
//  LightSnowDayTime.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#ifndef WeatherEffectsDemo_LightSnowDayTime_h
#define WeatherEffectsDemo_LightSnowDayTime_h

#include "cocos2d.h"
#import "WeatherEffectsUtils.h"

class LightSnowDayTime : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(LightSnowDayTime);
    
private:
    virtual void bgSpriteMoveFinished();
};

#endif
