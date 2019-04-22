//By Rino Santoso 2201798736

#include <iostream>
#include <string>

using namespace std;

// Swap function utilizing pointers
int swap(int* x, int* y){ // Passes 2 pointer variables instead of normal variables so that the value would be swapped
  int temp = *x; // temp now has the value of pointer x, pointing to the address of x
  *x = *y; // pointer x now has the value of pointer y
  *y = temp; // pointer y now has the value of the former pointer x   
}

int main(){
	int a;
	int b;
	while (true){
		cout << "Enter your first number.\n";
		cin >> a;
		cout << "Your first number is " << a << " and has been stored in the variable 'A'\n";
		cout << "Enter your second number.\n";
		cin >> b;
		cout << "Your second number is " << b << " and has been stored in the variable 'B'\n";
		swap(a,b);
		cout << "Your numbers have been swapped. They are now:\n A: " << a << "\n B: " << b << "\n";
	}
}
