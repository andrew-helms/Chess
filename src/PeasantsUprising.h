#ifndef PEASANTS_H
#define PEASANTS_H

#include <iostream>
#include "./Card.h"
#include "./Player.h"
#include "./Piece.h"
#include "./Point.h"

void printMenu();
void printBoard();
Point* preview(Piece piece);
void movePiece();
void createBoard();
void printScoreboard();
string toLower(string s1);
int boardSpotToNum(string s1);

#endif
