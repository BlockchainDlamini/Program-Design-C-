#include "Calculator.h"
using namespace std;

template <class T>
Calculator<T>::Calculator()
{
	valueStack = new Stack<T>();
	operatorStack = new Stack<Operator<T>*>();
}

template<class T>
Calculator<T>::~Calculator()
{
	delete valueStack;
	delete operatorStack;

	valueStack = NULL;
	operatorStack = NULL;
}

template <class T>
void Calculator<T>::addValue(T val)
{
	valueStack->push(val);
}

template <class T>
void Calculator<T>::addOperator(Operator<T>* op)
{
	Operator<T>* copy = op->clone();
	operatorStack->push(copy);
}

template <class T>
T Calculator<T>::removeValue()
{
	if (valueStack->isEmpty())
		return NULL;

	Node<T>* returnval = valueStack->pop();

	return returnval->getData();
}

template <class T>
Operator<T>* Calculator<T>::removeOperator()
{
	if (operatorStack->isEmpty())
		return NULL;

	return operatorStack->pop()->getData();
}

template <class T>
int Calculator<T>::numValues()
{
	return valueStack->size();
}

template <class T>
int Calculator<T>::numOperators()
{
	return operatorStack->size();
}

template <class T>
T Calculator<T>::calculate()
{
	if (numValues() < 2)
		return NULL;

	while(!operatorStack->isEmpty() && numValues() >= 2)
	{
		T val1, val2, result;
		Operator<T>* op = NULL;

		val1 = valueStack->pop()->getData();
		val2 = valueStack->pop()->getData();
		op = operatorStack->pop()->getData();
		result = op->operator()(val1, val2);
		valueStack->push(result);
	}

	return valueStack->getTop()->getData();
}














