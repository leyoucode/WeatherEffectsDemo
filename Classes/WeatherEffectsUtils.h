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
    static void doThunderShowerDayTime();
    // 雷阵雨晚上
    static void doThunderShowerNight();
    // 大雨白天
    static void doHeavyRainDayTime();
    // 大雨晚上
    static void doHeavyRainNight();
    // 小雨白天
    static void doLightRainDayTime();
    // 小雨晚上
    static void doLightRainNight();
    
    //============雪天=================
    //大雪白天
    static void doHeavySnowDayTime();
    //大雪晚上
    static void doHeavySnowNight();
    //小雪白天
    static void doLightSnowDayTime();
    //小雪晚上
    static void doLightSnowNight();
    
    //============晴天=================
    //晴天白天
    static void doSunnyDayTime();
    //晴天晚上
    static void doSunnyNight();
    
    //============多云=================
    //多云白天
    static void doCloudyDayTime();
    //多云晚上
    static void doCloudyNight();
    
    //============ 大风================
    //大风白天
    static void doWindyDayTime();
    
    //大风晚上
     static void doWindyNight();
    
};

#endif
