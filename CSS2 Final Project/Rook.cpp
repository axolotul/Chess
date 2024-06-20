#include "Rook.h"
#include <iostream>
using namespace std;
Rook::Rook()
{
	this->color = 1;
}
Rook::Rook(bool c)
{
	setColor(c);
}

//checks for valid rook movement
int Rook::move(int pos1, int pos2)
{
	double row1, row2, column1, column2;
	for (int i = 8; i--; i >= 1)
	{
		if ((pos1 - i) % 8 == 0)
		{
			column1 = (pos1 - i) / 8;
			row1 = pos1 - (column1 * 8);
			if (row1 == 0)
			{
				column1 -= 1;
				row1 = 8;
			}
		}
		if ((pos2 - i) % 8 == 0)
		{
			column2 = (pos2 - i) / 8;
			row2 = pos2 - (column2 * 8);
			if (row2 == 0)
			{
				column2 -= 1;
				row2 = 8;
			}
		}


	}
	if (pos2 <= 64)
	{
		if (column1 == column2 && row2 > row1)
		{
			return 1;
		}
		else if (row1 == row2 && column2 > column1)
		{
			return 2;
		}
		else if (column1 == column2 && row2 < row1)
		{
			return 3;
		}
		else if (row1 == row2 && column2 < column1)
		{
			return 4;
		}
	}
	return 0;
}
char Rook::getPiece() const
{
	if (color)
		return 'R';
	else
		return 'r';
}
void Rook::setColor(bool c)
{
	color = c;
}
bool Rook::getColor() const
{
	return color;
}