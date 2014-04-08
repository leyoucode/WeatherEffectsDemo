//
//  RainScene.h
//  helloword
//
//  Created by liu wei on 4/6/14.
//  Copyright 2014 __MyCompanyName__. All rights reserved.
//

#include "cocos2d.h"

class RainScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(RainScene);
};
