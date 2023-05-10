#include "ChessBoard.h"
#include <iostream>
int main()
{
	ChessBoard CB;
	CB.print();
	for (int i = 0; i < 10; i++)
	{
		CB.turn();
		CB.print();
	}
}