#include <iostream>
using namespace std;

void LogicOperations(bool value1, bool value2)
{
    cout << "Inverse of value1: " << !value1 << endl;
    cout << "Inverse of value2: " << !value2 << endl;

    cout << "Conjunction of values: " << (value1&&value2) << endl;
    cout << "Disjunction of values: " << (value1||value2) << endl;
}

int main()
{
    bool firstValue = false;
    bool secondValue = false;

    cout << "Enter the first value 0 or 1: ";
    cin >> firstValue;

    cout << "Enter the second value 0 or 1: ";
    cin >> secondValue;

    LogicOperations(firstValue, secondValue);
    return 0;
}
