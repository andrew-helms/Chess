#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.h"
#include "Card.h"

class Player {
private:
	int score;
	Piece ***playerPieces [16];

public:
	Player(bool isHuman);
	int getScore();
	void setScore(int scoreDiff);
	void playCard(int index);
	void printCards();
};

#endif
