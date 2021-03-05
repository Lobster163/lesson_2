#pragma once
#include <iostream>

#include <string>
#include <ctime>
#include <stdlib.h>

#define krupie 4

using namespace std;

class Card
{
public:
	int mast;
	int value;
};

class Koloda
{
private:
	int countCard = 52;
	Card card[52];
public:
	Koloda();
	Card popCard(int number);
	int getCoutCard();
};

class Blackjack
{
private:
	int countGamer = 1;
	int sumGamer[5] = { 0, 0, 0, 0 };
	string cardGamer[5][14];
	Koloda koloda;
	bool gt21 = false;
public:
	int getCountCard();
	int getCountGamer();
	int getSumGamer(int numberGamer);
	bool getStatus();
	int getCountCardGamer(int numberGamer);
	void addCardGamer(int numberGamer, string value);
	int setCountGamer(int count);
	void setSumGamer(int numberGamer, int sum);
	void resetGame();
	string getRandomCard();
	string getCardGamer(int numberGamer, int numberCard);
	void printCradGamer(int numberGamer, int type);
	void calcSum(int numberGamer);
	void deal(int countCard, int type);

	~Blackjack();
};

