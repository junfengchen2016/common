#include "system.datetime.h"

#include <time.h>
#include <stdio.h>

#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

namespace chenjunfeng
{
	namespace System
	{

DateTime DateTime::Now()
{
	ptime ptNow(second_clock::local_time());
	tm tm = to_tm(ptNow);

	DateTime ret;

	ret.Year = 1900 + tm.tm_year;
	ret.Month = tm.tm_mon + 1;
	ret.Day = tm.tm_mday;
	ret.Hour = tm.tm_hour;
	ret.Minute = tm.tm_min;
	ret.Second = tm.tm_sec;
	ret.DayofYear = tm.tm_yday + 1;
	ret.DayOfWeek = tm.tm_wday;

	return ret;
}

DateTime DateTime::AddDays(int value)
{
	DateTime dt = *this;

	ptime pt_old(date(dt.Year, dt.Month, dt.Day), time_duration(dt.Hour, dt.Minute, dt.Second));
	ptime pt_new = pt_old + days(1);

	tm tm = to_tm(pt_new);

	DateTime ret;

	ret.Year = 1900 + tm.tm_year;
	ret.Month = tm.tm_mon + 1;
	ret.Day = tm.tm_mday;
	ret.Hour = tm.tm_hour;
	ret.Minute = tm.tm_min;
	ret.Second = tm.tm_sec;
	ret.DayofYear = tm.tm_yday + 1;
	ret.DayOfWeek = tm.tm_wday;

	return ret;
}

DateTime::DateTime(int year, int month, int day)
{
	ptime pt(date(year, month, day), time_duration(0, 0, 0));
	tm tm = to_tm(pt);

	DateTime ret;

	ret.Year = 1900 + tm.tm_year;
	ret.Month = tm.tm_mon + 1;
	ret.Day = tm.tm_mday;
	ret.Hour = tm.tm_hour;
	ret.Minute = tm.tm_min;
	ret.Second = tm.tm_sec;
	ret.DayofYear = tm.tm_yday + 1;
	ret.DayOfWeek = tm.tm_wday;

	*this = ret;
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
{
	ptime pt(date(year, month, day), time_duration(hour, minute, second));
	tm tm = to_tm(pt);

	DateTime ret;

	ret.Year = 1900 + tm.tm_year;
	ret.Month = tm.tm_mon + 1;
	ret.Day = tm.tm_mday;
	ret.Hour = tm.tm_hour;
	ret.Minute = tm.tm_min;
	ret.Second = tm.tm_sec;
	ret.DayofYear = tm.tm_yday + 1;
	ret.DayOfWeek = tm.tm_wday;

	*this = ret;
}

int DateTime::CompareTo(DateTime value)
{
	using namespace boost::gregorian;
	using namespace boost::posix_time;

	ptime pt_old(date(Year, Month, Day), time_duration(Hour, Minute, Second));
	ptime pt_new(date(value.Year, value.Month, value.Day), time_duration(value.Hour, value.Minute, value.Second));

	if(pt_old < pt_new) return -1;
	else if(pt_old == pt_new) return 0;
	else return 1;
}

string DateTime::ToShortDateString()
{
	string ret = "";
	char buf[1000];
	sprintf(buf, "%d/%d/%d", Year, Month, Day);
	ret = buf;

	return ret;
}

string DateTime::ToShortTimeString()
{
	string ret = "";
	char buf[1000];
	sprintf(buf, "%d:%02d", Hour, Minute);
	ret = buf;

	return ret;
}

string DateTime::ToLongDateString()
{
	string ret = "";
	char buf[1000];
	sprintf(buf, "%d年%d月%d日", Year, Month, Day);
	ret = buf;

	return ret;
}

string DateTime::ToLongTimeString()
{
	string ret = "";
	char buf[1000];
	sprintf(buf, "%d:%02d:%02d", Hour, Minute, Second);
	ret = buf;

	return ret;
}
	}
}
