#include <iostream>
#include <memory>//Используется для укзателей
#include <string>
using namespace std;
/*Циклическиая зависимость*/

class Spirit
{
private:
    string name;
    shared_ptr<Spirit> partner;

public:
    Spirit(const string &curr_name): name(curr_name)
    {
        cout << name << " created\n";
    }
    ~Spirit()
    {
        cout << name << " destroyed\n";
    }

    friend bool partnerUp(shared_ptr<Spirit> &s1, shared_ptr<Spirit> &s2)
    {
        if(!s1 || !s2)
            return false;
        s1->partner = s2;
        s2->partner = s1;

        cout << s1->name << " is now partnered with " << s2->name << endl;
        return true;
    }
};

int main()
{
    auto angel = make_shared<Spirit>("Angel");
    auto demon = make_shared<Spirit>("Demon");
    partnerUp(angel, demon);
    //После завершения рпограммы ни один объект не уничтожится
    //Возникает циклическая зависимость, каждый объект указывает
    //на следующий, а последний на первый и не дает уничтожить объекты
    return 0;
}
