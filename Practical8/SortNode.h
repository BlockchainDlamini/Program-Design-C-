#ifndef DLL_H
#define DLL_H

#include "SortNode.h"
#include <string>

//SortList class Implementation here

template <class T>
class SortNode
{
protected:

	T value;

public:

	SortNode<T>* next;
	SortNode<T>* prev;

	SortNode(T);
	std::string print();
	T getValue();
};

#include "SortNode.cpp"

#endif