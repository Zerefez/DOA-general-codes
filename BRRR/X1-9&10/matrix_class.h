#ifndef _MATRIX_H_
#define _MATRIX_H_

using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>

template <typename Object>
class Matrix {
private:
	vector<vector<Object>> array;

public:
	Matrix() {};

	Matrix(int rows, int cols) : array(rows) {
		for (auto& r : array) {
			r.resize(cols);
		}
	}

	Matrix(vector<vector<Object>> v) : array{ v } {}

	int numrows() const { return array.size(); }

	int numcols() const {
		if (numrows() > 0) {
			return array[0].size();
		}
		return 0;
	}

	const vector<Object>& operator[](int row) const {
		if (row < 0 || row >= array.size())
			throw out_of_range("Invalid row.");
		return array[row];
	}

	vector<Object>& operator[](int row) {
		if (row < 0 || row >= array.size())
			throw out_of_range("Invalid row.");
		return array[row];
	}

	friend ostream& operator<<(ostream& t, Matrix<Object>& mat) {
		cout << fixed;
		cout.precision(2);
		for (int i = 0; i < mat.numrows(); ++i) {
			cout << "|";
			for (int j = 0; j < mat.numcols(); ++j) {
				cout << " " << setw(6) << mat[i][j] << " ";
			}
			cout << "|" << endl;
		}
		return t;
	}


	void add(Matrix& mat) {
		int rows = numrows();
		int cols = numcols();

		if (rows != mat.numrows() || cols != mat.numcols()) {
			throw invalid_argument{ "Matrix has incompatible dimensions" };
		}

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				array[i][j] = array[i][j] + mat[i][j];
			}
		}
	}

	Matrix<Object> multiply(const Matrix<Object>& a, const Matrix<Object>& b) {
		if (a.numcols() != b.numrows()) {
			throw invalid_argument{ "Matrix has incompatible dimensions" };
		}

		Matrix<Object> mult(a.numrows(), b.numcols());

		for (int i = 0; i < a.numrows(); ++i) {
			for (int j = 0; j < b.numcols(); ++j) {
				mult[i][j] = 0;
				for (int k = 0; k < b.numrows(); k++) {
					mult[i][j] += a[i][k] * b[k][j];
				}
			}
		}

		return mult;
	}



};

#endif

