#ifndef CARD_H
#define CARD_H

#include "Suit.h"
#include <iostream>
#include <string>

class Card {
	friend class Hand;
public:
	Card(Suit, const std::string&, int);
	Suit getSuit() const;
	const std::string& getRank() const;
	int getValue() const;
	void printCard(std::ostream& = std::cout) const;
private:
	Suit suit;
	std::string rank;
	int value;
};

#endif