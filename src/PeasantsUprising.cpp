#include "./PeasantsUprising.h"

int main() {
	string input;
	int turnTracker = 1;

	std::cout << "Welcome to Peasant's Uprising!\n";

	std::cout << "\nHumans start.";

	createBoard();
	printBoard();

	std::cout << "Piece - ";

	std::cin >> input;

	input = toLower(input);

	//Loops until user exits
	while (input != "exit") {
		int boardSpot = boardSpotToNum(input);
		Point pieceLoc;
		Piece* piece;

		//Loops until the user enters a valid board space
		while (boardSpot == -1) {
			std::cout << "\nLet's try that again.\n\nPiece - ";
			std::cin >> input;
			boardSpot = boardSpotToNum(input);
		}

		pieceLoc = Point((int)boardSpot/10, boardSpot%10);
		//piece = findPiece(pieceLoc);
		//preview(piece);


		//CLEAR SCREEN HERE

		std::cout << (turnTracker == 0 ? "\nHumans " : "\nOrcz ") << "turn";

		printBoard();

		std::cout << "\nPiece - ";
		std::cin >> input;
		input = toLower(input);

		turnTracker = (turnTracker == 0 ? 1 : 0); //Switches to the next player
	}

	return 1;
}

/* This function takes a string and converts it to an all lowercase string. The string can contain any character.
@param string: The string to convert
@return string: The lowercase string
*/
string toLower(string s1) {
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] >= 65 && s1[i] <= 90) s1[i] = tolower(s1[i]);
	}

	return s1;
}

/* This function converts a space on the board to the corresponding index in the board array. If the space isn't on the board, -1 is returned.
@param string: The space to convert.
@return int: The corresponding index in the board array. The first digit corresponds the first array index, the second digit corresponds to the second.
An example of a return is 67 which means the spot is the 7th index in the 6th indexed array in board
*/
int boardSpotToNum(string s1) {
	int spot;
	s1 = toLower(s1);

	if (s1.length() != 2) return -1; //If the input is not 2 characters

	if (s1[1] == '1') {
		spot = 0;
	}
	else if (s1[1] == '2') {
		spot = 10;
	}
	else if (s1[1] == '3') {
		spot = 20;
	}
	else if (s1[1] == '4') {
		spot = 30;
	}
	else if (s1[1] == '5') {
		spot = 40;
	}
	else if (s1[1] == '6') {
		spot = 50;
	}
	else if (s1[1] == '7') {
		spot = 60;
	}
	else if (s1[1] == '8') {
		spot = 70;
	}
	else {
		return -1;
	}

	if (s1[0] == 'a') {
		spot += 0;
	}
	else if (s1[0] == 'b') {
		spot += 1;
	}
	else if (s1[0] == 'c') {
		spot += 2;
	}
	else if (s1[0] == 'd') {
		spot += 3;
	}
	else if (s1[0] == 'e') {
		spot += 4;
	}
	else if (s1[0] == 'f') {
		spot += 5;
	}
	else if (s1[0] == 'g') {
		spot += 6;
	}
	else if (s1[0] == 'h') {
		spot += 7;
	}
	else {
		return -1;
	}

	return spot;
}

bool spotOccupied(int spot) {
	return (board[(int)spot/10][spot%10][0] != ' ');
}

/* This function finds the piece at the given spot.
@param Point: The point to look for
@return Piece*: A pointer to the piece found
*/
Piece* findPiece(Point spot) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 16; j++) {
			if (pieces[i][j]->getPos().x == spot.x && pieces[i][j]->getPos().y == spot.y) return pieces[i][j];
		}
	}
}

/* This function prints the menu
*/
void printMenu() {
	std::cout << "1. Move piece\n2. Pick different piece\n";
}

/* This function prints the board in its current state
*/
void printBoard() { 
	//Prints the scoreboard
	std::cout << "\n\n\tScore";
	std::cout << "\nHumans\t" << players[0].getScore();
	std::cout << "\nOrcz\t" << players[1].getScore();
	std::cout << "\n\n  +---------------------------------------+\n"; //outputs the first line of the board

																	  //Loops through the board
	for (int i = 0; i < 8; i++) {
		std::cout << (i + 1) << " |";
		for (int j = 0; j < 8; j++) {
			std::cout << " " << board[i][j][0] << board[i][j][1] << " |";
		}

		std::cout << ((i != 7) ? "\n  |----+----+----+----+----+----+----+----|\n" : "\n  +---------------------------------------+\n");
	}

	std::cout << "    A    B    C    D    E    F    G    H\n\n"; //Outputs the bottom of the board
}

