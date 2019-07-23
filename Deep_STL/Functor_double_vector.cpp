#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*Написать унарную функцию, возращающую удвоенный параметр*/

template <typename Type>
void Fill_vector(vector<Type>& user_vector)
{
    char finish_fill = 'n';
    while(finish_fill != 'y')
    {
        cout << "Enter the element of vector:";
        Type curr_elem;
        cin >> curr_elem;
        user_vector.push_back(curr_elem);
        cout << "Finish fill? Print y/n(yes/no):";
        cin >> finish_fill;
    }
}

//Структура ведущая себя как унарная функция
template <typename Type>
struct Display_vector
{
    void operator ()(const Type& element) const
    {
        cout << element << ' ';
    }
};

template <typename Type>
struct Display_double_value
{
    int counter;
    Display_double_value() : counter(0) {};
    void operator ()(const Type& element)
    {
        cout << 2*element << ' ';
        counter++;
    }
};

template <typename Type>
void Display_user_vector(const vector<Type>& user_vector)
{
    cout << "User vector contain: ";
    for_each(user_vector.begin(), user_vector.end(), Display_vector<Type>());
    cout << endl;
}

template <typename Type>
void Display_double_vector(const vector<Type>& user_vector)
{
    cout << "Double user vector: ";
    Display_double_value<int> result;
    result = for_each(user_vector.begin(), user_vector.end(), Display_double_value<Type>());
    cout << endl;
    cout << "Functor summon: " << result.counter << " times";//Выодит количество вызовов унарного оператора
}

int main() {

    vector<int> numsInVec;
    Fill_vector(numsInVec);
    cout << numsInVec.size() << endl;
    Display_user_vector(numsInVec);
    Display_double_vector(numsInVec);
    return 0;
}
