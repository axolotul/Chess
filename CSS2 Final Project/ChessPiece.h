#pragma once
class ChessPiece
{
	protected:
		bool color;

	//virtual functions, meant to be used for polymorphism
	public:
		ChessPiece();
		virtual void setColor(bool c);
		virtual bool getColor() const;
		virtual int move(int pos1, int pos2);
		virtual char getPiece() const;
};

