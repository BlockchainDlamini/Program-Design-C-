//The Passenger implementation file
#include "Passenger.h"
using namespace std;


Passenger::Passenger(string id, double w, double t) : ID(id)
{
	if (w < 0)
		weight = 0;
	else 
		weight = w;
	
	if (t < 0)
		ticketPrice = 0;
	else 
		ticketPrice = 0;
}

string Passenger::describe()
{
	string finalstring = ID +" <";

	stringstream stream;
	stream<<ticketPrice;

	string temp;
	
	stream>>temp;
	finalstring+=temp+"> (";	
	stream.clear();
	stream<<weight;
	stream>>temp;
	finalstring+=temp+")";
	
	return finalstring;
}

double Passenger::getWeight() const
{
	return weight; 
}


double Passenger::getValue() const
{
	return ticketPrice;
}