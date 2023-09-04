#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

class Dealer : public Player {
public:
	Dealer(Hand*, std::istream&, std::ostream&);
	bool makeMove() override;
	void printDealerHand() const;
};

#endif