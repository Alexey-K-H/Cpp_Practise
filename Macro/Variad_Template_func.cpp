#include <iostream>
using namespace std;

/*Реализовать вариадический шаблон и вывести его элементы*/

//Шаблон для однократного применения
template <typename ValType>
void Print(ValType& val)
{
    cout << val << " ";
}

//Сама вариадическая функция
template <typename First, typename ... Rest>
void Print(First val1, Rest... valN)
{
    cout << val1 << " ";
    return Print(valN ...);
}

int main()
{
    cout << "First example:" << endl;
    Print(3.14, 56, 100, 58.69);
    cout << endl;
    cout << "Second example:" << endl;
    Print("Hello", "World,", "My", "Dear", "Friends...");
    cout << endl;
    cout << "Third example:" << endl;
    Print('a', 'b', 'c', 'f');
    return 0;
}
