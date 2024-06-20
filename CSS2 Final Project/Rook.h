#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece
{
	public:
		Rook();
		Rook(bool c);
		int move(int pos1, int pos2) override;
		char getPiece() const override;
		void setColor(bool c) override;
		bool getColor() const override;

};

