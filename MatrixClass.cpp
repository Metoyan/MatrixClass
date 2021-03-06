// MatrixClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"

using namespace std;

template<class T>
matrix<T>::matrix(unsigned int  rr, unsigned int cc, const T &init) {
	mat.resize(rr);
	int t = mat.size();
	for (int i = 0; i<t; i++) {
		mat[i].resize(cc, init);
	}
	r = rr;
	c = cc;
}

template<class T>
matrix<T>::matrix(const matrix<T> &rhs) {
	(*this) = rhs;
	r = rhs.get_rows();
	c = rhs.get_cols();
}

template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T> &rhs) {
	if (&rhs == this)
		return *this;

	int  nr = rhs.get_rows();
	int  nc = rhs.get_cols();

	mat.resize(nr);
	int t = mat.size();
	for (int i = 0; i<t; i++) {
		mat[i].resize(nc);
	}

	for (int i = 0; i<nr; i++) {
		for (int j = 0; j<nc; j++) {
			mat[i][j] = rhs(i, j);
		}
	}
	r = nr;
	c = nc;

	return *this;
}
template<class T>
matrix<T> matrix<T>::operator+(const matrix<T> &rhs) {
	matrix result(r, c, 0);

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			result(i, j) = this->mat[i][j] + rhs(i, j);
		}
	}

	return result;
}

template<class T>
matrix<T> matrix<T>::operator-(const matrix<T> &rhs) {
	T r = rhs.get_rows();
	T c = rhs.get_cols();
	matrix result(r, c, 0);

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			result(i, j) = this->mat[i][j] - rhs(i, j);
		}
	}

	return result;
}


template<class T>
matrix<T> matrix<T>::operator*(const matrix<T> &rhs) {
	T r = rhs.get_rows();
	T c = rhs.get_cols();
	matrix result(r, c, 0);

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			for (int k = 0; k<r; k++) {
				result(i, j) = result(i, j) + this->mat[i][k] * rhs(k, j);
			}
		}
	}

	return result;
}

template<class T>
matrix<T> matrix<T>::transpose() {
	matrix result(r, c, 0);

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			result(i, j) = this->mat[j][i];
		}
	}

	return result;
}

template<class T>
matrix<T> matrix<T>::operator+(const T &rhs) {
	matrix result(r, c, 0);

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			result(i, j) = this->mat[i][j] + rhs;
		}
	}

	return result;
}

template<class T>
matrix<T> matrix<T>::operator-(const T &rhs) {
	matrix result(r, c, 0);

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			result(i, j) = this->mat[i][j] - rhs;
		}
	}

	return result;
}

template<class T>
matrix<T> matrix<T>::operator*(const T &rhs) {
	matrix result(r, c, 0);

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			result(i, j) = this->mat[i][j] * rhs;
		}
	}

	return result;
}

template<class T>
matrix<T> matrix<T>::operator/(const T &rhs) {
	matrix result(r, c, 0);

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			result(i, j) = this->mat[i][j] / rhs;
		}
	}

	return result;
}

template<class T>
vector<T> matrix<T>::operator*(const vector<T> &rhs) {
	int k = rhs.size();
	vector<T> result(k, 0);

	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			result[i] = result[i] + this->mat[i] * rhs[i];
		}
	}

	return result;
}

template<class T>
T& matrix<T>::operator()(const int &r, const int &c) {
	return this->mat[r][c];
}

template<class T>
const T& matrix<T>::operator()(const int &r, const int &c) const {
	return this->mat[r][c];
}

template<class T>
vector<T>& matrix<T>::operator[](int i) {
	return mat[i];
}

template<class T>
const vector<T>& matrix<T>::operator[](int i) const {
	return mat[i];
}


template<class T>
T matrix<T>::get_rows() const {
	return this->r;
}

template<class T>
T matrix<T>::get_cols() const {
	return this->c;
}

template<class T>
matrix<T> matrix<T>::extr(int r, int c, int M, int N) {
	matrix<T> result(r, c, 0);
	for (int i = 0; i<r; i++)
		for (int j = 0; j<c; j++)
			result(i, j) = (*this)(i + M, j + N);
	return result;
}

