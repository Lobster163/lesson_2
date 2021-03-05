#include "include/punkt_3.h"

Blackjack::~Blackjack()
{
}
int Blackjack::getCountCard() { return koloda.getCoutCard(); }
int Blackjack::getCountGamer() { return countGamer; }
bool Blackjack::getStatus() { return gt21; }
int Blackjack::getSumGamer(int numberGamer){ return sumGamer[numberGamer]; }
void Blackjack::resetGame()
{
	for (int i = 0; i < 4; ++i)
		sumGamer[i] = 0;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 14; ++j)
		{
			if(j==0)
				cardGamer[i][j] = "0";
			else
				cardGamer[i][j] = "";
		}
}
int Blackjack::setCountGamer(int count)
{
	if (count > 1 && count <= 4)
	{
		countGamer = count;
		for (int i = 0; i < 4; ++i)
			sumGamer[i] = 0;
		return 1;
	}
	else
		return -1;
};

string Blackjack::getRandomCard()
{	
	Card card;
	do {
		card = koloda.popCard(rand() % getCountCard());
	} while (card.value == -1);

	switch (card.value)
	{
	case 0:
		return "T";
	case 10:
		return "J";
	case 11:
		return "Q";
	case 12:
		return "K";
	default:
		return std::to_string(card.value+1);
		break;
	}
	
}
void Blackjack::addCardGamer(int numberGamer, string value)
{
	int cnt = getCountCardGamer(numberGamer);
	cnt++;
	cardGamer[numberGamer][0] = std::to_string(cnt);
	cardGamer[numberGamer][cnt] = value;
	
}
string Blackjack::getCardGamer(int numberGamer,int numberCard)
{
	return cardGamer[numberGamer][numberCard];
}
int Blackjack::getCountCardGamer(int numberGamer)
{
	return std::stoi(cardGamer[numberGamer][0]);
}
void Blackjack::printCradGamer(int numberGamer, int type)
{
	if(type == 0)
		cout << "Игроку № " << numberGamer + 1 << " выпали карты: ";
	else
		cout << "Крупье выпали карты: ";

	for (int i = 0; i < getCountCardGamer(numberGamer); ++i)
		cout << getCardGamer(numberGamer, i + 1) << " ";

	int sum = getSumGamer(numberGamer);
	cout << "Сумма карт= " << sum <<endl;
}
void Blackjack::setSumGamer(int numberGamer, int sum)
{
	sumGamer[numberGamer] = sum;
	if (sum > 21)
		gt21 = true;
}
void Blackjack::calcSum(int numberGamer)
{
	int sum = 0;
	for (int i = 0; i < getCountCardGamer(numberGamer); ++i)
	{
		string card = getCardGamer(numberGamer, i+1);
		if (card != "T")
		{
			if (card == "J" || card == "Q" || card == "K")
				sum = sum + 10;
			else
				sum = sum + std::stoi(card);
		}
	}

	for (int i = 0; i < getCountCardGamer(numberGamer); ++i)
	{
		string card = getCardGamer(numberGamer, i+1);
		if (card == "T")
		{
			if (sum > 10)
				sum = sum + 1;
			else
				sum = sum + 11;
		}
	}
	setSumGamer(numberGamer, sum);
}
void Blackjack::deal(int countCard, int type)
{
	if (type == 0)
	{
		for (int gamer = 0; gamer < getCountGamer(); ++gamer)
		{
			for (int i = 0; i < countCard; ++i)
				addCardGamer(gamer, getRandomCard());
			calcSum(gamer);
			printCradGamer(gamer, type);
		}
	}
	else
	{
		addCardGamer(krupie, getRandomCard());
		calcSum(krupie);
		printCradGamer(krupie, type);
	}

}

Koloda::Koloda()
{
	int m = 0;
	for (int i = 0; i < getCoutCard(); ++i)
	{
		card[i].mast = m;
		card[i].value = i / 4;
		if (m == 3)
			m = 0;
		else
			m++;
	}		
}
Card Koloda::popCard(int number)
{	
	Card tmp = card[number];
	card[number].mast = -1;
	card[number].value = -1;
	if (countCard > 1)
		countCard = countCard - 1;
	return tmp;
}
int Koloda::getCoutCard()
{
	return countCard;
}