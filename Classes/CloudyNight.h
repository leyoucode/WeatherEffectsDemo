//
//  CloudyNight.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#ifndef WeatherEffectsDemo_CloudyNight_h
#define WeatherEffectsDemo_CloudyNight_h

#include "cocos2d.h"
#import "WeatherEffectsUtils.h"

class CloudyNight : public cocos2d::CCLayer
{
public:
    
    //是否播放声音
    bool isPlaySound;
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(CloudyNight);
    
private:
    
    virtual void bgSpriteMoveFinished();
    virtual void cloudy1SpriteMoveFinished(CCNode *sender);
    virtual void cloudy2SpriteMoveFinished(CCNode *sender);
    virtual void cloudy3SpriteMoveFinished(CCNode *sender);
    virtual void cloudy4SpriteMoveFinished(CCNode *sender);
};

#endif
