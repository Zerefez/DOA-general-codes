

#include <iostream>
#include <stdexcept>
#include "matrix_class.h"
#include "stdlib.h"
using namespace std;

#define ROWS		10
#define COLS		5
#define MAX 		100

int main(void) {
	Matrix<double> mat(ROWS, COLS), id(COLS, COLS);
	srand(time(0));

	for (int i = 0; i < COLS; i++) id[i][i] = 1; // intialize id

	for (int i = 0; i < ROWS; i++) {             // randomize mat
		for (int j = 0; j < COLS; j++) {
			mat[i][j] = ((double)rand() / (RAND_MAX)) * MAX;
		}
	}

	try {
		mat[ROWS][COLS] = 0.0f;                  // invalid access
	}
	catch (exception& e) {
		cout << e.what() << endl;
		mat[ROWS - 1][COLS - 1] = 0.0f;
	}

	cout << "mat=" << endl << mat << endl;
	mat.add(mat);
	cout << "add=" << endl << mat << endl;

	cout << "id =" << endl << id << endl;
	Matrix<double>& mult = multiply(mat, id);
	cout << "mult=" << endl << mult << endl;

	delete& mult;
}