/* This function prints a preview board which showcases all of the possible spots a piece can move.
@param Piece: The piece to preview
@return Point*: The pointer to the array of the spots the piece can move
*/
Point* preview(Piece* piece) {
	Piece** pieces[2];
	pieces[0] = players[0].getPieces();
	pieces[1] = players[1].getPieces();

	Player plyr = players[!piece->isHuman];
	Point* move = piece->determineMoveSet(pieces); //Will need to rework

	Point comp; //Comparison point (used to test whether piece is on spot)
	Point endPt = Point(-1, -1);

	std::cout << "\nThese are the available spots for the " << piece->name << ":";
	std::cout << "\n  +---------------------------------------+\n"; //outputs the first line of the board

																  //Loops through the board
	for (int i = 0; i < 8; i++) {
		std::cout << (i + 1) << " |";
		for (int j = 0; j < 8; j++) {
			std::cout << " " << board[i][j][0] << board[i][j][1] << " |";
			int k = 0;
			comp.x = i;
			comp.y = j;

			while (!move[k].equals(endPt)) {
				if (move[k].equals(comp)) {
					if (board[i][j][0] == ' ') { //Empty spots are double spaced
						std::cout << "xxxx";
					}
					else {
						std::cout << "x" << board[i][j][0] << board[i][j][1] << "x";
					}
				}

				k++;
			}
		}

		std::cout << ((i != 7) ? "\n  |----+----+----+----+----+----+----+----|\n" : "\n  +---------------------------------------+\n");
	}

	std::cout << "    A    B    C    D    E    F    G    H "; //Outputs the bottom of the board

	return move;
}

/* This function moves a piece to the given spot. It updates the piece's interal spot and the board. The space where the piece was originally is turned blank
@param Piece*: The pointer to the piece to move
@param Point: The spot to move the piece to
*/
void movePiece(Piece* piece, Point spot) {
	Point oldPos = piece->getPos(); //Tracks the old position
	
	//Moves the piece
	if (spot.x == -1) { //if the piece is being captured
		piece->move(pieces, -1, -1);
	} else {
		piece->move(pieces, spot.x, spot.y);
		board[spot.y][spot.x][0] = (piece->isHuman ? 'H' : 'O');
		board[spot.y][spot.x][1] = piece->symb;
	}

	//Updates the board
	board[7 - oldPos.y][oldPos.x][0] = ' ';
	board[7 - oldPos.y][oldPos.x][1] = ' ';
}

/* This function fills the global board with the symbols for the initial piece positions
*/
void createBoard() {

	//Sets all values to a space the will be overwritten later
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 2; k++)
				board[i][j][k] = ' ';

	for (int i = 0; i < 8; i++) {
		//Sets Human and Orc type
		board[0][i][0] = 'O';
		board[1][i][0] = 'O';
		board[6][i][0] = 'H';
		board[7][i][0] = 'H';

		//Sets pawn type
		board[1][i][1] = 'P';
		board[6][i][1] = 'P';
	}

	//Fills remaining Orc pieces
	board[0][0][1] = 'R';
	board[0][1][1] = 'N';
	board[0][2][1] = 'B';
	board[0][3][1] = 'Q';
	board[0][4][1] = 'K';
	board[0][5][1] = 'B';
	board[0][6][1] = 'N';
	board[0][7][1] = 'R';

	//FIlls remaining Human pieces
	board[7][0][1] = 'R';
	board[7][1][1] = 'N';
	board[7][2][1] = 'B';
	board[7][3][1] = 'Q';
	board[7][4][1] = 'K';
	board[7][5][1] = 'B';
	board[7][6][1] = 'N';
	board[7][7][1] = 'R';
}

/* This function handles the event in which the Switch card is played.
@param Piece*: The pointer to the first piece to switch
@param Piece*: The pointer to the second piece to switch
*/
void switchCard(Piece* piece1, Piece* piece2) {
	Point oldP1 = piece1->getPos();
	Point oldP2 = piece2->getPos();

	//Updates the pieces position
	piece1->move(pieces, oldP2.x, oldP2.y);
	piece2->move(pieces, oldP1.x, oldP1.y);

	//Updates the board
	board[7 - oldP2.y][oldP2.x][1] = piece1->symb;
	board[7 - oldP1.y][oldP1.x][1] = piece2->symb;
}

void empowerCard() {
	empowered = true;
}

/* This function brings the specified piece back to life in a spot in the first 2 rows. --> need to check that the spot is in the first two rows
@param Piece*: A pointer to the piece to bring back
*/
void reviveCard(Piece* res) {
	Player player = players[!res->isHuman];
	Piece** pieces[2]; //All the pieces on the board
	pieces[0] = players[0].getPieces();
	pieces[1] = players[1].getPieces();
	string stringSpot;
	int numSpot;

	std::cout << "You may pick a spot in your first two rows.\nSpot - ";
	std::cin >> stringSpot;

	numSpot = boardSpotToNum(stringSpot); //The 2 digit representation of the spot

	//Loops while the user enters an available spaces
	while (spotOccupied(numSpot)) {
		std::cout << "Spot is unavailable. Let's try that again.\nSpot- ";
		std::cin >> stringSpot;

		numSpot = boardSpotToNum(stringSpot);
	}

	//Loops through the players pieces
	for (int i = 0; i < 16; i++) {
		if (pieces[!res->isHuman][i]->bit == res->bit && pieces[!res->isHuman][i]->getPos().x == -1) { //If the piece matches and is captured
			pieces[!res->isHuman][i]->move(pieces, (int)numSpot/10, numSpot%10); //Move the piece

			//update the board
			board[(int)numSpot / 10][numSpot % 10][0] = (res->isHuman ? 'H' : 'O');
			board[(int)numSpot / 10][numSpot % 10][1] = res->symb;
		}
	}
}