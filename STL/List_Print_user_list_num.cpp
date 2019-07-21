#include <iostream>
#include <list>

using namespace std;
//Напишите короткую программу, которая получает введенные пользователем
//числа и вставляет их в начало списка.

void Fill_list(list<float>& user_list)
{
    char finish_fill = 'n';
    while(finish_fill != 'y'){
        cout << "Enter your digit:";
        float curr_num = 0;
        cin >> curr_num;
        user_list.push_front(curr_num);
        cout << "Want to finish? Press 'y'- Yes or 'n' - No:";
        cin >> finish_fill;
    }
}

void Display_list(list<float>& user_list)
{
    cout << "User_list:";
    for(auto element = user_list.cbegin(); element != user_list.end(); element++)
    {
        cout << *element << " ";
    }
}

int main() {

    list<float> user_list;
    Fill_list(user_list);
    Display_list(user_list);
    return 0;
}
