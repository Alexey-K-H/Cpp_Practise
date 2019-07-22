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
    cout << endl;
}

struct ContactID_sort_name
{
        string name;
        string phoneNum;
        string displayAs;

    ContactID_sort_name(const string& nameInit, const string & phone)
        {
            name = nameInit;
            phoneNum = phone;
            displayAs = (name + ": " + phoneNum);
        }

        //Оператор сравнения имен
        bool operator ==(const ContactID_sort_name& IDtoCompare) const {
            return (IDtoCompare.name == this->name);
        }

        //Используется для сортировки
        bool operator <(const ContactID_sort_name& IDtoComapre) const {
            return (this->name < IDtoComapre.name);
        }

        //Используется для вывода
        operator const char*() const {
            return displayAs.c_str();
        }
};

struct ContactID_sort_phone
{
    string name;
    string phoneNum;
    string displayAs;

    ContactID_sort_phone(const string& nameInit, const string & phone)
    {
        name = nameInit;
        phoneNum = phone;
        displayAs = (name + ": " + phoneNum);
    }

    //Оператор сравнения номера
    bool operator ==(const ContactID_sort_phone& IDtoCompare) const {
        return (IDtoCompare.phoneNum == this->phoneNum);
    }

    //Используется для сортировки
    bool operator <(const ContactID_sort_phone& IDtoComapre) const {
        return (this->phoneNum < IDtoComapre.phoneNum);
    }

    //Используется для вывода
    operator const char*() const {
        return displayAs.c_str();
    }
};

int main() {
 //В зависимости от праметра поиска нужно выбирать соответствующий контейнер
    string finish = "yes";
    while(finish != "no")
    {
        cout << "Want to find user by name? press(yes/no):";
        string name_search = "no";
        getline(cin, name_search);
        if(name_search == "yes")
        {
            set<ContactID_sort_name> setID_name;
            setID_name.insert(ContactID_sort_name("Jack Welsch", "+1 7889 879 879"));
            setID_name.insert(ContactID_sort_name("Bill Gates", "+1 97 7897 8799 8"));
            setID_name.insert(ContactID_sort_name("Agni Merkel", "+49 23456 5466"));
            setID_name.insert(ContactID_sort_name("Dim Medoed", "+7 6645 4564 797"));
            setID_name.insert(ContactID_sort_name("John Travolta", "91 234 4564 789"));
            setID_name.insert(ContactID_sort_name("Ben Affleck", "+1 745 641 314"));
            DisplayContents(setID_name);
            string exit = "yes";
            while(exit != "no"){
            cout << "Enter name of user:";
            string inputIDname;
            getline(cin, inputIDname);
            auto contactFound = setID_name.find(ContactID_sort_name(inputIDname, ""));
            if(contactFound != setID_name.end())
            {
                cout << "After erase:" << inputIDname << ":" << (*contactFound).phoneNum << endl;
                cout << endl;
                setID_name.erase(contactFound);
                DisplayContents(setID_name);
            }
            else
            {
                cout << "There is no user with this name" << endl;
            }
            cout << "Want to try again? press(yes/no):";
            getline(cin, exit);
            }
        }
        string phone_search = "no";
        cout << "Want to find user by number? press(yes/no):";
        getline(cin, phone_search);
        if(phone_search == "yes")
        {
            set<ContactID_sort_phone> setID_phone;
            setID_phone.insert(ContactID_sort_phone("Jack Welsch", "+1 7889 879 879"));
            setID_phone.insert(ContactID_sort_phone("Bill Gates", "+1 97 7897 8799 8"));
            setID_phone.insert(ContactID_sort_phone("Agni Merkel", "+49 23456 5466"));
            setID_phone.insert(ContactID_sort_phone("Dim Medoed", "+7 6645 4564 797"));
            setID_phone.insert(ContactID_sort_phone("John Travolta", "91 234 4564 789"));
            setID_phone.insert(ContactID_sort_phone("Ben Affleck", "+1 745 641 314"));
            DisplayContents(setID_phone);
            string exit_search = "yes";
            while (exit_search != "no")
            {
                cout << "Enter the phone of user:";
                string phone_user;
                getline(cin, phone_user);
                auto contact_Found = setID_phone.find(ContactID_sort_phone("", phone_user));
                if(contact_Found != setID_phone.end())
                {
                    cout << "After erase:" << (*contact_Found).name << ":" << phone_user << endl;
                    cout << endl;
                    setID_phone.erase(contact_Found);
                    DisplayContents(setID_phone);
                }
                else
                {
                    cout << "There is no user with this phone" << endl;
                }
                cout << "Want to try again? press(yes/no):";
                getline(cin, exit_search);
            }
        }
        cout << "Want to restart program? press(yes/no):";
        getline(cin, finish);
    }
    return 0;
}
