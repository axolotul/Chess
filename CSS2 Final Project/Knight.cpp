#include "Knight.h"
Knight::Knight()
{
	this->color = 1;
}
//checks for valid knight movement
int Knight::move(int pos1, int pos2)
{
	if (pos2 <= 64)
	{
		if (pos2 == pos1 + 10 || pos2 == pos1 + 17 || pos2 == pos1 + 6 || pos2 == pos1 - 6 || pos2 == pos1 + 15 || pos2 == pos1 - 15 || pos2 == pos1 - 17 || pos2 == pos1 - 10)
		{
			return 1;
		}
	}
	return 0;
}
char Knight::getPiece() const
{
	if (color)
		return 'H';
	else
		return 'h';
	//dont remember if i updated calls to this
}
void Knight::setColor(bool c)
{
	color = c;
}
bool Knight::getColor() const
{
	return color;
}