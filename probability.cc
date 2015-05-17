#include<iostream>
#include<vector>
#include<sstream>
#include "Card.h"
#include "probability.h"
using namespace std;

vector<Card*> sort(const vector<Card*>& hand){
	vector<Card*> re;
	int place0 = 0;
	int place1 = 0;
	int place2 = 0;
	int place3 = 0;
	int place4 = 0;
	int start = hand[0]->number;
	for(int j = 1; j < 5; ++j){
		if(hand[j]->number < start){
			start = hand[j]->number;
			place0 = j;
		}
	}
	re.push_back(hand[place0]);
	start = 14;
	for(int k = 0; k < 5; ++k){
		if(hand[k]->number < start && k != place0){
			start = hand[k]->number;
			place1 = k;
		}
	}
	re.push_back(hand[place1]);
	start = 14;
	for(int l = 0; l < 5; ++l){
		if(hand[l]->number < start && l != place0 && l != place1){
			start = hand[l]->number;
			place2 = l;
		}
	}
	re.push_back(hand[place2]);
	start = 14;
	for(int m = 0; m < 5; ++m){
		if(hand[m]->number < start && m != place0 && m != place1 && m != place2){
			start = hand[m]->number;			
			place3 = m;
		}
	}
	re.push_back(hand[place3]);
	place4 = 10 - place0 - place1 - place2 - place3;
	re.push_back(hand[place4]);
	return re;
}

string CheckFlush(const vector<Card*>& hand){
	string result = hand[0]->suit;
	for(int i = 1; i < 5; ++i){
		if(hand[i]->suit != result){
			return "nothing";
		}
	}
	return result;
} 

int CheckStraight(const vector<Card*>& hand){
	int result = hand[0]->number;
	if(result == 1 && hand[1]->number == 10 && hand[2]->number == 11 && hand[3]->number == 12 && hand[4]->number == 13){
		return 10;
	}
	for(int i = 1; i < 5; ++i){
		if(hand[i]->number != result+1){
			return 0;
		}
		result++;
	}
	return result - 4;
}

int FourKind(const vector<Card*>& hand){
	int result1 = hand[0]->number;
	if(hand[1]->number == result1 && hand[2]->number == result1 && hand[3]->number == result1){
		return result1;
	}
	int result2 = hand[4]->number;	
	if(hand[1]->number == result2 && hand[2]->number == result2 && hand[3]->number == result2){
		return result2;
	}
	return 0;
}

string FullHouse(const vector<Card*>& hand){
	int first = hand[0]->number;
	int second = hand[4]->number;
	if(hand[1]->number == first && hand[3]->number == second){
		if(hand[2]->number == first){
			return to_string(first) + " " + to_string(second);
		}
		if(hand[2]->number == second){
			return to_string(second) + " " + to_string(first);
		}
	}
	return "nothing";
}

int ThreeKind(const vector<Card*>& hand){
	int result1 = hand[0]->number;
	if(hand[1]->number == result1 && hand[2]->number == result1){
		return result1;
	}
	int result2 = hand[1]->number;
	if(hand[2]->number == result2 && hand[3]->number == result2){
		return result2;
	}
	int result3 = hand[4]->number;
	if(hand[2]->number == result3 && hand[3]->number == result3){
		return result3;
	}
	return 0;
}

string TwoPair(const vector<Card*>& hand){
	int h0 = hand[0]->number;
	int h1 = hand[1]->number;
	int h2 = hand[2]->number;
	int h3 = hand[3]->number;
	int h4 = hand[4]->number;
	if(h0 == h1){
		if(h3 == h4){
			if(h3 > h0){
				return to_string(h3) + to_string(h0);
			}
			else{
				return to_string(h0) + to_string(h3);
			}
		}
		if(h2 == h3){
			if(h2 > h0){
				return to_string(h2) + to_string(h0);
			}
			else{
				return to_string(h0) + to_string(h2);
			}
		}
	}
	if(h1 == h2 && h3 == h4){
		if(h1 > h3){
			return to_string(h1) + to_string(h3);
		}
		else{
			return to_string(h3) + to_string(h1);
		}
	}
	return "nothing";
}

int Pair(const vector<Card*>& hand){
	if(hand[0]->number == hand[1]->number){
		return hand[0]->number;
	}
	if(hand[1]->number == hand[2]->number){
		return hand[1]->number;
	}
	if(hand[2]->number == hand[3]->number){
		return hand[2]->number;
	}
	if(hand[3]->number == hand[4]->number){
		return hand[3]->number;
	}
	return 0;
}

