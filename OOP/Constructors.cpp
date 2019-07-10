#include <iostream>
#include <string>
using namespace std;
//Использование конструктора, а так же public и private
class Human
{
private:
    //Эти данные скрыты от использования напрямую в других функциях
    string name;
    int age;

public:
    Human()//Конструктор
    {
        age = 0;//Инициализация
        cout << "Конструирование объекта:" << endl;
    }
    //Присвоить имя
    void SetName(string humanName)
    {
        name = humanName;
    }
    //Присвоить возраст
    void SetAge(int age_of_human)
    {
        age = age_of_human;
    }
    //Представиться
    void IntroduceSelf()
    {
        cout << "I'm " + name << " and I'm ";
        cout << age << " year old" << endl;
    }
};

int main() {

    Human* firstWoman = new Human;
    firstWoman->SetName("Eve");
    firstWoman->SetAge(28);

    firstWoman->IntroduceSelf();

    return 0;
}
