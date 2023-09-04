#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Hand {
public:
	Hand();
	~Hand(); // possibly useless: delete if so
	void addCard(Card*);
	int getScore() const;
	const std::vector<Card*>& getCards() const;
	void printHand(std::ostream& = std::cout) const;
private:
	std::vector<Card*> hand;
	int score;
};

#endif