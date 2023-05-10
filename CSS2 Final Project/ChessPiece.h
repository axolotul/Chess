#pragma once
class ChessPiece
{
	protected:
		bool color;

	public:
		ChessPiece();
		ChessPiece(bool c);
		virtual void setColor(bool c);
		virtual bool getColor();
		virtual bool move(int pos1, int pos2);
		virtual char getPiece();
};

