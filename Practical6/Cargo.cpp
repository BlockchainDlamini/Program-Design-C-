//The Cargo implementation file
#include "Cargo.h"
using namespace std;

Cargo::Cargo(double w, double ppw) 
{
	if (weight < 0)
		weight = 0;
	else 
		weight = w;

	value = ppw * w;
}

string Cargo::describe()
{
	stringstream stream;
	string temp, finalstring = "Generic Cargo <";

	stream<<value;
	stream>>temp;
	finalstring+=temp+"> (";	
	stream.clear();
	stream<<weight;
	stream>>temp;
	finalstring+=temp+")";

	return finalstring;
}

double Cargo::getWeight() const
{
	return weight;
}


double Cargo::getValue() const
{
	return value;
}