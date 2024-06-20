#pragma once
#include <vector>
#include "Position.h"
using namespace std;
class ChessBoard
{
	private:
		vector<Position> positions; //resized to 64 positions
		bool t = 1; //turn: 1 is white, 0 is black
	public:
		ChessBoard(); //creates starting pieces
		void turn(); //game loop without sfml
		void print(); //print board with ascii graphics
		int valid(int pos1, int pos2); //checks if piece movement is valid
		void gameLoop(); //sfml game loop
};