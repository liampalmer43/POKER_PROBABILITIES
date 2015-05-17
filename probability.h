#ifndef probability_h_
#define probability_h_

#include <vector>
#include "Card.h"

std::vector<Card*> sort(const std::vector<Card*>& hand);
std::string CheckFlush(const std::vector<Card*>& hand);
int CheckStraight(const std::vector<Card*>& hand);
int FourKind(const std::vector<Card*>& hand);
std::string FullHouse(const std::vector<Card*>& hand);
int ThreeKind(const std::vector<Card*>& hand);
std::string TwoPair(const std::vector<Card*>& hand);
int Pair(const std::vector<Card*>& hand);
std::string HiCard(const std::vector<Card*> hand);
std::string Hand(const std::vector<Card*>& hand);
int* Probability(const std::vector<Card*>& hands, const std::vector<Card*>& flipped);

#endif
