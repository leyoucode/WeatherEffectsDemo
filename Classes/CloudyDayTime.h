//
//  CloudyDayTime.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#ifndef WeatherEffectsDemo_CloudyDayTime_h
#define WeatherEffectsDemo_CloudyDayTime_h

#include "cocos2d.h"
#import "WeatherEffectsUtils.h"
USING_NS_CC;

class CloudyDayTime : public cocos2d::CCLayer
{
public:
    
    CCSize winSize;
    
    float scale;
    
    //背景纹理图片
    CCTexture2D *bgTexture;
    
    //是否播放声音
    bool isPlaySound;
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(CloudyDayTime);
    
private:
    
    virtual void moveBackgroundSprite(CCNode *sender);
    
    virtual void cloudy1SpriteMoveFinished(CCNode *sender);
    virtual void cloudy2SpriteMoveFinished(CCNode *sender);
    virtual void cloudy3SpriteMoveFinished(CCNode *sender);
    virtual void cloudy4SpriteMoveFinished(CCNode *sender);
};

#endif
