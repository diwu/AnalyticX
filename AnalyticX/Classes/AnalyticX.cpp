//
//  AnalyticX.cpp
//  AnalyticX
//
//  Created by diwwu on 5/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "AnalyticX.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#include "AnalyticXStringUtilAndroid.h"
#include <string>

using namespace std;

void AnalyticX::flurryLogEvent(const char * eventName) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurryLogEvent");
        jstring stringArg1 = minfo.env->NewStringUTF(eventName);
        jstring stringArg2 = minfo.env->NewStringUTF("false");

        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryLogEventTimed(const char * eventName, bool timed) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurryLogEventTimed");
        jstring stringArg1 = minfo.env->NewStringUTF(eventName);
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        if (timed == true) {
            stringArg2 = minfo.env->NewStringUTF("true");

        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryLogEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters) {
    cocos2d::JniMethodInfo minfo;

    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;)V"); 

    if (!isHave) {
        //do nothing
    } else {
        string eventNameString("flurryLogEventWithParameters,");
        eventNameString += eventName;
		jstring stringArg0 = minfo.env->NewStringUTF(eventNameString.c_str());
        jstring stringArg2 = minfo.env->NewStringUTF("false");

        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, AnalyticXStringUtilAndroid::jobjectArrayFromCCDictionary(minfo, parameters), stringArg2);

    }
}

void AnalyticX::flurryLogEventWithParametersTimed(const char * eventName, cocos2d::CCDictionary * parameters, bool timed) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        string eventNameString("flurryLogEventWithParametersTimed,");
        eventNameString += eventName;
        jstring stringArg0 = minfo.env->NewStringUTF(eventNameString.c_str());
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        if (timed == true) {
            stringArg2 = minfo.env->NewStringUTF("true");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, AnalyticXStringUtilAndroid::jobjectArrayFromCCDictionary(minfo, parameters), stringArg2);
        
    }
}

// Since Flurry for Android does not support *parameters* in *endTimedEvent()*.
// This *parameters* will be ignored when running in Android
void AnalyticX::flurryEndTimedEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurryEndTimedEvent");
        jstring stringArg1 = minfo.env->NewStringUTF(eventName);
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryLogPageView() {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurryLogPageView");
        jstring stringArg1 = minfo.env->NewStringUTF("placeholder");
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetAppVersion(const char * version) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurrySetAppVersion");
        jstring stringArg1 = minfo.env->NewStringUTF(version);
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

const char * AnalyticX::flurryGetFlurryAgentVersion() {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","flurryGetAgentVersion", "()I"); 
    
    if (!isHave) {
        //do nothing
        return NULL;
    } else {
        jint version =  minfo.env->CallStaticIntMethod(minfo.classID, minfo.methodID);
        static char result[20];
        sprintf(result, "%d", version);
        return result;
    }
}

void AnalyticX::flurrySetShowErrorInLogEnabled(bool value) {
    //do nothing on Android
    //only supported in iOS
}

void AnalyticX::flurrySetDebugLogEnabled(bool value) {
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurrySetLogEnabled");
        jstring stringArg1 = minfo.env->NewStringUTF("placeholder");
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        if (value == true) {
            stringArg2 = minfo.env->NewStringUTF("true");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetSessionContinueSeconds(int seconds) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","flurrySetSessionContinueSecond", "(I)V"); 
    
    if (!isHave) {
        //do nothing
    } else {        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, (jint)seconds);
    }
}

void AnalyticX::flurrySetSecureTransportEnabled(bool value) {
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurrySetSecureEnabled");
        jstring stringArg1 = minfo.env->NewStringUTF("placeholder");
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        if (value == true) {
            stringArg2 = minfo.env->NewStringUTF("true");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryStartSession(const char * apiKey) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurryOnStartSession");
        jstring stringArg1 = minfo.env->NewStringUTF(apiKey);
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryEndSession() {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurryOnEndSession");
        jstring stringArg1 = minfo.env->NewStringUTF("placeholder");
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetUserID(const char * userID) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurrySetUserID");
        jstring stringArg1 = minfo.env->NewStringUTF(userID);
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetAge(int age) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","flurrySetAge", "(I)V"); 
    
    if (!isHave) {
        //do nothing
    } else {        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, (jint)age);
    }
}


void AnalyticX::flurrySetGender(const char * gender) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurrySetGender");
        jstring stringArg1 = minfo.env->NewStringUTF("female");
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        if (strcmp(gender, "m") == 0) {
            stringArg1 = minfo.env->NewStringUTF("male");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
    
}

void AnalyticX::flurrySetLatitudeLongitudeHorizontalAccuracyVerticalAccuracy(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy) {
    // Not supported in Android
}

void AnalyticX::flurrySetReportLocation(bool reportLocation) {
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = minfo.env->NewStringUTF("flurryReportLocation");
        jstring stringArg1 = minfo.env->NewStringUTF("placeholder");
        jstring stringArg2 = minfo.env->NewStringUTF("false");
        
        if (reportLocation == true) {
            stringArg2 = minfo.env->NewStringUTF("true");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose) {
    //iOS only
}

void AnalyticX::flurrySetSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled) {
    //iOS only
}

void AnalyticX::flurrySetEventLoggingEnabled(bool value) {
    //iOS only
}









