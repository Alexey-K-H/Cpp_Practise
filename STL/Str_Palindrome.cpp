#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//Проверить является ли слово введенное пользователем палиндромом
void Check_For_Palindrome(string userWord)
{
    string reversed_str = userWord;
    reverse(userWord.begin(), userWord.end());
    if(reversed_str == userWord)
        cout << "Your word is a palindrome" << endl;
    else
        cout << "Your word is not a palindrome" << endl;
}


int main()
{
    char finish = 's';//Завершение алгоритма
    while(finish != 'f')
    {
        cout << "Enter your word:";
        string userWord;
        cin >> userWord;
        Check_For_Palindrome(userWord);

        cout << "Want to repeat? Press (f) if not," << endl;
        cout << "or something else if you want to try the other word:";
        cin >> finish;
    }
    cout << "The end of the work, goodbye!";
    return 0;
}
