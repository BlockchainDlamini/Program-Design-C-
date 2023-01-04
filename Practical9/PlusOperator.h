#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H
#include "Operator.h"

template <class T>
class PlusOperator: public Operator<T>
{
public:

	T operator()(T, T);
	Operator<T>* clone();
};

//#include "PlusOperator.cpp"

#endif