#ifndef SN_H
#define SN_H

#include <string>
#include <sstream>
#include "SortNode.h"

//SortNode class implementation here
template <class T>
class SortList
{
private:

	bool ascending;
	SortNode<T>* head;
	SortNode<T>* tail;

public:

	SortList(bool);
	void add(SortNode<T>*);
	SortNode<T>* remove(T val);
	void sort();
	std::string print();
	SortNode<T>* getHead();
	void setAsc(bool);
	string debug();
};

#include "SortList.cpp"

#endif
