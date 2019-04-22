#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <iostream>
#include <iomanip>
#include "books.h"


using namespace std;

// Table-style printing function (element)
template<typename T> void printElement(T t, const int& width)
{
    const char separator    = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

// Table-style printing function (row)
void printBookDetail(Books book, int index){
	const int noWidth = 4;
	const int titleWidth = 45;
	const int authorWidth = 20;
	const int publisherWidth = 20;
	const int qtyWidth = 5;
	const int borrowedWidth= 10;
	const int availableWidth = 11;
	const int yearWidth = 6;
	const int categoryWidth = 15;
	
	printElement(index+1, noWidth);
	printElement(book.getTitle(), titleWidth);
	printElement(book.getAuthor(), authorWidth);
	printElement(book.getPublisher(), publisherWidth);
	printElement(book.getQty(), qtyWidth);
	printElement(book.getBorrowed(), borrowedWidth);
	printElement(book.getAvailable(), availableWidth);
	printElement(book.getYear(), yearWidth);
	printElement(book.getCategory(), categoryWidth);
	cout << "\n";
	
}

// Table-style printing function (header)
void printTableHeader(){
	const int noWidth = 4;
	const int titleWidth = 45;
	const int authorWidth = 20;
	const int publisherWidth = 20;
	const int qtyWidth = 5;
	const int borrowedWidth = 10;
	const int availableWidth = 11;
	const int yearWidth = 6;
	const int categoryWidth = 15;
	
	printElement("No. ", noWidth);
	printElement("Title: ", titleWidth);
	printElement("Author: ", authorWidth);
	printElement("Publisher: ", publisherWidth);
	printElement("Qty: ", qtyWidth);
	printElement("Borrowed: ", borrowedWidth);
	printElement("Available: ", availableWidth);
	printElement("Year: ", yearWidth);
	printElement("Category: ", categoryWidth);
	cout << "\n\n";
}

#endif
