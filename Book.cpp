// Kathy Saad
// 10-21-13
// Books with classes

#pragma once

#include <iostream>
#include "Book.h"
#include "Date.h"

// initializes count
int Book::count = 0;

//const Book & Book::operator = (const Book other){
//	this->due = other.due;
//	this->checkOut = other.checkOut;
//	strcpy(this->firstName, other.firstName);
//	strcpy(this->lastName, other.lastName);
//	strcpy(this->title, other.title);
//	return *this;
//}

// constructor
Book::Book(const char* lName, const char* fName, const char* bTitle, Date checkOutDate, Date dueDate){
	setLastName(lName);
	setFirstName(fName);
	setTitle(bTitle);
	setCheckOutDate(checkOutDate);
	setDueDate(dueDate);
	count++;
}

// assigns checkOut to user-entered checkOutDate 
Book & Book::setCheckOutDate(Date checkOutDate){
	checkOut.setDate(checkOutDate.getMonth(), checkOutDate.getDay(), checkOutDate.getYear());
	return *this;
}

// assigns due to user-entered dueDate 
Book & Book::setDueDate(Date dueDate){
	due.setDate(dueDate.getMonth(), dueDate.getDay(), dueDate.getYear());
	return *this;
}

// assigns lastName to user-entered lName 
Book & Book::setLastName(const char * lName){
	strcpy(lastName, lName);
	return *this;
}

// assigns firstName to user-entered fName
Book & Book::setFirstName(const char * fName){
	strcpy(firstName, fName);
	return *this;
}

// assigns title to user-entered bTitle
Book & Book::setTitle(const char * bTitle){
	strcpy(title, bTitle);
	return *this;
}

// returns lastName
const char * Book::getLastName(){
	return lastName;
}

// returns firstName
const char * Book::getFirstName(){
	return firstName;
}

// returns title
const char * Book::getTitle(){
	return title;
}

// returns checkOut
Date Book::getCheckOutDate(){
	return checkOut;
}

// returns due
Date Book::getDueDate(){
	return due;
}

// destructor
// decrements count each time a book object goes out of scope
Book::~Book(){
	count--;
}

// returns count of book objects in library
int Book::getCount(){
	return count;
}