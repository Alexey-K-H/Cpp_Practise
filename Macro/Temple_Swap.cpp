#include <iostream>

using namespace std;

//Реализовать шаблон swap
template <typename Type>
void Swap(Type& value1, Type& value2)
{
    cout << "Value1 = " << value1 << endl;
    cout << "Value2 = " << value2 << endl;
    Type tmp = value1;
    value1 = value2;
    value2 = tmp;
    cout << "After swap" << endl;
    cout << "Value1 = " << value1 << endl;
    cout << "Value2 = " << value2 << endl;
}



int main()
{
    cout << "Enter 2 numbers:" << endl;
    cout << "Enter the first number:";
    double val1 = 0;
    cin >> val1;
    cout << "Enter the second number:";
    double val2 = 0;
    cin >> val2;

    cout << "Print 2 strings:" << endl;
    cout << "Enter the first string:";
    string first_str;
    cin >> first_str;
    cout << "Print the second string:";
    string second_str;
    cin >> second_str;

    Swap(val1, val2);
    cout << endl;
    Swap(first_str, second_str);

    return 0;
}
