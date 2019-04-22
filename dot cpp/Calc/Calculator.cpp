// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "calc_func.h"

using namespace std;

int main()
{
	
	Calculator <int> calc;
	while (true) {
		cout << "Welcome to a simple calculator program. What would you like to do?\n [1]. Add\n [2]. Subtract\n [3]. Divide\n [4]. Multiply\n [5]. Modulo\n [6]. Power\n [7]. EXIT\n";
		cin >> calc.choice;
		if (calc.choice == 7) {
			break;
		}

		else
		{
			cout << "Enter the first number\n";
			cin >> calc.num1;
			cout << "Enter the second number\n";
			cin >> calc.num2;
			calc.calculate();
			cout << "\n";
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
