// Kathy Saad
// 10-21-13
// Books with classes

#pragma once
#include "Date.h"

class Book{

public:
	Book(const char * lName, const char * fName, const char * bTitle, Date checkOutDate, Date dueDate);
	// constructor
	// Postcondition: All parameters are initialized, and the count has been incremented by 1
	// Parameters:
		// lName - last name of author
		// fName - first name of author
		// bTitle - title of the book that the author wrote
		// checkOutDate - the date that the book was checked out
		// dueDate - the date that the book is due to be returned (14 days after the check out date)
				
	~Book();
	// Precondition: count has been declared and initialized, and given a value greater than 0
	// Postcondition: count has been decremented once a book has gone out of scope, or has been removed

	Book & setCheckOutDate(Date checkOutDate);
	// Precondition: checkOutDate has been given a value
	// Postcondition: the private member checkOut has been assigned the value that the user entered
	// Parameters:
		// checkOutDate - the check out date that the user entered

	Book & setDueDate(Date dueDate);
	// Precondition: dueDate has been given a value
	// Postcondition: the private member due has been assigned the value that the user entered
	// Parameters:
		// dueDate - the due date that the user entered

	Book & setFirstName(const char * fName);
	// Precondition: fName has been given a value
	// Postcondition: the private member firstName has been assigned the value that the user entered
	// Parameters:
		// fName - the first name of the author that the user entered

	Book & setLastName(const char * lName);
	// Precondition: lName has been given a value
	// Postcondition: the private member lastName has been assigned the value that the user entered
	// Parameters:
		// lName - the last name of the author that the user entered

	Book & setTitle(const char * bTitle);
	// Precondition: bTitle has been given a value
	// Postcondition: the private member title has been assigned the value that the user entered
	// Parameters:
		// bTitle - the title of the book that the user entered

	const char * getLastName();
	// Precondition: lastName has been assigned a value
	// Postcondition: lastName's value is returned

	const char * getFirstName();
	// Precondition: firstName has been assigned a value
	// Postcondition: firstName's value is returned

	const char * getTitle();
	// Precondition: title has been assigned a value
	// Postcondition: title's value is returned

	Date getCheckOutDate();
	// Precondition: checkOut has been assigned a value
	// Postcondition: checkOut's value is returned

	Date getDueDate();
	// Precondition: due has been assigned a value
	// Postcondition: due's value is returned

	static int getCount();
	// Precondition: count has been initialized and given some value
	// Postcondition: count (or number of "books" in library) is returned

private:
	char firstName[30];
	char lastName[30];
	char title[30];
	Date checkOut;
	Date due;
	static int count;
};