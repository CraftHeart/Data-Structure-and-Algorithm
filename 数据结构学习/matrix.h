#pragma once
#ifndef MATRIX_H_
#define MATRIX_H_

#include"myExceptions.h"

template<class T>
class matrix
{
public:
	// constructor
	matrix(int row = 0, int colum = 0);
	//copy constructor
	matrix(const matrix&);
	//destructor
	~matrix();

	//ADT
	//get row
	int rows() const { return row_; }
	//get colum
	int colums() const { return column_; }
	T& operator()(int i, int j) const;
	matrix<T>& operator=(const matrix<T>&);
	matrix<T> operator=(const matrix<T>&);
	matrix<T> operator+() const;
	matrix<T> operator+(const matrix<T>&) const;
	matrix<T> operator-() const;
	matrix<T> operator-(const matrix<T>&) const;
	matrix<T> operator*(const matrix<T>&) const;
	matrix<T> operator+=(const T&);
private:
	//the row of the matrix
	int row_;
	//the colum of the matrix
	int column_;
	//the element of the matrix
	T* element_;
};

template<class T>
matrix<T>::matrix(int row ,int column)
{
	//check if the row and colum is illegal
	if (row < 0 || column < 0)
		throw illegalParameterValue("Both rows and columns should be >= 0");
	if ((row == 0 || column == 0) && (row != 0 || column != 0))
		throw illegalParameterValue("Either both or neither rows and colums should be zero");
	row_ = row;
	column_ = column;
	element_ = new T [row*column];
}

template<class T>
matrix<T>::matrix(const matrix<T>& m)
{
	row_ = m.row_;
	column_ = m.column_;
	element_ = new T[row_*column_];

	copy(m.element_, m.element_ + row_*column_, element_);
}

template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
	if (this = &m)
		return *this;
	delete[] element_;
	row_ = m.row_;
	column_ = m.column_;
	element_ = new T[row_*column_];

	copy(m.element_, m.element_ + row_*column_, element_);

	return *this;
}

//the index of array starting at 0;
//the index of matrix starting at 1;
//M(i,j) <==> x[i-1][j-1]
template<class T>
T& matrix<T>::operator()(int i, int j) const
{
	if (i<1 || i>row_ || j<1 || j>column_)
		throw illegalParameterValue("out of matrix bound");
	return element_[(i-1)*column_ + (j-1)];
}

template<class T>
matrix<T> matrix<T>::operator+(const matrix<T>& m) const
{
	//check if the matrix can add
	if (row_ != m.row_ || column_ = m.column_)
		throw illegalParameterValue("the matrix size doesn`t match");
	matrix<T> temp_matrix(row_, column_);
	for (int i = 0; i < row_*column_; i++)
		temp_matrix.element_[i] = element_[i] + m.element_[i];
	return temp_matrix;
}

template<class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m) const
{
	if (column_ != m.row_)
		throw illegalParameterValue("the matrix doesn`t match");

	//result matrix
	matrix<T> temp_matrix(row_, m.column_);

	//
	int ct = 0;		//this 的一维数组映射index
	int cm = 0;		//m一维数组映射index
	int cw = 0;		//c一维数组映射index
	for (int i = 1; i < row_; i++)
	{
		for (int j = 1; j < m.column_; j++)
		{
			//计算第一项
			T sum = element_[ct] * m.element_[cm];

			//累加其余所有项
			for (int k = 2; k <= column_; k++)
			{
				ct++;
				cm = cm + m.column_;
				sum += element_[ct] * m.element_[cm];
			}

			//存储w(i,j)
			temp_matrix.element_[cw++] = sum;

			//回到行的起点和下一列的起点
			ct -= column_ - 1;
			cm = j;
		}
		//从下一行的起点和第一列的起点重新开始
		ct += column_;
		cm = 0;
	}
	return temp_matrix;
}



#endif // !MATRIX_H_
