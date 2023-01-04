#include "MinusOperator.h"
using namespace std;

template <class T>
T MinusOperator<T>::operator()(T lhs, T rhs)
{
	return lhs - rhs;
} 

template <class T>
Operator<T>* MinusOperator<T>::clone()
{
	Operator<T>* OperatorPtr = new MinusOperator<T>();
	
	return OperatorPtr;
}