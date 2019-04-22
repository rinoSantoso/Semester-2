#include <iostream>
#include <string>

using namespace std;

struct node{
	int value;
	node *next, *prev;
}*head = NULL, *tail = NULL;

void insertHead(int value){
	node *curr = new(node);
	curr->value = value;
	
	if(head == NULL){
		head = tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	
	else{
		curr->next = head;
		head->prev = curr;
		head = curr;
		curr->prev = NULL;
	}
}

void insertTail(int value){
	node *curr = new(node);
	curr->value = value;
	
	if(head == NULL){
		head = tail = curr;
		curr->next = curr->prev = NULL; 
	}
	else{
		tail->next = curr;
		curr->prev = tail;
		curr->next = NULL;
		tail = curr;
	}
}

void insert(int value){
	node *curr = new(node);
	curr->value = value;
	
	if(head == NULL){
		head = tail = curr;
		curr->next = curr->prev = NULL; 
	}
	
	else{
		if(curr->value <= head->value){
			insertHead(value);
		}
		
		else if(curr->value >= tail->value){
			insertTail(value);
		}
		
		else{
			node *pointer  = head->next;
			
			while(pointer != NULL){
				if (curr->value <= pointer->value){
					curr->next = pointer;
					curr->prev = pointer->prev;
					pointer->prev = curr;
					pointer = curr->prev;
					pointer->next = curr;
					break;
				}
				pointer = pointer->next;
			}
		}
	}
	
}
/*
void deleteHead(){
	if (head == NULL){
		cout << "There is no head.\n";
	}
	else{
		node *curr = head;
		if(head->next == NULL){
			tail = head = NULL;
			delete(curr);
		}
		else{
			head = head->next;
			head->prev = NULL;
			delete(curr);
		}
	}
}*/

void deleteHead(){
	node *curr = head;
	if (head == NULL){
		cout << "There is nothing to delete\n";
	}
	else if(head->next = NULL){
		head = NULL;
		tail = NULL;
		delete(curr);
	}
	else{
		head = head->next;
		head->prev = NULL;
		delete(curr);
	}
	cout << "Item is deleted";
}

void deleteTail(){
	if (head == NULL){
		cout << "There is no head.\n";
	}
	else{
		node *curr = tail;
		if(tail->prev == NULL){
			head = tail = NULL;
			delete(curr);
		}
		else{
			tail = tail->prev;
			tail->next = NULL;
			delete(curr);
		}
	}
}

void deleteKey(int key){
	node *curr = head->next;
	int deleteFlag = 0;
	if(head != NULL){
		if(head->value == key){
			while(head->value == key){
				deleteHead();
				deleteFlag++;
			}
		}
		else if(tail->value == key){
			while(tail->value == key){
				deleteTail();
				deleteFlag++;
			}
		}
		else{
			node *shadowcurr = head;
			int sentinel = 0;
			while(curr != NULL){
				if(curr->value == key){
					shadowcurr->next = shadowcurr->next->next;
					curr->next->prev = shadowcurr;
					delete(curr);
					deleteFlag++;
					curr = shadowcurr->next;
					sentinel++;
				}
				if(sentinel <1){
					curr = curr->next;
					shadowcurr = shadowcurr->next;
				}
				sentinel = 0;	
			}
		}
	}
	if(deleteFlag < 1){
		cout << "Key not found.\n";
	}
}

void view(){
	node *curr = head;
	while(curr != NULL){
		cout << curr->value << " ";
		curr = curr->next;
	}
}

void viewTail(){
	node *curr = tail;
	while(curr !=NULL){
		cout << curr->value << " ";
		curr = curr->prev;
	}
}

int main(){
	insert(11);
	insert(11);
	insert(10);
	deleteKey(9);
	deleteHead();
	view();
	cout << endl;
	viewTail();
	
	
	return 0;
}
