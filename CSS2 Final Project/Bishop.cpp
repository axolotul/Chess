#include "Bishop.h"
#include <iostream>
using namespace std;
Bishop::Bishop()
{
	this->color = 1;
}
//checks for valid bishop movement
int Bishop::move(int pos1, int pos2) 
{
	double row1, row2, column1, column2;
	for (int i = 8; i>=1; i--)
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
	for (int i = 8; i >= 1; i--)
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
		//if ((column2 - column1) / (row2 - row1) == 1)
		//{
		//	cout << "Worked: (" << column2 << " - " << column1 << ") / (" << row2 << " - " << row1 << "))" << endl;
		//	return 1;
		//}
		//else if ((column2 - column1) / (row2 - row1) == -1)
		//{
		//	return 2;
		//}
		if ((column2 - column1) / (row2 - row1) == 1 && column2 - column1 > 0)
			return 1;
		else if ((column2 - column1) / (row2 - row1) == -1 && column2 - column1 > 0)
			return 2;
		else if ((column2 - column1) / (row2 - row1) == 1 && column2 - column1 < 0)
			return 3;
		else if ((column2 - column1) / (row2 - row1) == -1 && column2 - column1 < 0)
			return 4;
	}
	return 0;
}
char Bishop::getPiece() const
{
	if (color)
		return 'B';
	else
		return 'b';
}
void Bishop::setColor(bool c)
{
	color = c;
}
bool Bishop::getColor() const
{
	return color;
}