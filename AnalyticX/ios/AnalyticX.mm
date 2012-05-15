//
//  AnalyticX.cpp
//  AnalyticX
//
//  Created by diwwu on 5/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "AnalyticX.h"
#import "FlurryAnalytics.h"
#import "AnalyticXStringUtil.h"

void AnalyticX::flurrySetAppVersion(const char * version) {
    NSString *versionString = [AnalyticXStringUtil nsstringFromCString:version];
    [FlurryAnalytics setAppVersion:versionString];
}

const char * AnalyticX::flurryGetFlurryAgentVersion() {
    NSString *versionString = [FlurryAnalytics getFlurryAgentVersion];
    return [AnalyticXStringUtil cstringFromNSString:versionString];
}

void AnalyticX::flurrySetShowErrorInLogEnabled(bool value) {
    [FlurryAnalytics setShowErrorInLogEnabled:value];
}

void AnalyticX::flurrySetDebugLogEnabled(bool value) {
    [FlurryAnalytics setDebugLogEnabled:value];
}

void AnalyticX::flurrySetSessionContinueSeconds(int seconds) {
    [FlurryAnalytics setSessionContinueSeconds:seconds];
}

void AnalyticX::flurrySetSecureTransportEnabled(bool value) {
    [FlurryAnalytics setSecureTransportEnabled:value];
}

void AnalyticX::flurryStartSession(const char * apiKey) {
    [FlurryAnalytics startSession:[AnalyticXStringUtil nsstringFromCString:apiKey]];
}

void AnalyticX::flurryEndSession() {
    //Android only
}

void AnalyticX::flurryLogEvent(const char * eventName) {
    [FlurryAnalytics logEvent:[AnalyticXStringUtil nsstringFromCString:eventName]];
}

void AnalyticX::flurryLogEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters) {
    
    [FlurryAnalytics logEvent:[AnalyticXStringUtil nsstringFromCString:eventName] withParameters:[AnalyticXStringUtil nsDictionaryFromCCDictionary:parameters]];
}

void AnalyticX::flurryLogEventTimed(const char * eventName, bool timed) {
    [FlurryAnalytics logEvent:[AnalyticXStringUtil nsstringFromCString:eventName] timed:timed];
}

void AnalyticX::flurryLogEventWithParametersTimed(const char * eventName, cocos2d::CCDictionary * parameters, bool timed) {
    [FlurryAnalytics logEvent:[AnalyticXStringUtil nsstringFromCString:eventName] withParameters:[AnalyticXStringUtil nsDictionaryFromCCDictionary:parameters] timed:timed];
}

void AnalyticX::flurryEndTimedEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters) {
    [FlurryAnalytics endTimedEvent:[AnalyticXStringUtil nsstringFromCString:eventName] withParameters:[AnalyticXStringUtil nsDictionaryFromCCDictionary:parameters]];
}

void AnalyticX::flurryLogPageView() {
    [FlurryAnalytics logPageView];
}

void AnalyticX::flurrySetUserID(const char * userID) {
    [FlurryAnalytics setUserID:[AnalyticXStringUtil nsstringFromCString:userID]];
}

void AnalyticX::flurrySetAge(int age) {
    [FlurryAnalytics setAge:age];
}

void AnalyticX::flurrySetGender(const char * gender) {
    [FlurryAnalytics setGender:[AnalyticXStringUtil nsstringFromCString:gender]];
}

void AnalyticX::flurrySetLatitudeLongitudeHorizontalAccuracyVerticalAccuracy(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy) {
    [FlurryAnalytics setLatitude:latitude longitude:longitude horizontalAccuracy:horizontalAccuracy verticalAccuracy:verticalAccuracy];
}

void AnalyticX::flurrySetSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose) {
    [FlurryAnalytics setSessionReportsOnCloseEnabled:sendSessionReportsOnClose];
}

void AnalyticX::flurrySetSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled) {
    [FlurryAnalytics setSessionReportsOnPauseEnabled:setSessionReportsOnPauseEnabled];
}

void AnalyticX::flurrySetEventLoggingEnabled(bool value) {
    [FlurryAnalytics setEventLoggingEnabled:value];
}

void AnalyticX::flurrySetReportLocation(bool reportLocation) {
    //Android only
}












