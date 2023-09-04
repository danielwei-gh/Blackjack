#include "Hand.h"

Hand::Hand() : hand(std::vector<Card*>()), score(0) {}

Hand::~Hand() {
	for (Card* card : hand)
		delete card;
}

void Hand::addCard(Card* newCard) {
	hand.push_back(newCard);
	score += newCard->getValue();
	if (score > 21) {
		for (Card* card : hand) {
			if (card->getValue() == 11) {
				card->value = 1;
				score -= 10;
				if (score <= 21)
					return;
			}
		}
	}
}

int Hand::getScore() const {
	return score;
}

const std::vector<Card*>& Hand::getCards() const { // might need to remove const
	return hand;
}

void Hand::printHand(std::ostream& os) const {
	for (Card* card : hand)
		card->printCard(os);
}
