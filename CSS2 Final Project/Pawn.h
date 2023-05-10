#pragma once
#include "ChessPiece.h"
class Pawn: public ChessPiece
{
	private:
		bool isFirstMove = 1;
	public:
		Pawn();
		bool move(int pos1, int pos2) override;
		char getPiece() override;
		void setColor(bool c);
		bool getColor();
};