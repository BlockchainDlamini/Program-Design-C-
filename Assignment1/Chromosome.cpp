#include "Chromosome.h"
using namespace std;

Chromosome::Chromosome(int numGenes, RandomGenerator* rand)
{	
	if (numGenes < 0 )
	{ 
	this->numGenes = 0;
	this->genes = new bool[0];
	}
	else
	{
		this->numGenes = numGenes;
		this->genes = new bool[this->numGenes];
	}

	if (rand == NULL)
	{
		for (int j = 0 ; j < this->numGenes ; j++)
		this->genes[j] = false;
	}
	else
	{
		for (int j = 0 ; j < this->numGenes ;  j++)
		this->genes[j] = rand->randomBool();
	}
}

Chromosome::Chromosome(Chromosome* chromosome)
{	
	if (chromosome == NULL)
	{
		this->numGenes = 0;
		this->genes = new bool[0];
	} 
	else
	{
		this->numGenes = chromosome->numGenes;
		this->genes = new bool[this->numGenes];
		
		for (int i = 0 ; i < this->numGenes ; i++)
			this->genes[i] = chromosome->genes[i]; 
	}
}

Chromosome::Chromosome(bool* genes, int numGenes)
{	
	if (numGenes < 0)
	{
		this->numGenes = 0 ; 
		this->genes = new bool[0];
	}
	else
	{
		this->numGenes = numGenes;
		this->genes = new bool[this->numGenes];
		
		if (genes == NULL )
		{
			for (int i = 0; i < this->numGenes ; i++)
				this->genes[i] = false ; 
			
		}
		else
		{
			for(int k = 0 ; k < this->numGenes; k++)
				this->genes[k] = genes[k];
				
		}
	}
}

Chromosome::~Chromosome()
{
	delete [] genes;
}

double Chromosome::fitness(FitnessFunction* fitnessFunction, Chromosome* chromosome, int numGenes)
{	
	double fitness = 0;
	
	if (fitnessFunction == NULL || chromosome == NULL || numGenes <= 0)
		return fitness;
	else
		return fitnessFunction->calculateFitness(chromosome, numGenes);	
}

int Chromosome::getNumGenes()
{
	return this->numGenes;
}

Chromosome* Chromosome::crossOver(Chromosome* c2)
{
	if (c2 == NULL)
	{
		int nGenesn = c2->getNumGenes();
		bool nGenes[nGenesn];
		
		for(int i = 0 ; i < c2->numGenes ; i++)
			nGenes[i] = c2->genes[i];
			
		Chromosome * NewChromosome = new Chromosome(nGenes, nGenesn);

		return NewChromosome;
	}
	else
	{
		int crossOverPoint = floor(c2->numGenes/2);
		int nGenesn = this->getNumGenes();
		bool nGenes[nGenesn];
		
		for(int i = 0 ; i < crossOverPoint ; i++)
			nGenes[i] = this->genes[i];

		for(int k = crossOverPoint ; k < this->numGenes; k++ )
			nGenes[k] = c2->genes[k];
		
		Chromosome * NewChromosome = new Chromosome(nGenes, nGenesn );
		
		return NewChromosome;
	}
}

Chromosome* Chromosome::mutate()
{	
	int nGenesn = this->getNumGenes();
	bool nGenes[nGenesn];
	
	for (int i = 0 ; i < this->numGenes ; i ++)
		nGenes[i] = !(this->genes[i]);
		
	Chromosome *NewChromosome = new Chromosome(nGenes, nGenesn);
		
	return NewChromosome;
}

string Chromosome::toString()
{
	string strchromosome = "";
	
	if (this->numGenes == 0)
		return strchromosome; 
	else 
	{
		for (int j = 0 ; j < this->numGenes; j++)
		{
			if (this->genes[j] == false)
				strchromosome = strchromosome + "0";
			else 
				strchromosome = strchromosome + "1";
		}

		return strchromosome;
	}
}

bool* Chromosome::getGenes()
{
	return genes;
}
