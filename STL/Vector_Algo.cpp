#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //Динамический массив целых чисел
    vector<int> intArray;

    intArray.push_back(50);
    intArray.push_back(2991);
    intArray.push_back(23);
    intArray.push_back(9999);

    cout << "Vector values:" << endl;

    //Обход вектора с помощбю итератора
    auto arrIterator = intArray.begin();

    while (arrIterator != intArray.end()){
        //Вывод значения на экран
        cout << *arrIterator << endl;

        arrIterator++;
    }

    //Поиск элемента
    auto elFound = find(intArray.begin(), intArray.end(), 2991);

    //Проверить, найдено ли значение
    if(elFound != intArray.end())
    {
        //Если найдено, определяем позицию
        int elPos = distance(intArray.begin(), elFound);
        cout << "Value " << *elFound;
        cout << " located in position " << elPos << endl;
    }

    return 0;
}
