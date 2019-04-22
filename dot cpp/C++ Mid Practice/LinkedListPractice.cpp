#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct node{
	string value;
	node *next, *prev;
};
node *head = NULL, *tail = NULL;

void insertHead(string value){
	node *curr = new(node);
	curr->value = value;
	if(head == NULL){
		head = curr;
		tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else{
		curr->next = head;
		head->prev = curr;
		curr->prev = NULL;
		head = curr;
	}
}

void insertTail(string value){
	node *curr = new(node);
	curr->value = value;
	if(tail == NULL){
		head = curr;
		tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else{
		curr->next = NULL;
		curr->prev = tail;
		tail->next = curr;
		tail = curr;
	}
}

void deleteHead(){
	node *curr = head;
	if (head == NULL){
		cout << "There is nothing to delete\n";
	}
	else if(head->next == NULL){
		head = NULL;
		tail = NULL;
		delete(curr);
	}
	else{
		head = head->next;
		head->prev = NULL;
		delete(curr);
	}
}

void view(){
	node *curr = head;
	int num = 1;
	if(head == NULL){
		cout << "No data in the Linked List\n";
	}
	else{
		while(curr != NULL){
			cout << num << ". " << curr->value << endl;
			curr = curr->next;
			num++;
		}
	}
}

void viewTail(){
	node *curr = tail;
	int num = 1;
	if(tail == NULL){
		cout << "No data in the Linked List";
	}
	else{
		while(curr != NULL){
			cout << num << ". " << curr->value << endl;
			curr = curr->prev;
			num++;
		}
	}
}

int main(){
	insertHead("is");
	insertHead("a");
	insertHead("Linked");
	insertHead("List");
	insertTail("This");
	insertHead("Something that needs to be deleted");
	deleteHead();
	viewTail();
}
