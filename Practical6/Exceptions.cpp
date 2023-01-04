//Exception implementations
#include "Exceptions.h"
using namespace std;


AboveWeightEx::AboveWeightEx(double wd) : weightDiff(wd) {}

double AboveWeightEx::getDifference() const
{
    return weightDiff;
}

template<class E>
UndervaluedEx<E>::UndervaluedEx(E* uv , double s) : underVal(uv), sum(s) {}

template<class E>
E* UndervaluedEx<E>::getUndervalued() const
{
    return underVal;
}

template<class E>
double UndervaluedEx<E>::getSum() const
{
    return sum;
}

template<class E>
NotFoundEx<E>::NotFoundEx(E* nf) : missing(nf) {}

template<class E>
E* NotFoundEx<E>::getNotFound() const
{
    return missing;
}
