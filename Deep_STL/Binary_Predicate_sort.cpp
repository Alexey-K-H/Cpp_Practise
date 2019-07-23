#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*Написать бинарный предикат, обеспечивающий сортировку в порядке возрастания*/

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

//Пользовательский бинарный предикат
class Compare_twoNum_value
{
public:
    template <typename Type>
    bool operator()(const Type& val1, const Type& val2) const
    {
        return (val1 < val2);
    }
};

int main() {

    vector<float > numsInVec;
    Fill_vector(numsInVec);
    cout << "<Before sort>" << endl;
    Display_user_vector(numsInVec);
    cout << "<After sort with predicate>" << endl;
    sort(numsInVec.begin(), numsInVec.end(), Compare_twoNum_value());
    Display_user_vector(numsInVec);
    return 0;
}
