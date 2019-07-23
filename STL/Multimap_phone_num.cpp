#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
/*Написать приложение справочник, где имена жлементов могут быть не уникальными*/

template <typename Type>
void DisplayUsers(const Type& container)
{
    for(auto ind_elem = container.cbegin(); ind_elem != container.cend(); ind_elem++)
    {
        cout << ind_elem -> first << ": " << ind_elem -> second << endl;
    }
}

//Предикат использующий сортировку без учета регистра
struct PredIgnoreCase
{
        bool operator()(const string& str1, const string& str2) const
        {
            string str1NoCase(str1), str2NoCase(str2);
            transform(str1.begin(), str1.end(), str1NoCase.begin(),::tolower);
            transform(str2.begin(), str2.end(), str2NoCase.begin(),::tolower);

            return (str1NoCase < str2NoCase);
        };
};

typedef multimap<string, string, PredIgnoreCase> Dir_No_case;

void Search_Curr_User(Dir_No_case& container)
{
    cout << "Enter user name:";
    string name;
    getline(cin, name);

    auto pair_with_name = container.find(name);
    if(pair_with_name != container.end()){
        size_t numPairsInList = container.count(name);
        for(size_t counter  = 0; counter < numPairsInList; ++counter)
        {
            cout << "UserID: " << pair_with_name->first << "(" << pair_with_name->second << ")" << endl;
            pair_with_name++;
        }
    }else
    {
        cout << "There is no user with this name" << endl;
    }
}


int main() {

    Dir_No_case phone_list;

    phone_list.insert(make_pair("Jack Welsch", "+1 7889 879 879"));
    phone_list.insert(make_pair("Bill Gates", "+1 97 7897 8799 8"));
    phone_list.insert(make_pair("Agni Merkel", "+49 23456 5466"));
    phone_list.insert(make_pair("Dima Medoed", "+7 6645 4564 797"));
    phone_list.insert(make_pair("John Travolta", "91 234 4564 789"));
    phone_list.insert(make_pair("Ben Affleck", "+1 745 641 314"));
    phone_list.insert(make_pair("Jack Welsch", "+1 989 645 288 6"));

    cout << "Phone number list:" << endl;
    DisplayUsers(phone_list);

    Search_Curr_User(phone_list);
    return 0;
}
