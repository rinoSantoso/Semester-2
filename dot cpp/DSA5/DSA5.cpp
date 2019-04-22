#include<iostream>
#include "LinkedList.h"

using namespace std;


int main(){
	LinkedList<int> x;
	x.InsertBack(10);
	x.InsertBack(20);
	LinkedList<int>::iterator y;
	
	for(y = x.itr_begin(); y != x.itr_end(); y++){
		cout << *y << endl;
	} 
}
