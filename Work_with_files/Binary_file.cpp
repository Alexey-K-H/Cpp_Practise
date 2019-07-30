#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>//Манипуляторы
using namespace std;
/*Запись и чтение из бинарного файла*/

struct Human
{
    char name[30];
    int age;
    char DOB[20];

    Human() {};
    Human(const char* in_Name, int in_Age, const char*iDOB):age(in_Age)
    {
        strcpy(name, in_Name);
        strcpy(DOB, iDOB);
    }
};

int main()
{
    //Создание объекта с ID
    Human input("Andrey Tkachev", 25, "June 1998");
    ofstream fsOut("My Birthday.bin", ios_base::out|ios_base::binary);
    if(fsOut.is_open())
    {
        cout << "Input to binary file" << endl;
        fsOut.write((const char*)&input, sizeof(input));
        fsOut.close();
    }

    ifstream fsIn("My Birthday.bin", ios_base::in|ios_base::binary);
    
    //Чтение из файла
    if(fsIn.is_open())
    {
        Human somePerson;
        fsIn.read((char*)&somePerson, sizeof(somePerson));

        cout << "Read from binary file:" << endl;
        cout << "Name: " << somePerson.name << endl;
        cout << "Age: " << somePerson.age << endl;
        cout << "Date of Birth: " << somePerson.DOB << endl;
    }
    return 0;
}
