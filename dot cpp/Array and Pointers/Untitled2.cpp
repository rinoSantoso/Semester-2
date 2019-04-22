#include <iostream>
#include <string.h>
#include <bits/stdc++.h> 

using namespace std;

class Numbers{
	private:
		int value;
		int occurences;
	
	public:
		Numbers(int value, int occurences){
			this-> value = value;
			this-> occurences = occurences;
		}
		
		void setValue(int value){
			this->value = value;
		}
		
		void setOccurences(int occurences){
			this->occurences = occurences;
		}
		
		void addOccurences(int plus){
			occurences += plus;
		}
		
		int getValue(){
			return value;
		}
		
		int getOccurences(){
			return this->occurences;
		}
};


int main(){
	int arr[9];
	int odd;
	vector<Numbers> numList;
	int flag = -1;
	
	cout << "Create an array consisting of a few repeating numbers. Only one number is allowed to repeat an odd number of times, the rest must repeat an even number of times.\n";
	for(int i = 0; i < 9; i++){
		cout << "Input a number to append to the array ";
		cin >> arr[i] ;
	}
	
	Numbers Num(arr[0], 1);
	numList.push_back(Num);
	
	
	for(int i = 1; i < 9; i++){
		flag = -1;
		for(int j = 0; j < numList.size(); j++){
			if (arr[i] == numList[j].getValue()){
				numList[j].addOccurences(1);
				flag = 1;
			}
		}
	
		if(flag == -1){
			Numbers a(arr[i], 1);
			numList.push_back(a);
		}	
	}
	
	
	/*
	int flag=-1;
	for(int i = 1; i < 9; i++){
		flag=-1;
		for(int j = 0; j < numList.size(); j++){
			if (arr[i] == numList[j].getValue()){
				flag=j;
				break;
			}
		}
		if (flag!=-1){
			numList[flag].addOccurences(1);
		}
		else{
			Numbers a(arr[i], 1);
			numList.push_back(a);
		}
	}
	*/
	
	for (int i = 0; i < numList.size(); i++){
		cout << "Value:" << numList[i].getValue() << " Occurences:" << numList[i].getOccurences() << "\n";
	}
	
	for(int i = 0; i < numList.size(); i++){
			if((numList[i].getOccurences()) % 2 == 1){
				odd = numList[i].getValue();
			}
		}
	
	
	cout << "Number with odd occurences is: " << odd;
	
	
}
