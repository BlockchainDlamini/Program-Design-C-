#ifndef MULTIPLYOPERATOR_H
#define MULTIPLYOPERATOR_H

#include "Operator.h"

template <class T>
class MultiplyOperator : public Operator<T>
{
public:

	T operator()(T, T);
	Operator<T>* clone();
};

//#include "MultiplyOperator.cpp"

#endif