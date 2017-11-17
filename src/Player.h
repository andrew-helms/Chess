#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.h"

class Player {
private:
	int score;
	Piece ***playerPieces [2][16];

public:
	Player(bool isHuman);
	int getScore();
	void playCard(int index);
	void setScore();
	void printCards();
};

#endif
