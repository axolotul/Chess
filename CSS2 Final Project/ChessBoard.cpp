#include "ChessBoard.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
ChessBoard::ChessBoard()
{
	positions.resize(65);

	//white pieces
	for (int i = 2; i <= 64; i+=8)
	{
		positions[i] = Position(new Pawn, 1);
	}
	positions[1] = Position(new Rook, 1);
	positions[9] = Position(new Knight, 1);
	positions[17] = Position(new Bishop, 1);
	positions[33] = Position(new King, 1);
	positions[25] = Position(new Queen, 1);
	positions[41] = Position(new Bishop, 1);
	positions[49] = Position(new Knight, 1);
	positions[57] = Position(new Rook, 1);

	//black pieces
	for (int i = 7; i <= 64; i += 8)
	{
		positions[i] = Position(new Pawn, 0);
	}
	positions[8] = Position(new Rook, 0);
	positions[16] = Position(new Knight, 0);
	positions[24] = Position(new Bishop, 0);
	positions[40] = Position(new King, 0);
	positions[32] = Position(new Queen, 0);
	positions[48] = Position(new Bishop, 0);
	positions[56] = Position(new Knight, 0);
	positions[64] = Position(new Rook, 0);
}

/*
void ChessBoard::turn()
{
	int start, end, v;
	char h;
	cout << (t == 1 ? "White's " : "Black's ") << "turn, Enter position of piece to move : ";
	cin >> h >> v;
	start = ((int(h) - 65) * 8) + v;
	if (positions[start].getOccupied() == 1 && positions[start].getColor() == t)
	{
		cout << "Enter position to move to: ";
		cin >> h >> v;
		end = ((int(h) - 65) * 8) + v;

		if (valid(start, end) == 1)
		{	
			if (positions[end].getOccupied() == 1 && (positions[end].getType() == 'K' || positions[end].getType() == 'k'))
			{
				positions[end] = Position(positions[start].getPiece(), positions[start].getColor());
				positions[start] = Position();
				print();
				cout << "Checkmate: " << (positions[end].getColor() == 1 ? "White " : "Black ") << "wins!" << endl;
			}
			else
			{
				positions[end] = Position(positions[start].getPiece(), positions[start].getColor());
				positions[start] = Position();
			}
		}
		
		
		
		
		
		////empty end position
		//if (positions[end].getOccupied() == 0 && positions[start].valid(start, end) != 0 && skip(start, end, positions[start].getType(), positions[start].valid(start, end)) == 1)
		//{
		//	positions[end] = Position(positions[start].getPiece());
		//	positions[start] = Position();
		//	cout << "Empty end position" << endl;
		//}

		////pawn
		//else if ((positions[start].getType() == 'P' || positions[start].getType() == 'p'))
		//{
		//	if (positions[end].getOccupied() == 1 && positions[end].getColor() != t && positions[start].valid(start, end) == 2 && skip(start, end, positions[start].getType()) == 1)
		//	{
		//		positions[end] = Position(positions[start].getPiece());
		//		positions[start] = Position();
		//		cout << "Pawn capture" << endl;
		//	}
		//}
		////knight
		//else if (positions[start].getType() == 'K' || positions[start].getType() == 'k')
		//{
		//	cout << "Knight" << endl;
		//}
		//else
		//	cout << "Invalid move" << endl;





		//else if (positions[end].getOccupied() == 1 && positions[end].getColor() != t && positions[start].valid(start, end))
		//{
		//	positions[end] = Position(positions[start].getPiece());
		//	positions[start] = Position();
		//}
		//else if (positions[start].getType() == 'P' || positions[start].getType() == 'p')
		//{
		//	if (positions[end].getOccupied() == 1 && positions[end].getColor() != t && positions[start].valid(start, end))
		//	{
		//		positions[end] = Position(positions[start].getPiece());
		//		positions[start] = Position();
		//	}
		//}
	}
	if (t == 1)
		t = 0;
	else
		t = 1;
}
*/

