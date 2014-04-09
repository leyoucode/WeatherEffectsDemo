//
//  WeatherEffectsUtils.h
//  WeatherEffectsDemo
//
//  Created by liu wei on 4/8/14.
//
//

#ifndef WeatherEffectsDemo_WeatherEffectsUtils_h
#define WeatherEffectsDemo_WeatherEffectsUtils_h

#define TRANSACTION_DURATION 0.8f

class WeatherEffectsUtils
{
public:
    // 雷阵雨
    static void doThunderShower();
    // 阵雨
    static void doShower();
    //小，中雨
    static void doLightRain();
    //大雨
    static void doHeavyRain();
    
};

#endif
