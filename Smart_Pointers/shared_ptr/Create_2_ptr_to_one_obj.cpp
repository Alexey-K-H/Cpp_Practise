#include <iostream>
#include <memory>//Используется для укзателей
using namespace std;
/*Создание объекта с помощью укзаателя и исопльзоввние
 двух укзаателей, указывающих на один объект*/

class Fish
{
public:
    Fish() { cout << "Create fish\n";}
    ~Fish(){ cout << "Fish destroyed\n";}
};

int main()
{
    Fish *curr_fish = new Fish;
    shared_ptr<Fish> ptr1(curr_fish);
    {
        shared_ptr<Fish> ptr2(ptr1);
        cout << "Killing one shared pointer\n";
    }
    cout << "Killing another shared pointer\n";
    return 0;
}
