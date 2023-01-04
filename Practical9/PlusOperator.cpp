#include "PlusOperator.h"
using namespace std;

template <class T>
T PlusOperator<T>::operator()(T lhs, T rhs)
{ 
	return lhs + rhs; 
}

template <class T>
Operator<T>* PlusOperator<T>::clone()
{
	Operator<T>* OperatorPtr = new PlusOperator<T>();

	return OperatorPtr;
}