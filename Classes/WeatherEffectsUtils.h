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
#define BACKGROUND_MOVE_SPEED  5 

//daytime night

typedef enum DayTimeOrNight {
    DAYTIME,
    NIGHT
} DayTimeOrNight;


class WeatherEffectsUtils
{
public:
    
    //============晴天=================
    //晴天白天
    static void doSunnyDayTime(bool isPlaySound);
    //晴天晚上
    static void doSunnyNight(bool isPlaySound);
    
    //============雨天=================
    // 雷阵雨白天
    static void doThunderShowerDayTime(bool isPlaySound);
    // 雷阵雨晚上
    static void doThunderShowerNight(bool isPlaySound);
    // 雨白天
    static void doRainDayTime(bool isPlaySound);
    // 雨晚上
    static void doRainNight(bool isPlaySound);
    
    
    //============雪天=================
    //雪白天
    static void doSnowDayTime(bool isPlaySound);
    //雪晚上
    static void doSnowNight(bool isPlaySound);
    
    //============多云 =================
    //多云白天
    static void doCloudyDayTime(bool isPlaySound);
    //多云晚上
    static void doCloudyNight(bool isPlaySound);
    
    
};

#endif
