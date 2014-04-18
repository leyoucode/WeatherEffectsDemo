
#ifndef WeatherEffectsDemo_MainScene_h
#define WeatherEffectsDemo_MainScene_h

#include "cocos2d.h"

class MainScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    virtual void keyBackClicked();//Android 返回键
    virtual void keyMenuClicked();//Android 菜单键
    
    // implement the "static node()" method manually
    CREATE_FUNC(MainScene);
};

#endif // __HELLOWORLD_SCENE_H__
