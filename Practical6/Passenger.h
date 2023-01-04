//The Passenger class
#ifndef PASSENGER_H
#define PASSENGER_H

#include <sstream>
#include <string>

class Passenger
{
private:

	std::string ID;
	double weight;
	double ticketPrice;

public:

	Passenger(std::string, double, double);
	double getWeight() const ;
	double getValue() const ;
	std::string describe();

};

#endif