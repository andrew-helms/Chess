#include "Player.h"

Player::Player(bool isHuman) {
	int start1 = (isHuman ? 7 : 0);
	int start2 = (isHuman ? 6 : 1);

	playerPieces[0] = new Piece(rook, 0, start1, isHuman);
	playerPieces[1] = new Piece(knight, 1, start1, isHuman);
	playerPieces[2] = new Piece(bishop, 2, start1, isHuman);
	playerPieces[3] = new Piece(queen, 3, start1, isHuman);
	playerPieces[4] = new Piece(king, 4, start1, isHuman);
	playerPieces[5] = new Piece(bishop, 5, start1, isHuman);
	playerPieces[6] = new Piece(knight, 6, start1, isHuman);
	playerPieces[7] = new Piece(rook, 7, start1, isHuman);
	playerPieces[8] = new Piece(pawn, 0, start2, isHuman);
	playerPieces[9] = new Piece(pawn, 1, start2, isHuman);
	playerPieces[10] = new Piece(pawn, 2, start2, isHuman);
	playerPieces[11] = new Piece(pawn, 3, start2, isHuman);
	playerPieces[12] = new Piece(pawn, 4, start2, isHuman);
	playerPieces[13] = new Piece(pawn, 5, start2, isHuman);
	playerPieces[14] = new Piece(pawn, 6, start2, isHuman);
	playerPieces[15] = new Piece(pawn, 7, start2, isHuman);

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
	std::cout << (cards[0]->active ? " _____________ " : " _____________ ") << "\t" <<
		(cards[1]->active ? " _____________ " : " _____________ ") << "\t" <<
		(cards[2]->active ? " _____________ " : " _____________ ") << "\n" <<
		(cards[0]->active ? "/             \\" : "/             \\") << "\t" <<
		(cards[1]->active ? "/             \\" : "/             \\") << "\t" <<
		(cards[2]->active ? "/             \\" : "/             \\") << "\n" <<
		(cards[0]->active ? "|   E      1  |" : "|   \\     /   |") << "\t" <<
		(cards[1]->active ? "|   S      2  |" : "|   \\     /   |") << "\t" <<
		(cards[2]->active ? "|   R      3  |" : "|   \\     /   |") << "\n" <<
		(cards[0]->active ? "|    M        |" : "|    \\   /    |") << "\t" <<
		(cards[1]->active ? "|    W        |" : "|    \\   /    |") << "\t" <<
		(cards[2]->active ? "|    E        |" : "|    \\   /    |") << "\n" <<
		(cards[0]->active ? "|     P       |" : "|     \\ /     |") << "\t" <<
		(cards[1]->active ? "|     I       |" : "|     \\ /     |") << "\t" <<
		(cards[2]->active ? "|     V       |" : "|     \\ /     |") << "\n" <<
		(cards[0]->active ? "|      O      |" : "|      X      |") << "\t" <<
		(cards[1]->active ? "|      T      |" : "|      X      |") << "\t" <<
		(cards[2]->active ? "|      I      |" : "|      X      |") << "\n" <<
		(cards[0]->active ? "|       W     |" : "|     / \\     |") << "\t" <<
		(cards[1]->active ? "|       C     |" : "|     / \\     |") << "\t" <<
		(cards[2]->active ? "|       V     |" : "|     / \\     |") << "\n" <<
		(cards[0]->active ? "|        E    |" : "|    /   \\    |") << "\t" <<
		(cards[1]->active ? "|        H    |" : "|    /   \\    |") << "\t" <<
		(cards[2]->active ? "|        E    |" : "|    /   \\    |") << "\n" <<
		(cards[0]->active ? "|  1      R   |" : "|   /     \\   |") << "\t" <<
		(cards[1]->active ? "|  2      !   |" : "|   /     \\   |") << "\t" <<
		(cards[2]->active ? "|  3      !   |" : "|   /     \\   |") << "\n" <<
		(cards[0]->active ? "\\_____________/" : "\\_____________/") << "\t" <<
		(cards[1]->active ? "\\_____________/" : "\\_____________/") << "\t" <<
		(cards[2]->active ? "\\_____________/" : "\\_____________/") << "\n";
}

Piece** Player::getPieces() {
	return playerPieces;
}