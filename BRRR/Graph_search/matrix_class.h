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

	Matrix(vector<vector<Object>> v) : array{ v } { }

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

	void add(Matrix& mat);
};

#include "matrix_class.tpp"

#endif
