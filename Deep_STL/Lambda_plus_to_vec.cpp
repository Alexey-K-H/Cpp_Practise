#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*Написать лямбда выражение, которое прибавляет к значениям ветора число, введенное пользователем*/

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
    cout << "<User vector>" << endl;
    Display_user_vector(numsInVec);
    cout << "Enter your value:";
    float user_val = 0;
    cin >> user_val;
    cout << "<User_value>: " << user_val << endl;

    for_each(numsInVec.begin(), numsInVec.end(), [=](float & element){
        element += user_val;
    });
    Display_user_vector(numsInVec);
    return 0;
}
