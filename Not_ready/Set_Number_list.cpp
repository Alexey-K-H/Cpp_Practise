#include <iostream>
#include <set>
#include <string>

using namespace std;
/*Составить телефонный справочник,
 в котором доступен поиск по номеру телефона и по имени*/

template <typename Type>
void DisplayContents(const Type& container)
{
    for(auto iElement = container.cbegin(); iElement != container.cend(); iElement++)
        cout << *iElement << endl;
    cout << endl;
}

struct ContactID
{
        string name;
        string phoneNum;
        string displayAs;

        ContactID(const string& nameInit, const string& phone)
        {
            name = nameInit;
            phoneNum = phone;
            displayAs = (name + ": " + phoneNum);
        }

        //Оператор сравнения имен или номера
        bool operator ==(const ContactID& IDtoCompare) const {
            return ((IDtoCompare.name == this->name) || (IDtoCompare.phoneNum == this->phoneNum));
        }

        //Используется для сортировки
        bool operator <(const ContactID& IDtoComapre) const {
            return (this->name < IDtoComapre.name);
        }

        //Используется для вывода
        operator const char*() const {
            return displayAs.c_str();
        }
};

int main() {

    set<ContactID> setID;
    setID.insert(ContactID("Jack Welsch", "+1 7889 879 879"));
    setID.insert(ContactID("Bill Gates", "+1 97 7897 8799 8"));
    setID.insert(ContactID("Agni Merkel", "+49 23456 5466"));
    setID.insert(ContactID("Dim Medoed", "+7 6645 4564 797"));
    setID.insert(ContactID("John Travolta", "91 234 4564 789"));
    setID.insert(ContactID("Ben Affleck", "+1 745 641 314"));
    DisplayContents(setID);
    string finish = "yes";
    while(finish != "no")
    {
        cout << "Want to find user by name? press(yes/no):";
        string name_search = "no";
        getline(cin, name_search);
        if(name_search == "yes")
        {
            string exit = "yes";
            while(exit != "no"){
            cout << "Enter name of user:";
            string inputIDname;
            getline(cin, inputIDname);
            auto contactFound = setID.find(ContactID(inputIDname, ""));
            if(contactFound != setID.end())
            {
                setID.erase(contactFound);
                cout << "After erase:" << inputIDname << endl;
                DisplayContents(setID);
            }
            else
            {
                cout << "There is no user with this name" << endl;
            }
            cout << "Want to try again? Press(yes/no):";
            getline(cin, exit);
            }
        }
        string phone_search = "no";
        cout << "Want to find user by number? press(yes/no):";
        getline(cin, phone_search);
        if(phone_search == "yes")
        {
            string exit_search = "yes";
            while (exit_search != "no")
            {
                cout << "Enter the phone of user:";
                string phone_user;
                getline(cin, phone_user);
                auto contact_Found = setID.find(ContactID("", phone_user));
                if(contact_Found != setID.end())
                {
                    setID.erase(contact_Found);
                    cout << "After erase:" << phone_user << endl;
                    DisplayContents(setID);
                }
                else
                {
                    cout << "There is no user with this phone" << endl;
                }
                cout << "Want to try again? Press(yes/no):";
                getline(cin, exit_search);
            }
        }
        cout << "Want to restart program? Press(yes/no):";
        getline(cin, finish);
    }
    return 0;
}
