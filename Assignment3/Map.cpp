#include "Map.h"
#include <iostream>
using namespace std;

Map::Map(int w, int h) : height(h), width(w){

	rows = new ObjectList*[h];
	columns = new ObjectList*[w];
		
	for (int i = 0; i < h; i++)  //initialise each object list with a specific dimension 
		rows[i] = new ObjectList(0);

	for (int i = 0; i < w; i++)
		columns[i] = new ObjectList(1);

}

Map::~Map(){

	Object* node = NULL;
		
	for (int i = 0; i < height; i++){
		node = rows[i]->getHead();

		if (node){
			while (node->getNext(0)){

				Object* temp = node;
				node = node->getNext(0);
				delete temp;
				temp = NULL;

			}
		}

		delete rows[i];
	
	}

	delete rows;
	delete columns;
	rows = NULL;
	columns = NULL;

}

void Map::add(Object* obj){

	int xdim, ydim;

	if (obj){
		xdim = obj->getCoord(0);
		ydim = obj->getCoord(1);
		
		//Links are updated over here
		if (ydim < height && ydim > -1)
			rows[ydim]->add(obj);

		if (xdim < width && xdim > -1)
			columns[xdim]->add(obj);

	}
	
}

string Map::print(){

	string final = "";

	for (int i = 0; i < height; i++)
		final = final + rows[i]->print() + '\n';

	return final;

}
