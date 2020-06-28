#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "matrixfunction.h"
using namespace std;
//////////////////////////////////////////// Input Parsing///////////////////////////////////////////
vector<string> ParseToRows() {//a function to parse the input into arrays of rows and save these arrays into vector

	vector<string> input;
	int inputlength = userinput.length();// measure length of input

	//indicating the begining and ending indexes of a row
	int counterA = 0;//initializing the counter A and B where A is at the beginning of each row 
	int counterB = 0;//B is at the end of each row before the separator

	while (counterA < inputlength) {
		if (userinput[counterA] == ';')
		{
			input.push_back(userinput.substr(counterB, counterA - counterB));// push back the array of elements before the ;
			if (counterA - counterB == 0)
			{
				input.pop_back(); //remove spaces if enetered wrong by users between elements
			}

			counterA++;
			counterB = counterA;
		}
		else {
			counterA++;
		}
	}
	//the below 3 lines to push the last row into the vector as there is no semi colon in the end
	input.push_back(userinput.substr(counterB, counterA - counterB));
	if (counterA - counterB == 0) { input.pop_back(); }
	return input;


}
vector<string> ParseToColumns(const string rows) {//function to parse the array of rows parsed in the previous function into columns
	int i = 0;

	vector<string> input;
	int inputlength = rows.length();// measure each row's length

		//indicating the begining and ending indexes of a column

	int counterA = 0;
	int counterB = 0;
	while (counterA < inputlength) {
		if (rows[counterA] == ' ')//parse the rows into columns with the separator is space 
		{
			input.push_back(rows.substr(counterB, counterA - counterB));// push back each each element of row using substring function and the counters
			if (counterA - counterB == 0) //remove spaces between elements
			{
				input.pop_back();
			}

			counterA++;
			counterB = counterA;

		}
		else {
			counterA++;
		}
	}
	input.push_back(rows.substr(counterB, counterA - counterB));
	if (counterA - counterB == 0) { input.pop_back(); }
	return input;

}
void GetMatrix(float matrix[100][100], int& row, int& col) {

	int StringLength = userinput.length(); //measure the input's length  used in the line below to remove the brackets


	userinput = userinput.substr(1, StringLength - 2); //to take the input from the first number to the last and remove brackets
	vector<vector<string>>Matrix; //multidimensional vector for the entered matrix
	vector<string>rows = ParseToRows();    //a vector to save each array of rows into row vector 


	for (int rowno = 0; rowno < rows.size(); rowno++)
	{
		vector<string>columns = ParseToColumns(rows[rowno]);  // a vector to save each parsed row from the row vector into it where i is the index of each row of arrays
		if (rowno == 0) { col = columns.size(); }
		Matrix.push_back(columns); //push vector of columns which contains each element
	}
	row = Matrix.size(); //get the order of the matrix based on the user's input to use it in operations 
	for (int rows = 0; rows < row; rows++) {
		for (int columns = 0; columns < col; columns++)
		{
			matrix[rows][columns] = stof(Matrix[rows][columns]);//transform the numbers saved as strings in the 2D vector into float saved in a matrix entered as a parameter
		}


	}

}
/////////////////////////////////////////////Input Functions/////////////////////////////////////////
int GetMatA() {
	cout << "- Enter Matrix A :  ";
	getline(cin, userinput);//get input from user 
	cout << endl;
	if (userinput == "exit" || userinput == "Exit")
	{
		exit(0);
	}
	GetMatrix(MatrixA, a, b);
	return 0;
}
int GetMatB() {
	cout << "- Enter Matrix B :  ";
	getline(cin, userinput);
	cout << endl;
	if (userinput == "exit" || userinput == "Exit")
	{
		exit(0);
	}
	GetMatrix(MatrixB, c, d);

	return 0;

}
int printMatA() {
	for (int row = 0; row < a; row++)
	{
		for (int column = 0; column < b; column++)
		{
			cout << MatrixA[row][column] << "   ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	return 0;


}
int printMatB() {
	for (int row = 0; row < c; row++)
	{
		for (int column = 0; column < d; column++)
		{
			cout << MatrixB[row][column] << "   ";
		}
		cout << endl;



	}
	return 0;

}
//////////////////////////////////////////////operations Functions//////////////////////////////////////////////////////////////////
int add() {
	for (An = 0; An < a; An++)
	{
		for (Bn= 0; Bn < b; Bn++)
		{
			MatrixSum[An][Bn] = MatrixA[An][Bn] + MatrixB[An][Bn];
		}
	}
	cout << endl;
	return 0;


}
int subtract() {
	for (An = 0; An < a; An++)
	{
		for ( Bn = 0; Bn < b; Bn++)
		{
			Matrixdiff[An][Bn] = MatrixA[An][Bn] - MatrixB[An][Bn];
		}
	}
	cout << endl;
	return 0;

}
int multiply(float mat1[100][100], float mat2[100][100]) {


	for ( x = 0; x < a; x++) {
		for ( y = 0; y < d; y++) {
			float sum = 0;
			for (int k = 0; k < b; k++) {
				sum = sum + mat1[x][k] * mat2[k][y];
			}
			MatrixMult[x][y] = sum;
		}
		//cout << endl;
	}
	return 0;

}
void TransposeA() {
	for (x = 0; x < b; x++) {
		for (y = 0; y < a; y++) {
			cout << MatrixA[y][x] << " ";
		}
		cout << endl;
	}
}
void TransposeB() {
	for (x = 0; x < b; x++) {
		for (y = 0; y < a; y++) {
			cout << MatrixB[y][x] << "  ";
		}
		cout << endl;
	}
}




int powerA() {
	// in this function we use multiply function to obtain any power of Matrix A


	swap(MatrixA, Matrix); //copy function to duplicate matrix A
	for (int t = 0; t < n - 1; t++)//for loop loops n-1 times so when n=2 it loops one time and multiply A by A
	{
		multiply(MatrixA, Matrix); //MULTIPLY THE DUPLICATE MATRIX
		swap(MatrixMult, Matrix);// copy the result into a matrix to be multiplied by the original one again
	}




	return 0;
}

int identity() {// identity matrix function generator used if power equal zero
	for (int row = 0; row < a; row++)
	{

		for (int column = 0; column < b; column++)
		{
			Identity[row][column] = 0; //give all the matrix elements value of zero
		}
	}

	for (int t = 0; t < a; t++)
	{
		Identity[t][t] = 1; //giving the diagonals of the matrix a value of 1

	}



	return 0;
}
int swap(float matt1[100][100], float matt2[100][100])//copy function to duplicate a matrix used in power function
{
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			matt2[i][j] = matt1[i][j];

		}

	}
	return 0;
}
float det(int a, float mat[100][100])
{
	float SubMat[100][100];
	if (a == 2)
		return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
	if (a == 1)
		return (mat[0][0]);

	else
	{
		for (int y = 0; y < a; y++)
		{
			int subrow = 0; //submatrix's row value
			for (int row = 1; row < a; row++)
			{
				int subcolumn = 0;
				for (int column = 0; column < a; column++)
				{
					if (column == y)
						continue;
					SubMat[subrow][subcolumn] = mat[row][column];
					subcolumn++;
				}
				subrow++;

			}
			Det = Det + (pow(-1, y) * mat[0][y] * det(a - 1, SubMat));
		}
	}
	return Det;
}

