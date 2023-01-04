#include "Object.h"
using namespace std;

Object::Object(int x, int y) : xPos(x), yPos(y){

	icon = '?';
	nextHoriz = NULL;
	nextVert = NULL;
	prevHoriz = NULL;
	prevVert = NULL;
	above = NULL;
	below = NULL;

}

char Object::getIcon(){

	if (above)
		return above->getIcon();

	return icon;

}

int Object::getCoord(bool dimension){

	if (!dimension)
		return xPos;

	return yPos;

}

Object* Object::getNext(bool dimension){ // Note can return NULL pointers

	if (!dimension) 
		return nextHoriz;
	
	return nextVert;

}

Object* Object::getPrev(bool dimension){

	if (!dimension)
		return prevHoriz;

	return prevVert;

}

void Object::setNext(Object* obj, bool dim){

	if (!dim)
		nextHoriz = obj;
	else
		nextVert = obj;

}

void Object::setPrev(Object* obj, bool dim){

	if (!dim)
		prevHoriz = obj;
	else
		prevVert = obj;

}
