#pragma once

#include <string>
using namespace std;

namespace chenjunfeng
{
	namespace System
	{

class DateTime
{
public:
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
	int DayofYear;
	int DayOfWeek;
public:
	static DateTime Now();
	DateTime AddDays(int value);
	DateTime() {};
	DateTime(int year, int month, int day);
	DateTime(int year, int month, int day, int hour, int minute, int second);
	int CompareTo(DateTime value);
	string ToShortDateString();
	string ToShortTimeString();
	string ToLongDateString();
	string ToLongTimeString();
};

	}
}