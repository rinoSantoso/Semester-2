#ifndef BOOKS_H
#define BOOKS_H
#include <string>
#include <iostream>

using namespace std;

class Books
{
	protected:
		string author;
		string title;
		string publisher;
		int qty;
		int borrowed;
		int available;
		int year;
		string category;
	
	public:
		Books(){}
		
		Books(string title, string author, string publisher, int qty, int borrowed, int available, int year, string category){
			this->author = author;
			this->title = title;
			this->publisher = publisher;
			this->qty = qty;
			this->borrowed = borrowed;
			this->available = available;
			this->year = year;
			this->category = category;
				
		}
		
		void setAuthor(string author){
			this->author = author;
		}
		void setTitle(string title){
			this->title = title;
		}
		void setPublisher(string publisher){
			this->publisher = publisher;
		}
		void setQty(int qty){
			this->qty = qty;
		}
		void setBorrowed(int borrowed){
			this->borrowed = borrowed;
		}
		void setAvailable(int available){
			this->available = available;
		}
		void setYear(int year){
			this->year = year;
		}
		void setCategory(string category){
			this->category = category;
		}
		
		
		string getAuthor(){
			return author;
		}
		string getTitle(){
			return title;
		}
		string getPublisher(){
			return publisher;
		}
		int getQty(){
			return qty;
		}
		int getAvailable(){
			return available;
		}
		int getBorrowed(){
			return borrowed;
		}
		int getYear(){
			return year;
		}
		string getCategory(){
			return category;
		}
		
		void borrowBook(){
			if(available < 1){
				cout << "This book is not available. All copies of this book is currently being borrowed. Please try again later.\n";
			}
			else{
				borrowed++;
				available--;
				cout << "You've borrowed " << title << " by " << author << endl;
			}
		}
		
		void returnBook(){
			if (borrowed < 1){
				cout << "All copies of this book has been returned and is available for borrowing.\n";
			}
			else{
				borrowed--;
				available++;
				cout << "You have returned " << title << " by " << author << endl;
			}
		}
		
};

#endif