float inverse(float Matrix[100][100]) {

	for (int row = 0; row < a; row++)
	{
		for (int column = a; column < 2 * a; column++)
		{
			if (row == column - a)
				Matrix[row][column] = 1;
			else
				Matrix[row][column] = 0;
		}
	}
	for (int row = 0; row < a; row++)
	{
		t = Matrix[row][row];
		for (int column = row; column < 2 * a; column++)
			Matrix[row][column] = Matrix[row][column] / t;
		for (int column = 0; column < a; column++)
		{
			if (row != column)
			{
				t = Matrix[column][row];
				for (int k = 0; k < 2 * a; k++)
					Matrix[column][k] = Matrix[column][k] - t * Matrix[row][k];
			}
		}
	cout << "\n\nInverse matrix\n\n";
	for (int row = 0; row < a; row++)
	{
		for (int column = a; column < 2 * a; column++)
			cout << "\t" << Matrix[row][column];
		cout << "\n";
	}

	return 0;

}
///////////////////                       Print Functions            /////////////////////////////////////////////////////////////////
int printsum()
{
	cout << "The Matrices Sum is:" << endl;
	for (int row = 0; row < a; row++)
	{
		for (int column = 0; column < b; column++)
		{

			cout << MatrixSum[row][column] << "  ";

		}
		cout << endl;

	}
	return 0;

}
int printdiff() {
	cout << "The Matrices diff is:" << endl;
	for (int row = 0; row < a; row++)
	{
		for (int column = 0; column < b; column++)
		{

			cout << Matrixdiff[row][column] << "  ";
		}
		cout << endl;

	}
	return 0;

}
int printmult()
{
	cout << endl;
	cout << "The Matrices Multiplication is:" << endl;
	for (x = 0; x < a; x++)
	{
		for (y = 0; y < d; y++)
		{

			cout << MatrixMult[x][y] << "  ";
		}
		cout << endl;

	}
	return 0;

}
int printpower()
{
	cout << "Matrix A power " << n << " equals: " << endl;
	for (int row = 0; row < a; row++)
	{
		for (int column = 0; column < b; column++)
		{

			cout << MatrixMult[row][column] << "  ";
		}
		cout << endl;

	}
	return 0;

}
int printIdentity() {

	for (int row = 0; row < a; row++)
	{
		for (int column = 0; column < a; column++)
		{

			cout << Identity[row][column] << "  ";
		}
		cout << endl;

	}
	return 0;


}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






