![Flurry Icon](http://pic.yupoo.com/diwup_v/BY5uWwj1/c1igU.png) ![-X Icon](http://pic.yupoo.com/diwup_v/BY5waKBY/MC5wD.png)

#AnalyticX - With the latest 6.2.0 Flurry lib!!!
A C++ wrapper of [Flurry](http://www.flurry.com/) for [Cocos2d-X](https://github.com/cocos2d/cocos2d-x). Supports Android and iOS.

#Changelog
* Updated Flurry iOS SDK to version 6.4.0 and Flurry Android SDK to 5.3.0
* Updated environment to be compatible with Cocos2dX-3.4
* Added reflection to AnalyticXStringUtil
* Updated Flurry iOS SDK to version 4.0.0

#Environment
***cocos2dx-3.4*** or higher is recommended. Lower versions are not tested. Due to the underlying difference in the ***CCDictionary*** implementation, there may be compatibility issues when running on lower versions.

#Flurry SDK Version
1. Android: v2.2.5
2. iOS: v5.4.0

#Example Project
1. iOS: ./AnalyticX.xcodeproj
2. Android: ./AnalyticX/proj.android/

***You need to change the build script (such as build_native.sh for Mac OSX) according to your own environment before compiling***.

#Add to Your Own Project - iOS
1. Add ***FlurryAnalytics.h*** and ***libFlurryAnalytics.a*** to your Xcode project
2. Add ***AnalyticX.h*** and ***AnalyticX.mm*** to your Xcode project
3. Add ***AnalyticXStringUtil.h*** and ***AnalyticXStringUtil.mm*** to your Xcode project
4. Add ***AnalyticXMacros.h*** to your XCode project

#Add to Your Own Project - Android
1. Add ***com.diwublog.AnalyticX*** the package and its ***AnalyticXBridge.java*** to your Eclipse project
2. Add ***FlurryAnalytics.jar*** as an external jar to your Eclipse project
3. Drop ***AnalyticX.h*** and ***AnalyticX.cpp*** to your ***Classes*** folder
4. Drop ***AnalyticXStringUtilAndroid*** and ***AnalyticXStringUtilAndroid.cpp*** to your ***Classes*** folder
5. Add ***AnalyticX.cpp*** and ***AnalyticXStringUtilAndroid.cpp*** to your jni's ***Android.mk***
6. Add ***AnalyticXMacros.h*** to your XCode project
7. In the java implementation of your main activity (which should have been created by the Cocos2d-X script), import ***com.diwublog.AnalyticX.AnalyticXBridge***
8. At the beginning of ***onCreate(Bundle savedInstanceState)***, right after ***super.onCreate(savedInstanceState)***, add one line:

		AnalyticXBridge.sessionContext = this.getApplicationContext();
9. In the project manifest, add one line:

    	<uses-permission android:name="android.permission.INTERNET"></uses-permission>

#Add to Your Own Project - Hybrid
1. Follow the iOS and Android set up steps separately
2. iOS and Android will share the same ***AnalyticX.h*** and ***AnalyticXMacros.h*** header file
3. Use Separate Flurry Api Keys for Android and iOS

		#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    		AnalyticX::flurryStartSession("YOUR_FLURRY_API_KEY_FOR_IPHONE_BUILD");
		#endif

		#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    		AnalyticX::flurryStartSession("YOUR_FLURRY_API_KEY_FOR_ANDROID_BUILD");
		#endif
4. For Android, you need to end the session when the app goes in the background or when you manually quit the application, else the events may not be recorded on Flurry website. First, add the calls in your AppDelegate.cpp :

		void AppDelegate::applicationDidEnterBackground()
		{
    		AnalyticX::flurryEndSession();
			//Your code
		}

		void AppDelegate::applicationDidEnterForeground()
		{
	    	AnalyticX::flurryStartSession("YOUR_FLURRY_API_KEY_FOR_ANDROID_BUILD");
			//Your code
		}
5. After that, before any call to exit(0), add this code :

    	AnalyticX::flurryEndSession();

#Best Practice Using Analytic Service or Any Third Party Framework#
1. Define FLURRY at the top of source code, or the source code that starts first before other

        #define FLURRY
2. Or, you can define FLURRY as per project-based. For XCode, go to Build Setting->Apple LLVM 6.0 - Preprocessing, then add "FLURRY" with not double quotation to target build.
3. In code, wrap the flurry related calls with

        #ifdef FLURRY
            ...
            AnalyticX::flurryLogEvent("event_3");
            AnalyticX::flurryLogEventTimed(" log event timed test...", false);
            ...
        #endif
4. But if using macros in AnalyticXMacros.h, there's no need to wrap the code like in no.3. Just directly call like following.

        FLURRYLogEvent("event_logging_via_macro");
        FLURRYLogEvent("event_logging_via_macro dummy-num: %d - %d", 1, 2);


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
    static void flurrySetGender(const char * gender);//"m" for male, "f" for female

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

#Contributors
* Di Wu
* Anton Turko
* François Dupayrat
* Wasin Thonkaew
