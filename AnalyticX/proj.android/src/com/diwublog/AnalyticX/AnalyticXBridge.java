package com.diwublog.AnalyticX;

import java.util.HashMap;

import android.content.Context;
import android.util.Log;

import com.flurry.android.Constants;
import com.flurry.android.FlurryAgent;

public class AnalyticXBridge {
	
	public static Context sessionContext;
	
	static void Bridge (String arg0, String arg1, String arg2) {

		if (arg0.equalsIgnoreCase("flurryLogEvent")) {

			AnalyticXBridge.flurryLogEvent(arg1);
		} else if (arg0.equalsIgnoreCase("flurryLogEventTimed")) {

			AnalyticXBridge.flurryLogEventTimed(arg1, arg2);
		} else if (arg0.equalsIgnoreCase("flurryEndTimedEvent")) {

			AnalyticXBridge.flurryEndTimedEvent(arg1);
		} else if (arg0.equalsIgnoreCase("flurryLogPageView")) {
			
			AnalyticXBridge.flurryLogPageView();
		} else if (arg0.equalsIgnoreCase("flurrySetAppVersion")) {
			
			AnalyticXBridge.flurrySetAppVersion(arg1);
		} else if (arg0.equalsIgnoreCase("flurrySetLogEnabled")) {
			AnalyticXBridge.flurrySetLogEnabled(arg2);
		} else if (arg0.equalsIgnoreCase("flurrySetSecureEnabled")) {
			AnalyticXBridge.flurrySetSecureEnabled(arg2);
		} else if (arg0.equalsIgnoreCase("flurryOnStartSession")) {
			AnalyticXBridge.flurryOnStartSession(arg1);
		} else if (arg0.equalsIgnoreCase("flurryOnEndSession")) {
			AnalyticXBridge.flurryOnEndSession();
		} else if (arg0.equalsIgnoreCase("flurrySetUserID")) {
			AnalyticXBridge.flurrySetUserID(arg1);
		} else if (arg0.equalsIgnoreCase("flurrySetGender")) {
			AnalyticXBridge.flurrySetGender(arg1);
		} else if (arg0.equalsIgnoreCase("flurryReportLocation")) {
			AnalyticXBridge.flurrySetReportLocation(arg2);
		}
			
	}
	
	static void Bridge (String arg0, String [] arg1, String arg2) {
		Log.v("diwu", "string array count = " + arg1.length);
		String[] splitedString = arg0.split(",");
		if (splitedString[0].equalsIgnoreCase("flurryLogEventWithParameters")) {
			AnalyticXBridge.flurryLogEventWithParameters(splitedString[1], arg1);
		} else if (arg0.equalsIgnoreCase("flurryLogEventWithParametersTimed")) {
			AnalyticXBridge.flurryLogEventWithParametersTimed(arg0, arg1, arg2);
		}
	}
	
	static private void flurryLogEvent(String eventID) {
		Log.v("diwu", "flurryLogEvent() is called... eventID = " + eventID);
		FlurryAgent.logEvent(eventID);
	}
	
	static private void flurryLogEventTimed(String eventID, String timed) {
		boolean timedBool = false;
		if (timed.equalsIgnoreCase("false")) {
			timedBool = false;
		} else if (timed.equalsIgnoreCase("true")) {
			timedBool = true;
		}
		Log.v("diwu", "flurryLogEventTimed(), eventID = " + eventID + ", timed = " + timedBool);
		FlurryAgent.logEvent(eventID, timedBool);
		
	}
	
	static private void flurryLogEventWithParameters(String eventID, String [] parametersArray) {
		Log.v("diwu", "flurryLogEventWithParameters... event id = " + eventID);

		HashMap<String, String> someMap = new HashMap<String, String>();

		for (int i = 0; i < parametersArray.length / 2; i++) {
			Log.v("diwu", "elm" + i + " = " + parametersArray[i]);
			Log.v("diwu", parametersArray[2*i] + " = " + parametersArray[2*i+1]);
			someMap.put(parametersArray[2*i], parametersArray[2*i+1]);
		}
		
		FlurryAgent.logEvent(eventID, someMap);
	}
	
