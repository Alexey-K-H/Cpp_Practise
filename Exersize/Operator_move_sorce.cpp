#include <iostream>

using namespace std;
//Реализация перемещающего оператора и
//оператора копирования
class DymInteger
{
private:
    int * ptrArr;
public:
    //Перемещающий конструктор
    DymInteger(DymInteger && moveSource)
    {
        ptrArr = moveSource.ptrArr;
        moveSource.ptrArr = nullptr;
    }
    //Перемещающий оператор присваивания
    DymInteger & operator= (DymInteger && moveSource)
    {
        if(this != & moveSource)
        {
            delete[] ptrArr;
            ptrArr = moveSource.ptrArr;
            moveSource.ptrArr = nullptr;
        }
        return *this;
    }
    DymInteger();//Конструктор
    DymInteger(const DymInteger & copySource);
    DymInteger & operator= (const DymInteger & copySource);
    ~DymInteger() {delete[] ptrArr;}//Деструктор
};

int main()
{
    //Что-то...
    return 0;
}
