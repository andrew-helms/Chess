#include "Player.h"

Player::Player(bool isHuman) {
	*playerPieces[0] = Piece(rook, 0, 0, isHuman);
	*playerPieces[1] = Piece(knight, 1, 0, isHuman);
	*playerPieces[2] = Piece(bishop, 2, 0, isHuman);
	*playerPieces[3] = Piece(queen, 3, 0, isHuman);
	*playerPieces[4] = Piece(king, 4, 0, isHuman);
	*playerPieces[5] = Piece(bishop, 5, 0, isHuman); 
	*playerPieces[6] = Piece(knight, 6, 0, isHuman);
	*playerPieces[7] = Piece(rook, 7, 0, isHuman);
	*playerPieces[8] = Piece(pawn, 0, 1, isHuman);
	*playerPieces[9] = Piece(pawn, 1, 1, isHuman);
	*playerPieces[10] = Piece(pawn, 2, 1, isHuman);
	*playerPieces[11] = Piece(pawn, 3, 1, isHuman);
	*playerPieces[12] = Piece(pawn, 4, 1, isHuman);
	*playerPieces[13] = Piece(pawn, 5, 1, isHuman); 
	*playerPieces[14] = Piece(pawn, 6, 1, isHuman);
	*playerPieces[15] = Piece(pawn, 7, 1, isHuman);

	score = 0;
}

int Player::getScore() {
	return score;
}
	
void Player::setScore(int scoreDiff) {
	score += scoreDiff;
}

void Player::playCard(int index) {

}
	
void Player::printCards() {

}

