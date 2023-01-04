#include <iostream>
#include "matrix.h"

using namespace std;

//Do not change the displayMatrix() function
void Matrix::displayMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << *matrix[i][j];

            if (j != columns - 1) 
                cout << " ";
        }

        cout << endl;
    }
}

Matrix::Matrix(int in_rows, int in_columns)
{
    
    if (in_rows < 1 || in_columns < 1)
    {
        
        rows = 3;
        columns = 3; 
        matrix = new int**[rows];

        for (int i = 0; i < rows ; i++)
        {
            matrix[i] = new int *[columns];

            for (int k = 0; k < columns ; k++)
                matrix[i][k] = new int(1);
        }
    }
    else if (in_rows > 1 || in_columns > 1)
    {
        
        rows = in_rows;
        columns = in_columns;
        matrix = new int**[rows];
        
        for (int i = 0; i < rows ; i++)
        {
            matrix[i] = new int *[columns];
            
            for (int k = 0; k < columns ; k++)
                matrix[i][k] = new int(0);
        }
    }
}

Matrix::~Matrix()
{
    
    for (int i = 0 ; i < rows ; i ++ )
    {
        for (int k = 0 ; k < columns ; k ++)
            delete matrix[i][k];

        delete [] matrix[i];
    }

    delete [] matrix;
}

void  Matrix::resizeRows(int num_rows)
{
    
    int origmatrix[rows][columns]; 
    int orgrows = rows;
    
    if (num_rows < 1)
        cout<< "Error: cannot have less than 1 row" <<endl;
    else if(num_rows > rows && num_rows > 1 )
    {

        for (int i = 0 ; i < rows ; i++)
        {
            for(int k = 0 ; k < columns ; k++)
            {
                origmatrix[i][k]  = *(matrix[i][k]);
                delete matrix[i][k];
            }

            delete [] matrix[i];
        }

        delete [] matrix ;
        rows = num_rows;
        matrix = new int**[rows];

        for (int i = 0; i < rows ; i++)
        {
            matrix[i] = new int *[columns];

            for (int k = 0; k < columns ; k++)
            {    
                if ( i < orgrows)
                    matrix[i][k] = new int(origmatrix[i][k]);
                else 
                    matrix[i][k] = new int(0);
            }

        }
    }
    
    else if (num_rows < rows && num_rows > 1)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for( int k = 0 ; k < columns ; k++)
            {
                origmatrix[i][k]  = *(matrix[i][k]);
                delete matrix[i][k];
            }

            delete [] matrix[i];
        }

        delete [] matrix ;
        rows = num_rows;
        matrix = new int**[rows];

        for (int i = 0; i < rows ; i++)
        {
            matrix[i] = new int *[columns];
            
            for (int k = 0; k < columns ; k++)
                matrix[i][k] = new int(origmatrix[i][k]);
        }
    }
} 

void  Matrix::resizeColumns(int num_cols)
{

    int origmatrix[rows][columns]; 
    int orgcols = columns;
    
    if (num_cols < 1)
        cout<< "Error: cannot have less than 1 column" <<endl;
    else if(num_cols > columns && num_cols > 1)
    {
        for (int i = 0 ; i < rows ; i++ )
        {
            for( int k = 0 ; k < columns ; k++ )
            {
                origmatrix[i][k]  = *(matrix[i][k]);
                delete matrix[i][k];
            }

            delete [] matrix[i];
        }

        delete [] matrix ;
        columns = num_cols;
        matrix = new int**[rows];

        for (int i = 0; i < rows ; i++)
        {
            matrix[i] = new int *[columns];

            for (int k = 0; k < columns ; k++)
            {
                if ( k < orgcols)
                    matrix[i][k] = new int(origmatrix[i][k]);
                else 
                    matrix[i][k] = new int(0);
            }
        }
    }
    else if (num_cols < columns && num_cols > 1)
    {
        for (int i = 0 ; i < rows ; i++ )
        {
            for( int k = 0 ; k < columns ; k++ )
            {
                origmatrix[i][k]  = *(matrix[i][k]);
                delete matrix[i][k];
            }

            delete [] matrix[i];
        }

        delete [] matrix ;
        columns = num_cols;
        matrix = new int**[rows];

        for (int i = 0; i < rows ; i++)
        {
            matrix[i] = new int *[columns];

            for (int k = 0; k < columns ; k++)
                matrix[i][k] = new int(origmatrix[i][k]);

        }
    }
}
    

void Matrix::setMatrix()
{
    int data;

    for (int i =  0 ; i < rows ; i++)
        for (int k = 0 ; k < columns ; k++)
        {
            cin >> data;
            *(matrix[i][k]) = data;
        }  
}

