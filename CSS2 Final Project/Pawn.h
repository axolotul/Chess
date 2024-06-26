#pragma once
#include "ChessPiece.h"
class Pawn: public ChessPiece
{
	private:
		bool isFirstMove;
	public:
		Pawn();
		int move(int pos1, int pos2) override;
		char getPiece() const override;
		void setColor(bool c) override;
		bool getColor() const override;
};