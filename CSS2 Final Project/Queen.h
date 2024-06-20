#pragma once
#include "ChessPiece.h"
class Queen : public ChessPiece
{
public:
	Queen();
	int move(int pos1, int pos2) override;
	char getPiece() const override;
	void setColor(bool c) override;
	bool getColor() const override;
};


