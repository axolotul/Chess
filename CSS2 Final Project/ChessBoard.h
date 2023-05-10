#pragma once
#include <vector>
#include "Position.h"
using namespace std;
class ChessBoard
{
	private:
		vector<Position> positions;
		bool t = 1;
	public:
		ChessBoard();
		void turn();
		void print();

};