#AnalyticX
A C++ wrapper of [Flurry](http://www.flurry.com/) for [Cocos2d-X](https://github.com/cocos2d/cocos2d-x). Supports Android and iOS.

#Requirement
Requires ***cocos2d-2.0-rc0a-x-0.1.0*** or higher

#Example Project
1. iOS: ./AnalyticX.xcodeproj
2. Android: ./AnalyticX/proj.android/

***You need to change the build script (such as build_native.sh for Mac OSX) according to your own environment before compiling***.

#Add to Your Own Project - iOS
1. Add ***FlurryAnalytics.h*** and ***libFlurryAnalytics.a*** to your Xcode project
2. Add ***AnalyticX.h*** to your Xcode project
3. Add ***AnalyticX.mm*** to your Xcode project

#Add to Your Own Project - Android
1. Add ***com.diwublog.AnalyticX*** the package and its ***AnalyticXBridge.java*** to your Eclipse project
2. Add ***FlurryAgent.jar*** as an external jar to your Eclipse project
3. Add ***AnalyticX.h*** and ***AnalyticX.cpp*** to your ***Classes*** folder
4. Add ***AnalyticX.cpp*** to your jni's ***Android.mk***
5. In the java implementation of your main activity (which should have been created by the Cocos2d-X script), import ***com.diwublog.AnalyticX.AnalyticXBridge***
6. In the beginning of ***onCreate(Bundle savedInstanceState)***, right after ***super.onCreate(savedInstanceState)***, add one line:

		AnalyticXBridge.sessionContext = this.getApplicationContext();
7. In the project manifest, add one line:

    	<uses-permission android:name="android.permission.INTERNET"></uses-permission>

#Use Separate Api Keys for Android and iOS
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    	AnalyticX::flurryStartSession("YOUR_FLURRY_API_KEY_FOR_IPHONE_BUILD");
	#endif
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    	AnalyticX::flurryStartSession("YOUR_FLURRY_API_KEY_FOR_ANDROID_BUILD");
	#endif

#APIs Supported on both Android and iOS
    static void flurrySetAppVersion(const char * version);
    static const char * flurryGetFlurryAgentVersion();
    static void flurrySetDebugLogEnabled(bool value);
    static void flurrySetSessionContinueSeconds(int seconds);//The param is in second. Will be converted to millisecond internally.
    static void flurrySetSecureTransportEnabled(bool value);
    static void flurryStartSession(const char * apiKey);
    static void flurryLogEvent(const char * eventName);
    static void flurryLogEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters);
    static void flurryLogEventTimed(const char * eventName, bool timed);
    static void flurryLogEventWithParametersTimed(const char * eventName, cocos2d::CCDictionary * parameters, bool timed);
    static void flurryEndTimedEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters);
    static void flurryLogPageView();
    static void flurrySetUserID(const char * userID);
    static void flurrySetAge(int age);
    static void flurrySetGender(const char * gender);//iOS + Android. "m" for male, "f" for female

#APIs Supported only on iOS
When running on an Android device, these APIs will have no effect. They are safe and won't crash.

    static void flurrySetShowErrorInLogEnabled(bool value);
    static void flurrySetLatitudeLongitudeHorizontalAccuracyVerticalAccuracy(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy);
    static void flurrySetSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose);
    static void flurrySetSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled);
    static void flurrySetEventLoggingEnabled(bool value);

#APIs Supported only on Android
When running on an iOS device, these APIs will have no effect. They are safe and won't crash.

    static void flurryEndSession();
    static void flurrySetReportLocation(bool reportLocation);

#Email: <diwufet@gmail.com>
#You're welcome to contribute. ;-)
