#include "matrix.h"
#include <iomanip>
using namespace std;


Matrix::Matrix(unsigned r , unsigned c ) : Arithmetic(){

	rows = r;
	cols = c;

	matrix = new double*[rows];

	for (unsigned i = 0; i < rows; i++){
		matrix[i] = new double[cols];
		
		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] = 0;
	
	}

}

Matrix::Matrix(const Matrix& rhs) : Arithmetic(rhs){

	rows = rhs.rows;
	cols = rhs.cols;

	matrix = new double*[rows];

	for (unsigned i = 0; i < rows; i++){
		matrix[i] = new double[cols];

		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] = rhs.matrix[i][j];

	}

}

Matrix::~Matrix(){

	for (unsigned i = 0; i < rows; i++){
		delete [] matrix[i];
		matrix[i] = NULL;
	}

	delete [] matrix;
	matrix = NULL;

}

const Matrix& Matrix::operator=(const Matrix& rhs){

	if (this != &rhs){

		for (unsigned i = 0; i < rows; i++){
			delete [] matrix[i];
			matrix[i] = NULL;
		}

		delete [] matrix;
		matrix = NULL;

		rows = rhs.rows;
		cols = rhs.cols;

		matrix = new double*[rows];

		for (unsigned i = 0; i < rows; i++){
			matrix[i] = new double[cols];
			
			for (unsigned j = 0; j < cols; j++)
				matrix[i][j] = rhs.matrix[i][j];

		}
		
	}

	return *this;

}

void Matrix::readFile(istream& infile){

	if (!infile.fail()){

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				infile>> matrix[i][j];

		}

}


void Matrix::print(){

	for (unsigned i = 0; i < rows; i++){
		if ( i != 0)
			cout << endl;

		for (unsigned j = 0; j < cols; j++)
			cout << setprecision(3)<< setw(10) << matrix[i][j] ;

	}
	cout<<endl;

}

Vector Matrix::operator[](const unsigned r) const {

	Vector vector(cols);


	if ( r  >= rows )
		throw "Error: invalid row index";

	for (unsigned j = 0; j < cols; j++)
		vector[j] = matrix[r][j];

	return vector;
}

//Modifiable
double& Matrix::operator()(const unsigned r, const unsigned c){
	
	if (r >= rows)
		throw "Error: invalid row index";

	if (c >= cols)
		throw "Error: invalid column index";
	
	//cout<< "Cause of segfault"<<endl;
	return matrix[r][c];

}

const double& Matrix::operator()(const unsigned r , const unsigned c ) const{

	if (r >= rows)
		throw "Error: invalid row index";
	
	if (c >= cols)
		throw "Error: invalid column index";
	
	return matrix[r][c];	

}

unsigned Matrix::getRows() const{

	return rows;

}

unsigned Matrix::getCols() const{

	return cols;

}

//Matrix/Scalar operations

Matrix Matrix::operator*(const double& rhs){

	Matrix result(*this);

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] *= rhs;

	return result; 

}

Matrix& Matrix::operator*=(const double&rhs){

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] *= rhs;

	return *this;

}

Matrix Matrix::operator/(const double& rhs){

	if (rhs == 0)
		throw "Error: division by zero";

	Matrix result(*this);

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] /= rhs;

	return result; 

}

//Matrix mathematical operations

Matrix Matrix::operator+(const Matrix& rhs){

	if (rows != rhs.rows || cols != rhs.cols)
		throw "Error: adding matrices of different dimensionality";

	Matrix result(*this);

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] += rhs.matrix[i][j];

	return result;

}

Matrix& Matrix::operator+=(const Matrix& rhs){

	if (rows != rhs.rows || cols != rhs.cols)
		throw "Error: adding matrices of different dimensionality";

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] += rhs.matrix[i][j];

	return *this;

}

Matrix Matrix::operator-(const Matrix& rhs){

	if (rows != rhs.rows || cols != rhs.cols)
		throw "Error: subtracting matrices of different dimensionality";

	Matrix result(*this);

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[i][j] -= rhs.matrix[i][j];

	return result;

}

Matrix& Matrix::operator-=(const Matrix& rhs){

	if (rows != rhs.rows || cols != rhs.cols)
		throw "Error: subtracting matrices of different dimensionality";

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			matrix[i][j] -= rhs.matrix[i][j];

	return *this;

}

Matrix Matrix::operator*(const Matrix& rhs){ //review

	if (cols != rhs.rows)
		throw "Error: invalid matrix multiplication";

	Matrix result(rows, rhs.cols);

	for (unsigned i = 0; i < result.rows; i++)
		for (unsigned j = 0; j < result.cols; j++)
			for (unsigned k = 0; k < cols; k++)
				result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];

	return result;

}

Matrix& Matrix::operator*=(const Matrix& rhs){ //review

	if (cols != rhs.rows)
		throw "Error: invalid matrix multiplication";

	Matrix result(rows, rhs.cols);
	
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < rhs.cols; j++)
			for (unsigned k = 0; k < cols; k++)
				result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
			
	*this = result;

	return *this;	
}


