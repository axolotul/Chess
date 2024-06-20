#include "Pawn.h"
#include <iostream>
using namespace std;
Pawn::Pawn()
{
	isFirstMove = 1;
	color = 1;
}
//checks for valid pawn movement
int Pawn::move(int pos1, int pos2) 
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
	int row1, row2, column1, column2;
	for (int i = 8; i > 0; i--)
	{
		if ((pos1 - i) % 8 == 0)
		{
			column1 = (pos1 - i) / 8;
			row1 = i;
		}
		if ((pos2 - i) % 8 == 0)
		{
			column2 = (pos2 - i) / 8;
			row2 = i;
		}
	}
	//cout << "Column: " << column1 << endl << "Row: " << row1 << endl;
	//cout << "Column 2: " << column2 << endl << "Row 2: " << row2 << endl;

	if (color == 1)
	{
		if (pos2 <= 64 && pos2 >= 1)
		{

			if (pos2 == pos1 + 1 || pos2 == pos1 + 1 + isFirstMove)
			{
				isFirstMove = 0;
				return 1;
			}

			else if (pos2 == pos1 - 7 || pos2 == pos1 + 9)
			{
				isFirstMove = 0;
				return 2;
			}
			else
			{
				return 0;
			}

		}
	}

	if (color == 0)
	{
		if (pos2 <= 64 && pos2 >= 1)
		{

			if (pos2 == pos1 - 1 || pos2 == pos1 - 1 - isFirstMove)
			{
				isFirstMove = 0;
				return 1;
			}

			else if (pos2 == pos1 - 9 || pos2 == pos1 + 7)
			{
				isFirstMove = 0;
				return 2;
			}
			else
			{
				return 0;
			}

		}
	}

}
char Pawn::getPiece() const
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
bool Pawn::getColor() const
{
	return color;
}