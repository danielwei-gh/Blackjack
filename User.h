#ifndef USER_H
#define USER_H

#include "Player.h"

class User : public Player {
public:
	User(int, Hand*, std::istream&, std::ostream&);
	int getBalance() const;
	void placeBet(int);
	void receiveWinnings(int);
	bool makeMove() override;
	void printUserHand() const;
private:
	int balance;
	bool doubleDown;
};

#endif