//checks if piece movement is valid
int ChessBoard::valid(int pos1, int pos2)
{	
	//converts positions into column/row
	int row1, row2, column1, column2;
	for (int i = 8; i >= 1; i--)
	{
		if ((pos1 - i) % 8 == 0)
		{
			column1 = (pos1 - i) / 8;
			row1 = pos1 - (column1 * 8);
			if (row1 == 0)
			{
				column1 -= 1;
				row1 = 8;
			}
		}
		if ((pos2 - i) % 8 == 0)
		{
			column2 = (pos2 - i) / 8;
			row2 = pos2 - (column2 * 8);
			if (row2 == 0)
			{
				column2 -= 1;
				row2 = 8;
			}
		}
	}

	//checks if movement is valid for specific piece (ex. Pawn cant move horizontally)
	if (positions[pos1].valid(pos1, pos2) == 0)
	{
		return 0;
	}

	//can't land on friendly piece
	else if (positions[pos2].getOccupied() == 1 && positions[pos1].getColor() == positions[pos2].getColor())
	{
		return 0;
	}

	//following checks if piece would 'skip' over any pieces
	//pawn
	else if (positions[pos1].getType() == 'P' || positions[pos1].getType() == 'p')
	{
		if (positions[pos1].getType() == 'P')
		{
			if (pos2 == pos1 + 2 && positions[pos1 + 1].getOccupied() == 1)
				return 0;
			else if (positions[pos1].valid(pos1, pos2) == 2 && positions[pos2].getOccupied() == 0)
				return 0;
			else if (positions[pos1].valid(pos1, pos2) == 1 && positions[pos2].getOccupied() == 1)
				return 0;
		}
		else if (positions[pos1].getType() == 'p')
		{
			if (pos2 == pos1 - 2 && positions[pos1 - 1].getOccupied() == 1)
				return 0;
			else if (positions[pos1].valid(pos1, pos2) == 2 && positions[pos2].getOccupied() == 0)
				return 0;
			else if (positions[pos1].valid(pos1, pos2) == 1 && positions[pos2].getOccupied() == 1)
				return 0;
		}
	}

	//rook
	else if (positions[pos1].getType() == 'R' || positions[pos1].getType() == 'r')
	{
		switch (positions[pos1].valid(pos1, pos2))
		{
			case 1:
			{
				for (int i = 1; i < (row2 - row1); i++)
				{
					if (positions[pos1 + i].getOccupied())
						return 0;
				}
				break;
			}
			case 2:
			{
				for (int i = 1; i < (column2 - column1); i++)
				{
					if (positions[pos1 + (8 * i)].getOccupied())
						return 0;
				}
				break;
			}
			case 3:
			{
				for (int i = 1; i < (row1-row2); i++)
				{
					if (positions[pos1 - i].getOccupied())
						return 0;
				}
				break;
			}

			case 4:
			{
				for (int i = 1; i < (column1 - column2); i++)
				{
					if (positions[pos1 - (8 * i)].getOccupied())
						return 0;
				}
				break;
			}
		}
	}

	//bishop
	else if (positions[pos1].getType() == 'B' || positions[pos1].getType() == 'b')
	{
		switch (positions[pos1].valid(pos1, pos2))
		{
		case 1:
		{
			for (int i = 1; i < ((column2 - column1)); i++)
			{
				if (positions[pos1 + (8*i) + i].getOccupied())
					return 0;
			}
			break;
		}
		case 2:
		{
			for (int i = 1; i < ((column2 - column1)); i++)
			{
				if (positions[pos1 + (8 * i) - i].getOccupied())
					return 0;
			}
			break;
		}
		case 3:
		{
			for (int i = 1; i < (-1 * (column2 - column1)); i++)
			{
				if (positions[pos1 - (8 * i) - i].getOccupied())
					return 0;
			}
			break;
		}

		case 4:
		{
			for (int i = 1; i < (-1 * (column2 - column1)); i++)
			{
				if (positions[pos1 - (8 * i) + i].getOccupied())
					return 0;
			}
			break;
		}
		}
	}

	//queen
	else if (positions[pos1].getType() == 'Q' || positions[pos1].getType() == 'q')
	{
		switch (positions[pos1].valid(pos1, pos2))
		{
		case 1:
		{
			for (int i = 1; i < (row2 - row1); i++)
			{
				if (positions[pos1 + i].getOccupied())
					return 0;
			}
			break;
		}
		case 2:
		{
			for (int i = 1; i < ((column2 - column1)); i++)
			{
				if (positions[pos1 + (8 * i) + i].getOccupied())
					return 0;
			}
			break;
		}
		case 3:
		{
			for (int i = 1; i < (column2 - column1); i++)
			{
				if (positions[pos1 + (8 * i)].getOccupied())
					return 0;
			}
			break;
		}
		case 4:
		{
			for (int i = 1; i < ((column2 - column1)); i++)
			{
				if (positions[pos1 + (8 * i) - i].getOccupied())
					return 0;
			}
			break;
		}
		case 5:
		{
			for (int i = 1; i < (row1 - row2); i++)
			{
				if (positions[pos1 - i].getOccupied())
					return 0;
			}
			break;
		}
		case 6:
		{
			for (int i = 1; i < (-1 * (column2 - column1)); i++)
			{
				if (positions[pos1 - (8 * i) - i].getOccupied())
					return 0;
			}
			break;
		}
		case 7:
		{
			for (int i = 1; i < (column1 - column2); i++)
			{
				if (positions[pos1 - (8 * i)].getOccupied())
					return 0;
			}
			break;
		}
		case 8:
		{
			for (int i = 1; i < (-1 * (column2 - column1)); i++)
			{
				if (positions[pos1 - (8 * i) + i].getOccupied())
					return 0;
			}
			break;
		}
		}
	}
	return 1;
	//knight not included as it can skip over pieces
	//king not included as it can only move one position
}

