#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Hand.h"

class Player {
public:
	Player(Hand*, std::istream&, std::ostream&);
	~Player();
	Hand* getHand() const; // possible delete const qualifier
	void resetHand();
	void hit(Card*);
	virtual bool makeMove() = 0;
protected:
	Hand* hand;
	std::istream& is;
	std::ostream& os;
};

#endif