#include "./Card.h"

Card::Card(CardType kind) {
	name = kind;
	active = false;
}

bool Card::playCard() {
	if (active)
	{
		active = false;
		return true;
	}
	return false;
}

