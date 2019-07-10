#include <iostream>
#include <string.h>
using namespace std;
//Использование копирующего коструктора
class MyString
{
private:
    char* buffer;

public:
    MyString(const char* initString)//Конструктор по умолчанию
    {
        buffer = nullptr;
        cout << "Constructor default" << endl;
        if(initString != nullptr)
        {
            buffer = new char[strlen(initString) + 1];
            strcpy(buffer, initString);
        }
    }

    MyString(const MyString& copySourse)//Копирующий конструктор
    {
        buffer = nullptr;
        cout << "Copy constructor" << endl;
        if(copySourse.buffer != nullptr)
        {
            //Выделение собственного буфера
            buffer = new char[strlen(copySourse.buffer) + 1];

            //Глубокое копирование исходного буфера в целевой
            strcpy(buffer, copySourse.buffer);
        }
    }

    ~MyString()//Деструктор
    {
        cout << "Destructor" << endl;
        delete[] buffer;
    }

    int GetLength()
    {
        return strlen(buffer);
    }

    const char* GetString()
    {
        return buffer;
    }
};

void UseMyString(MyString str)
{
    cout << "Buffer size is: ";
    cout << str.GetLength() << " symbols" << endl;

    cout << "Buffer contains: " << str.GetString() << endl;
    return;
}

int main() {

    //Нужно определить длину исходной строки, используя функцию
    MyString sayHello("Copy Constructor");
    UseMyString(sayHello);//В функцию передается копия которая создается копирующим коструктором

    return 0;
}
