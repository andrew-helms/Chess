#include "./PeasantsUprising.h"

char board[8][8][2]; //Spaces that are not occupied will be NULL
Player players[2] = {new Player(true), new Player(false)};
bool empowered = false; //Tracks whether the empowered card is being played

int main() {
	std::cout << "Welcome to Peasant's Uprising!\n";

	std::cout << "1. Start Game\n2. Exit\n";

	createBoard();
	printBoard();

	return 1;
}

/* This function prints the menu
*/
void printMenu() {
	std::cout << "1. Move piece\n2. Pick different piece\n3. Exit\n";
}

/* This function prints the board in its current state
*/
void printBoard() {
	std::cout << "  +---------------------------------------+\n"; //outputs the first line of the board

	//Loops through the board
	for (int i = 0; i < 8; i++) {
		std::cout << (i + 1) << " |";
		for (int j = 0; j < 8; j++) {
			std::cout << " " << board[i][j][0] << board[i][j][1] <<" |";
		}

		std::cout << ((i != 7) ? "\n  |----+----+----+----+----+----+----+----|\n" : "\n  +---------------------------------------+\n");
	}

	std::cout << "    A    B    C    D    E    F    G    H "; //Outputs the bottom of the board
}

/* This function prints a preview board which showcases all of the possible spots a piece can move.
@param Piece: The piece to preview
@return Point*: The pointer to the array of the spots the piece can move 
*/
Point* preview(Piece piece) {
	Player plyr = (piece.isHuman ? players[0] : players[1]);
	Point* move = piece.determineMoveSet(plyr.playerPieces); //Will need to rework
	Point m1 = move[1];
	Point comp; //Comparison point (used to test whether piece is on spot)

	std::cout << "  +---------------------------------------+\n"; //outputs the first line of the board

	//Loops through the board
	for (int i = 0; i < 8; i++) {
		std::cout << (i + 1) << " |";
		for (int j = 0; j < 8; j++) {
			std::cout << " " << board[i][j][0] << board[i][j][1] << " |";
			comp.x = i;
			comp.y = j;

			for (int k = 0; k < sizeof(move); k++) { //Will need to get length method
				if (move[k].equals(comp)) {
					if (board[i][j][0] == NULL) { //Empty spots are NULL
						std::cout << "xxxx";
					} else {
						std::cout << "x" << board[i][j][0] << board[i][j][1] << "x";
					}
				}
			}

		}

		std::cout << ((i != 7) ? "\n  |----+----+----+----+----+----+----+----|\n" : "\n  +---------------------------------------+\n");
	}

	std::cout << "    A    B    C    D    E    F    G    H "; //Outputs the bottom of the board

	return move;
}

/* This function moves a piece
*/
void movePiece() {

}


/* This function fills the global board with the symbols for the initial piece positions
*/
void createBoard() {
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
