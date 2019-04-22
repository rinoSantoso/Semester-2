#ifndef BOOKS_H
#define BOOKS_H
#include<iostream>

using namespace std;

template <typename T>
struct Node{
	T data;
	Node<T> *next = NULL;
	Node<T> (){}
	Node<T>(T data, Node<T> *ptr){
		this -> data = data;
		this -> next = ptr;
	}
};

template <typename T>
class LinkedList{
	private:
		Node<T> *head;
		Node<T> *tail;
	public:
		LinkedList(){
			head = tail = new Node<T>;
		}
		
		class iterator{
			public:
				Node<T> *current;
				
				iterator(){}
				iterator(Node<T> *ptr){
					current = ptr;
				} 
				
				T operator*()const {
					return current->data;
				};
				
				iterator operator++(int){
					current = current -> next;
					return *this;
				};
				
				bool operator!=(const iterator &right){
					return current != right.current;
				}
		};
		
		iterator itr_begin(){
			return iterator(head->next);
		}
		
		iterator itr_end(){
			return iterator(NULL);
		}
		
		void InsertBack(T x){
			Node<T> *temp;
			temp = tail;
			tail = new Node<T>;
			tail -> data = x;
			temp -> next = tail;
		}
		bool empty(){
			if(head->next == NULL){
				return true;
			}
		}
		
		T popBack(){
			T x;
			if(!this -> empty()){
				Node<T> *scanner = head;
				while(scanner->next->next != NULL){
					scanner = scanner->next;
				}
				x = tail -> data;
				delete tail;
				tail = scanner;
				tail -> next = NULL;
			}
			return x;
		}
};


#endif
