#include "SortNode.h"
using namespace std;

template <class T>
SortNode<T>::SortNode(T val) : value(val)
{
	next = NULL;
	prev = NULL;
}

template <class T>
string SortNode<T>::print()
{
	stringstream ss;
	string result = "";

	ss << value;
	ss >> result;

	return result;
}

template <class T>
T SortNode<T>::getValue()
{
	return value;
}

