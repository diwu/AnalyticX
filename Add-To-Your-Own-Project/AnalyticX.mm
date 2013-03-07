//
//  AnalyticX.cpp
//  AnalyticX
//
//  Created by diwwu on 5/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "AnalyticX.h"
#import "Flurry.h"
#import "AnalyticXStringUtil.h"

void AnalyticX::flurrySetAppVersion(const char * version) {
    NSString *versionString = [AnalyticXStringUtil nsstringFromCString:version];
    [Flurry setAppVersion:versionString];
}

const char * AnalyticX::flurryGetFlurryAgentVersion() {
    NSString *versionString = [Flurry getFlurryAgentVersion];
    return [AnalyticXStringUtil cstringFromNSString:versionString];
}

void AnalyticX::flurrySetShowErrorInLogEnabled(bool value) {
    [Flurry setShowErrorInLogEnabled:value];
}

void AnalyticX::flurrySetDebugLogEnabled(bool value) {
    [Flurry setDebugLogEnabled:value];
}

void AnalyticX::flurrySetSessionContinueSeconds(int seconds) {
    [Flurry setSessionContinueSeconds:seconds];
}

void AnalyticX::flurrySetSecureTransportEnabled(bool value) {
    [Flurry setSecureTransportEnabled:value];
}

void AnalyticX::flurryStartSession(const char * apiKey) {
    [Flurry startSession:[AnalyticXStringUtil nsstringFromCString:apiKey]];
}

void AnalyticX::flurryEndSession() {
    //Android only
}

void AnalyticX::flurryLogEvent(const char * eventName) {
    [Flurry logEvent:[AnalyticXStringUtil nsstringFromCString:eventName]];
}

void AnalyticX::flurryLogEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters) {
    
    [Flurry logEvent:[AnalyticXStringUtil nsstringFromCString:eventName] withParameters:[AnalyticXStringUtil nsDictionaryFromCCDictionary:parameters]];
}

void AnalyticX::flurryLogEventTimed(const char * eventName, bool timed) {
    [Flurry logEvent:[AnalyticXStringUtil nsstringFromCString:eventName] timed:timed];
}

void AnalyticX::flurryLogEventWithParametersTimed(const char * eventName, cocos2d::CCDictionary * parameters, bool timed) {
    [Flurry logEvent:[AnalyticXStringUtil nsstringFromCString:eventName] withParameters:[AnalyticXStringUtil nsDictionaryFromCCDictionary:parameters] timed:timed];
}

void AnalyticX::flurryEndTimedEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters) {
    [Flurry endTimedEvent:[AnalyticXStringUtil nsstringFromCString:eventName] withParameters:[AnalyticXStringUtil nsDictionaryFromCCDictionary:parameters]];
}

void AnalyticX::flurryLogPageView() {
    [Flurry logPageView];
}

void AnalyticX::flurrySetUserID(const char * userID) {
    [Flurry setUserID:[AnalyticXStringUtil nsstringFromCString:userID]];
}

void AnalyticX::flurrySetAge(int age) {
    [Flurry setAge:age];
}

void AnalyticX::flurrySetGender(const char * gender) {
    [Flurry setGender:[AnalyticXStringUtil nsstringFromCString:gender]];
}

void AnalyticX::flurrySetLatitudeLongitudeHorizontalAccuracyVerticalAccuracy(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy) {
    [Flurry setLatitude:latitude longitude:longitude horizontalAccuracy:horizontalAccuracy verticalAccuracy:verticalAccuracy];
}

void AnalyticX::flurrySetSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose) {
    [Flurry setSessionReportsOnCloseEnabled:sendSessionReportsOnClose];
}

void AnalyticX::flurrySetSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled) {
    [Flurry setSessionReportsOnPauseEnabled:setSessionReportsOnPauseEnabled];
}

void AnalyticX::flurrySetEventLoggingEnabled(bool value) {
    [Flurry setEventLoggingEnabled:value];
}

void AnalyticX::flurrySetReportLocation(bool reportLocation) {
    //Android only
}












