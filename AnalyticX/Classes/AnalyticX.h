//
//  AnalyticX.h
//  AnalyticX
//
//  Created by diwwu on 5/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnalyticX_AnalyticX_h
#define AnalyticX_AnalyticX_h

#include "cocos2d.h"

class AnalyticX {
    
public:
    /*
     optional sdk settings that should be called before start session
     */
    /*
    + (void)setAppVersion:(NSString *)version;		// override the app version
    + (NSString *)getFlurryAgentVersion;			// get the Flurry Agent version number
    + (void)setShowErrorInLogEnabled:(BOOL)value;	// default is NO
    + (void)setDebugLogEnabled:(BOOL)value;			// generate debug logs for Flurry support, default is NO
    + (void)setSessionContinueSeconds:(int)seconds; // default is 10 seconds
    + (void)setSecureTransportEnabled:(BOOL)value; // set data to be sent over SSL, default is NO
     */
    static void flurrySetAppVersion(const char * version);
    static const char * flurryGetFlurryAgentVersion();
    static void flurrySetShowErrorInLogEnabled(bool value);
    static void flurrySetDebugLogEnabled(bool value);
    static void flurrySetSessionContinueSeconds(int seconds);
    static void flurrySetSecureTransportEnabled(bool value);
    
    /*
     start session, attempt to send saved sessions to server 
     */
    /*
    + (void)startSession:(NSString *)apiKey;
     */
    static void flurryStartSession(const char * apiKey);

    /*
     log events or errors after session has started
     */
    /*
    + (void)logEvent:(NSString *)eventName;
    + (void)logEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters;
    + (void)logError:(NSString *)errorID message:(NSString *)message exception:(NSException *)exception;
    + (void)logError:(NSString *)errorID message:(NSString *)message error:(NSError *)error;
     */
    static void flurryLogEvent(const char * eventName);
    static void flurryLogEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters);

    /* 
     start or end timed events
     */
    /*
    + (void)logEvent:(NSString *)eventName timed:(BOOL)timed;
    + (void)logEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters timed:(BOOL)timed;
    + (void)endTimedEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters;	// non-nil parameters will update the parameters
     */
    static void flurryLogEventTimed(const char * eventName, bool timed);
    static void flurryLogEventWithParametersTimed(const char * eventName, cocos2d::CCDictionary * parameters, bool timed);
    static void flurryEndTimedEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters); // non-nil parameters will update the parameters
    
    /*
     count page views
     */
    /*
    + (void)logAllPageViews:(id)target;		// automatically track page view on UINavigationController or UITabBarController
    + (void)logPageView;					// manually increment page view by 1
     */
    static void flurryLogPageView();
    
    /*
     set user info
     */
    /*
    + (void)setUserID:(NSString *)userID;	// user's id in your system
    + (void)setAge:(int)age;				// user's age in years
    + (void)setGender:(NSString *)gender;	// user's gender m or f
     */
    static void flurrySetUserID(const char * userID);
    static void flurrySetAge(int age);
    static void flurrySetGender(const char * gender);
    
    /*
     set location information
     */
    /*
    + (void)setLatitude:(double)latitude longitude:(double)longitude horizontalAccuracy:(float)horizontalAccuracy verticalAccuracy:(float)verticalAccuracy;
     */
    static void flurrySetLatitudeLongitudeHorizontalAccuracyVerticalAccuracy(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy);
    
    /*
     optional session settings that can be changed after start session
     */
    /*
    + (void)setSessionReportsOnCloseEnabled:(BOOL)sendSessionReportsOnClose;	// default is YES
    + (void)setSessionReportsOnPauseEnabled:(BOOL)setSessionReportsOnPauseEnabled;	// default is NO
    + (void)setEventLoggingEnabled:(BOOL)value;		// default is YES
     */
    static void flurrySetSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose);
    static void flurrySetSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled);
    static void flurrySetEventLoggingEnabled(bool value);
};

#endif
