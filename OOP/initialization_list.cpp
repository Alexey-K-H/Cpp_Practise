#include <iostream>
#include <string>
using namespace std;
//Использование списков инициализации
class Human
{
private:
    //Эти данные скрыты от использования напрямую в других функциях
    string name;
    int age;

public:
    Human(string human_name = "Adam", int human_age = 25)
          :name(human_name), age(human_age)//Список инициализации
    {
        cout << name << " with the age: " << age << endl;
    }
};

int main() {

    Human firstMan;
    Human firstWoman("Eve", 20);
    return 0;
}
