#include <iostream>
#include <string>

using namespace std;
//Напишите для класса Date оператор преобразования, который преобразует содержащуюся
//в нем дату в целое число.

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int inMonth, int inDay, int inYear)
    : month(inMonth), day(inDay), year(inYear) {};

    operator int()
    {
        return (10000 * year + 100 * month + day);
    }
};

int main()
{
    Date Holiday(1, 7, 2019);
    cout << "Date in int_value is: " << Holiday << endl;
    return 0;
}
