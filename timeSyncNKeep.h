/*

 timeSyncNKeep library combines NTPtimesESP and RtcDS3231 libraries to provide
 universal solution to keeping time and syncing with NTP servers for application
 that require robust time managment solutions
 Author: Ante Klarin
 email: anteklarin2@gmail.com

*/


#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "NTPtimeESP.h"
#include "RtcDateTime.h"
#include "RtcDS1307.h"
#include "RtcUtility.h"

class timeSyncNKeep(){
	public:
		timeSyncNKeep(String server, float timeZone, int summerTime);
		RtcDS3231<TwoWire> rtcObject(Wire);
		strDateTime NPTtime;
		RtcDateTime RTCtime;
		float timeZone;
		int summerTime;
	
	private:
	
		timeSyncNKeep(String server, float timeZone, int summerTime);
		strDateTime getTimeFromNTP();
		RtcDateTime NTPtoRTC(NPTtime time);
		void syncRTC();
		void setTimeOnRTC(RTCtime time);
		RtcDateTime getTimeFromRTC();

}