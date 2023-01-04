#include "MultiplyOperator.h"
using namespace std;

template <class T>
T MultiplyOperator<T>::operator()(T lhs, T rhs)
{
	return lhs * rhs;
} 

template <class T>
Operator<T>* MultiplyOperator<T>::clone()
{
	Operator<T>* OperatorPtr = new MultiplyOperator<T>();

	return OperatorPtr;
}