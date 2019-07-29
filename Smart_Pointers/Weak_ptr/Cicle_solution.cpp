#include <iostream>
#include <memory>//Используется для укзателей
#include <string>
using namespace std;
/*Использование weak_ptr при циклической зависимости*/

class Spirit
{
private:
    string name;
    weak_ptr<Spirit> partner;

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
    //Теперь необходимо конвертировать weak_ptr в shared_ptr с помощью lock()
    shared_ptr<Spirit> getPartner() const { return partner.lock();}
    string getName() const { return name;}
};

int main()
{
    auto angel = make_shared<Spirit>("Angel");
    auto demon = make_shared<Spirit>("Demon");
    partnerUp(angel, demon);
    //После завершения рпограммы ни один объект не уничтожится
    //Возникает циклическая зависимость, каждый объект указывает
    //на следующий, а последний на первый и не дает уничтожить объекты

    auto partner = demon->getPartner();//Передаем этому указателю содержимое указаетля, котрым владеет Demon(т.е. Angel)
    cout << demon->getName() << "'s partner with: " << partner->getName() << endl;
    return 0;
}
