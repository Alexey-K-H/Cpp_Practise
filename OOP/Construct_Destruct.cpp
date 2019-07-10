#include <iostream>
#include <cstring>
using namespace std;
//Использование конструкторов и деструкторов на примере строк в стиле С
class MyString
{
private:
    char* buffer;

public:
    MyString(const char* initString)//Конструктор
    {
        if(initString != nullptr)
        {
            buffer = new char[strlen(initString)+1];
            strcpy(buffer, initString);
        }
        else
            buffer = nullptr;
    }

    ~MyString()
    {
        cout << "Destruction point:" << endl;
        if(buffer != nullptr)
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

int main() {

    MyString sayHello("String Class");
    cout << "Buffer size is: ";
    cout << sayHello.GetLength() << " symbols." << endl;

    cout << "Buffer contain: " << sayHello.GetString() << endl;

    return 0;
}
