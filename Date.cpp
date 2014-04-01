// Kathy Saad
// 10-21-13
// Books with classes

#pragma once

#include <iostream>
#include "Date.h"

// initialize static member at file scope; 
// one class-wide copy.
const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31 };

// date constructor
Date::Date( int m, int d, int y ) { setDate( m, d, y ); }

// set the date
void Date::setDate( int mm, int dd, int yy )
{
   month = ( mm >= 1 && mm <= 12 ) ? mm : 1;
   year = ( yy >= 1900 && yy <= 2100 ) ? yy : 1900;

   // test for a leap year
   if ( month == 2 && leapYear() )
      day = ( dd >= 1 && dd <= 29 ) ? dd : 1;
   else
      day = ( dd >= 1 && dd <= days[ month ] ) ? dd : 1;
}

// if the year is a leap year, return true; 
// otherwise, return false
bool Date::leapYear() const
{
   if ( year % 400 == 0 || ( year % 100 != 0 && year % 4 == 0 ) )
      return true;   // a leap year
   else
      return false;  // not a leap year
}

// determine if the day is the end of the month
bool Date::endOfMonth() const
{
   if ( month == 2 && leapYear() )
      return (day == 29); // last day of Feb. in leap year
   else
      return (day == days[ month ]);
}

// function to help increment the date
void Date::helpIncrement()
{
   if ( ! endOfMonth()) {  // date is not at the end of the month
      day++;
   }
   else if (month < 12) {       // date is at the end of the month, but month < 12
      day = 1;
      ++month;
   }
   else       // end of month and year: last day of the year
   {  
      day = 1;
      month = 1;
      ++year;
    }
}

// overloaded output operator
ostream & operator<<( ostream &output, const Date &d )
{
   static char *monthName[ 13 ] = { "", "January",
      "February", "March", "April", "May", "June",
      "July", "August", "September", "October",
      "November", "December" };

   output << monthName[ d.month ] << ' '
          << d.day << ", " << d.year;

   return output;   // enables cascading
}

// increments date by however many days are passed into the function
void Date::operator+=(int daysToAdd){
	for(int i = 0; i < daysToAdd; i++){
		helpIncrement();
	}
}

// returns month
int Date::getMonth(){
	return month;
}

// returns day
int Date::getDay(){
	return day;
}

// returns year
int Date::getYear(){
	return year;
}