#include "chessboard.h"
using namespace std;

Chessboard::Chessboard(Chessboard& obj)
{
	
	this->rows = obj.rows;
	this->columns = obj.columns;
	
	board = new Chesspiece**[rows];
	
	for(int i = 0 ; i < this->rows; i++)
	{
		board[i] = new Chesspiece*[columns];

		for (int j = 0 ; j < this->columns ; j++)			
			if (obj.board[i][j] != NULL) 
				board[i][j] = new Chesspiece(*obj.board[i][j]);
			else 
				board[i][j] = NULL;
	}    
}

Chessboard::Chessboard(int in_rows, int in_columns)
{

	this->rows = in_rows;
	this->columns = in_columns;
	
	board = new Chesspiece**[rows];
	
	for (int i = 0; i < rows ; i++)
	{
		board[i] = new Chesspiece*[columns];
			
		for (int j = 0 ; j < columns ; j++)
			board[i][j] = NULL;
	}
	
}

Chessboard::~Chessboard()
{

	if (board != NULL)
	{ 
		for (int i = 0 ; i < rows ; i++)
		{
			for (int j = 0 ; j < columns ; j++)
			{
				if (board[i][j] != NULL)
				delete board[i][j];   
			}

			delete [] board[i];
		}

		delete [] board;
	}
}

void Chessboard::addChesspiece(Chesspiece *piece, int row, int column)
{	
	board[row][column] = piece;
}

void Chessboard::removeChesspiece(int row, int column)
{
	if (board[row][column] != NULL)
	{
		delete board[row][column];
		board[row][column] = NULL;
	} 
}

Chesspiece& Chessboard::at(int row, int column) const
{	
	//if (board[row][column] != NULL) 
	return *board[row][column];
}


Chessboard& Chessboard::operator=(const Chessboard& other)
{	
	for (int i = 0 ; i < rows ; i++)
	{
		for (int j = 0 ; j < columns ; j++)
		{
			if (board[i][j] != NULL)
				delete board[i][j]; 
		}

		delete [] board[i];
	}

	delete [] board;
	this->rows = other.rows;
	this->columns = other.columns;
	
	board = new Chesspiece**[rows];

	if (other.board != NULL)
	{
		for(int i = 0 ; i < rows ; i++)
		{
			board[i] = new Chesspiece *[columns];

			for (int j = 0; j < columns ; j++)
			{
				if ( other.board[i][j] != NULL)
					board[i][j] = new Chesspiece(*other.board[i][j]);
				else 
					board[i][j] = NULL;
			} 
		}  
	}

	return *this;
}


Chessboard& Chessboard::operator+=(const Chessboard& rhs)
{
	
	for (int i = 0 ; i < rows ; i++ )
	{
		for (int j = 0 ; j < columns ; j++)
		{
			if (rhs.board[i][j] != NULL && board[i][j] == NULL)
				board[i][j] = new Chesspiece(*rhs.board[i][j]); 
		}
	}
	
	return *this;	
}

