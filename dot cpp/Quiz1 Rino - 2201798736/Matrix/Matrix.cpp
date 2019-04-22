#include <iostream>
#include <string>

using namespace std;

void printMatrix(int matrix[4][4]){
	for (int i = 0; i < 4; i++){ 
		for (int j = 0; j < 4; j++){ 
			if (matrix[i][j] >= 10 or matrix[i][j] <= -10){
					cout << matrix[i][j] << " "; 
			}
			else{
				cout << matrix[i][j] << "  "; 
			}
		}
     
   // Newline for new row 
   cout << endl; 
   }
}

int multMatrix(int result[4][4], int matrix1[4][4], int matrix2[4][4]){
	int xa = 0;
	int ya = 0;
	int xb = 0;
	int yb = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			for (xa = 0; xa < 4; xa++){
				result[i][j] = result[i][j] + matrix1[ya][xa] * matrix2 [yb][xb];
				yb++;
			}
			yb = 0;
			xb++;	
		}
		xb = 0;
		ya++;
		
	}
	return result[4][4];
}

int main(){
	int matrix1 [4][4];
	matrix1[0][0] = 3;
	matrix1[0][1] = 4;
	matrix1[0][2] = 5;
	matrix1[0][3] = 5;
	matrix1[1][0] = 5;
	matrix1[1][1] = 6;
	matrix1[1][2] = 7;
	matrix1[1][3] = 9;
	matrix1[2][0] = 1;
	matrix1[2][1] = 7;
	matrix1[2][2] = 11;
	matrix1[2][3] = 10;
	matrix1[3][0] = 2;
	matrix1[3][1] = 8;
	matrix1[3][2] = 9;
	matrix1[3][3] = 4;
	
	int matrix2 [4][4];
	matrix2[0][0] = 1;
	matrix2[0][1] = 2;
	matrix2[0][2] = 3;
	matrix2[0][3] = 4;
	matrix2[1][0] = 8;
	matrix2[1][1] = 7;
	matrix2[1][2] = 6;
	matrix2[1][3] = 5;
	matrix2[2][0] = 9;
	matrix2[2][1] = 10;
	matrix2[2][2] = 11;
	matrix2[2][3] = 2;
	matrix2[3][0] = 6;
	matrix2[3][1] = 5;
	matrix2[3][2] = 4;
	matrix2[3][3] = 3;
	
	int matrix3 [4][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
	matrix3 [4][4]= multMatrix(matrix3, matrix1, matrix2);
	printMatrix(matrix3);

}
