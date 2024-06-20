#include "Position.h"
#include <iostream>
using namespace std;

//default constructor
Position::Position()
{
	setOccupied(0);
}

//when position is captured
Position::Position(ChessPiece* p, bool c)
{
	setOccupied(1);
	setPiece(p);
	setColor(c);
}
void Position::setOccupied(bool o)
{
	occupied = o;
}
bool Position::getOccupied()
{
	return occupied;
}


char Position::getType()
{
	return piece->getPiece();
}
void Position::setPiece(ChessPiece *p)
{
	piece = p;
}
ChessPiece* Position::getPiece()
{
	return piece;
}
bool Position::getColor()
{
	if (occupied == true)
		return piece->getColor();
	else
		return 1;
}
void Position::setColor(bool c)
{
	piece->setColor(c);
}
//checks if piece movement is valid
int Position::valid(int pos1, int pos2)
{
	return piece->move(pos1, pos2);
}