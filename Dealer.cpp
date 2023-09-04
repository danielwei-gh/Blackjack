#include "Dealer.h"

Dealer::Dealer(Hand* hand, std::istream& input, std::ostream& output) : 
	Player(hand, input, output) {}

bool Dealer::makeMove() {
	return false;
}

void Dealer::printDealerHand() const {
	os << "Dealer's hand: " << std::endl;
	hand->printHand(os);
}