#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

class Matrix
{

public:

	void displayMatrix();
	Matrix(int,int);
	~Matrix();
	void resizeRows(int);
	void resizeColumns(int);
	void setMatrix();

private:

	int rows;
	int columns;
	int*** matrix;

};

#endif