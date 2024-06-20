#include "King.h"
#include <iostream>
using namespace std;
King::King()
{
	this->color = 1;
}
//checks for valid king movement
int King::move(int pos1, int pos2)
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


	}
	for (int i = 8; i--; i >= 1)
	{
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
	//for (int i = 0; i++; i < 8)
	//{
	//	if ((pos1 + i) % 8 == 0)
	//	{
	//		column1 = (pos1+i)/
	//	}
	//}


	if (pos2 <= 64 && pos2 >= 1)
	{
		if (column2 == column1 + 1 || column2 == column1 - 1 && row1 == row2)
			return 1;
		else if (row2 == row1 + 1 || row2 == row1 - 1 && column1 == column2)
			return 1;
		else if (column2 == column1 + 1 && row2 == row1 + 1)
			return 1;
		else if (column2 == column1 - 1 && row2 == row1 - 1)
			return 1;
		else if (column2 == column1 + 1 && row2 == row1 - 1)
			return 1;
		else if (column2 == column1 - 1 && row2 == row1 + 1)
			return 1;
	}
	return 0;
}
char King::getPiece() const
{
	if (color)
		return 'K';
	else
		return 'k';
}
void King::setColor(bool c)
{
	color = c;
}
bool King::getColor() const
{
	return color;
}