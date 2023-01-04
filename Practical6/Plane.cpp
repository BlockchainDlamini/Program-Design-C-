//The Plane implementation file
#include "Plane.h"
using namespace std;

template <class T>
Plane<T>::Plane(double max) : maxWeight(max) {}

template <class T>
Plane<T>::~Plane()
{
	for (int i = 0; i < cargo.size(); i++)
		cargo.erase(cargo.begin() + i); // be sure to know if the erase function takes an int parameter
}

template <class T>
void Plane<T>::add(T* item)
{
	
	double currWeight = 0;

	for (int i = 0; i < cargo.size(); i++) // you cant go over bounds with a vector
		if (cargo[i] != NULL)
			currWeight += cargo[i]->getWeight();
	
	if (item != NULL)
	{
		if (item->getWeight() + currWeight <= maxWeight) // not sure if 
			cargo.push_back(item);// cargo is a vector of item pointers therefore the function should be legal
		else if (item->getWeight() + currWeight > maxWeight )
		{
			double weightdifference = (item->getWeight() + currWeight) - maxWeight;
			throw AboveWeightEx(weightdifference);//verify
		}
	}
	

}

template <class T>
void Plane<T>::remove(T* item)
{	
	bool found = false;

	if (item != NULL)
	{
		if (!(cargo.empty()))
		{
			for (int i = 0; i < cargo.size(); i++)
				if (cargo[i] != NULL && cargo[i] == item)
				{
					found = true;
					cargo.erase(cargo.begin() + i);
				}

			if (!(found))
				throw NotFoundEx<T>(item);//verify 
		}
		else
			throw EmptyEx();//verify
	}

}


template <class T>
string Plane<T>::getDescription()
{		
	string description = "";

	if (cargo.empty())
		throw EmptyEx();
	else
	{
		for (int i = 0; i < cargo.size() ; i++)
		{ // why use -1?
			if (cargo[i] != NULL)
			{
				if (i == cargo.size()-1 )
					description += cargo[i]->describe();
				else
					description += cargo[i]->describe() + '\n';
			}
		}
		//return description;
	}

	return description;
}

template <class T>
double Plane<T>::calculateValue()
{	
	double totalvalue = 0;

	if (cargo.empty())
		throw EmptyEx(); // an instance of emptyex should be throw? I throw the class itself in this case
	else
	{
		if (cargo[0] != NULL)
		{
			double smallest = cargo[0]->getValue();
			int index = 0;
			double secondsmallest = cargo[0]->getValue();

			//determine smallest value
			for (int i = 1; i < cargo.size(); i++)
				if (smallest > cargo[i]->getValue() && cargo[i] != NULL) 
				{ // if its smaller than it than smallest takes its value
					smallest = cargo[i]->getValue();
					index = i;
				}
			
			//determine second smallest value
			for (int i = 0; i < cargo.size(); i++)
				if (secondsmallest >= cargo[i]->getValue() && cargo[i]->getValue() != smallest && cargo[i] != NULL) // if it smaller than it but it is not equal to the value of the smallest thus we exclude smallest from our search
					secondsmallest = cargo[i]->getValue(); // we can make it greater than or equal to it because it begin with the first value in the vector
					// it will not alter anything because if the smallest values are equal than it remain the same
			
			double benchmark = secondsmallest / 2;

			//determine if the undervalued exception will be thrown
			if (smallest < benchmark)
			{
				for (int i = 0; i < cargo.size(); i++)
				{
					if (i != index && cargo[i] != NULL)						
						totalvalue += cargo[i]->getValue();
				}				
				throw UndervaluedEx<T>(cargo[index], totalvalue);// not to sure if we are throwing a instance of the class or the class itself
			}
			else
			{
				for (int i = 0; i < cargo.size(); i++) 
					if (cargo[i] != NULL)
						totalvalue += cargo[i]->getValue();
			}
		}
	}
}

//see how specialized classes are implemented

/*template <>
Plane<SecretCargo>::Plane(double max) : maxWeight(max) {}

template <>
Plane<SecretCargo>::~Plane() {
	for (int i = 0; i < (int) cargo.size(); i++)
		cargo.erase(cargo.begin() + i); // be sure to know if the erase function takes an int parameter
}

template <>
void Plane<SecretCargo>::add(SecretCargo* item) {
	
	double currWeight = 0;

	for (int i= 0; i < (int) cargo.size(); i++) // you cant go over bounds with a vector
		if (cargo[i] != NULL)
		currWeight += cargo[i]->getWeight();
	
	if (item != NULL) {
		if (item->getWeight() + currWeight <= maxWeight) // not sure if 
			cargo.push_back(item);// cargo is a vector of item pointers therefore the function should be legal
		else if (item->getWeight() + currWeight > maxWeight)
			throw AboveWeightEx(maxWeight);//verify
	}
	

}

template <>
void Plane<SecretCargo>::remove(SecretCargo* item) {
	
	bool found = false;

	if (item != NULL){
		if (!(cargo.empty())) {
			for (int i = 0; i < (int)cargo.size(); i++)
				if (cargo[i] != NULL && cargo[i] == item){
						found = true;
						cargo.erase(cargo.begin() + i);
					}
			if (!(found))
				throw NotFoundEx<SecretCargo>(item);//verify 
		}
		else
			throw EmptyEx();//verify
	}

}*/


template <>
string Plane<SecretCargo>::getDescription()
{	
	if (cargo.empty())
		throw EmptyEx();
	
	throw UnauthorisedEx();
}

template <>
double Plane<SecretCargo>::calculateValue()
{
	if (cargo.empty())
		throw EmptyEx(); // an instance of emptyex should be throw? I throw the class itself in this case
	
	throw UnauthorisedEx();
}



