#include "timeSyncNKeep.h"

timeSyncNKeep:timeSyncNKeep(String server, float timeZone, int summerTime){ //creates timeSyncNKeep object
	//Time zone in floating point; second parameter: 1 for European summer time; 2 for US daylight saving time
	this.NTPtime NTPserver(server);
	this.timeZone = timeZone;
	this.summerTime = summerTime;
	this.rtcObject.Begin();
}

strDateTime timeSyncNKeep:getTimeFromNTP(){ //get time from ntp server
		return NTPserver.getNTPtime(timeZone, summerTime);
}

RtcDateTime timeSyncNKeep:NTPtoRTC(NPTtime time){ //converts ntc format to rtc
		return RtcDateTime(time.year,time.month,time.day,time.hour,time.minute,time.second);
}

void timeSyncNKeep:syncRTC(){ //sync rtc with time from NTP server
		strDateTime time =NTPserver.getNTPtime(timeZone, summerTime)
		rtcObject.SetDateTime(time);
}

void timeSyncNKeep:setTimeOnRTC(RTCtime time){ //manually set time on rtc
		rtcObject.SetDateTime(time);
}

RtcDateTime timeSyncNKeep:getTimeFromRTC(){ // returns time currently on RTC
		return rtcObject.GetDateTime();
}
