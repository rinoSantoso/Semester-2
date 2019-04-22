#include "pch.h"
#include <iostream>
#include <string>
#include "tri.h"

using namespace std;

int main()
{
	triangles triangle;
	int choice = 0;
	int count;
	while(true){
		cout << "Enter the type of triangle you wish to create ([1]. BtootmLeft / [2]. TopRight / [3]. TopLeft / [4]. BottomRight / [5]. Equilateral, [6]. FlippedEquilateral / [7]. Diamond / [8]. EXIT): ";
		cin >> choice;
		if (choice == 8) {
			break;
		}
		else {
			cout << "Enter the height of triangle you wish to create: ";
			cin >> count;
			triangle.trimaker(choice, count);
		}
	}

 return 0;
}