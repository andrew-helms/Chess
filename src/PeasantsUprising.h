#ifndef PEASANTS_H
#define PEASANTS_H

#include <iostream>
#include "./Card.h"
#include "./Player.h"
#include "./Piece.h"
#include "./Point.h"
#include "./Enumerations.h"

char board[8][8][2]; //Spaces that are not occupied will be ' '
Player players[2] = { new Player(true), new Player(false) }; //Array for players. First is Humans
Piece** pieces[2] = { players[0].getPieces(), players[1].getPieces() };
bool empowered = false; //Tracks whether the empowered card is being played

void printMenu();
void printBoard();
Point* preview(Piece* piece);
void createBoard();
Piece* findPiece(Point spot);
void movePiece(Piece* piece, Point spot);
bool spotOccupied(int spot);
string toLower(string s1);
int boardSpotToNum(string s1);
void switchCard(Piece* piece1, Piece* piece2);
void empowerCard();
void reviveCard(Piece* res);

#endif