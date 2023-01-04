//The SecretCargo implementation file
#include "SecretCargo.h"
using namespace std;

SecretCargo::SecretCargo(double w)
{
    if (w  < 0)
        weight = 0;
    else 
        weight = w;
}

double SecretCargo::getWeight() const
{
    return weight;
}