#pragma once
#ifndef MATRIX_H_
#define MATRIX_H_

template<class T>
class matrix
{
public:
	// constructor
	matrix(int row = 0; int colum = 0);
	//copy constructor
	matrix(matrix&);
	//destructor
	~matrix();

	//ADT
	//get row
	int rows() const { return row_; }
	//get colum
	int colums() const { return colum_; }
private:
	//the row of the matrix
	int row_;
	//the colum of the matrix
	int colum_;
	//the element of the matrix
	T* elmemt_;
};
#endif // !MATRIX_H_
