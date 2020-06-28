//NOTES:
//You can perform operations on Matrix A as you can until you type exit
//note : the power function is for square matrices only

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>//input/output manipulation library to give specific width to each line of output
#include "matrixfunction.h"// created library to store matrix functions
using namespace std;

int a, b, c, d, n,x,y,An,Bn; ////////   n is the value of the power entered by user
string operation, userinput, decision;//decision is if the user want to perform other operations on matrix A or exit
float MatrixA[100][100], MatrixB[100][100], MatrixSum[100][100], Matrixdiff[100][100], MatrixMult[100][100], MatrixTa[100][100],
MatrixTb[100][100], Identity[100][100], Matrix[100][100];// definition of matrices used
float Det ;
float t;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()

{
	cout << "                        YOU CAN PERFORM ANY NUMBER OF OPERATIONS ON MATRIX A UNTIL YOU TYPE 'exit' " << endl;
	cout << "                                 NOTE:THE POWER OPERATION IS FOR SQUARE MATRICES ONLY" << endl;


	GetMatA();
	cout << "                                     -Enter the operation you want to perform-" << endl;
	cout << endl;
	cout << setw(10) << left << "                                   To Show Matrix A" << "            Type==>       " << setw(10) << "show A" << endl;
	cout << "                                =====================================================" << endl;
	cout << setw(10) << left << "                                   Addition (C=A + B) " << "         Type==>       " << setw(10) << "add" << endl;
	cout << "                                =====================================================" << endl;
	cout << setw(10) << left << "                                   Subtraction(C=A - B)" << "        Type==>       " << setw(10) << "subt" << endl;
	cout << "                                =====================================================" << endl;
	cout << setw(10) << left << "                                   Multiplication(C=A * B)" << "     Type==>       " << setw(10) << "multiply" << endl;
	cout << "                                =====================================================" << endl;
	cout << setw(10) << left << "                                   Transpose(C=A')" << "             Type==>       " << setw(10) << "trans" << endl;
	cout << "                                =====================================================" << endl;
	cout << setw(10) << left << "                                   Power(C=A ^ n)" << "              Type==>       " << setw(10) << "power" << endl;
	cout << "                                =====================================================" << endl;
	cout << setw(10) << left << "                                   Inverse(C=A ^ -1 )" << "          Type==>       " << setw(10) << "inv" << endl;
	cout << "                                =====================================================" << endl;
	cout << setw(10) << left << "                                   To End the Program " << "         Type==>       " << setw(10) << "exit" << endl;
	cout << "                                =====================================================" << endl;
	cout << endl;



again://the statement of goto where the code jumps to here to perform other operations

	cout << "Type the Operation Command : ";
	getline(cin, operation);

	if (operation == "exit")
	{
		exit(0);
	}
	else
	{
		if (operation == "Show A" || operation == "show A" || operation == "Show a" || operation == "show a")
		{
			printMatA();
			cout << "Do you want to perform another operation on Matrix A? (Type 'yes' or type 'exit') :";
			getline(cin, decision);
			if (decision == "Yes" || decision == "yes")
			{
				cout << endl;
				cout << endl;

				goto again;  // if the user entered yes the go to jumps to the again statement above and re-run the code starting from the operation 
			}

		}
		else
		{
			if (operation == "add" || operation == "Add")
			{
			add:
				GetMatB();
				if (a == c && b == d) {

					add();
					printsum();
					cout << "Do you want to perform another operation on Matrix A?(Type 'yes' or type 'exit') :";
					getline(cin, decision);
					if (decision == "Yes" || decision == "yes")
					{
						cout << endl;
						cout << endl;

						goto again;
					}
				}
				else {
					cout << "Wrong Input. Please Enter a Matrix of size " << a << "x" << b << endl;
					goto add;
				}
			}
			else
			{
				if (operation == "subt" || operation == "Subt")//subtraction
				{
				sub:
					GetMatB();
					if (a == c && b == d) {

						subtract();
						printdiff();
						cout << "Do you want to perform another operation on Matrix A?(Type 'yes' or type 'exit') :";
						getline(cin, decision);
						if (decision == "Yes" || decision == "yes")
						{
							cout << endl;
							cout << endl;

							goto again;
						}
					}
					else {
						cout << "Wrong Input. Please Enter a Matrix of size " << a << "x" << b << endl;
						goto sub;

					}
				}
				else
				{
					if (operation == "multiply" || operation == "Multiply")
					{
					mult:
						GetMatB();
						if (b == c) {
							multiply(MatrixA, MatrixB);
							printmult();
							cout << "Do you want to perform another operation on Matrix A?(Type 'yes' or type 'exit') :";
							getline(cin, decision);
							if (decision == "Yes" || decision == "yes")
							{
								cout << endl;
								cout << endl;

								goto again;
							}
						}
						else {
							cout << "Wrong Input:Enter a Matrix with " << b << " row(s)." << endl;
							goto mult;
						}
					}
					else
					{
						if (operation == "trans" || operation == "Trans")//transpose
						{
							TransposeA();
							
							cout << "Do you want to perform another operation on Matrix A?(Type 'yes' or type 'exit') :";
							getline(cin, decision);
							if (decision == "Yes" || decision == "yes")
							{
								cout << endl;
								cout << endl;

								goto again;
							}

						}
						else
						{
							if (operation == "Power" || operation == "power")//Extra power function
							{

								cout << "Enter the value of the power:" << endl;
								cin >> n;

								cout << endl;

								if (n == 0)// if power equal zero use identity functions to get the output
								{
									identity();
									cout << "Matrix power zero equals: " << endl;

									printIdentity();
									cout << "Do you want to perform another operation on Matrix A?(Type 'yes' or type 'exit') :";
									cin.ignore();
									getline(cin, decision);
									if (decision == "Yes" || decision == "yes")
									{
										cout << endl;
										cout << endl;

										goto again;
									}
								}

								if (n == 1)// if the power equall one print the original matrix
								{
									cout << "Matrix Power 1 equals:" << endl;
									printMatA();
									cout << "Do you want to perform another operation on Matrix A?(Type 'yes' or type 'exit') :";
									cin.ignore();
									getline(cin, decision);
									if (decision == "Yes" || decision == "yes")
									{
										cout << endl;
										cout << endl;

										goto again;
									}


								}
								if (n != 0 && n != 1)// if n not 1 or 0 use the normal power functions
								{
									d=a ;

									powerA();
									printpower();
									cout << "Do you want to perform another operation on Matrix A?(Type 'yes' or type 'exit') :";
									cin.ignore();
									getline(cin, decision);
									if (decision == "Yes" || decision == "yes")
									{
										cout << endl;
										cout << endl;

										goto again;
									}


								}

							}
							else {
								if ((operation == "Inv" || operation == "inv"))
								{
								div:
									GetMatB();
									if (a == c && b == d) {

										cout << endl;
										cout << "Matrix B:" << endl;
										printMatB();
										if (det(a, MatrixB) == 0)
										{
											cout << "This Matrix Has no inverse ,operation cannot be done" << endl;
											cout << "ERROR" << endl;
											exit(0);
										}
										else {
											inverse(MatrixA);


										}
										cout << "Do you want to perform another operation on Matrix A?(Type 'yes' or type 'exit') :";
										getline(cin, decision);
										if (decision == "Yes" || decision == "yes")
										{
											cout << endl;
											cout << endl;

											goto again;
										}
									}
									else {
										cout << "Wrong Input. Please Enter a Matrix of size " << a << "x" << b << endl;
										goto div;

									}
								}
							}
						}
					}
				}
			}
		}
	}





}

