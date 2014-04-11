package com.weather.effect;

public class CallWeatherEffects {

	//============雨天=================
	// 雷阵雨白天
	public static native void doThunderShowerDayTime(boolean isPlaySound);
    // 雷阵雨晚上
	public static native void doThunderShowerNight(boolean isPlaySound);
    // 大雨白天
	public static native void doHeavyRainDayTime(boolean isPlaySound);
    // 大雨晚上
	public static native void doHeavyRainNight(boolean isPlaySound);
    // 小雨白天
	public static native void doLightRainDayTime(boolean isPlaySound);
    // 小雨晚上
	public static native void doLightRainNight(boolean isPlaySound);
    
    //============雪天=================
    //大雪白天
	public static native void doHeavySnowDayTime(boolean isPlaySound);
    //大雪晚上
	public static native void doHeavySnowNight(boolean isPlaySound);
    //小雪白天
	public static native void doLightSnowDayTime(boolean isPlaySound);
    //小雪晚上
	public static native void doLightSnowNight(boolean isPlaySound);
    
    //============晴天=================
    //晴天白天
	public static native void doSunnyDayTime(boolean isPlaySound);
    //晴天晚上
	public static native void doSunnyNight(boolean isPlaySound);
    
    //============多云=================
    //多云白天
	public static native void doCloudyDayTime(boolean isPlaySound);
    //多云晚上
	public static native void doCloudyNight(boolean isPlaySound);
    
    //============ 大风================
    //大风白天
    public static native void doWindyDayTime(boolean isPlaySound);
    
    //大风晚上
    public static native void doWindyNight(boolean isPlaySound);
}
