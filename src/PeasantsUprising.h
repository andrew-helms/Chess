#ifndef PEASANTS_H
#define PEASANTS_H

#include <iostream>
#include "./Card.h"
#include "./Player.h"
#include "./Piece.h"
#include "./Point.h"
#include "./Enumerations.h"

char board[8][8][2]; //Spaces that are not occupied will be ' '
Player players[2];
bool empowered;//Tracks whether the empowered card is being played

void printMenu();
void printBoard();
Point* preview(Piece piece);
void movePiece();
void createBoard();
void printScoreboard();
string toLower(string s1);
int boardSpotToNum(string s1);
void switchCard(Piece piece1, Piece piece2);
void empowerCard();
void reviveCard(Piece res);

#endif
