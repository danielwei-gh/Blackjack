#include "Card.h"

Card::Card(Suit s, const std::string& r, int val) : suit(s), rank(r), value(val) {}

Suit Card::getSuit() const {
	return suit;
}

const std::string& Card::getRank() const {
	return rank;
}

int Card::getValue() const {
	return value;
}

void Card::printCard(std::ostream& os) const {
	os << "Suit: " << getSuit() << ", Rank: " << getRank() << ", Value: " 
		<< getValue() << std::endl;
}
