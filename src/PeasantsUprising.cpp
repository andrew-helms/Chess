#include "./PeasantsUprising.h"

players[2] = {new Player(true), new Player(false)};
empowered = false; //Tracks whether the empowered card is being played

//King 8
//Queen 27
//Bishop 13
//Rook 14
//Knight 8
//Pawn 3

int main() {
	string input;
	int turnTracker = 1;

	std::cout << "Welcome to Peasant's Uprising!\n";

	std::cout << "\nHumans start.";

	createBoard();
	printScoreboard();
	printBoard();

	std::cout << "Piece - ";

	std::cin >> input;

	input = toLower(input);

	//Loops until user exits
	while (input != "exit") {
		int boardSpot = boardSpotToNum(input);

		//Loops until the user enters a valid board space
		while (boardSpot == -1) {
			std::cout << "\nLet's try that again.\n\nPiece - ";
			std::cin >> input;
			input = toLower(input);
			boardSpot = boardSpotToNum(input);
		}
		

		//CLEAR SCREEN HERE

		std::cout << (turnTracker == 0 ? "\nHumans " : "\nOrcz ") << "turn";

		printScoreboard();
		printBoard();

		std::cout << "\nPiece - ";
		std::cin >> input;
		input = toLower(input);

		turnTracker = (turnTracker == 0 ? 1 : 0); //Switches to the next player
	}

	return 1;
}

void printScoreboard() {
	std::cout << "\n\n\tScore";
	std::cout << "\nHumans\t";
	std::cout << "\nOrcz\t";
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
@param string: The space to convert. It assumes the space is lowercase.
@return int: The corresponding index in the board array. The first digit corresponds the first array index, the second digit corresponds to the second.
An example of a return is 67 which means the spot is the 7th index in the 6th indexed array in board
*/
int boardSpotToNum(string s1) {
	int spot;

	if (s1.length() != 2) return -1; //If the input is not 2 characters

	if (s1[1] == '1') {
		spot = 0;
	} else if (s1[1] == '2') {
		spot = 10;
	} else if (s1[1] == '3') {
		spot = 20;
	} else if (s1[1] == '4') {
		spot = 30;
	} else if (s1[1] == '5') {
		spot = 40;
	} else if (s1[1] == '6') {
		spot = 50;
	} else if (s1[1] == '7') {
		spot = 60;
	} else if (s1[1] == '8') {
		spot = 70;
	} else {
		return -1;
	}

	if (s1[0] == 'a') {
		spot += 0;
	} else if (s1[0] == 'b') {
		spot += 1;
	} else if (s1[0] == 'c') {
		spot += 2;
	} else if (s1[0] == 'd') {
		spot += 3;
	} else if (s1[0] == 'e') {
		spot += 4;
	} else if (s1[0] == 'f') {
		spot += 5;
	} else if (s1[0] == 'g') {
		spot += 6;
	} else if (s1[0] == 'h') {
		spot += 7;
	} else {
		return -1;
	}

	return spot;
}

/* This function prints the menu
*/
void printMenu() {
	std::cout << "1. Move piece\n2. Pick different piece\n";
}

/* This function prints the board in its current state
*/
void printBoard() {
	std::cout << "\n\n  +---------------------------------------+\n"; //outputs the first line of the board

	//Loops through the board
	for (int i = 0; i < 8; i++) {
		std::cout << (i + 1) << " |";
		for (int j = 0; j < 8; j++) {
			std::cout << " " << board[i][j][0] << board[i][j][1] <<" |";
		}

		std::cout << ((i != 7) ? "\n  |----+----+----+----+----+----+----+----|\n" : "\n  +---------------------------------------+\n");
	}

	std::cout << "    A    B    C    D    E    F    G    H\n\n"; //Outputs the bottom of the board
}

/* This function prints a preview board which showcases all of the possible spots a piece can move.
@param Piece: The piece to preview
@return Point*: The pointer to the array of the spots the piece can move 
*/
Point* preview(Piece piece) {
	Piece** pieces[2];
	pieces[0] = players[0].getPieces();
	pieces[1] = players[1].getPieces();	

	Player plyr = players[!piece.isHuman];
	Point* move = piece.determineMoveSet(pieces); //Will need to rework

	Point comp; //Comparison point (used to test whether piece is on spot)
	Point endPt = Point(-1, -1);

	std::cout << "These are the available spots for the " << piece.name << ":";
	std::cout << "  +---------------------------------------+\n"; //outputs the first line of the board

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
					if (board[i][j][0] == NULL) { //Empty spots are NULL
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

/* This function moves a piece

ADD

*/
void movePiece() {

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
