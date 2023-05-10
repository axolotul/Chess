#include "ChessBoard.h"
#include <iostream>
using namespace std;
ChessBoard::ChessBoard()
{
	positions.resize(65);
	for (int i = 1; i < 65; i++)
	{
		positions[i] = Position();
		positions[i].setPos(i);
	}
	positions[34] = Position(new Pawn);
	positions[38] = Position(new Pawn);
	positions[34].setColor(1);
	positions[38].setColor(0);
}
void ChessBoard::turn()
{
	int start, end, v;
	char h;
	cout << (t == 1 ? "White's " : "Black's ") << "turn, Enter position of piece to move : ";
	cin >> h >> v;
	start = ((int(h) - 65) * 8) + v;
	if (positions[start].getOccupied() == 1 && positions[start].getColor() == t)
	{
		cout << "Enter position to move to: ";
		cin >> h >> v;
		end = ((int(h) - 65) * 8) + v;
		if (positions[end].getOccupied() == 0 && positions[start].valid(start, end))
		{
			positions[end] = Position(positions[start].getPiece());
			positions[start] = Position();
		}
		else if (positions[end].getOccupied() == 1 && positions[end].getColor() != t && positions[start].valid(start, end))
		{
			positions[end] = Position(positions[start].getPiece());
			positions[start] = Position();
		}
	}
	if (t == 1)
		t = 0;
	else if (t == 0)
		t = 1;
}
void ChessBoard::print()
{
	int posCount = 1;
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
		{
			cout << "     A   B   C   D   E   F   G   H " << endl;
		}
		cout << "    --- --- --- --- --- --- --- ---" << endl;

		for (int l = 0; l < 9; l++)
		{
			if (l<8)
			{
				if (l == 0)
				{
					cout << ' ' << 8-i << " | ";
				}
				else
					cout << "| ";
				if (positions[(l * 8)+(8 - i)].getOccupied() == 1)
					cout << positions[(l * 8) + (8 - i)].getType();
				else
					cout << " ";
				cout << " ";
				posCount++;
			}
			else
			{
				cout << "| " << 8-i;
				cout << endl;
			}

		}
		if (i == 7)
		{
			cout << "    --- --- --- --- --- --- --- ---" << endl;
			cout << "     A   B   C   D   E   F   G   H " << endl;
		}
	}
}