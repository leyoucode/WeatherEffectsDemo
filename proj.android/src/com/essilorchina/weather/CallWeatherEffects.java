package com.essilorchina.weather;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.AlertDialog;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Looper;

public class CallWeatherEffects {

	
    //============晴天=================
    //晴天白天
	public static native void doSunnyDayTime(boolean isPlaySound);
    //晴天晚上
	public static native void doSunnyNight(boolean isPlaySound);
    
    //============雨天=================
    // 雷阵雨白天
	public static native void doThunderShowerDayTime(boolean isPlaySound);
    // 雷阵雨晚上
	public static native void doThunderShowerNight(boolean isPlaySound);
    // 雨白天
	public static native void doRainDayTime(boolean isPlaySound);
    // 雨晚上
	public static native void doRainNight(boolean isPlaySound);
    
    
    //============雪天=================
    //雪白天
	public static native void doSnowDayTime(boolean isPlaySound);
    //雪晚上
    public static native void doSnowNight(boolean isPlaySound);
    
    //============多云 =================
    //多云白天
    public static native void doCloudyDayTime(boolean isPlaySound);
    //多云晚上
    public static native void doCloudyNight(boolean isPlaySound);
	
    //Signature: ()V
    public static void back()
    {
    	 System.out.println("=======>back");
    	 
 	}
    	 
    
    //Signature: ()V
    public static void menu()
    {
    	
    		System.out.println("=======>menu");
    }
}
