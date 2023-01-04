#ifndef OBJECTLIST_H
#define OBJECTLIST_H
#include "Object.h"
#include <string>


class ObjectList{

	private:

		bool dimension;
		Object* head;
		Object* current;

	public:

		ObjectList(bool);
		void add(Object*);
		Object* getHead();
		std::string print();
		void reset();
		Object* iterate();
		std::string debug();

};

#endif