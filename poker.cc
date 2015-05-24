#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<time.h>
#include "Card.h"
#include "probability.h"
using namespace std;

vector<Card*> deck;
int recorder[104];

int getRandom(){                                //getRandom randomly selects a card fromt the deck
	int v1;
		while(true){
			v1 = rand() % 104;
			if(recorder[v1] == 0){          //checks if card is already in use
				recorder[v1] = 1;       
				break;
			}       
		}       
		return v1;
}

int main(){
/*
	vector<Card*> test;
	test.push_back(new Card("Spade", 9));
	test.push_back(new Card("Diamond", 10));
	test.push_back(new Card("Heart", 2));
	test.push_back(new Card("Spade", 10));
	test.push_back(new Card("Club", 13));
	string t = Hand(test);
	cout << t << endl;
	for(int i = 0; i < 5; ++i){
		delete test[i];
	}
	
	vector<Card*> test1;
	test1.push_back(new Card("Spade", 1));
	test1.push_back(new Card("Spade", 11));
	test1.push_back(new Card("Spade", 10));
	test1.push_back(new Card("Spade", 12));
	test1.push_back(new Card("Spade", 13));
	string t1 = Hand(test1);
	cout << t1 << endl;
	for(int i = 0; i < 5; ++i){
		delete test1[i];
	}
	
	vector<Card*> test2;
	test2.push_back(new Card("Spade", 9));
	test2.push_back(new Card("Spade", 10));
	test2.push_back(new Card("Spade", 12));
	test2.push_back(new Card("Spade", 11));
	test2.push_back(new Card("Spade", 13));
	string t2 = Hand(test2);
	cout << t2 << endl;
	for(int i = 0; i < 5; ++i){
		delete test2[i];
	}
		
	vector<Card*> test3;
	test3.push_back(new Card("Spade", 9));
	test3.push_back(new Card("Diamond", 9));
	test3.push_back(new Card("Heart", 9));
	test3.push_back(new Card("Spade", 10));
	test3.push_back(new Card("Club", 9));
	string t3 = Hand(test3);
	cout << t3 << endl;
	for(int i = 0; i < 5; ++i){
		delete test3[i];
	}
	
	vector<Card*> test4;
	test4.push_back(new Card("Spade", 9));
	test4.push_back(new Card("Diamond", 9));
	test4.push_back(new Card("Heart", 2));
	test4.push_back(new Card("Spade", 2));
	test4.push_back(new Card("Club", 9));
	string t4 = Hand(test4);
	cout << t4 << endl;
	for(int i = 0; i < 5; ++i){
		delete test4[i];
	}
	
	vector<Card*> test5;
	test5.push_back(new Card("Diamond", 9));
	test5.push_back(new Card("Diamond", 10));
	test5.push_back(new Card("Diamond", 2));
	test5.push_back(new Card("Diamond", 1));
	test5.push_back(new Card("Diamond", 13));
	string t5 = Hand(test5);
	cout << t5 << endl;
	for(int i = 0; i < 5; ++i){
		delete test5[i];
	}
	
	vector<Card*> test6;
	test6.push_back(new Card("Diamond", 9));
	test6.push_back(new Card("Diamond", 10));
	test6.push_back(new Card("Spade", 11));
	test6.push_back(new Card("Diamond", 8));
	test6.push_back(new Card("Diamond", 7));
	string t6 = Hand(test6);
	cout << t6 << endl;
	for(int i = 0; i < 5; ++i){
		delete test6[i];
	}
	
	vector<Card*> test7;
	test7.push_back(new Card("Heart", 1));
	test7.push_back(new Card("Diamond", 1));
	test7.push_back(new Card("Diamond", 2));
	test7.push_back(new Card("Spade", 1));
	test7.push_back(new Card("Diamond", 13));
	string t7 = Hand(test7);
	cout << t7 << endl;
	for(int i = 0; i < 5; ++i){
		delete test7[i];
	}
	
	vector<Card*> test8;
	test8.push_back(new Card("Diamond", 2));
	test8.push_back(new Card("Diamond", 1));
	test8.push_back(new Card("Spade", 2));
	test8.push_back(new Card("Clube", 1));
	test8.push_back(new Card("Diamond", 13));
	string t8 = Hand(test8);
	cout << t8 << endl;
	for(int i = 0; i < 5; ++i){
		delete test8[i];
	}
	
	vector<Card*> test9;
	test9.push_back(new Card("Diamond", 9));
	test9.push_back(new Card("Heart", 10));
	test9.push_back(new Card("Diamond", 2));
	test9.push_back(new Card("Club", 1));
	test9.push_back(new Card("Spade", 13));
	string t9 = Hand(test9);
	cout << t9 << endl;
	for(int i = 0; i < 5; ++i){
		delete test9[i];
	}

	cout << FiveOnes(63) << endl;
	cout << FiveOnes(31) << endl;
	cout << FiveOnes(62) << endl;
	cout << FiveOnes(10) << endl;
	
	vector<Card*> t1k;
	t1k.push_back(new Card("Diamond", 8));
	t1k.push_back(new Card("Spade", 8));
	t1k.push_back(new Card("Heart", 3));
	t1k.push_back(new Card("Heart", 4));
	vector<Card*> t11;
	t11.push_back(new Card("Heart", 2));
	t11.push_back(new Card("Heart", 10));
	t11.push_back(new Card("Spade", 4));
	t11.push_back(new Card("Heart", 8));
	t11.push_back(new Card("Club", 1));
	Probability(t1k, t11);
*/
	srand (time(NULL));
	for(int j = 0; j < 104; j++){
		recorder[j] = 0;
	}
	string suits[4] = {"HEART","DIAMOND","CLUB","SPAID"};
	int Number = 1;
	int Suit = 0;
	for(int i = 0; i < 104; i++){
		deck.push_back(new Card(suits[Suit], Number));
		Number++;
		Suit++;
		if(Number == 14){ Number = 1; }
		if(Suit == 4){ Suit = 0; }
	}
	cout << "Let's play some poker!" << endl;
	string s;
	int f1, f2, s1, s2;
	while(cin >> s){
		if(s == "deal"){
			f1 = getRandom();
			f2 = getRandom();
			s1 = getRandom();
			s2 = getRandom();
			cout << "Player1 (you): " << *deck[f1] << *deck[f2] << endl;
			cout << "Player2 (computer): " << *deck[s1] << *deck[s2] << endl;
		}
	}
	for(int j = 0; j < deck.size(); ++j){
		delete deck[j];
	}
	return 0;
}
