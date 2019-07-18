#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//Вывести все позиции вхождения буквы в предложение которые вводит пользователь

void Char_Search(string& user_str, const char user_char)
{
    auto charPos = user_str.find(user_char, 0);
    int count = 0;
    while (charPos != string::npos)
    {
        cout << "Character " << user_char << " is founded in position: " << charPos << endl;
        auto searchOffset = charPos + 1;
        count++;
        charPos = user_str.find(user_char, searchOffset);
    }
    if(count == 0)
    {
        cout << "There is no your symbol in your sentence" << endl;
    }
}

int main()
{
    char finish = 'n';
    while (finish != 'f')
    {
        cout << "Enter your sentence:";
        string user_string;
        getline(cin, user_string);
        cout << "Your sentence: " << user_string << endl;
        cout << "Enter your character for search:";
        char user_char;
        cin >> user_char;
        Char_Search(user_string, user_char);
        cout << "Want to repeat or not?" << endl;
        cout << "Press (f) to finish or something else to repeat:";
        cin >> finish;
    }
    cout << "End of the program, goodbye!" << endl;
    return 0;
}
