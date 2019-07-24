#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*Написать бинарный предикат, обеспечивающий сортировку в порядке возрастания в виде лямбда-выражения*/

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
void Display_user_vector(const vector<Type>& user_vector)
{
    cout << "User vector contain: ";
    for_each(user_vector.begin(), user_vector.end(), Display_vector<Type>());
    cout << endl;
}


int main() {

    vector<float > numsInVec;
    Fill_vector(numsInVec);
    cout << "<Before sort>" << endl;
    Display_user_vector(numsInVec);
    cout << "<After sort with lambda_value>" << endl;

    //Сортировка с использование лямбда_выражения
    sort(numsInVec.begin(), numsInVec.end(),
         [](const float& val1, const float& val2) -> bool
            {
             return (val1 > val2);
            }
         );
    Display_user_vector(numsInVec);
    return 0;
}
