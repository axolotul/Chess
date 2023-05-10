#pragma once
#include "ChessPiece.h"
#include "Pawn.h"
class Position
{
	private:
		bool occupied;
		ChessPiece* piece;
		int pos;
	public:
		Position();
		Position(ChessPiece* p);
		void Position1();
		bool getOccupied();
		void setOccupied(bool o);
		int getPos();
		char getType();
		bool getColor();
		void setColor(bool c);
		ChessPiece* getPiece();
		void setPiece(ChessPiece* p);
		void setPos(int p);
		bool valid(int pos1, int pos2);
};

