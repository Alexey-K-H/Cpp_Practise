#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//Определить количество гласных в введенном предложении
//Гласные буквы в английском: A, E, I, O, U

void Find_Vowels(string user_str)
{
    transform(user_str.begin(), user_str.end(), user_str.begin(), ::toupper);
    int count_of_vowels = 0;
    for(auto charLocator = user_str.cbegin(); charLocator != user_str.cend(); ++charLocator)
    {
        switch (*charLocator)
        {
            case ('A'):
                count_of_vowels++;
                break;
            case ('E'):
                count_of_vowels++;
                break;
            case ('I'):
                count_of_vowels++;
                break;
            case ('O'):
                count_of_vowels++;
                break;
            case ('U'):
                count_of_vowels++;
                break;
        }
    }
    cout << "Count of vowels in your sentence is: " << count_of_vowels << endl;
}

int main()
{
    char finish = 'n';
    while (finish != 'f')
    {
        cout << "Enter your sentence:";
        string user_Sentence;
        getline(cin, user_Sentence);
        cout << "Your sentence is: " << user_Sentence << endl;
        Find_Vowels(user_Sentence);
        cout << "Want to repeat or not?" << endl;
        cout << "Press (f) to finish or something else to repeat:";
        cin >> finish;
    }
    cout << "End of the program, goodbye!" << endl;
    return 0;
}
