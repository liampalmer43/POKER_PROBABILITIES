#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

Card::Card(string suit, int number): suit(suit), number(number){}

bool Card::CompNum(Card* c){
	return number == c->number;
}

bool Card::CompSuit(Card* c){
	return suit == c->suit;
}

ostream& operator<< (ostream &out, Card &cCard){
	out << cCard.number << " " << cCard.suit << " ";
	return out;
}
