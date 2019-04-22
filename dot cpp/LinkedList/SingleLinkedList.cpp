#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct node{
	string name;
	int qty;
	struct node *next;
};
node *head = NULL;

void insertHead(string n, int q){
	//node *curr = (node*) malloc(sizeof(node));
	node *curr = new(node);
	curr->name = n;
	curr->qty = q;
	
	if(head == NULL){
		head = curr;
		curr->next = NULL;
	}
	else{
		curr->next = head;
		head = curr;
	}
}

void insertTail(string n, int q){
	node *curr = new(node);
	curr->name = n;
	curr->qty = q;
	
	if(head == NULL){
		head = curr;
		curr->next = NULL;
	}
	else{
		node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = curr;
		curr->next = NULL;
	}
	
}

void deleteHead(){
	node *curr = head;
	
	if(head == NULL){
		cout << "Data Still Empty\n";
	}
	else{
		head = head->next;
		delete(curr);
	}
}

void deleteTail(){
	node *curr = head;
	if(head == NULL){
		cout << "Data Still Empty";
	}
	else{
		if (head->next == NULL){
			head = head->next;
			delete(curr);
		}
		else{
			/*
			//Ver 1.0
			node *temp = head;
			curr = head->next;
			while(curr->next != NULL){
				curr = curr->next;
				temp = temp->next;
			}
			temp->next = NULL;
			delete(curr);
			*/
			
			//Ver 2.0
			curr = head;
			while(curr->next->next != NULL){
				curr = curr->next;
			}
			node *temp = curr;
			curr = curr->next;
			temp->next = NULL;
			delete(curr);
			
			
		}
	}
}

void view(){
	node *curr = head;
	while(curr != NULL){
		//print
		cout << curr->name << ": " << curr->qty << "\n";
		
		curr = curr->next; //go to next data
	}
	cout << endl;
}

void insertMid(string n, int q, string key){
	int sentinel;
	node *curr = new(node);
	curr -> name = n;
	curr->qty = q;
	
	if(head == NULL){
		head = curr;
		curr->next = NULL;
		sentinel++;
	}
	else{
		node *temp = head;
		while(temp != NULL){
			if(temp->name == key){
				curr->next = temp->next;
				temp->next = curr;
				sentinel++;
				break;
			}
			temp = temp->next;
		}
	}
	if (sentinel < 1){
			cout << "Specified string (" << key << ") does not exist in the list.\n";
		}
	
}

void deleteKey(string key){
	int sentinel;
	node *curr = head;
	if(head == NULL){
		cout << "Data Still Empty";
	}
	else{
		if(head->name == key){
			deleteHead();
			sentinel++;
		}
		else{
			node *temp = head;
			curr = head->next;
			
			while(curr != NULL){
				if (curr->name == key){
					temp->next = curr->next;
					delete(curr);
					sentinel++;
					break;
				}
				curr = curr->next;
				temp = temp->next;
			}
		}
		if (sentinel < 1){
			cout << "Specified string (" << key << ") does not exist in the list.\n";
		}
	}
}

int main(){
	insertHead("A", 10);
	insertHead("B", 11);
	insertHead("C", 12);
	insertTail("D", 13);
	insertTail("E", 14);
	insertMid("T", 88, "C");
	deleteKey("R");
	view();
	return 0;
}
