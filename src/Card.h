#ifndef CARD_H
#define CARD_H

#include "Enumerations.h"

class Card {
private:
	CardType name;
	
public:
	bool active;

	Card(CardType kind);
	bool playCard();
};

#endif
