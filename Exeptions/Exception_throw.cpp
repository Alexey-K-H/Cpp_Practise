#include <iostream>
using namespace std;
/*Генерация конкрентого исключения при попытке деления на ноль*/

double Divide(double dividend, double divisor)
{
    if(divisor == 0)
        throw "You can't divide by 0";
    return (dividend/divisor);
}

int main()
{
    cout << "Enter dividend: ";
    double dividend = 0;
    cin >> dividend;
    cout << "Enter divisor: ";
    double divisor = 0;
    cin >> divisor;

    try
    {
        cout << "Result is: " << Divide(dividend, divisor);
    }
    catch (const char* exp)
    {
        cout << "Exception: " << exp << endl;
        cout << "Finish of the program." << endl;
    }
    return 0;
}
