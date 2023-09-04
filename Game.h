#ifndef GAME_H
#define GAME_H

#include "Dealer.h"
#include "Deck.h"
#include "User.h"

class Game {
public:
	Game(User&, Dealer&, Deck&, std::istream&, std::ostream&);
	int getUserBet() const;
	void dealInitialCards();
	void resetGame();
	void playGame();
private:
	User& user;
	Dealer& dealer;
	Deck& deck;
	std::istream& is;
	std::ostream& os;
	bool isNum(const std::string&) const;
};

void playBlackjack(std::istream& = std::cin, std::ostream& = std::cout);

#endif
