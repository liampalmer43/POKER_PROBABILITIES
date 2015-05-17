#include<iostream>
#include<string>
#include<vector>
#include "Card.h"
#include "probability.h"
using namespace std;

int main(){
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
	return 0;
}	
