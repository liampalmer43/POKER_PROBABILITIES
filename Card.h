#ifndef Card_h_
#define Card_h_

#include <iostream>
#include <string>

class Card{
	public:
	Card(std::string suit, int number);
	std::string suit;
	int number;
	bool CompNum(Card* c);
	bool CompSuit(Card* c);
};

std::ostream& operator<< (std::ostream &out, Card &cCard);

#endif
