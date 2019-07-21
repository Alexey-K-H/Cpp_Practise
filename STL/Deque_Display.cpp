#include <iostream>
#include <deque>

using namespace std;
//Напишите приложение, которое инициализирует дек тремя строками. Их следует
//вывести на экран с помощью шаблонной функции, которая может работать с дека
//ми любого вида. Ваше приложение должно продемонстрировать инициализацию
//списком из стандарта С ++11 и использование оператора " "s из стандарта С++14.

template <typename Type>
void Display_Vector(const deque<Type>& curr_deque)
{
    for(auto elemPos = curr_deque.cbegin(); elemPos != curr_deque.cend(); elemPos++){
        cout << *elemPos << endl;
    }
}

int main() {
    deque <int> some_array_int {45, 67, 89, 450};
    deque <string> some_array_str{"Bayonetta 1"s, "Verse_5" , "Father Balder"s};
    deque <float> some_array_float {5.32, 2.5, 68.5};

    cout << "The first array:" << endl;
    Display_Vector(some_array_int);

    cout << "The second array:" << endl;
    Display_Vector(some_array_str);

    cout << "The third array:" << endl;
    Display_Vector(some_array_float);

    return 0;
}
