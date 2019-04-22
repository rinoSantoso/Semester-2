#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

void printBoard(char board[3][3]){
	for (int i = 0; i < 3; i++){ 
		for (int j = 0; j < 3; j++){ 
			cout << board[i][j] << "  "; 
		}
   		cout << endl; 
	}
}

void turnAction(char board[3][3], char turn){
	while(true){
		int choice;
		cout << "Enter the tile number you wish to fill. ";
		cin >> choice;
		choice = choice-1;
		int x_axis = choice%3;
		int y_axis = choice/3;
		if (board[y_axis][x_axis] == 'X' or board[y_axis][x_axis] == 'O'){
			cout << "This tile has been filled. Please try again.\n";
		}
		else{
			board[y_axis][x_axis] = turn;
			break;
		}
	}
	
}

void checkWinHV(char board[3][3], char turn, int &winCount){
	string horizontal = "";
	string vertical = "";
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			horizontal.push_back(board[i][j]);
			vertical.push_back(board[j][i]);
		}
		if (horizontal == "XXX" or horizontal == "OOO"){
			winCount++;
		}
		if (vertical == "XXX" or vertical == "OOO"){
			winCount++;
		}
		horizontal = "";
		vertical = "";
	}
}

void checkWinDiagonal(char board[3][3], char turn, int &winCount){
	char diag1[] = {board[0][0], board[1][1], board[2][2]};
	char diag2[] = {board[0][2], board[1][1], board[2][0], 'a', 's', 'd'}; // Without using the three extra chars this array (diag2) returns "+ " at the end of the array for some unknow reason.
	if (strcmp(diag1, "OOO") == 0 or strcmp(diag1, "XXX") == 0){
		winCount++;
	}
	if (strcmp(diag2, "OOOasd") == 0 or strcmp(diag2, "XXXasd") == 0){
		winCount++;
	}
}

int checkWin (char board[3][3], char turn){
	int winCount = 0;
	checkWinHV(board, turn, winCount);
	checkWinDiagonal(board, turn, winCount);
	return winCount;
}

void switchPlayer(char &turn){
	if (turn == 'X'){
		turn = 'O';
	}
	else{
		turn = 'X';
	}
}

int main(){
	cout << "Welcome to a Tic-Tac-Toe game.\n";
	char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	int turnCount = 1;
	char turn = 'X';
	printBoard(board);
	while (turnCount <= 9){
		turnAction(board, turn);
		printBoard(board);
		if (checkWin(board, turn) > 0){
			cout << "\n" << turn << " WINS!" << endl;
			return 0;
		}
		switchPlayer(turn);
		turnCount++;
	}
	cout << "DRAW";
}