template<class T>
matrix<T> matrix<T>::getSubmatrix(int row, int col) {
	int colCount = 0, rowCount = 0;
	matrix<T>  result(r - 1, c - 1, 0);
	for (int i = 0; i<r; i++) {
		if (i != row) {
			colCount = 0;
			for (int j = 0; j<c; j++) {
				if (j != col) {
					result(rowCount, colCount) = this->mat[i][j];
					colCount++;
				}
			}
			rowCount++;
		}
	}

	return result;
}

template<class T>
ostream & operator<< (ostream& out, const matrix<T> &result) {
	for (int i = 0; i < result.get_rows(); i++) {
		for (int j = 0; j < result.get_cols(); j++) {
			out << result(i, j) << " ";
		}
		out << endl;
	}
	return out;
}

template<class T>
vec<T> matrix<T>::column(int col) {
	vec<T> result;
	vector<T> res(c);
	res.swap(result);
	for (int i = 0; i<c; i++)
		result[i] = this->mat[i][col];
	return result;
}

template<class T>
vec<T> matrix<T>::row(int row) {
	vec<T> result;
	vector<T> res1(r);
	res1.swap(result);
	for (int i = 0; i<r; i++)
		result[i] = this->mat[row][i];
	return result;
}

int main() {

	matrix<int> mat1(5, 5, 0);
	matrix<int> mat2(5, 5, 0);
	vec<int> vector1;
	vec<int> vector2;

	mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3; mat1[0][3] = 2; mat1[0][4] = 1;
	mat1[1][0] = 4; mat1[1][1] = 1; mat1[1][2] = 1; mat1[1][3] = 3; mat1[1][4] = 1;
	mat1[2][0] = 1; mat1[2][1] = 2; mat1[2][2] = 3; mat1[2][3] = 2; mat1[2][4] = 2;
	mat1[3][0] = 2; mat1[3][1] = 3; mat1[3][2] = 4; mat1[3][3] = 1; mat1[3][4] = 1;
	mat1[4][0] = 1; mat1[4][1] = 2; mat1[4][2] = 3; mat1[4][3] = 4; mat1[4][4] = 1;

	mat2(0, 0) = 1; mat2(0, 1) = 2; mat2(0, 2) = 3; mat2(0, 3) = 2; mat2(0, 4) = 3;
	mat2(1, 0) = 2; mat2(1, 1) = 1; mat2(1, 2) = 1; mat2(1, 3) = 1; mat2(1, 4) = 2;
	mat2(2, 0) = 3; mat2(2, 1) = 3; mat2(2, 2) = 3; mat2(2, 3) = 1; mat2(2, 4) = 2;
	mat2(3, 0) = 1; mat2(3, 1) = 2; mat2(3, 2) = 3; mat2(3, 3) = 2; mat2(3, 4) = 1;
	mat2(4, 0) = 2; mat2(4, 1) = 3; mat2(4, 2) = 2; mat2(4, 3) = 5; mat2(4, 4) = 1;

	cout << "mat1:\n" << mat1 << endl;
	cout << "mat2:\n" << mat2 << endl;
	cout << "mat1 transpose:\n" << mat1.transpose() << endl;
	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl;
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl;
	cout << "mat1 * 10:\n" << mat1 * 10 << endl;
	cout << "mat1 - 1:\n" << mat1 - 1 << endl;
	cout << "getSubmatrix mat1:\n" << mat1.getSubmatrix(1, 1) << endl;
	matrix<int> vec1 = mat1.get_column(1);
	cout << "vec1 :\n" << mat1.get_column(1) << endl;
	cout << "mat2 * vec1:\n" << mat2 * vec1 << endl;
	cout << "mat1 column 3(vector):\n";
	vector1 = mat1.column(2);
	cout << vector1;
	cout << "\nmat2 row 2(vector):\n";
	vector2 = mat2.row(1);
	cout << vector2;
	cout << endl;
	system("pause");
	return 0;

}
