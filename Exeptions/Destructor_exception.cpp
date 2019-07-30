#include <iostream>
using namespace std;
/*Последовательное удаление объектов в случае исключения*/
/*Исключение когда дважды уничтожается объект*/
struct ObjectA
{
    ObjectA() {cout << "Create object A" << endl;}
    ~ObjectA(){cout << "Delete object A" << endl;}
};

struct ObjectB
{
    ObjectB(){cout << "Create object B" << endl;}
    ~ObjectB(){cout << "Delete object B" << endl;}
};

void FunctionB()//Генерация исключения
{
    cout << "In FunctionB():" << endl;
    ObjectA objA;
    ObjectB objB;
    cout << "Exception" << endl;
    throw "Catch me!";//Объект уже уничтожен, но его еще раз пытаются удалить
}

void FunctionA()
{
    try {
        cout << "In FunctionA():" << endl;
        ObjectA objA;
        ObjectB objB;
        FunctionB();
        cout << "Return to summoned function." << endl;
    }
    catch (const char* exp)
    {
        cout << "FunctionA: got exception:" << exp << endl;
        cout << "FunctionA: ready, don't allow to continue" << endl;
    }

}

int main()
{
    cout << "Star:" << endl;
    try {
        FunctionA();
    }
catch (const char* exp)
{
    cout << "Exception:" << exp << endl;
}
    cout << "Finish" << endl;
    return 0;
}
