#ifndef PEASANTS_H
#define PEASANTS_H

#include <iostream>
#include "./Card.h"
#include "./Player.h"
#include "./Piece.h"
#include "./Point.h"
#include "./Enumerations.h"

char board[8][8][2]; //Spaces that are not occupied will be ' '
bool empowered = false; //Tracks whether the empowered card is being played
Player players[2] = { Player(true), Player(false) }; //Array for players. First is Humans
Piece** pieces[2] = { players[0].getPieces(), players[1].getPieces() };

void printBoard();
Point* preview(Piece* piece);
void createBoard();
Piece* findPiece(Point spot, bool isHuman);
void movePiece(Piece* piece, Point spot);
bool spotOccupied(Point spot);
string toLower(string s1);
Point boardSpotToPoint(string s1);
void switchCard(Piece* piece1, Piece* piece2);
int empowerCard(Piece* piece);
void reviveCard(Piece* res);

#endif