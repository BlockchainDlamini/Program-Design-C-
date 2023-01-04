#include "matrix.h"
#include <iomanip>
using namespace std;

const char exception1[] = "Error: invalid row index";
const char exception2[] = "Error: invalid column index";


Matrix::Matrix(unsigned r , unsigned c ) : Arithmetic()
{
	rows = r;
	cols = c;

	matrix = new double*[rows];

	for (unsigned i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		
		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix& rhs) : Arithmetic(rhs)
{
	rows = rhs.rows;
	cols = rhs.cols;

	matrix = new double*[rows];

	for (unsigned i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];

		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] = rhs.matrix[i][j];
	}
}

Matrix::~Matrix()
{
	for (unsigned i = 0; i < rows; i++)
	{
		delete [] matrix[i];
		matrix[i] = NULL;
	}

	delete [] matrix;
	matrix = NULL;
}

const Matrix& Matrix::operator=(const Matrix& rhs)
{
	if (this != &rhs)
	{
		for (unsigned i = 0; i < rows; i++)
		{
			delete [] matrix[rows];
			matrix[rows] = NULL;
		}

		delete [] matrix;
		matrix = NULL;

		rows = rhs.rows;
		cols = rhs.cols;

		matrix = new double*[rows];

		for (unsigned i = 0; i < rows; i++)
		{
			matrix[i] = new double[cols];
			
			for (unsigned j = 0; j < cols; j++)
				matrix[i][j] = rhs.matrix[i][j];
		}
	}

	return *this;
}

void Matrix::readFile(istream& infile)
{
	int count = 0; 

	if (!infile.fail())
	{		
		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				infile>> matrix[i][j];			
	}
}


void Matrix::print()
{
	for (unsigned i = 0; i < rows; i++)
	{
		if ( i != 0)
			cout << endl;

		for (unsigned j = 0; j < cols; j++)
			cout << setprecision(3)<< setw(10) << matrix[i][j];
	}
	cout<<endl;
}

Vector Matrix::operator[](const unsigned r) const
{
	Vector vector(cols);

	if ( r  >= rows )
		throw "Error: invalid row index";

	for (unsigned j = 0; j < cols; j++)
		vector[j] = matrix[r][j];

	return vector;
}

//Modifiable
double& Matrix::operator()(const unsigned r, const unsigned c)
{	
	if (r >= rows)
	{
		cout<<"Exception 1 thrown \n";
		throw "Error: invalid row index";
	}
	
	if (c >= cols)
	{
		cout<<"Exception 2 thrown \n";
		throw "Error: invalid column index";
	}

	return matrix[r][c];
}

const double& Matrix::operator()(const unsigned r , const unsigned c ) const
{
	if (r >= rows)
	{
		cout<<"Exception 1 thrown \n";
		throw "Error: invalid row index";
	}
	
	if (c >= cols)
	{
		cout<<"Exception 2 thrown \n";
		throw "Error: invalid column index";
	}
	
	return matrix[r][c];	
}

unsigned Matrix::getRows() const
{
	return rows;
}

unsigned Matrix::getCols() const
{
	return cols;
}

//Matrix/Scalar operations

Matrix Matrix::operator*(const double& rhs)
{
	Matrix result(*this);

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] *= rhs;

	return result; 
}

Matrix& Matrix::operator*=(const double&rhs)
{
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] *= rhs;

	return *this;
}

Matrix Matrix::operator/(const double& rhs)
{
	if (rhs == 0)
		throw "Error: division by zero";

	Matrix result(*this);

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] /= rhs;

	return result; 
}

//Matrix mathematical operations

Matrix Matrix::operator+(const Matrix& rhs)
{
	if (rows != rhs.rows || cols != rhs.cols)
		throw "Error: adding matrices of different dimensionality";

	Matrix result(*this);

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] += rhs.matrix[i][j];

	return result;
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
	if (rows != rhs.rows || cols != rhs.cols)
		throw "Error: adding matrices of different dimensionality";

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] += rhs.matrix[i][j];

	return *this;
}

Matrix Matrix::operator-(const Matrix& rhs)
{
	if (rows != rhs.rows || cols != rhs.cols)
		throw "Error: subtracting matrices of different dimensionality";

	Matrix result(*this);

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] -= rhs.matrix[i][j];

	return result;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
	if (rows != rhs.rows || cols != rhs.cols)
		throw "Error: subtracting matrices of different dimensionality";

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] -= rhs.matrix[i][j];

	return *this;
}

Matrix Matrix::operator*(const Matrix& rhs)
{ //review
	if (cols != rhs.rows)
		throw "Error: invalid matrix multiplication";

	Matrix result(rows, rhs.cols);

	for (unsigned i = 0; i < result.rows; i++)
		for (unsigned j = 0; j < result.cols; j++)
			for (unsigned k = 0; k < cols; k++)
				result[i][j] += matrix[i][k] * rhs.matrix[k][j];

	return result;
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{ //review
	if (cols != rhs.rows)
		throw "Error: invalid matrix multiplication";

	Matrix result(rows, rhs.cols);

	for (unsigned i = 0; i < result.rows; i++)
		for (unsigned j = 0; j < result.cols; j++)
			for (unsigned k = 0; k < cols; k++)
				result[i][j] += matrix[i][k] * rhs.matrix[k][j];

	*this = result;

	return *this;	
}


Matrix Matrix::operator^(int pow)
{
	Matrix result(*this);
	return result;
}

Matrix& Matrix::operator^=(int pow)
{
	return *this;
}

Matrix Matrix::operator~()
{
	Matrix result(*this);
	return result;
}

Matrix Matrix::operator|(const Matrix& rhs)
{
	Matrix result(*this);
	return result;
}

Matrix& Matrix::operator|=(Matrix& rhs)
{
	return *this;
}