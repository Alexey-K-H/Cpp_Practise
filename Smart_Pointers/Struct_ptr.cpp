#include <iostream>
#include <string>
#include <memory>
using namespace std;
/*Структура и укзазатель*/
/*Пользователь вводит имя и возраст*/
struct HumanID {
    int age;
    string name;
    HumanID(int& curr_age, string& curr_name)
    :name(curr_name), age(curr_age){}

    void Display_ID(int& curr_index){
        cout << "Elements of structure ["<< curr_index <<"]: " << name << ", " << age << endl;
    }
};

int main()
{
    int finish = 1;
    int index_ID = 1;
    while (finish != 0){
        cout << "Name:";
        string name;
        cin >> name;
        cout << "Age:";
        int age;
        cin >> age;
        auto curr_person = make_unique<HumanID>(age, name);
        curr_person->Display_ID(index_ID);
        index_ID++;
        cout << "Want to continue? 1-yes, 0 - no :";
        cin >> finish;
    }
    return 0;
}
