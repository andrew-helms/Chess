#include <iostream>
#include "Piece.h"
#include "Point.h"
#include "Player.h"
#include "Enumerations.h"

using namespace std;

int main()
{
	/*Piece *WPawn = new Piece(pawn, 2, 2, true);
	WPawn->getPos().print();
	cout<<"ks\n";
	Piece ***playerPieces = new Piece **[2];
	playerPieces[0] = new Piece *[16];
	playerPieces[1] = new Piece *[16];
	playerPieces[0][0] = WPawn;
	for (int i = 1; i < 16; i++)
		playerPieces[0][i] = new Piece(pawn, -1, -1, true);
	for (int i = 0; i < 16; i++)
		playerPieces[1][i] = new Piece(pawn, -1, -1, false);
	//playerPieces[0][12] = new Piece(pawn, 4, 5, true);
	playerPieces[1][2] = new Piece(rook, 2, 3, false);
	//playerPieces[1][4] = new Piece(bishop, 1, 3, false);
	//playerPieces[1][12] = new Piece(pawn, 2, 4, false);
	//playerPieces[1][6] = new Piece(knight, 2, 3, false);
	//playerPieces[1][0] = new Piece(king, 1, 2, false);
	//playerPieces[0][0] = new Piece(king, 0, 1, true);

	Point *moveSet = WPawn->determineMoveSet(playerPieces);
	for (int i = 0; i < 3; i++) {
		moveSet[i].print();
	}*/
	Player* plyr1 = new Player(true);
	plyr1->setScore(11);
	plyr1->setScore(20);
	plyr1->printCards();
	plyr1->playCard(0);
	plyr1->printCards();
}