//ascii graphics
/*
void ChessBoard::print()
{
	int posCount = 1;
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
		{
			cout << "     A   B   C   D   E   F   G   H " << endl;
		}
		cout << "    --- --- --- --- --- --- --- ---" << endl;

		for (int l = 0; l < 9; l++)
		{
			if (l < 8)
			{
				if (l == 0)
				{
					cout << ' ' << 8 - i << " | ";
				}
				else
					cout << "| ";
				if (positions[(l * 8) + (8 - i)].getOccupied() == 1)
					cout << positions[(l * 8) + (8 - i)].getType();
				else
					cout << " ";
				cout << " ";
				posCount++;
			}
			else
			{
				cout << "| " << 8 - i;
				cout << endl;
			}

		}
		if (i == 7)
		{
			cout << "    --- --- --- --- --- --- --- ---" << endl;
			cout << "     A   B   C   D   E   F   G   H " << endl;
		}
	}
}
*/

//sfml game loop
void ChessBoard::gameLoop()
{
	//variables
	bool pressed = 0;
	int locx, locy, pos1 = 7, pos2, x, y;
	sf::Texture Board;
	sf::Texture p;
	sf::Texture h;
	sf::Texture b;
	sf::Texture r;
	sf::Texture q;
	sf::Texture k;

	//window
    sf::RenderWindow window(sf::VideoMode(512, 512), "Chessboard");

	//load textures
	Board.loadFromFile("C:/Users/andyg/Pictures/ChessBoard.png");
	p.loadFromFile("C:/Users/andyg/Pictures/pawn.png");
	h.loadFromFile("C:/Users/andyg/Pictures/knight.png");
	b.loadFromFile("C:/Users/andyg/Pictures/bishop.png");
	r.loadFromFile("C:/Users/andyg/Pictures/rook.png");
	q.loadFromFile("C:/Users/andyg/Pictures/queen.png");
	k.loadFromFile("C:/Users/andyg/Pictures/king.png");

	//sprites
    sf::Sprite chessBoard;
	sf::Sprite pawn;
	sf::Sprite knight;
	sf::Sprite bishop;
	sf::Sprite rook;
	sf::Sprite queen;
	sf::Sprite king;

	//place textures on sprites
	chessBoard.setTexture(Board);
	pawn.setTexture(p);
	knight.setTexture(h);
	bishop.setTexture(b);
	rook.setTexture(r);
	queen.setTexture(q);
	king.setTexture(k);

	cout << "White's turn" << endl;

	//game loop
    while (window.isOpen()) 
    {
		//events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
				//closes window if user tries to
				case(sf::Event::Closed):
				{
					window.close();
					break;
				}

				//get current mouse coordinates
				case(sf::Event::MouseMoved):
				{
					x = event.mouseMove.x;
					y = event.mouseMove.y;
					break;
				}

				//get mouse coordinates when click
				case(sf::Event::MouseButtonPressed):
				{
					//converts click coordinates into board position and checks if occupied by players piece
					locx = event.mouseButton.x / 64;
					locy = event.mouseButton.y / 64;
					pos1 = (locx * 8) + (8 - locy);
					if (positions[pos1].getOccupied() == 1 && positions[pos1].getColor() == t)
					{
						pressed = 1;
					}
					break;
				}

				//mouse coordinates when click is released
				case(sf::Event::MouseButtonReleased):
				{
					if (pressed == 1)
						positions[pos1].setOccupied(1);
					locx = event.mouseButton.x / 64;
					locy = event.mouseButton.y / 64;
					pos2 = (locx * 8) + (8 - locy);

					//checks if position where click is released can be captured
					if (pressed == 1 && valid(pos1, pos2))
					{	
						//checks for checkmate
						if (positions[pos2].getOccupied() == 1 && (positions[pos2].getType() == 'K' || positions[pos2].getType() == 'k'))
						{
							positions[pos2] = Position(positions[pos1].getPiece(), t);
							positions[pos1] = Position();
							cout << "Checkmate: " << (positions[pos2].getColor() == 1 ? "White " : "Black ") << "wins!" << endl;
							window.close();
						}

						//captures position
						else
						{
							positions[pos2] = Position(positions[pos1].getPiece(), t);
							positions[pos1] = Position();
							if (t == 1)
								t = 0;
							else
								t = 1;
							cout << (t == 1 ? "White's " : "Black's ") << "turn" << endl;
						}
					}
					pressed = 0;
					break;
				}
				default:
					break;
            }
        }
		//clears window
		window.clear();

		//displays board
		window.draw(chessBoard);

		//displays pieces
		for (int i = 8; i >= 1; i--)
		{
			for (int x = 0; x < 8; x++)
			{

				if (positions[(x * 8) + i].getOccupied() == 1)
				{
					switch (positions[(x * 8) + i].getType())
					{
					case('P'):
					{
						pawn.setPosition((x * 64), ((8 - i) * 64));
						pawn.setColor(sf::Color(255, 255, 255));
						window.draw(pawn);
						break;
					}
					case('H'):
					{
						knight.setPosition((x * 64), ((8 - i) * 64));
						knight.setColor(sf::Color(255, 255, 255));
						window.draw(knight);
						break;
					}
					case('B'):
					{
						bishop.setPosition((x * 64), ((8 - i) * 64));
						bishop.setColor(sf::Color(255, 255, 255));
						window.draw(bishop);
						break;
					}
					case('R'):
					{
						rook.setPosition((x * 64), ((8 - i) * 64));
						rook.setColor(sf::Color(255, 255, 255));
						window.draw(rook);
						break;
					}
					case('Q'):
					{
						queen.setPosition((x * 64), ((8 - i) * 64));
						queen.setColor(sf::Color(255, 255, 255));
						window.draw(queen);
						break;
					}
					case('K'):
					{
						king.setPosition((x * 64), ((8 - i) * 64));
						king.setColor(sf::Color(255, 255, 255));
						window.draw(king);
						break;
					}
					case('p'):
					{
						pawn.setPosition((x * 64), ((8 - i) * 64));
						pawn.setColor(sf::Color(0, 0, 0));
						window.draw(pawn);
						break;
					}
					case('h'):
					{
						knight.setPosition((x * 64), ((8 - i) * 64));
						knight.setColor(sf::Color(0, 0, 0));
						window.draw(knight);
						break;
					}
					case('b'):
					{
						bishop.setPosition((x * 64), ((8 - i) * 64));
						bishop.setColor(sf::Color(0, 0, 0));
						window.draw(bishop);
						break;
					}
					case('r'):
					{
						rook.setPosition((x * 64), ((8 - i) * 64));
						rook.setColor(sf::Color(0, 0, 0));
						window.draw(rook);
						break;
					}
					case('q'):
					{
						queen.setPosition((x * 64), ((8 - i) * 64));
						queen.setColor(sf::Color(0, 0, 0));
						window.draw(queen);
						break;
					}
					case('k'):
					{
						king.setPosition((x * 64), ((8 - i) * 64));
						king.setColor(sf::Color(0, 0, 0));
						window.draw(king);
						break;
					}
					default:
						break;
					}
				}
			}
		}

		//drags held piece where mouse goes
		if (pressed == 1)
		{
			positions[pos1].setOccupied(0);
			switch (positions[pos1].getType())
			{
				case('P'):
				{
					pawn.setPosition(x - 32, y - 32);
					pawn.setColor(sf::Color(255, 255, 255));
					window.draw(pawn);
					break;
				}
				case('H'):
				{
					knight.setPosition(x - 32, y - 32);
					knight.setColor(sf::Color(255, 255, 255));
					window.draw(knight);
					break;
				}
				case('B'):
				{
					bishop.setPosition(x - 32, y - 32);
					bishop.setColor(sf::Color(255, 255, 255));
					window.draw(bishop);
					break;
				}
				case('R'):
				{
					rook.setPosition(x - 32, y - 32);
					rook.setColor(sf::Color(255, 255, 255));
					window.draw(rook);
					break;
				}
				case('Q'):
				{
					queen.setPosition(x - 32, y - 32);
					queen.setColor(sf::Color(255, 255, 255));
					window.draw(queen);
					break;
				}
				case('K'):
				{
					king.setPosition(x - 32, y - 32);
					king.setColor(sf::Color(255, 255, 255));
					window.draw(king);
					break;
				}
				case('p'):
				{
					pawn.setPosition(x - 32, y - 32);
					pawn.setColor(sf::Color(0, 0, 0));
					window.draw(pawn);
					break;
				}
				case('h'):
					knight.setPosition(x - 32, y - 32);
					knight.setColor(sf::Color(0, 0, 0));
					window.draw(knight);
					break;
				case('b'):
					bishop.setPosition(x - 32, y - 32);
					bishop.setColor(sf::Color(0, 0, 0));
					window.draw(bishop);
					break;
				case('r'):
					rook.setPosition(x - 32, y - 32);
					rook.setColor(sf::Color(0, 0, 0));
					window.draw(rook);
					break;
				case('q'):
					queen.setPosition(x - 32, y - 32);
					queen.setColor(sf::Color(0, 0, 0));
					window.draw(queen);
					break;
				case('k'):
					king.setPosition(x - 32, y - 32);
					king.setColor(sf::Color(0, 0, 0));
					window.draw(king);
					break;
				default:
					break;
			}
		}
		
		//displays drawn items
        window.display();
    }
	//closes window
	window.close();
}