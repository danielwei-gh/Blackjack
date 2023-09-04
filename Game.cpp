#include "Game.h"
#include <stdexcept>

Game::Game(User& r1, Dealer& r2, Deck& r3, std::istream& input, std::ostream& output) :
	user(r1), dealer(r2), deck(r3), is(input), os(output) {}

int Game::getUserBet() const {
	os << "Player's balance: $" << user.getBalance() << std::endl;
	os << "Enter your bet: $";
	std::string s;
	int bet;
	while (1) {
		try {
			is >> s;
			if (!isNum(s))
				throw std::invalid_argument("Invalid bet\n");
			bet = std::stoi(s);
			if (bet <= 0 || bet > user.getBalance())
				throw std::out_of_range("Invalid bet\n");
			break;
		}
		catch (std::invalid_argument err1) {
			os << err1.what() << std::endl;
			os << "Enter your bet: $";
		}
		catch (std::out_of_range err2) {
			os << err2.what() << std::endl;
			os << "Enter your bet: $";
		}
	}
	return bet;
}

void Game::dealInitialCards() {
	for (int i = 0; i < 2; ++i) {
		user.hit(deck.drawCard());
		dealer.hit(deck.drawCard());
	}
	Card* dealerCard = dealer.getHand()->getCards()[0];
	os << "Dealer's first card:" << std::endl;
	dealerCard->printCard(os);
	os << std::endl;
	user.printUserHand();
	os << user.getHand()->getScore() << ". Your turn..." << std::endl;
	os << std::endl;
}

void Game::resetGame() {
	user.resetHand();
	dealer.resetHand();
}

void Game::playGame() {
	deck.shuffleDeck();
	int bet = getUserBet();
	user.placeBet(bet);
	os << "------------------------------------------------------------" << std::endl;
	dealInitialCards();
	Hand* userHand = user.getHand();
	Hand* dealerHand = dealer.getHand();
	if (dealerHand->getScore() == 21 && userHand->getScore() == 21) {
		dealer.printDealerHand();
		os << "Push at blackjack" << std::endl;
		user.receiveWinnings(bet);
		return;
	}
	else if (dealerHand->getScore() == 21) {
		dealer.printDealerHand();
		os << "The dealer has blackjack" << std::endl;
		return;
	}
	else if (userHand->getScore() == 21) {
		os << "Blackjack" << std::endl;
		user.receiveWinnings(bet * 2);
		return;
	}
	while (user.makeMove()) {
		user.hit(deck.drawCard());
		user.printUserHand();
		if (userHand->getScore() > 21) {
			os << "Bust at " << userHand->getScore() << std::endl;
			os << "------------------------------------------------------------" << std::endl;
			resetGame();
			return;
		}
		else if (userHand->getScore() == 21)
			break;
		os << userHand->getScore() << ". Your turn..." << std::endl;
		os << std::endl;
	}
	os << "You stood at " << userHand->getScore() << std::endl;
	os << std::endl;
	dealer.printDealerHand();
	while (dealerHand->getScore() < 17) {
		os << "Dealer has " << dealerHand->getScore() << std::endl;
		os << std::endl;
		dealer.hit(deck.drawCard());
		dealer.printDealerHand();
	}
	if (dealerHand->getScore() > 21) {
		os << "Dealer busts with " << dealerHand->getScore() << std::endl;
		user.receiveWinnings(bet * 2);
		os << std::endl;
		os << "You won $" << bet << std::endl;
	}
	else if (dealerHand->getScore() > userHand->getScore()) {
		os << "Dealer stands on " << dealerHand->getScore() << std::endl;
		os << std::endl;
		os << "You lost $" << bet << std::endl;
	}
	else if (dealerHand->getScore() < userHand->getScore()) {
		os << "Dealer stands on " << dealerHand->getScore() << std::endl;
		user.receiveWinnings(bet * 2);
		os << std::endl;
		os << "You won $" << bet << std::endl;
	}
	else {
		os << "Pushed" << std::endl;
		user.receiveWinnings(bet);
	}
	os << "------------------------------------------------------------" << std::endl;
	resetGame();
}

bool Game::isNum(const std::string& s) const {
	if (s.empty())
		return false;
	for (const char& c : s) {
		if (!isdigit(c))
			return false;
	}
	if (s.length() > 1 && s[0] == '0')
		return false;
	return true;
}

void playBlackjack(std::istream& is, std::ostream& os) {
	User user(100, new Hand(), is, os);
	Dealer dealer(new Hand(), is, os);
	Deck deck;
	Game game(user, dealer, deck, is, os);
	while (user.getBalance() > 0)
		game.playGame();
	os << "Game Over =(" << std::endl;
}
