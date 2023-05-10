#include "ChessPiece.h"
#include <iostream>
using namespace std;
ChessPiece::ChessPiece()
{
	color = 1;
}
ChessPiece::ChessPiece(bool c)
{
	color = c;
}

bool ChessPiece::move(int pos1, int pos2)
{
	cout << "Error: Derived class did not use virtual function" << endl;
	return 0;
}
char ChessPiece::getPiece()
{
	cout << "Error: Derived class did not use virtual function" << endl;
	return 'X';
}
void ChessPiece::setColor(bool c)
{
	cout << "Error: Derived class did not use virtual function" << endl;
}
bool ChessPiece::getColor()
{
	cout << "Error: Derived class did not use virtual function" << endl;
	return 0;
}