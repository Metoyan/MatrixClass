#pragma once
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <class T>
class vec :public vector<T> {
public:

	template <class N>
	friend ostream& operator<<(ostream &out, const vector<N> &result) {
		int t = result.size();
		for (int i = 0; i<t; i++)
			out << result[i] << " ";
		out << endl;
		return out;
	}

};

template <class T>
class matrix {

	vector<vector<T> > mat;
	T r;
	T c;

public:
	matrix(unsigned int  rr, unsigned int  cc, const T &init);
	matrix(const matrix<T> &rhs);
	~matrix() {};
	T get_rows() const;
	T get_cols() const;
	T& operator()(const int &r, const int &c);
	const T& operator()(const int &r, const int &c) const;
	vector<T>& operator[](int i);
	const vector<T>& operator[](int i) const;
	matrix<T>& operator=(const matrix<T> &rhs);
	matrix<T> operator+(const matrix<T> &rhs);
	matrix<T> operator-(const matrix<T> &rhs);
	matrix<T> operator*(const matrix<T> &rhs);
	matrix<T> transpose();
	matrix<T> operator+(const T &rhs);
	matrix<T> operator-(const T &rhs);
	matrix<T> operator*(const T &rhs);
	matrix<T> operator/(const T &rhs);
	vector<T> operator*(const std::vector<T> &rhs);
	vec<T> column(int col);
	vec<T> row(int row);
	matrix<T> extr(int r, int  c, int M = 0, int N = 0);
	matrix<T> get_row(int i) { return extr(1, r, i, 0); }
	matrix<T> get_column(int j) { return extr(c, 1, 0, j); }
	matrix<T> getSubmatrix(int row, int col);
	template<class M>
	friend ostream & operator<< (ostream &out, const matrix<M> &result);

};
