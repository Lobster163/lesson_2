#include "include/lesson_2.h"

using namespace std;

void genStudent(vector<Student>& class_1, int sizeGroup)
{
    for (int i = 0; i < sizeGroup; ++i)  
        class_1.push_back(Student("name" + std::to_string(i), 18 + i, rand() % 1, 60 + i));
};

Student getStudent(vector<Student>& class_1, int number)
{
    return class_1[number];
};

Student getStudent(vector<Student>& class_1, string name)
{
    for (int i = 0; i < (int)class_1.size(); ++i)
    {
        if (class_1[i].printName() == name)
            return class_1[i];
    }
    return Student("error",-1,-1,-1);
};

int main()
{
    setlocale(LC_CTYPE, "rus");

    vector<Student>class_1;
    genStudent(class_1, 30);    //генерация студентов
    Student student = getStudent(class_1, 10);  //получаем по номеру
    std::cout << "student_1: " << student.printName() << endl;
    student = getStudent(class_1, "name29"); //ищем студента по имени
    std::cout << "student_2 = " << student.printName() << endl;
    std::cout << "count student = " << class_1.size() << endl;  //кол-во студентов

    std::cout << endl;
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    cout << endl;

    Blackjack blackjack;
    srand(time(0));
    blackjack.resetGame();
    blackjack.setCountGamer(1);

    //первая раздача
    blackjack.deal(2, 0);
    blackjack.deal(1, 1);    

    int end = -1;
    do {
        if (!blackjack.getStatus())
        {
            cout << "Взять еще(1) или закончить(0): ";
            cin >> end;
        }
        else
        {

        }
    } while (!blackjack.getStatus());

    blackjack.addCardGamer(krupie, blackjack.getRandomCard());
    cout << "Крупье выпало: " << blackjack.getCardGamer(4, 1) << endl;

   /* for (int gamer = 0; gamer < blackjack.getCountGamer(); ++gamer)
    {
        for (int c = 0; c < blackjack.getCountCardGamer(gamer); ++c)
            std::cout << "card gamer = " << blackjack.getCardGamer(gamer,c) << endl;
    }
    */

    /*for(int i=0;i<blackjack.getCountCard();++i)
        std::cout << "new " << i <<" Card = " << blackjack.getRandomCard() << endl;
    */
    cout << endl;
    return 0;
};