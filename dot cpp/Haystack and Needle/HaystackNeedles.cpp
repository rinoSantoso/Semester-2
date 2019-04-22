#include <iostream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;

string noWhitespace(string str){
	for(int i = 0; i < str.length(); i++){
		if (str[i] == char(32)){
			str.erase(i,1);
		}
	}
	return str;
}

void seperator(string input, string &haystack, string &needle){
	for(int i = 0; i < input.size(); i++){
		if(input[i] == char(124)){
			break;
		}
		else{
			haystack.push_back(input[i]);
	
		}
	}
	for(int i = haystack.size() + 1; i < input.size(); i++){
		needle.push_back(input[i]);
	}
	haystack = noWhitespace(haystack);
	needle = noWhitespace(needle);
}


bool isInHaystack(string haystack, string needle){
	int counter = 0;
	for(int i = 0; i < needle.size(); i++){
		for(int j = 0; j < haystack.size(); j++){
			if(haystack[j] == needle[i]){
				counter++;
				break;
			}
		}
	}
	if(counter == needle.size()){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	while (true){
		bool inHaystack;
		string haystack;
		string needle;
		string input;
		cout << "Please enter haystack and needle strings seperated by the '|' character.\n";
		getline(cin, input);
		seperator(input, haystack, needle);
		inHaystack = isInHaystack(haystack, needle);
		if (inHaystack == true){
			cout << "True\n";
		}
		else{
			cout << "False\n";
		}
	}
}
