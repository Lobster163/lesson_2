#pragma once
#include <string>
using namespace std;

class Person
{
    private:
        string name;
        int year;
        int gender;
        int weight;

    public:
        Person(string name, int year, int gender, int weight) : name(name), year(year), gender(gender), weight(weight) {}
        void changeName(string newName);
        void changeYear(int newYear);
        void changeGender(int newGender);
        void changeWeight(int newWeight);
        string printName();
        int printYear();
        int printGender();
        int printWeight();
};

class Student : public Person
{
    private:
        int yearOfStudy = 0;

    public:
        Student(string name, int year, int gender, int weight) : Person(name, year, gender, weight), yearOfStudy(0) {}
        void changeYoS(int yos);
        int printYoS();
};