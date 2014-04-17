//
//  LightRainDayTime.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#ifndef WeatherEffectsDemo_RainDayTime_h
#define WeatherEffectsDemo_RainDayTime_h

#include "cocos2d.h"
USING_NS_CC;

class RainDayTime : public cocos2d::CCLayer
{
public:
    
    CCSize winSize;
    
    float scale;
    
    //背景纹理图片
    CCTexture2D *bgTexture;
    
    CCSprite *thunderlight1;
    
    CCSprite *thunderlight2;
    
    int thunderSound;//雷声
    
    //是否播放声音
    bool isPlaySound;
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    void onExit();
    void onEnterTransitionDidFinish();
    
    // implement the "static node()" method manually
    CREATE_FUNC(RainDayTime);
    
private:
    virtual void moveBackgroundSprite(CCNode *sender);
    
    virtual void cloudy1SpriteMoveFinished(CCNode *sender);
    virtual void cloudy2SpriteMoveFinished(CCNode *sender);
    virtual void cloudy3SpriteMoveFinished(CCNode *sender);
    virtual void cloudy4SpriteMoveFinished(CCNode *sender);
};


#endif
