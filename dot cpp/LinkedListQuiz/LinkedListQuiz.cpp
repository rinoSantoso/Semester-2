#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct node{
	string name;
	int qty;
	node *next, *prev;
};
node *head = NULL, *tail = NULL;

void addNewOrder(string name, int qty){
	node *curr = new(node);
	curr->name = name;
	curr->qty = qty;
	
	if (head == NULL){
		head = tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else{
		curr->next = head;
		curr->prev = NULL;
		head->prev = curr;
		head = curr;
	}
	
	cout << "-------- Add New Order Success --------\n\n";
}

void takeOrder(int number){
	int index  = number-1;
	node *curr = head;
	bool sentinel = false;
	
	for (int i = 0; i < index; i++){
		curr = curr->next;
	}
	
	if (head == NULL){
		cout << "---- There is No Order in The List ----\n\n";
	}
	else if (curr == head and curr == tail){
		head = tail = NULL;
		delete(curr);
		sentinel = true;
	}
	else if (curr == tail){
		curr->prev->next = NULL;
		tail = curr->prev;
		delete(curr);
		sentinel = true;
	}
	else if (curr == head){
		curr->next->prev = NULL;
		head = curr->next;
		delete(curr);
		sentinel = true;
	}
	else{
		curr->next->prev = curr->prev;
		curr->prev->next = curr->next;
		sentinel = true;delete(curr);
	}
	
	if (sentinel == true){
		cout << "--------- Take Order Success ----------\n\n";
	}
}

bool deleteHead(){
	node *curr = head;
	if(head == NULL){
		return false;
	}
	else{
		curr = head->next;
		delete(head);
		head = curr;
		return true;
	}
}

void deleteAll(){
	while(deleteHead());
}

// Table-style printing function (element)
template<typename T> void printElement(T t, const int& width)
{
    const char separator    = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

void printTableHeader(){
	const int noWidth = 4;
	const int nameWidth = 31;
	const int qtyWidth = 4;
	const int titleWidth = 38;
	
	printElement("         --- ORDER LIST ---", titleWidth);
	cout << "\n\n";
	printElement("No. ", noWidth);
	printElement("Name: ", nameWidth);
	printElement("Qty:", qtyWidth);
	cout << "\n\n";
}

void printOrderDetail(node *curr, int index){
	const int noWidth = 2;
	const int nameWidth = 31;
	const int qtyWidth = 4;
	
	
	printElement(index+1, noWidth);
	cout << ". ";
	printElement(curr->name, nameWidth);
	printElement(curr->qty, qtyWidth);
	cout << "\n";
}

int view(){
	node *curr = head;
	int index = 0;
	if (head == NULL){
		cout << "---- There is No Order in The List ----\n\n";
	}
	else{
		printTableHeader();
		while (curr != NULL){
			printOrderDetail(curr, index);
			index++;
			curr = curr->next;
		}
		cout << endl;
		return index;
	}
}

int main(){
	while(true){
		int mainOption;
		cout << "-------- BLUE MOTORCYCLE PARTS --------\n---------------------------------------\n1. View Order List\n2. Add New Order\n3. Take Order\n4. EXIT\n\n>> Input choice: ";
		cin >> mainOption;
		if(mainOption == 1){
			view();
		}
		else if(mainOption == 2){
			string name;
			int qty;
			while(true){
				cout << "Please input the name of motorcycle\npart you would like to order\n\n>> Name: ";
				cin.get();
				getline(cin, name);
				if(name.size() >= 3 && name.size() <= 30){
					break;
				}
				cout << "Invalid name length, must be between\n3 and 30 characters. Please try again.\n\n";
			}
			while(true){
				cout << "Please input the quantity of\nmotorcycle part you would like to order\n\n>> Qty: ";
				cin >> qty;
				if(qty >= 1 && qty <= 20){
					break;
				}
				cout << "Invalid quantity, must be between\n1 and 20. Please try again.\n\n";
			}
			addNewOrder(name, qty);
		}
		else if(mainOption == 3){
			int total = view();
			if (total > 0){
				int number;
				while(true){
					cout << "Input the number of order you\nwould like to take out\n\n>> Num: ";
					cin >> number;
					if (number >=1 and number <= total){
						takeOrder(number);
						break;
					}
					cout << "Invalid order number, must be between\n1 and " << total << ". Please try again.\n\n";
				}
			}
		}
		else if(mainOption == 4){
			deleteAll();
			break;
		}
	}
}
