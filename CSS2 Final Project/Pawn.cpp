#include "Pawn.h"
#include <iostream>
using namespace std;
Pawn::Pawn()
{
}

bool Pawn::move(int pos1, int pos2)
{
	/*
		Pawn move conditions:
			Must not land out of bounds
			Must not land on friendly piece
			Must not pass over any pieces
			Can only move forward (if not capturing)
			Can move two spaces on first move
			Capture must be diagonal
			'En Passant'
	*/
	cout << "Derived class did use virtual function" << endl;
	if (color == 1)
	{
		if (pos1 == pos2 + 1 + isFirstMove)
			if 





	}
	else if (color == 0)
	{
		if (pos2 == pos1 - 1)
		{
			isFirstMove = 0;
			return 1;
		}
		else if (pos2 == pos1 - 2 && isFirstMove == 1)
		{
			isFirstMove = 0;
			return 1;
		}
		else
		{
			cout << pos2 << " != " << pos1 << " - 1" << endl;
			return 0;
		}
	}

}
char Pawn::getPiece()
{
	if (color == 1)
		return 'P';
	else
		return 'p';
}
void Pawn::setColor(bool c)
{
	color = c;
}
bool Pawn::getColor()
{
	return color;
}