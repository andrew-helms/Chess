#include "Player.h"

Player::Player(bool isHuman) {
	playerPieces[0]	 = new Piece(rook,   0, 0, isHuman);
	playerPieces[1]	 = new Piece(knight, 1, 0, isHuman);
	playerPieces[2]	 = new Piece(bishop, 2, 0, isHuman);
	playerPieces[3]	 = new Piece(queen,  3, 0, isHuman);
	playerPieces[4]	 = new Piece(king,   4, 0, isHuman);
	playerPieces[5]	 = new Piece(bishop, 5, 0, isHuman); 
	playerPieces[6]	 = new Piece(knight, 6, 0, isHuman);
	playerPieces[7]	 = new Piece(rook,   7, 0, isHuman);
	playerPieces[8]	 = new Piece(pawn,   0, 1, isHuman);
	playerPieces[9]	 = new Piece(pawn,   1, 1, isHuman);
	playerPieces[10] = new Piece(pawn,   2, 1, isHuman);
	playerPieces[11] = new Piece(pawn,   3, 1, isHuman);
	playerPieces[12] = new Piece(pawn,   4, 1, isHuman);
	playerPieces[13] = new Piece(pawn,   5, 1, isHuman); 
	playerPieces[14] = new Piece(pawn,   6, 1, isHuman);
	playerPieces[15] = new Piece(pawn,   7, 1, isHuman);

	cards[0] = new Card(Empower);
	cards[1] = new Card(Switch);
	cards[2] = new Card(Revive);

	score = 0;
}

int Player::getScore() {
	return score;
}
	
void Player::setScore(int scoreDiff) {
	score += scoreDiff;

	if (score >= 30)
		cards[2]->active = true;

	else if (score >= 20)
		cards[1]->active = true;	

	else if (score >= 10)
		cards[0]->active = true;
}

bool Player::playCard(int index) {
	return cards[index]->playCard();
}
	
void Player::printCards() {
	std::cout << (cards[0]->active ? " _____________ " :  " _____________ ") << "\t" <<
		     (cards[1]->active ? " _____________ " :  " _____________ ") << "\t" <<
		     (cards[2]->active ? " _____________ " :  " _____________ ") << "\n" <<
		     (cards[0]->active ? "/             \\": "/             \\") << "\t" <<
		     (cards[1]->active ? "/             \\": "/             \\") << "\t" <<
		     (cards[2]->active ? "/             \\": "/             \\") << "\n" <<
		     (cards[0]->active ? "|   E      1  |" : "|   \\     /   |") << "\t" <<
		     (cards[1]->active ? "|   S      2  |" : "|   \\     /   |") << "\t" <<
		     (cards[2]->active ? "|   R      3  |" : "|   \\     /   |") << "\n" <<
		     (cards[0]->active ? "|    M        |" : "|    \\   /    |") << "\t" <<
		     (cards[1]->active ? "|    W        |" : "|    \\   /    |") << "\t" <<
		     (cards[2]->active ? "|    E        |" : "|    \\   /    |") << "\n" <<
		     (cards[0]->active ? "|     P       |" : "|     \\ /     |") << "\t" <<
		     (cards[1]->active ? "|     I       |" : "|     \\ /     |") << "\t" <<
		     (cards[2]->active ? "|     V       |" : "|     \\ /     |") << "\n" <<
		     (cards[0]->active ? "|      O      |" :  "|      X      |") << "\t" <<
		     (cards[1]->active ? "|      T      |" :  "|      X      |") << "\t" <<
		     (cards[2]->active ? "|      I      |" :  "|      X      |") << "\n" <<
		     (cards[0]->active ? "|       W     |" : "|     / \\     |") << "\t" <<
		     (cards[1]->active ? "|       C     |" : "|     / \\     |") << "\t" <<
		     (cards[2]->active ? "|       V     |" : "|     / \\     |") << "\n" <<
		     (cards[0]->active ? "|        E    |" : "|    /   \\    |") << "\t" <<
		     (cards[1]->active ? "|        H    |" : "|    /   \\    |") << "\t" <<
		     (cards[2]->active ? "|        E    |" : "|    /   \\    |") << "\n" <<
		     (cards[0]->active ? "|  1      R   |" : "|   /     \\   |") << "\t" <<
		     (cards[1]->active ? "|  2      !   |" : "|   /     \\   |") << "\t" <<
		     (cards[2]->active ? "|  3      !   |" : "|   /     \\   |") << "\n" <<
		     (cards[0]->active ? "\\_____________/": "\\_____________/") << "\t" <<
		     (cards[1]->active ? "\\_____________/": "\\_____________/") << "\t" <<
		     (cards[2]->active ? "\\_____________/": "\\_____________/") << "\n";
}

