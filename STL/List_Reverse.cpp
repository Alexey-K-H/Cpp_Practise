#include <iostream>
#include <list>
#include <string>

using namespace std;
//Напишите программу, обращающую список строк.

void Fill_List(list<string>& user_list)
{
    string finish_fill = "n";
    while(finish_fill != "y"){
        cout << "Enter your string:";
        string curr_str;
        getline(cin, curr_str);
        user_list.push_back(curr_str);

        cout << "Want to finish? Press 'y'- Yes or 'n' - No:";
        getline(cin, finish_fill);
    }
}

void Display_list_and_reversed(list<string>& user_list)
{
    cout << "User_list:";
    for(auto element = user_list.cbegin(); element != user_list.cend(); element++)
    {
        cout << *element << " ";
    }
    cout << endl;
    user_list.reverse();
    cout << "User_list_reversed:";
    for(auto element_list = user_list.cbegin(); element_list != user_list.cend(); element_list++)
    {
        cout << *element_list << " ";
    }
}

int main() {

    list<string> user_list;
    Fill_List(user_list);
    Display_list_and_reversed(user_list);
    return 0;
}
