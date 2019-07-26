#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
/*Заполнить вектор из двух разных типов контейнеров*/

template<typename Type>
void Display_container(vector<Type>& curr_vec)
{
    for(auto element = curr_vec.cbegin(); element != curr_vec.cend(); element++)
        cout << *element << " ";
}

template<typename Type>
void Fill_container(vector<Type>& curr_vec)
{
    char finish = 'n';
    while(finish!= 'y'){
        cout << "Enter your value:";
        Type curr_val;
        cin >> curr_val;
        curr_vec.push_back(curr_val);
        cout << "Finish fill container? press y/n:";
        cin >> finish;
    }
}

void Display_list(list<float>& user_list)
{
    cout << "<User_list>" << endl;
    for(auto element = user_list.cbegin(); element != user_list.cend(); element++)
    {
        cout << *element << " ";
    }
}

int main()
{
    vector<int> first_vec;
    cout << "Fill the first vector" << endl;
    Fill_container(first_vec);
    cout << "<The first vector>" << endl;
    Display_container(first_vec);
    cout << endl;
    vector<float> second_vec;
    cout << "Fill the second vector" << endl;
    Fill_container(second_vec);
    cout << "<The second vector>" << endl;
    Display_container(second_vec);
    cout << endl;
    list<float> user_list(first_vec.size()*2);
    /*Скопировать в список нечтеные числа из первого вектора и числа из диапозона [0;1] из второго вектора*/
    auto last_element = copy_if(first_vec.cbegin(), first_vec.cend(), user_list.begin(),
            [](int element){return ((element % 2) == 1);});
    copy_if(second_vec.cbegin(), second_vec.cend(), last_element,
            [](float element){ return(element >= 0 && element <= 1);});
    auto newEnd = remove(user_list.begin(), user_list.end(), 0);
    user_list.erase(newEnd, user_list.end());
    Display_list(user_list);
}
