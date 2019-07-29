#include <iostream>
#include <memory>//Используется для укзателей
using namespace std;
/*Создание объекта с помощью укзаателя*/

void foo(shared_ptr<int>& index)
{
    (*index)++;
}

int main()
{
    auto smart_pointer = make_shared<int>(10);
    foo(smart_pointer);
    cout << *smart_pointer << endl;
    return 0;
}
