#pragma once
#include <string>
using namespace std;

class Fruit
{
	protected:
		string name;
		string color;
	public:	
		Fruit() {};
		Fruit(string name, string color) : name(name), color(color) {}
		string getColor();
		string getName();

};

class Banana : public Fruit
{
	public:
		Banana() : Fruit("banana", "yellow") {}
};
class Apple : public Fruit
{
	public:
		Apple() {};
		Apple(string color) : Fruit("apple", color) {}
};
class GrannySmith : public Apple
{
	public:
		GrannySmith()
		{
			this->color = "green";
			this->name = "Granny Smith apple";
		}
};