Matrix Matrix::operator^(int pow){

	if (pow < 0)
		throw "Error: negative power is not supported";

	Matrix result(*this);

	if (result.rows != result.cols)
		throw "Error: non-square matrix provided";

	if (pow == 0){
		for (unsigned i = 0; i < result.rows; i++)
			for (unsigned j = 0; j < result.cols; j++)
				if ( i == j)
					result.matrix[i][j] = 1;
				else 
					result.matrix[i][j] = 0;
	}

	if (pow == 1)
		return result;

	for (int i = 1; i < pow; i++)
		result *= *this;
			
	return result;

}

Matrix& Matrix::operator^=(int pow){

	if (pow < 0)
		throw "Error: negative power is not supported";

	if (rows != cols)
		throw "Error: non-square matrix provided";

	if (pow == 0){
		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				if ( i == j)
					matrix[i][j] = 1;
				else 
					matrix[i][j] = 0;
	}

	if (pow == 1)
		return *this;

	Matrix holder(*this);

	for (int i = 1; i < pow; i++)
		*this *= holder;
			
	return *this;

}

Matrix Matrix::operator~(){

	Matrix result(cols,rows);

	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			result.matrix[j][i] = matrix[i][j];

	return result;

}

bool Matrix::operator==(const Matrix& rhs){

	if (this != &rhs){

		if (rows != rhs.rows)
			return false;

		if (cols != rhs.cols)
			return false;

		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < cols; j++)
				if ( matrix[i][j] != rhs.matrix[i][j])
					return false;
	}

	return true;

}

Matrix Matrix::operator|(const Matrix& rhs){

	if (rows != cols)
		throw "Error: non-square matrix provided";

	if (rhs.rows != rows || rhs.cols != 1)
		throw "Error: incorrect augmentation";

	double m = 0;
	Matrix A(*this);
	Matrix b(rhs);

	/*for (unsigned i = 0; i < rows; i++){
		if ( i != 0 )
			cout<<endl;
		for (unsigned j = 0; j < cols; j++)
			cout<< i <<" ";
	}

	cout<<endl;

	A|=b;*/

	//cout<<"operator|"<<endl;
	//cout<<"First loop"<<endl<<endl;

	for (unsigned j = 0; j < rows - 1; j++){
		for (unsigned i = j + 1; i < rows; i++){

		//	cout<<"Value of A("<<j<<","<<j<<")"<<A(j,j)<<endl;
			
			if (A(j,j) == 0)
				throw "Error: division by zero";

			m =  A(i,j)/A(j,j);

		//	cout <<"m = "<<m<<endl;

			for (unsigned k = 0; k < rows; k++){
				A(i,k) = A(i,k) -(  m * A(j,k) );
			}

			b(i,0) = b(i,0) - ( m * b(j,0) ) ;
		}
	}

	Matrix s(b);

	//	cout<<"Second loop"<<endl<<endl;

	for (int i = rows - 1; -1 < i; i--){
		for (unsigned j = i + 1; j < rows; j++){
			s(i,0) = s(i,0) - ( A(i,j) * s(j,0) );
		}
	
	//	cout<<"Value of A("<<i<<","<<i<<") = "<<A(i,i)<<endl;

		if ( A(i,i) == 0 )
			throw "Error: division by zero";

		s(i,0) = s(i,0)/A(i,i);
	}

	return s;

}



Matrix& Matrix::operator|=(Matrix& rhs){

	if (rows != cols)
		throw "Error: non-square matrix provided";

	if (rhs.rows != rows || rhs.cols != 1)
		throw "Error: incorrect augmentation";

	//this->operator()|=(rhs);

	double m = 0;

	//cout<<"operator|="<<endl;
	//cout<<"First loop"<<endl<<endl;

	for (unsigned j = 0; j < rows - 1; j++){
		for (unsigned i = j + 1; i < rows; i++){

		//	cout<<"Value of this("<<j<<","<<j<<")"<<this->operator()(j,j)<<endl;

			if (this->operator()(j,j) == 0)
				throw "Error: division by zero";



			m = this->operator()(i,j)/this->operator()(j,j);

			for (unsigned k = 0; k < rows; k++){
				this->operator()(i,k) =  this->operator()(i,k) - m * this->operator()(j,k);
			}

			rhs(i,0) =  rhs(i,0) -  m * rhs(j,0) ;  
		}

	}

	//this->print();


	Matrix* s = new Matrix(rhs); 

	//cout<<"Second loop"<<endl<<endl;

	for (int i = rows -1  ; -1 < i; i--){
		for (unsigned j = i + 1; j < rows; j++){

			//insider s mutator

			s->operator()(i,0) =  s->operator()(i,0) - this->operator()(i,j) * s->operator()(j,0);
		}

		//cout<<"Value of this("<<i<<","<<i<<")"<<this->operator()(i,i)<<endl;

		if ( this->operator()(i,i) == 0 )
			throw "Error: division by zero";

		//cout<<"Value of i = " << i <<endl;

		s->operator()(i,0) = s->operator()(i,0)/this->operator()(i,i);
	}

	return *s;

}