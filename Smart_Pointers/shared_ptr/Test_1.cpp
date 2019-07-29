#include <iostream>
#include <memory>//Используется для укзателей
using namespace std;
/*Интеллектуальные указатели shared_ptr*/

int main()
{
    shared_ptr<int> ptr1(new int(66));
    shared_ptr<int> empty_ptr;
    empty_ptr = ptr1;
    cout << empty_ptr.use_count() << endl;//Выведет 2, счетчик укзаателей на данный объект
    return 0;
}
