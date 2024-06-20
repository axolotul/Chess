#include "ChessPiece.h"
#include <iostream>
using namespace std;
ChessPiece::ChessPiece()
{
	color = 1;
}
int ChessPiece::move(int pos1, int pos2)
{
	cout << "Error: Virtual function failed" << endl;
	return 0;
}
char ChessPiece::getPiece() const
{
	cout << "Error: Virtual function failed" << endl;
	return 'X';
}
void ChessPiece::setColor(bool c)
{
	cout << "Error: Virtual function failed" << endl;
}
bool ChessPiece::getColor() const
{
	cout << "Error: Virtual function failed" << endl;
	return 0;
}