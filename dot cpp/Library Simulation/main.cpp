#include <iostream> 
#include <string> 
#include <vector>
#include <iomanip>
#include <algorithm>
#include "books.h"
#include "functions.h"


using namespace std; 
  
int main() 
{ 
    vector<Books> library;
    cout << "Welcome to a smiple library simulation. ";
	while(true){
		int choice;
		cout << "What would you like to do?\n [1]. Add Book\n [2]. Search Book\n [3]. View All\n";
		cin >> choice;
		
		if(choice == 1){
			string title, author, publisher, category;
			int qty, borrowed, available, year;
			
			cout << "Enter the book title: ";
			cin.get();
			getline(cin, title);
			cout << "Enter the author name: ";
			getline(cin, author);
			cout << "Enter the publisher: ";
			getline(cin, publisher);
			cout << "Enter the quantity of books you would like to add: ";
			cin >> qty;
			cout << "Enter the book release year: ";
			cin >> year;
			cout << "Enter the book category: ";
			cin.get();
			getline(cin, category);
			
			if(&library[0] == NULL){
				available = qty;
				borrowed = 0;
				Books book(title, author, publisher, qty, borrowed, available, year, category);
				library.push_back(book);
			}
			else{
				bool bookCheck = false;
				for(int i = 0; i < library.size(); i++){
					if(library[i].getTitle() == title && library[i].getAuthor() == author && library[i].getPublisher() == publisher){
						qty += library[i].getQty();
						available = library[i].getAvailable() + qty;
						library[i].setQty(qty);
						library[i].setAvailable(available);
						bookCheck = true;
					}
				}
				if (bookCheck == false){
					available = qty;
					borrowed = 0;
					Books book(title, author, publisher, qty, borrowed, available, year, category);
					library.push_back(book);
				}
			}
			cout << "You have added " << title << " by " << author << " (" << qty << " books)" << "\n\n";
		}
		
		else if(choice == 2){
			if(&library[0] == NULL){
				cout << "No books have been added into this library. It is currently empty.\n";
			}
			else{
				int searchOption;
				cout << "What would the search be based on?\n [1]. Title\n [2]. Author\n [3]. Publisher\n [4]. Year\n [5]. Category\n";
				cin >> searchOption;
				
				if(searchOption == 1){
					string search;
					vector<Books> matching;
					cout << "Enter the title you would like to search: ";
					cin.get();
					getline(cin, search);
					
					for(int i = 0; i < library.size(); i++){
						size_t found = library[i].getTitle().find(search);
						if(found != string::npos){
							matching.push_back(library[i]);
						}
					}
					
					if(&matching[0] == NULL){
						cout << "No results found. Please try again.\n";
					}
					else{
						printTableHeader();
						for(int i = 0; i < matching.size(); i++){
							printBookDetail(matching[i], i);
						}
						cout << endl;
					}
				}
			}
		} 
		
		else if(choice == 3){
			if(&library[0] == NULL){
				cout << "No books have been added into this library. It is currently empty.\n";
			}
			else{
				printTableHeader();
				for(int i = 0; i < library.size(); i++){
					printBookDetail(library[i], i);
				}
				cout << endl;
			}
			
		}
	}

    return 0; 
}
