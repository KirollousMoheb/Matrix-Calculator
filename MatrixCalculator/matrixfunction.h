#ifndef MATRIXFUNCTION_H

#define MATRIXFUNCTION_H
using namespace std;

//the use of extern to prevent the duplication of the variables in two files
extern int a, b, c, d, n ,x,y,An,Bn;
extern string operation, userinput;;

extern float MatrixA[100][100], MatrixB[100][100], MatrixSum[100][100], Matrixdiff[100][100], MatrixMult[100][100], MatrixTa[100][100],
MatrixTb[100][100], Matrix[100][100], Identity[100][100];

extern float Det;
extern float t;


/////////////////////
int GetMatA();
int GetMatB();
int printMatA();
int printMatB();
//////////////////
int add();
int subtract();
int multiply(float mat1[100][100], float mat2[100][100]);
void TransposeA();
void TransposeB();
int swap(float matt1[100][100], float matt2[100][100]);
int identity();
int powerA();
float det(int a, float mat[100][100]);
float inverse(float Matrix[100][100]);

///////////////////////////////////////////
int printsum();
int printdiff();
int printmult();
int printIdentity();
int printpower();
////////////////////////////////////////////////
vector<string> ParseToRows();
vector<string> ParseToColumns(const string rows);
void GetMatrix(float matrix[100][100], int& order);
#endif










