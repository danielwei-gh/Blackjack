#ifndef DECK_H
#define DECK_H

#include "Suit.h"
#include "Card.h"
#include <vector>

class Deck {
public:
	Deck();
	~Deck();
	void printDeck(std::ostream& = std::cout) const;
	Card* drawCard();
	void shuffleDeck();
private:
	std::vector<Card*> deck;
};

#endif