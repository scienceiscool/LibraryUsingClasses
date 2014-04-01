// Kathy Saad
// 10-21-13
// Books with classes

#pragma once

#include <iostream>

using namespace std;

class Date{
	friend ostream & operator << (ostream &, const Date &); // overloaded << operator for easy printing (of objects)

public:
	Date(int m = 1, int d = 1, int y = 1900); // constructor
	void setDate(int, int, int); // set the date (mm dd yyyy)
	bool leapYear() const;    // returns either T or F depending on whether the date is a leap year
	bool endOfMonth() const;  // returns either T or F depending on whether the date is at the end of the month
	void operator += (int); // increments date by as many days as are passed into the function
	int getMonth(); // returns month
	int getDay(); // returns day
	int getYear(); // returns year

private:
	int month;
	int day;
	int year;

	static const int days[];       // array of total days per month
	void helpIncrement();          // utility function
};