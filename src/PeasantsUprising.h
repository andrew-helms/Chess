#ifndef PEASANTS_H
#define PEASANTS_H

#include <iostream>
#include "./Card.h"
#include "./Player.cpp"
#include "./Piece.cpp"
#include "./Point.cpp"

void printMenu();
void printBoard();
Point* preview(Piece piece);
void movePiece();
void createBoard();

#endif
