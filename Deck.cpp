#include "Deck.h"

Deck::Deck() {
	for (Suit suit = Suit::CLUBS; suit <= Suit::SPADES; suit = (Suit)(suit + 1)) {
		deck.push_back(new Card(suit, "A", 11));
		for (int rank = 2; rank <= 10; ++rank)
			deck.push_back(new Card(suit, std::to_string(rank), rank));
		deck.push_back(new Card(suit, "J", 10));
		deck.push_back(new Card(suit, "Q", 10));
		deck.push_back(new Card(suit, "K", 10));
	}
}

Deck::~Deck() {
	for (Card* card : deck)
		delete card;
}

void Deck::printDeck(std::ostream& os) const {
	for (Card* card : deck)
		card->printCard(os);
}

Card* Deck::drawCard() {
	Card* card = deck.back();
	deck.pop_back();
	return card;
}

void Deck::shuffleDeck() {
	if (deck.size() < 17) {
		for (Card* card : deck)
			delete card;
		deck.clear();
		for (Suit suit = Suit::CLUBS; suit <= Suit::SPADES; suit = (Suit)(suit + 1)) {
			deck.push_back(new Card(suit, "A", 11));
			for (int rank = 2; rank <= 10; ++rank)
				deck.push_back(new Card(suit, std::to_string(rank), rank));
			deck.push_back(new Card(suit, "J", 10));
			deck.push_back(new Card(suit, "Q", 10));
			deck.push_back(new Card(suit, "K", 10));
		}
	}
	for (int i = 0; i < deck.size(); ++i) {
		int j = rand() % deck.size();
		Card* tmp = deck[i];
		deck[i] = deck[j];
		deck[j] = tmp;
	}
}
