#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class clsTicket
{
private:

	static string CurrentDateTime()
	{
		//system datetime string
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now.tm_year + 1900;
		Month = now.tm_mon + 1;
		Day = now.tm_mday;
		Hour = now.tm_hour;
		Minute = now.tm_min;
		Second = now.tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}

		string _GetTimeLeft(int TimeLeft)
	{
		int Hours = 0;
		int Minutes = 0;
		if (TimeLeft >= 60)
		{
			Hours = TimeLeft / 60;
			Minutes = TimeLeft % 60;
			
			return to_string(Hours) + " Hour(s)  and " + to_string(Minutes) + " Minute(s)";
		}
		return to_string(TimeLeft) + " Minute(s)";

	}
	string _Date = " ";
	string _Name = "";
	int _Order = 0;
	int _TimeLeft = 0;


public:

	clsTicket(string Prefix, int Order, int ServeTime)
	{
		_Name = Prefix + to_string(Order + 1);
		_Order = Order;
		_Date = CurrentDateTime();
		_TimeLeft = Order * ServeTime;


	}

	void Print()
	{
		cout << "\n\t\t\t\t____________________________";
		cout << "\n\t\t\t\t          " << _Name;
		cout << "\n\t\t\t\t " << _Date;
		cout << "\n\t\t\t\t Waiting Clients = " << _Order;
		cout << "\n\t\t\t\t Serve Time In";
		cout << "\n\t\t\t\t " << _GetTimeLeft(_TimeLeft);
		cout << "\n\t\t\t\t____________________________\n\n";
	}


	string Name()
	{
		return _Name;
	}
};

