LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libldweather

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/CloudyDayTime.cpp \
                   ../../Classes/CloudyNight.cpp \
                   ../../Classes/MainScene.cpp \
                   ../../Classes/RainDayTime.cpp \
                   ../../Classes/RainNight.cpp \
                   ../../Classes/SnowDayTime.cpp \
                   ../../Classes/SnowNight.cpp \
                   ../../Classes/SunnyDayTime.cpp \
                   ../../Classes/SunnyNight.cpp \
                   ../../Classes/ThunderShowerDayTime.cpp \
                   ../../Classes/ThunderShowerNight.cpp \
                   ../../Classes/WeatherEffectsUtils.cpp \
                   hellocpp/CallWeatherEffects.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
