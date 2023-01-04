#include "TwoDArray.h"
using namespace std;

TwoDArray::TwoDArray(int** array, int* sizes, int baseSize)
{
    this->sizes = new int[baseSize];

    for (int i = 0; i < baseSize; i++)
    {
        if (sizes != NULL)
            this->sizes[i] = sizes[i]; 
    }
     
    this->baseSize = baseSize;
    this->array = new int*[baseSize];

    for (int i = 0 ; i < baseSize; i++)
    {
        if (sizes != NULL)
        {
            this->array[i] = new int[sizes[i]];

            for (int j = 0 ; j < sizes[i]; j++)
                if(array[i] != NULL)
                    this->array[i][j] = array[i][j];
        }
    }
}

TwoDArray::~TwoDArray()
{   
    if (array != NULL)
    {    
        for (int i = 0 ; i < baseSize; i++)
            delete array[i];
             
        delete [] array;
        delete [] sizes;
    }
    else
    {
        array = NULL;
        sizes = NULL;
    }
}

ostream& operator<<(ostream& os, TwoDArray& tda)
{
    for (int i = 0; i < tda.baseSize; i++)
    {
        for (int j = 0; j < tda.sizes[i]; j++)
        {
            if (j != tda.sizes[i] - 1)
                os<< tda.array[i][j] <<  " ";
            else
                os<< tda.array[i][j];
        }

        os<<endl;
    }

    return os;
}

int** TwoDArray::getArray()
{    
    int **newarr = NULL;

    if (array != NULL)
    {     
        newarr = new int*[baseSize];

        for (int i = 0 ; i < baseSize; i++)
        {
            newarr[i] = new int[sizes[i]];

            for (int j = 0 ; j < sizes[i]; j++)
                newarr[i][j] = array[i][j];
        }
    }

    return newarr;
}

int* TwoDArray::getSizes()
{
    int* newsizes = NULL;

    if (sizes != NULL)
    {
        newsizes = new int[baseSize];

        for (int i = 0 ; i < baseSize; i++)
        {
            //cout<< "in constructor " << " sizes[i] = "<<sizes[i] <<endl;
            newsizes[i] = sizes[i];
        }
    }

    return newsizes;
}

int TwoDArray::getBaseSize()
{
    return baseSize;
}

TwoDArray::operator int**()
{
    int **newarr = NULL;

    if (array != NULL)
    {
        newarr = new int*[baseSize];

        for (int i = 0; i < baseSize; i++)
        {
            newarr[i] = new int[sizes[i]];

            for (int j = 0; j < sizes[i]; j++)
                newarr[i][j] = array[i][j];        
        }
    }

    return newarr;
}

TwoDArray::operator int*()
{        
    int* newsizes = NULL;

    if (sizes != NULL)
    { 
        newsizes = new int[baseSize];

        for (int i = 0; i < baseSize; i++)
            newsizes[i] = sizes[i];
    }

    return newsizes;
}

TwoDArray::operator int()
{
    return baseSize;
}
