#ifndef MAP_H
#define MAP_H
#include "ObjectList.h"
#include <string>

class Map{

	private:

		int width;
		int height;
		ObjectList** rows;
		ObjectList** columns;

	public:

		Map(int, int);
		~Map();
		void add(Object*);
		std::string print();

};

#endif