string HiCard(const vector<Card*> hand){
	int max = 0;
	string suit;
	for(int i = 0; i < 5; i++){
		if(hand[i]->number > max){
			max = hand[i]->number;
			suit = hand[i]->suit;
		}
	}
	return to_string(max) + " " + suit;
}
 
string Hand(const vector<Card*>& hand){
	if(hand.size() != 5){
		cerr << "Not a full hand of five cards!" << endl;
		return "error";
	}
	string a[9] = {"RoyalFlush", "StraightFlush", "4Kind", "FullHouse", "Flush", "Straight", "3Kind", "2Pair", "Pair"}; 
	vector<Card*> sorter = sort(hand);
	cout << *sorter[0] << *(sorter[1]) << *(sorter[2]) << *(sorter[3]) << *(sorter[4]) << endl; 
	string flush = CheckFlush(sorter);
	int straight = CheckStraight(sorter);
	if(flush != "nothing" && straight == 10){
		return a[0] + " " + flush + " " + to_string(straight);
	}
	if(flush != "nothing" && straight != 0){
		return a[1] + " " + flush + " " + to_string(straight);
	}
	int fourkind = FourKind(sorter);
	if(fourkind != 0){
		return a[2] + " " + to_string(fourkind);
	}
	string fullhouse = FullHouse(sorter);
	if(fullhouse != "nothing"){
		return a[3] + " " + fullhouse;
	}
	if(flush != "nothing"){
		return a[4] + " " + flush;
	}
	if(straight != 0){
		return a[5] + " " + to_string(straight);
	}
	int threekind = ThreeKind(sorter);
	if(threekind != 0){
		return a[6] + " " + to_string(threekind);
	}
	string twopair = TwoPair(sorter);
	if(twopair != "nothing"){
		return a[7] + " " + twopair;
	}
	int pair = Pair(sorter);
	if(pair	!= 0){
		return a[8] + " " + to_string(pair);
	}
	return "Hi " + HiCard(sorter);	
}

bool FiveOnes(int i){
	int numones = 0;
	while(i != 0){
		if(i % 2 == 1){
			numones++;
			i--;
		}
		i = i / 2;
	}
	return numones == 5;
}

void Subsets(const vector<Card*>& sevens, vector< vector<Card*> >& subsets){
	for(int i = 1; i < 256; i++){
		int placer = 0;
		if(FiveOnes(i)){
			vector<Card*> ex;
			while(i != 0){
				if(i % 2 == 1){
					ex.push_back(sevens[placer]);
					i--;
				}
				placer++;
				i = i / 2;
			}
			subsets.push_back(ex);
		}
	}
}

int Probability(const vector<Card*>& hands, const vector<Card*>& flipped){
	vector<int> players;
	int winner;
	int min = 15;	

	string a[9] = {"RoyalFlush", "StraightFlush", "4Kind", "FullHouse", "Flush", "Straight", "3Kind", "2Pair", "Pair"};
	int b[10];
	for(int i = 0; i < 10; ++i){
		b[i] = 0;
	}
	
	if(flipped.size() == 5){
		for(int i = 0; i < hands.size(); ++i){
			vector<Card*> sevens = flipped;
			sevens.push_back(hands[i]);
			sevens.push_back(hands[i+1]);
			vector< vector<Card*> > subsets;
			Subsets(sevens, subsets);
			for(int j = 0; j < subsets.size(); ++j){
				string result = Hand(subsets[j]);
				istringstream ss(result);
				string temp;
				ss >> temp;
				for(int k = 0; k < 9; ++k){
					if(temp == a[k]){
						b[k]++;
						break;
					}
					if(temp == "Hi"){
						int n;
						ss >> n;
						if(n > b[9]){
							b[9] = n;
						}
					}
				}
				for(int k1 = 0; k1 < 10; ++k1){
					if(b[k1] != 0){
						players.push_back(k1);
						break;
					}
				}
				for(int k2 = 0; k2 < 10; ++k2){
					b[k2] = 0;
				}
			}
			i++;
		}
		for(int i = 0; i < players.size(); ++i){
			if(b[i] < min){
				min = b[i];
				winner = i;
			}
		}	
	}
	return winner;
}





