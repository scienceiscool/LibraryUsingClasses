// Kathy Saad
// 10-21-13
// Books with classes

#include <iostream>
#include "Date.h"
#include "Book.h"

using namespace std;

int main(){
	int mm, dd, yr;
	char response;
	Date checkOutDate, dueDate;
	char lastName[100], firstName[100], title[100];
	Book * BookArray[50];
	int j = 0;
	Book * newBook;

	cout << "Welcome to the CS library program.\n"
		 << "Please enter the date in integers according to the following format - mm dd yyyy: ";
	cin  >> mm >> dd >> yr;

	checkOutDate.setDate(mm, dd, yr);
	dueDate.setDate(mm, dd, yr);
	dueDate += 14;

	do{
		cout << "Please enter your one letter choice as follows:\n"
			 << "C: Check out a book\n"
			 << "T: Print all books checked out so far ordered by title\n"
			 << "Q: Quit this program\n";
		cin  >> response;

		switch(response){
		case 'C':
		case 'c':
			cout << "Please enter one line consisting of the first and last name of the author\n"
				 << "followed by the title of the book.\n";
			cin  >> firstName >> lastName >> ws;
			cin.getline(title, 99);

			newBook = new Book(lastName, firstName, title, checkOutDate, dueDate);
			BookArray[j] = newBook;
			j++;
			break;

		case 'T':
		case 't':
			for(int i = 0; i < newBook->getCount(); i++){
				cout << "Author" << "\t" << "Title" << "\t\t" << "Check Out Date" << "\t" << "Due Date" << endl;
				cout << BookArray[i]->getLastName() << ", " << BookArray[i]->getFirstName() << " "
					<< BookArray[i]->getTitle() << " " << BookArray[i]->getCheckOutDate() << " "
					<< BookArray[i]->getDueDate() << endl;
			}
			cout << endl;
			break;

		case 'q':
		case 'Q':
			cout << "Now quitting the program.\n";
			break;
		default:
			cout << "Invalid input.\n";
		}
	}while((response != 'q') && (response != 'Q'));

	return 0;
}