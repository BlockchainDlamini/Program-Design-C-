#ifndef OPERATOR_H
#define OPERATOR_H

template <class T>
class Operator
{
public:

	Operator();
	virtual T operator()(T, T) = 0;
	virtual Operator<T>* clone() = 0;
	virtual ~Operator();
};

//#include "Operator.cpp"

#endif