//
//  LightSnowNight.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/10/14.
//
//

#ifndef WeatherEffectsDemo_SnowNight_h
#define WeatherEffectsDemo_SnowNight_h

#include "cocos2d.h"
#import "WeatherEffectsUtils.h"
USING_NS_CC;

class SnowNight : public cocos2d::CCLayer
{
public:
    
    CCSize winSize;
    
    //背景纹理图片
    CCTexture2D *bgTexture;
    
    //是否播放声音
    bool isPlaySound;
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    void onExit();
    void onEnterTransitionDidFinish();
    virtual void keyBackClicked();//Android 返回键
    virtual void keyMenuClicked();//Android 菜单键
    
    // implement the "static node()" method manually
    CREATE_FUNC(SnowNight);
    
private:
    virtual void moveBackgroundSprite(CCNode *sender);
};


#endif
