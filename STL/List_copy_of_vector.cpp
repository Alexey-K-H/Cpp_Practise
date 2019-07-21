#include <iostream>
#include <list>
#include <vector>

using namespace std;
//Напишите программу, которая вставляет содержимое вектора в список, исполь-
//зуя функцию вставки класса l i s t .

void Fill_vector(vector<float>& user_vector)
{
    char finish_fill = 'n';
    while(finish_fill != 'y'){
        cout << "Enter your digit:";
        float curr_num = 0;
        cin >> curr_num;
        user_vector.push_back(curr_num);
        cout << "Want to finish? Press 'y'- Yes or 'n' - No:";
        cin >> finish_fill;
    }
}

void Display_list_and_vector(list<float>& user_list, const vector<float>& user_vector)
{
    cout << "User_vector:";
    for(auto element = user_vector.cbegin(); element != user_vector.cend(); element++)
    {
        cout << *element << " ";
    }
    cout << endl;
    user_list.insert(user_list.cbegin(), user_vector.cbegin(), user_vector.cend());
    cout << "User_list:";
    for(auto element_list = user_list.cbegin(); element_list != user_list.cend(); element_list++)
    {
        cout << *element_list << " ";
    }
}

int main() {

    list<float> user_list;
    vector<float> user_vector;
    Fill_vector(user_vector);
    Display_list_and_vector(user_list, user_vector);
    return 0;
}