	static private void flurryLogEventWithParametersTimed(String eventID, String [] parametersArray, String timed) {

		HashMap<String, String> someMap = new HashMap<String, String>();

		for (int i = 0; i < parametersArray.length / 2; i++) {
			Log.v("diwu", "total = " +  parametersArray.length / 2 + " ;elm" + i + " = " + parametersArray[2*i]);
			someMap.put(parametersArray[2*i], parametersArray[2*i+1]);
		}
		
		boolean timedBool = false;
		
		if (timed.equalsIgnoreCase("true")) {
			timedBool = true;
		}
		
		Log.v("diwu", "flurryLogEventWithParametersTimed... event id = " + eventID + " timed = " + timedBool);

		FlurryAgent.logEvent(eventID, someMap, timedBool);
	}
	
	static private void flurryEndTimedEvent(String eventID) {
		Log.v("diwu", "end timed event with id = " + eventID);
		FlurryAgent.endTimedEvent(eventID);
	}
	
	static private void flurryLogPageView() {
		Log.v("diwu", "log page view()...");
		FlurryAgent.onPageView();
	}
	
	static private void flurrySetAppVersion(String version) {
		Log.v("diwu", "set App Version = " + version);
		FlurryAgent.setVersionName(version);
	}

	static public int flurryGetAgentVersion() {
		return FlurryAgent.getAgentVersion();
	}
	
	static private void flurrySetLogEnabled(String enabled) {
		if (enabled.equalsIgnoreCase("true")) {
			Log.v("diwu", "set log to true");
			FlurryAgent.setLogEnabled(true);
		} else {
			Log.v("diwu", "set log to false");
			FlurryAgent.setLogEnabled(false);
		}
	}
	
	static public void flurrySetSessionContinueSecond(int seconds) {
		Log.v("diwu", "is set sessionn continue seconds to " + seconds);
		FlurryAgent.setContinueSessionMillis(seconds * 1000);
	}
	
	static private void flurrySetSecureEnabled(String enabled) {
		boolean enabledBool = false;
		if (enabled.equalsIgnoreCase("true")) {
			enabledBool = true;
		}
		
		Log.v("diwu", "https is " + enabledBool);
		
		FlurryAgent.setUseHttps(enabledBool);
	}
	
	static private void flurryOnStartSession(String apiKey) {
		Log.v("diwu", "is trying to start session... " + apiKey);
		FlurryAgent.onStartSession(sessionContext, apiKey);
	}
	
	static private void flurryOnEndSession() {
		Log.v("diwu", "flurry on end session");
		FlurryAgent.onEndSession(sessionContext);
	}
	
	static private void flurrySetUserID(String userID) {
		Log.v("diwu", "flurry set user id = " + userID);
		FlurryAgent.setUserId(userID);
	}
	
	static public void flurrySetAge(int age) {
		Log.v("diwu", "flurry set age = " + age);
		FlurryAgent.setAge(age);
	}
	
	static private void flurrySetGender(String gender) {
		if (gender.equalsIgnoreCase("male")) {
			Log.v("diwu", "flurry set gender: male");
			FlurryAgent.setGender(Constants.MALE);
		} else {
			Log.v("diwu", "flurry set gender: female");
			FlurryAgent.setGender(Constants.FEMALE);
		}
	}
	
	static private void flurrySetReportLocation(String reportLocation) {
		boolean reportLocationBool = false;
		
		if (reportLocation.equalsIgnoreCase("true")) {
			reportLocationBool = true;
		}
		
		Log.v("diwu", "reportLocation = "+ reportLocationBool);
		FlurryAgent.setReportLocation(reportLocationBool);
	}
}
