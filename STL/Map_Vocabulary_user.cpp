#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
/*Написать приложение словарь, с пользоветльским предикатом*/

struct wordProperty
{
        string strWord;
        bool bIsFromLatin;

        wordProperty(const string& inStr)
        {
            strWord = inStr;
            bIsFromLatin = true;
        }
};

//Предикат использующий сортировку без учета регистра
struct fPredicate
{
    bool operator()(const wordProperty& left_word, const wordProperty& right_word) const
    {
        return (left_word.strWord < right_word.strWord);
    }
};

typedef map<wordProperty, string, fPredicate> mapWordDefinition;

template <typename Type>
void Fill_Vocabulary(Type& container)
{
    string finish_fill = "no";
    while (finish_fill != "yes")
    {
        cout << "Print your word:";
        string curr_word;
        getline(cin, curr_word);

        cout << "Print definition of this word:";
        string curr_def;
        getline(cin, curr_def);

        container.insert(make_pair(wordProperty(curr_word), curr_def));
        cout << "Want to finish? Press yes/no:";
        getline(cin, finish_fill);
    }
}

void DisplayVocabulary(mapWordDefinition& container)
{
    for(auto ind_elem = container.cbegin(); ind_elem != container.cend(); ind_elem++)
    {
        cout << ind_elem -> first.strWord << ": " << ind_elem -> second << endl;
    }
}

int main() {
    mapWordDefinition user_vocabulary;
    Fill_Vocabulary(user_vocabulary);
    DisplayVocabulary(user_vocabulary);
    return 0;
}
