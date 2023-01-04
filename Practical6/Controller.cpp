//The Controller implementation file
#include "Controller.h"
#include <iostream>

using namespace std;

template <class T>
Controller<T>::Controller(Plane<T>* p) : plane(p) {} // does not create plane just intialises it 


template <class T>
string Controller<T>::loadOnPlane(T*t)
{
// this is where the exceptions are meant to be caught
	try
	{
		plane->add(t);
		return "Success";
	}
	catch (AboveWeightEx e)
	{ // catch the above weight exception this for now is incorrect 
		stringstream store;
		store<< e.getDifference();
		string temp;
		store >> temp;
		return "Could not load item, above max weight by " + temp ;
	}
}

template <class T>
double Controller<T>::getTotalValue() 
{
	try
	{ 
		plane->calculateValue();
	}
	catch (UnauthorisedEx)
	{ // unauthorised is caught
		return 0;
	}
	catch (UndervaluedEx<T> undervalued)
	{ // undervalued is caught
		T* underptr = undervalued.getUndervalued();
		plane->remove(underptr);
		return undervalued.getSum();
		//catch (EmptyEx) {
		//	throw;
		//}
		//catch (NotFoundEx<T>) {	
		//	throw;
		//}
		////catch (UnauthorisedEx) { // unauthorised is caught
		//cout << "thrown again \n";
		//throw;
		//}
	}
	catch (EmptyEx)	{return 0;}
	catch (NotFoundEx<T>){return 0;}
	//catch (UnauthorisedEx) {return 0;}
}

template <class T>
string Controller<T>::getPlaneContents() 
{
	try
	{
		return plane->getDescription();
	}
	catch (EmptyEx)
	{ //empty contents
		cout << "Nothing to report";
	}
	catch (UnauthorisedEx)
	{ //unauthorised 
		cout << "Not permitted";	
	}
}
