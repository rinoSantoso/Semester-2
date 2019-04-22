#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Function to get rid of whitespaces
string noWhitespace(string str){
	for(int i = 0; i < str.length(); i++){
		if (str[i] == char(32)){
			str.erase(i,1);
		}
	}
	return str;
}

void printVectorLong(vector<unsigned long> vect){
	for (int i = 0; i < vect.size(); i++){
		cout << vect[i] << ' ';
	}
	cout << endl;
}

bool palLoop(string str, int *start, int *end, int *check){
	if (*check == (str.size()+1)/2){
		return true;
	}
	else if(str[*start] == str[*end]){
		*start += 1;
		*end -= 1;
		*check += 1;
		palLoop(str, start, end, check);
	}
	else{
		return false;
	}
}

void palindrome(string someString){
	string str = noWhitespace(someString);
	int start, check;
	int end = str.size() - 1;
	bool isPal = palLoop(str, &start, &end, &check);
	if (isPal == true){
		cout << "This string is a palindrome.\n";
	}
	else{
		cout << "This string is not a palindrome\n";
	}
}

void pascal(int *size, int *listCount, vector<unsigned long> *list){
	if(*listCount < *size){
		printVectorLong(*list);
		vector<unsigned long> tempList;
		tempList.push_back((*list)[0]);
		for(int tempCount = 0; tempCount < (*list).size() - 1; tempCount++){
			tempList.push_back((*list)[tempCount] + (*list)[tempCount + 1]);
		}
		tempList.push_back((*list)[(*list).size()-1]);
		*list = tempList;
		*listCount += 1;
		pascal(size, listCount, list);
	}
}

int factorial(int number){
    if(number<=1){
        return 1;
    }
    else{
        return number*factorial(number - 1);
    }
}

void fibonnaci(int number, int counter=1, int curr=1, int shadowCurr=0){
    if(number <= 1){
        cout << number;
    }
    else{
    	if(counter == 1){
    		cout << curr << " ";
    		counter++;
    		fibonnaci(number, counter);
		}
		else{
	    	int print = curr + shadowCurr;
	        cout << print << " ";
	        counter++;
	        shadowCurr = curr;
	        curr = print;
	        if (counter <= number){
	        	fibonnaci(number, counter, curr, shadowCurr);
			}
		}
    }
}

void powerCustom(int num, int ttpo, int counter=1, int total=0){
	if(num == 0){
		cout << "Result: 0\n";
	}
	else if(num < 0){
		cout << "Not yet supported.\n";
	}
	else if(counter <= ttpo){
		if(counter == 1){
			total = num;
			counter++;
			powerCustom(num, ttpo, counter, total);
		}
		else{
			total = total*num;
			counter++;
			powerCustom(num, ttpo, counter, total);
		}
	}
	else{
		cout << "Result: " << total << endl;;
	}
}

int main(){
	while (true){
		int mainOption;
		cout << "What would you like to do?\n [1]. Palindrome\n [2]. Pascal Triangle\n [3]. Factorial\n [4]. Fibonacci\n [5]. Power\n [6]. EXIT\n";
		cin >> mainOption;
		if (mainOption == 1){
			string str;
			cout << "Please enter a string you would like to check.\n";
			cin.get();
			getline(cin, str);
			transform(str.begin(), str.end(), str.begin(), ::tolower);
			
			if (str == "palindrome"){
				cout << "This string IS palindrome, but not A palindrome.\n";
			}
			else{
				palindrome(str);
			}
		}
		else if(mainOption == 2){
			vector<unsigned long> list;
			list.push_back(1);
			int size;
			cout << "Please input the size of the Pascal Triangle.\n";
			cin >> size;
			int listCount = 0;
			pascal(&size, &listCount, &list);
			
		}
		else if(mainOption == 3){
			int num;
			cout << "Enter the number you would like to factorialize.\n";
			cin >> num;
			cout << "The factorialization result is " << factorial(num) << endl;
			
		}
		else if(mainOption == 4){
			int num;
			cout << "Please enter the length of the sequence.\n";
			cin >> num;
			fibonnaci(num);
			cout << endl;
		}
		else if(mainOption == 5){
			int num;
			int ttpo;
			cout << "Please enter the base number.\n";
			cin >> num;
			cout << "What number will the base be powered by?\n";
			cin >> ttpo;
			powerCustom(num, ttpo);
		}
		else if(mainOption == 6){
			cout << "Closing the program.";
			break;
		}
	}
}
