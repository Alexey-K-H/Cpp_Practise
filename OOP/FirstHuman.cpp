#include <iostream>
#include <string>
using namespace std;
//Использование класса для создания приветствия
class Human
{
public:
    //свойсва
    string name;
    unsigned int age;

    //методы
    void IntroduseSelf(){
        cout << "I'm " + name << " and I'm ";
        cout << age << " year old";
        cout << endl;
    }
};

int main() {

    //Объект Human с именем Адам
    Human firstMan;
    firstMan.name = "Adam";
    firstMan.age = 30;

    //Объект Human с именем Eve
    Human* firstWoman = new Human();
    firstWoman->name = "Eve";
    (*firstWoman).age = 28;

    firstMan.IntroduseSelf();
    firstWoman->IntroduseSelf();

    delete(firstWoman);
    
    return 0;
}
