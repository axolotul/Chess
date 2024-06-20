#pragma once
#include "ChessPiece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
class Position
{
	private:
		bool occupied;
		ChessPiece* piece;
	public:
		Position();
		Position(ChessPiece* p, bool c);
		bool getOccupied();
		void setOccupied(bool o);
		char getType();
		bool getColor();
		void setColor(bool c);
		ChessPiece* getPiece();
		void setPiece(ChessPiece* p);
		int valid(int pos1, int pos2);
};

