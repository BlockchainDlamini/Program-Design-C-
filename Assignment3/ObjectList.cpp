#include "ObjectList.h"
#include <iostream>
using namespace std;

ObjectList::ObjectList(bool dim): dimension(dim){

	head = NULL;
	current = head;

}

void ObjectList::add(Object* obj){

	if (!head && obj){ // empty list ensure obj is not nulL;

		head = obj;
		current = head;
		obj->setNext(0,dimension);
		obj->setPrev(0, dimension);

	}
	else if (head  && obj){ //ensure obj is not null 

		Object* current = head;
		Object *tail = NULL;

		while(current && current->getCoord(dimension) < obj->getCoord(dimension)){
			tail = current;
			current = current->getNext(dimension);
		}

		if (!current){ //inserted last

			obj->setPrev(tail,dimension);
			obj->setNext(0,dimension);

			tail->setNext(obj,dimension);
			tail = NULL;
			
		}	
		else if (!current->getPrev(dimension)){ // inserted first

				obj->setNext(head, dimension);
				obj->setPrev(0, dimension);

				current->setPrev(obj, dimension);
				head = obj;
				this->current = head;
		
		}
		else{ 
			
			if (current->getCoord(dimension) >= obj->getCoord(dimension)){

				obj->setPrev(current->getPrev(dimension), dimension);
				obj->setNext(current, dimension);

				if (current->getPrev(dimension))
					current->getPrev(dimension)->setNext(obj, dimension);

				current->setPrev(obj, dimension);

			}
		}
	}
}

Object* ObjectList::getHead(){ // Can return a NULL head

	return head;

}

string ObjectList::print(){

	string final = "";

	if (head){

		Object* current = head;

		while (current)
		{			
			final = final + current->getIcon();
			current = current->getNext(dimension);	
		}
	}

	return final;

}

Object* ObjectList::iterate(){

	if (!head)
		return NULL;

	if (!current)
		return NULL;
	else
	{
		Object* tocurrent = current;
		current = current->getNext(dimension);
		return tocurrent;
	}
}

void ObjectList::reset(){

	current = head;

}

string ObjectList::debug(){

	string final = "";


	if (head)
	{

		Object* current = head;		
		char top = '\0'; 
		string x, y;
		stringstream ss;

		final = final + "Forward:\n";
		
		Object* tail = NULL;
		while (current){ //does not enter while
			
			ss<< current->getCoord(0)<<  " " << current->getCoord(1);
		    ss>>x;
		    ss>>y;
		    ss.clear();

			if (!current->above)
				top = 'Y';
			else 
				top = 'N';

			final = final + "<" + current->getIcon() + "> at (" +  x  + ',' +  y  +") Top:" + top + '\n';
			tail = current;
			current = current->getNext(dimension);

		}

		final = final + "Back:\n";
		current = tail;

		while (current){

			ss<< current->getCoord(0) << " " <<current->getCoord(1);
		    ss>>x; 
		    ss>>y;
		    ss.clear();

			if (!current->above)
				top = 'Y';
			else 
				top = 'N';

			final = final + "<" + current->getIcon() + "> at (" + x + ',' + y + ") Top:" + top + '\n';
			current = current->getPrev(dimension);

		}

	}

	return final;
}


















