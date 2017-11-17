#ifndef CARD_H
#define CARD_H

#include "Enumerations.h"

class Card {
private:
	
public:
	bool active;
	CardType name;

	Card(CardType kind);
	bool playCard();
};

#endif
