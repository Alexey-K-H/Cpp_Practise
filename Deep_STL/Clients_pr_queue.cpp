#include <iostream>
#include <string>
#include <queue>

using namespace std;
/*Дан список людей в очереди, отсортировать их так
  чтобы сначала шли старики и женщины*/

class Person{
public:
    int age;
    bool isWoman;
    string name;
    Person(int& curr_age, bool& curr_sex_person, string& curr_name){
        age = curr_age;
        isWoman = curr_sex_person;
        name = curr_name;
    }

    bool operator<(const Person& anotherPerson) const{
        bool bRet = false;//Человек старше
        if(age < anotherPerson.age)
            bRet = true;
        else if(isWoman && anotherPerson.isWoman)
            bRet = true;
        return bRet;
    }
};

void Fill_queue(priority_queue<Person>& clients){
    char finish = 'n';
    while (finish != 'y'){
        cout << "Enter the name:";
        string curr_name;
        cin >> curr_name;

        cout << "Enter the age:";
        int curr_age;
        cin >> curr_age;

        cout << "Enter the sex, is female?(true/false):";
        bool is_female;
        cin >> is_female;

        clients.push(Person(curr_age, is_female, curr_name));
        cout << "Want to finish? y/n:";
        cin >> finish;
    }
}

void Display_data(priority_queue<Person>& clients){
    while (!clients.empty()){
        cout << "Name:" << clients.top().name << " Age:" << clients.top().age << endl;
        clients.pop();
    }
}

int main()
{
    cout << "<Fill the queue>" << endl;
    priority_queue<Person> clients;
    Fill_queue(clients);
    Display_data(clients);
}
