#include "User.h"

User::User(int n, Hand* hand, std::istream& input, std::ostream& output) : 
	Player(hand, input, output), balance(n), doubleDown(false) {}

int User::getBalance() const {
	return balance;
}

void User::placeBet(int amount) {
	if (amount > balance)
		throw "Insufficient funds";
	balance -= amount;
}

void User::receiveWinnings(int amount) {
	balance += amount;
}

bool User::makeMove() { // possibly create double down here
	if (hand->getScore() >= 21)
		return false;
	os << "Hit? [y/n]" << std::endl;
	std::string move;
	is >> move;
	os << std::endl;
	return move == "y";
}

void User::printUserHand() const {
	os << "Player's hand:" << std::endl;
	hand->printHand(os);
}
