#include <iostream>
#include <string>
using namespace std;
//Перегруженные конструкторы
class Human
{
private:
    //Эти данные скрыты от использования напрямую в других функциях
    string name;
    int age;

public:
    Human()//Конструктор по умолчанию
    {
        age = 0;//Инициализация
        cout << "Create object:" << endl;
    }

    //Перегруженный конструктор
    Human(string human_name, int human_age)
    {
        name = human_name;
        age = human_age;
        cout << name << " who is " << age << " year old";
    }
};

int main() {

    Human firstMan;
    Human firstWoman("Eve", 20);
    return 0;
}
