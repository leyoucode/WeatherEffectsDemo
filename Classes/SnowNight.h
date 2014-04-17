//
//  LightSnowNight.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#ifndef WeatherEffectsDemo_LightSnowNight_h
#define WeatherEffectsDemo_LightSnowNight_h

#include "cocos2d.h"
#import "WeatherEffectsUtils.h"

class SnowNight : public cocos2d::CCLayer
{
public:
    
    //是否播放声音
    bool isPlaySound;
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    void onExit();
    void onEnterTransitionDidFinish();
    
    // implement the "static node()" method manually
    CREATE_FUNC(SnowNight);
    
private:
    virtual void bgSpriteMoveFinished();
};


#endif
