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
#define LAYER_TAG -999

//daytime night

typedef enum DayTimeOrNight {
    DAYTIME,
    NIGHT
} DayTimeOrNight;


class WeatherEffectsUtils
{
public:
    
    //============雨天=================
    // 雷阵雨白天
    static void doThunderShowerDayTime(bool isPlaySound);
    // 雷阵雨晚上
    static void doThunderShowerNight(bool isPlaySound);
    // 大雨白天
    static void doHeavyRainDayTime(bool isPlaySound);
    // 大雨晚上
    static void doHeavyRainNight(bool isPlaySound);
    // 小雨白天
    static void doLightRainDayTime(bool isPlaySound);
    // 小雨晚上
    static void doLightRainNight(bool isPlaySound);
    
    //============雪天=================
    //大雪白天
    static void doHeavySnowDayTime(bool isPlaySound);
    //大雪晚上
    static void doHeavySnowNight(bool isPlaySound);
    //小雪白天
    static void doLightSnowDayTime(bool isPlaySound);
    //小雪晚上
    static void doLightSnowNight(bool isPlaySound);
    
    //============晴天=================
    //晴天白天
    static void doSunnyDayTime(bool isPlaySound);
    //晴天晚上
    static void doSunnyNight(bool isPlaySound);
    
    //============多云=================
    //多云白天
    static void doCloudyDayTime(bool isPlaySound);
    //多云晚上
    static void doCloudyNight(bool isPlaySound);
    
    //============ 大风================
    //大风白天
    static void doWindyDayTime(bool isPlaySound);
    
    //大风晚上
     static void doWindyNight(bool isPlaySound);
    
};

#endif
