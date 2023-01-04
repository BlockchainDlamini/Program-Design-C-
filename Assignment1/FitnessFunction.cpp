#include "FitnessFunction.h"
using namespace std;

double FitnessFunction :: calculateFitness(Chromosome * chromosome, int numGenes )
{
	double fitnessval;
	double truecount = 0;
	bool *ptr = chromosome->getGenes();
	
	for (int i = 0; i < numGenes; i++)
	{ 
		if ( ptr[i] == true )
			truecount +=1;
	}
		
	fitnessval  = truecount/numGenes;
		
	return fitnessval;			
} 
			
			
		
