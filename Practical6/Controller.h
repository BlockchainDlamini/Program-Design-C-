//The Controller class
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Plane.h"
#include "Passenger.h"
#include "Cargo.h"

template<class T>
class Controller
{

private: 

	Plane<T>* plane;

public:

	Controller(Plane<T>*);
	std::string loadOnPlane(T* t);
	double getTotalValue();
	std::string getPlaneContents();

};

#include "Controller.cpp"

#endif
//See spec for inclusion strategy for templates
