#include "Player.h"

Player::Player(Hand* h, std::istream& input, std::ostream& output) : 
	hand(h), is(input), os(output) {}

Player::~Player() {
	delete hand;
}

Hand* Player::getHand() const {
	return hand;
}

void Player::resetHand() {
	delete hand;
	hand = new Hand();
}

void Player::hit(Card* card) {
	hand->addCard(card);
}
