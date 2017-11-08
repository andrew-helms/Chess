#ifndef PIECE_H
#define PIECE_H

#include "Point.h"
#include "Player.h"	
#include <string>
#include "Enumerations.h"

using namespace std;

class Piece {
	friend class Player;

private:
	Point pos;
public:

	char symb;
	string name;
	Type bit;
	bool isHuman;
	
	Piece(Type type, int x, int y, bool isHuman);
	void move(int x, int y);
	Point* determineMoveSet(Piece ***playerPieces);
	Point getPos();
 	bool danger(Piece ***playerPieces, Point tip);
	bool discoverCheck(Piece ***playerPieces, Point tryMove);
};

#endif
