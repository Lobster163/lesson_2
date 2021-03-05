#include "./include/punkt_1.h"
using namespace std;

void Person::changeName(string newName) 
{ 
	name = newName; 
};

void  Person::changeYear(int newYear) 
{ 
	year = newYear; 
};

void  Person::changeGender(int newGender) 
{ 
	gender = newGender; 
};

void  Person::changeWeight(int newWeight) 
{ 
	weight = newWeight; 
};

string  Person::printName() 
{ 
	return name; 
}
int  Person::printYear() 
{ 
	return year; 
}

int  Person::printGender() 
{ 
	return gender; 
}

int  Person::printWeight() 
{ 
	return weight; 
}

void Student::changeYoS(int yos) 
{
	yearOfStudy = yos;
}

int Student::printYoS() 
{ 
	return yearOfStudy; 
}