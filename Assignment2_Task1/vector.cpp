#include "vector.h"
#include <iomanip>
using namespace std;

//const char exception3[] = "Error: invalid row index";
//Constructor
Vector::Vector(unsigned s) : Arithmetic()
{
	size = s;
	vector = new double[s];

	for (unsigned i = 0; i < size; i++)
		vector[i] = 0;
}

// Copy constructor
Vector::Vector(const Vector& rhs) : Arithmetic(rhs) 
{
	size = rhs.size;
	vector = new double[size];

	for (unsigned i = 0; i < size; i++)
		vector[i] = rhs.vector[i];
}

//Overloaded = operator
const Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs)
	{
		delete [] vector;
		vector = NULL;

		size = rhs.size;
		vector = new double[size];

		for (unsigned i = 0 ; i < size; i++)
			vector[i] = rhs.vector[i];
	}

	return *this;
}

//Destructor
Vector::~Vector()
{
	if (vector != NULL)
	{
		delete [] vector;
		vector = NULL;
	}
}

//readfile 
void Vector::readFile(istream& infile)
{
	//int count = 0; 
	if (!infile.fail()) // if the file was successfully opened 				
		for (unsigned i = 0; i < size; i++)
			infile >> vector[i]; // assigned value in the file to the vector
}

//print function
void Vector::print()
{
	for (unsigned i = 0; i < size; i++)
		cout<< setprecision(3)<< setw(10) << vector[i] ;
	cout<<endl;
}

//Accessing the vector with no modification rights 
const double& Vector::operator[](const unsigned r ) const
{ //return by reference???, make it a pointer
	if ( r >= size)
		throw "Error: invalid row index";
	
	const double* val = &vector[r];

	return *val;
}

//Modifiable subscript operator 
double& Vector::operator[](const unsigned r)
{
	if (r >= size)
		throw "Error: invalid row index";

	return vector[r];
}

//accessor function get size
unsigned Vector::getSize() const
{
	return size;
}

//Vector/scalar operations
Vector Vector::operator*(const double& rhs)
{
	Vector result(*this);

	for (unsigned i = 0; i < size; i++)
		result.vector[i] *= rhs;

	return result;
}

Vector& Vector::operator*=(const double& rhs)
{
	for (unsigned i = 0; i < size; i++)
		vector[i] *= rhs;

	return *this;
}


Vector Vector::operator/(const double& rhs)
{
	if (rhs == 0)
		throw "Error: division by zero";

	Vector result(*this);

	for (unsigned i = 0; i < size; i++)
		result.vector[i] /= rhs;

	return result;
}

//Vector mathemetical operations

Vector Vector::operator+(const Vector& rhs)
{
	if (size != rhs.size)
		throw "Error: adding vectors of different dimensionality";

	Vector result(*this);

	for (unsigned i = 0; i < size; i++)
		result.vector[i] += rhs.vector[i];

	return result;
}

Vector& Vector::operator+=(const Vector& rhs)
{
	if (size != rhs.size)
		throw "Error: adding vectors of different dimensionality";

	for (unsigned i = 0; i < size; i++)
		vector[i] += rhs.vector[i];

	return *this;	
}

Vector Vector::operator-(const Vector& rhs)
{
	if (size != rhs.size)
		throw "Error: subtracting vectors of different dimensionality";

	Vector result(*this);

	for (unsigned i = 0; i < size; i++)
		result.vector[i] -= rhs.vector[i];

	return result;	
}


Vector& Vector::operator-=(const Vector& rhs)
{
	if (size != rhs.size)
		throw "Error: subtracting vectors of different dimensionality";

	for (unsigned i = 0; i < size; i++)
		vector[i] -= rhs.vector[i];

	return *this;
}


Vector Vector::operator^(int pow)
{
	if (pow < 0)
		throw "Error: negative power is not supported";

	Vector result(*this);

	if (pow == 0)
		for (unsigned i = 0; i < size; i++)
			result.vector[i] = 1;

	double temps[size];

	for (unsigned i = 0; i < size; i++)
		temps[i] = 1;

	for (unsigned i = 0; i < pow; i++)
		for (unsigned j = 0 ; j < size; j++)
			temps[j] *= result.vector[j];

	for (unsigned i = 0; i < size; i++)
		result.vector[i] = temps[i];

	return result;
}

Vector& Vector::operator^=(int pow)
{
	if (pow < 0)
		throw "Error: negative power is not supported";

	if (pow == 0)
		for (unsigned i = 0; i < size; i++)
			vector[i] = 1;

	double temps[size];

	for (unsigned i = 0; i < size; i++)
		temps[i] = 1;

	for (unsigned i = 0; i < pow; i++)
		for (unsigned j = 0 ; j < size; j++)
			temps[j] *= vector[j];

	for (unsigned i = 0; i < size; i++)
		vector[i] = temps[i];

	return *this;	
}

Vector Vector::operator~()
{
	Vector result(*this);
	
	double temp[size];
	double val = result.vector[size - 1];

	temp[size - 1] = result.vector[0];
	result.vector[size - 1] = result.vector[0];
	result.vector[0] = val;
	temp[0] = val;

	for (unsigned j = 1; j < size - 1; j++)
		temp[j] = result.vector[size - j - 1];

	for (unsigned i = 0; i < size; i++)
		result.vector[i] = temp[i];

	return result;
}