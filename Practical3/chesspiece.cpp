
#include "chesspiece.h" 
using namespace std;

int Chesspiece::numberOfPieces = 0;

Chesspiece::Chesspiece()
{
	this->name = "";
	type = true;
	++numberOfPieces;
}

Chesspiece::Chesspiece(Chesspiece& obj)
{	
	this->name = obj.name;
	this->type = obj.type;
	++numberOfPieces;
}

Chesspiece::Chesspiece(string in_name)
{
	this->name = in_name;
	++numberOfPieces;	
}

Chesspiece::~Chesspiece()
{
	--numberOfPieces;
}

string Chesspiece::getName() const
{
	return this->name;
}

bool Chesspiece::getType() const
{
	return type;
}

Chesspiece::Chesspiece(string in_name, bool in_type)
{
	name = in_name;
	type = in_type;
	++numberOfPieces;
}

int Chesspiece::getNumberOfPieces() const 
{
	return numberOfPieces;
}

