#include <iostream>
#define MULTIPLE(value1, value2) (value1)*(value2)
using namespace std;
//Макрос умножения 2 чисел

int main()
{
    cout << "Enter 2 numbers:" << endl;
    cout << "Enter the first number:";
    double val1 = 0;
    cin >> val1;
    cout << "Enter the second number:";
    double val2 = 0;
    cin >> val2;

    double result = MULTIPLE(val1, val2);
    cout << "Result is: " << result << endl;
    
    return 0;
}
