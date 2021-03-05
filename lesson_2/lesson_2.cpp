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
    bool first = true;
    int bit = -1;
    do {
        end = -1;
        if (!blackjack.getStatus())
        {
            cout << "Взять еще(1) или закончить(0): ";
            cin >> end;
            cout << "-------------------------------------------------\n";
            blackjack.deal(1, 0);
            blackjack.deal(1, 1);
        }
        else
        {
            cout << "-------------------------------------------------\n";
            for (int i = 0; i < blackjack.getCountGamer(); ++i)
            {
                if (blackjack.getSumGamer(i) > 21)
                {
                    cout << "Игрок № " << i + 1 << " проиграл. У него: " << blackjack.getSumGamer(i) << endl;
                    bit = i;
                }
            }
            if(bit == -1)
                cout << "Крупье проиграл. У него: " << blackjack.getSumGamer(4) << endl;
            else
            {
                if (blackjack.getSumGamer(4) > 21)
                {
                    if(blackjack.getSumGamer(4) > blackjack.getSumGamer(bit))
                        cout << "Игрок № " << bit + 1 << " проиграл. У него: " << blackjack.getSumGamer(bit) << endl;
                    else
                        cout << "Крупье проиграл. У него: " << blackjack.getSumGamer(4) << endl;
                }
            }

            return 0;
        }
    } while ( end >=1 || end <0);
    
    blackjack.deal(1, 1);
    //сделать проверку у кого больше не вышли за 21


    cout << endl;
    return 0;
};