#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//Преобразовать каждый второй символ строки в верхний регистр

void To_up_each_second(string user_str)
{
    for(auto charCounter = 1; charCounter < user_str.length(); charCounter += 2)
    {
        user_str[charCounter] = toupper(user_str[charCounter]);
    }
    cout << "New string is: " << user_str << endl;
}

int main()
{
    char finish = 'n';
    while (finish != 'f')
    {
        cout << "Enter your string:";
        string user_string;
        cin >> user_string;
        To_up_each_second(user_string);
        cout << "Want to repeat or not?" << endl;
        cout << "Press (f) to finish or something else to repeat:";
        cin >> finish;
    }
    cout << "End of the program, goodbye!" << endl;
    return 0;
}
