#include "GA.h"
using namespace std;

GA::GA(int populationSize, RandomGenerator* rand, int numGenes, int selectionSize)
{
	this->populationSize = populationSize;
	this->selectionSize = selectionSize;
	population = new Chromosome *[populationSize];

	for (int i = 0; i < this->populationSize; i++)
		population[i] = new Chromosome(numGenes, rand);
}

GA::GA(GA* geneticAlgorithm)
{
	this->populationSize = geneticAlgorithm->populationSize;
	this->selectionSize = geneticAlgorithm->selectionSize; 
	
	population = new Chromosome *[populationSize];

	for (int i = 0 ;  i < populationSize; i++)
		population[i] = new Chromosome(geneticAlgorithm->population[i]);
}

GA::~GA()
{
	for (int i = 0; i < populationSize; i++)
		delete population[i];

	delete [] population;
}

Chromosome** GA ::run(FitnessFunction* fitnessFunction)
{
	int offsize = 3*selectionSize;
	Chromosome **offsprings = NULL;
	Chromosome **P = NULL;
	Chromosome **nChromosomes = NULL;
	Chromosome **temp = NULL;
	
	Chromosome **winners;
	temp = selection(fitnessFunction);
	winners = new Chromosome*[populationSize];

	for (int i = 0 ; i < populationSize ; i++)
		winners[i]= temp[i];

	temp = inverseSelection(fitnessFunction);
	Chromosome **losers;
	losers = new Chromosome*[populationSize];

	for (int i = 0; i < populationSize; i++)
		losers[i] = temp[i];
		
	offsprings = new Chromosome*[offsize];
	P = new Chromosome*[populationSize];

	for(int i = 0; i < 2*selectionSize; i++)
	{
		nChromosomes = crossOver(winners[i], winners[i+1]);
		offsprings[i] = nChromosomes[i]; 
		offsprings[i+1] = nChromosomes[i+1];
		i++;
	}

	for(int i = 0; i < selectionSize; i++)
		offsprings[i+2*selectionSize] = mutate(winners[i+2*selectionSize]);

	for(int i = 0 ; i < populationSize; i++)		
		P[i] = population[i];

	bool found = false;
	Chromosome* dyingChromosome =NULL; 

	for(int i = 0; i < 3*selectionSize; i++)
	{
		dyingChromosome = losers[i];
		int u = 0; 

		for (int j = 0; j < populationSize; j++)
		{
			if(dyingChromosome == P[j])
			{
				u = j;
				found = true;
				break;
			}
		}

		if( found == true)
			P[u] = offsprings[i];
	}
			
	delete [] winners;
	delete [] losers;
	delete [] offsprings;
	delete [] temp;
	delete [] nChromosomes;

	return P;
}

double** GA::run(FitnessFunction* fitnessFunction, int numGenerations)
{
	double **results = NULL;
	Chromosome **P = NULL;
	Chromosome **temp = NULL;

	results = new double*[numGenerations];
	P = new Chromosome*[populationSize];

	for(int i = 0 ; i < numGenerations; i++)
	{
		results[i] = new double[3];
		temp = run(fitnessFunction);

		for(int i = 0 ; i < populationSize ; i++)
			P[i] = new Chromosome(temp[i]);

		population = P;
		results[i][0] = calculateAvgAccuracy(fitnessFunction);
		results[i][1] = calculateStd(fitnessFunction);
		results[i][2] = calculateVariance();
	}
		
	return results;
}

Chromosome** GA::selection(FitnessFunction* fitnessFunction)
{
	Chromosome ** arrchrom = NULL;
	Chromosome* temp = NULL; 

	arrchrom = new Chromosome*[populationSize];

	for (int i = 0; i < populationSize; i++)
		arrchrom[i] = population[i];

		for (int i = 0; i < populationSize; i++)
		{
			for (int k = 0; k < populationSize - 1; k++)
			{
				if ( arrchrom[k]->fitness(fitnessFunction,arrchrom[k], arrchrom[k]->getNumGenes()) < arrchrom[k+1]->fitness(fitnessFunction,arrchrom[k+1], arrchrom[k+1]->getNumGenes()))
				{
					temp = arrchrom[k];
					arrchrom[k] = arrchrom[k+1];
					arrchrom[k+1] = temp;
				}
			}
		}

	return arrchrom;
}

Chromosome** GA::inverseSelection(FitnessFunction* fitnessFunction)
{	
	Chromosome ** arrchrom1 = NULL;
	Chromosome* temp1 = NULL; 

	arrchrom1 = new Chromosome*[populationSize];

	for (int i = 0; i < populationSize; i++)
		arrchrom1[i] = population[i];

	for (int i = 0; i < populationSize; i++)
	{
		for (int k = 0;  k  < populationSize - 1; k++)
		{
			if( arrchrom1[k]->fitness(fitnessFunction,arrchrom1[k], arrchrom1[k]->getNumGenes()) > arrchrom1[k+1]->fitness(fitnessFunction, arrchrom1[k+1], arrchrom1[k+1]->getNumGenes()))
			{
				temp1 = arrchrom1[k];
				arrchrom1[k] = arrchrom1[k+1];
				arrchrom1[k+1] = temp1;
			}
			else if( arrchrom1[k]->fitness(fitnessFunction, arrchrom1[k], arrchrom1[k]->getNumGenes()) == arrchrom1[k+1]->fitness(fitnessFunction,arrchrom1[k+1], arrchrom1[k+1]->getNumGenes()))
			{
				temp1 = arrchrom1[k];
				arrchrom1[k] = arrchrom1[k+1];
				arrchrom1[k+1] = temp1;
			}
		}
	}
		
	return arrchrom1;
}

Chromosome** GA::crossOver(Chromosome* c1, Chromosome* c2)
{
	Chromosome ** arrchrom = NULL;
	arrchrom = new Chromosome *[2];

	arrchrom[0] = c1->crossOver(c2);
	arrchrom[1] = c2->crossOver(c1);
	
	return arrchrom;
}

Chromosome* GA::mutate(Chromosome* c1)
{
	return c1->mutate();
}

double GA::calculateAvgAccuracy(FitnessFunction* fitnessFunction)
{
	double sum = 0;
	
	for (int i = 0; i < populationSize; i++)
		sum += fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes());
		
	return sum/populationSize; 
}

double GA::calculateStd(FitnessFunction* fitnessFunction)
{
	double sumstd = 0, avg = 0;
	avg = calculateAvgAccuracy(fitnessFunction); 
	
	for (int k = 0; k < populationSize; k++)
		sumstd += pow(fitnessFunction->calculateFitness(population[k], population[k]->getNumGenes()) - avg, 2);
	
	return sqrt(sumstd/populationSize);
}

double GA::calculateVariance()
{
	double count = 0;
	int k = 0;

	for (int i = 0; i < populationSize; i++)
	{
		for ( k = 0; k < i; k++)
			if (population[i]->toString() == population[k]->toString()) 
				break;

		if (i == k) 
			count+= 1;
	} 		
	
	double var = count/populationSize;

	return var;
}

void GA::setPopulation(Chromosome** p)
{ 
	delete [] population;

    population = new Chromosome*[populationSize];

	for (int i = 0; i < populationSize; i++)
		population[i] = new Chromosome(p[i]); 
}
