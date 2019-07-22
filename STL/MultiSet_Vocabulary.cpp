#include <iostream>
#include <set>
#include <string>

using namespace std;
/*Составить телефонный справочник,
 в котором доступен поиск по номеру телефона и по имени и последующее удаление из списка номеров*/

template <typename Type>
void DisplayContents(const Type& container)
{
    for(auto iElement = container.cbegin(); iElement != container.cend(); iElement++)
        cout << *iElement << endl;
}

struct Vocabulary_word
{
        string word;
        string definition;
        string displayAs;

    Vocabulary_word(const string& inWord, const string& inDefinition)
        {
            word = inWord;
            definition = inDefinition;
            displayAs = ("*" + inWord + " - " + inDefinition);
        }

    operator const char*() const {
        return displayAs.c_str();
    }

    bool operator <(const Vocabulary_word& word_to_Compare) const {
        return (this->word < word_to_Compare.word);
    }
};

int main() {

    multiset<Vocabulary_word> user_Vocabulary;
    string start_fill = "yes";
    while (start_fill != "no")
    {
        cout << "Enter your word:";
        string user_word;
        getline(cin, user_word);

        cout << "Enter the definition of your word:";
        string user_definition;
        getline(cin, user_definition);

        user_Vocabulary.insert(Vocabulary_word(user_word, user_definition));
        cout << "Continue? yes/no:";
        getline(cin, start_fill);
    }
    cout << "Your Vocabulary:" << endl;
    DisplayContents(user_Vocabulary);
    return 0;
}
