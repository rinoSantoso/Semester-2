#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Person
{
	string name = "Rino S.";
	int age = 19;
	string occupation = "University Student";
	string hobby = "Gaming";
	string favFood = "Pizza";

};

int main()
{
	Person rin;
    cout << "Name: " << rin.name << "\n"; 
	cout << "Age: " << rin.age << "\n";
	cout << "Occupation: " << rin.occupation << "\n";
	cout << "Hobby: " << rin.hobby << "\n";
	cout << "Favorite Food: " << rin.favFood << "\n";

 return 0;
}

