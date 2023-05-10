#include "Position.h"
#include <iostream>
using namespace std;
Position::Position()
{
	setOccupied(0);
}
Position::Position(ChessPiece* p)
{
	setOccupied(1);
	//setPiece(t)
	setPiece(p);
}
void Position::setOccupied(bool o)
{
	occupied = o;
}
bool Position::getOccupied()
{
	return occupied;
}
int Position::getPos()
{
	return pos;
}
void Position::setPos(int p)
{
	pos = p;
}
char Position::getType()
{
	return piece->getPiece();
}
void Position::setPiece(ChessPiece *p)
{
	//if (t == 'P')
	//{
	//	piece = new Pawn;
	//	piece->setColor(1);
	//}
	//else if (t == 'p')
	//{
	//	piece = new Pawn;
	//	piece->setColor(0);
	//}
	piece = p;
}
ChessPiece* Position::getPiece()
{
	return piece;
}
bool Position::getColor()
{
	return piece->getColor();
}
void Position::setColor(bool c)
{
	piece->setColor(c);
}
bool Position::valid(int pos1, int pos2)
{
	return piece->move(pos1, pos2);
}