#include <iostream>

using namespace std;

//Реализовать шаблон умножения
template <typename Type>
void Multiple(const Type& value1, const Type& value2)
{
    Type multiple = value1 * value2;
    cout << "Value1 * Value2 = " << multiple << endl;
}

//Шаблон сложения
template <typename Type>
Type Get_Sum(const Type& value1, const Type& value2)
{
    Type summary = value1 + value2;
    return summary;
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

    Multiple<>(val1, val2);
    cout << "Value1 + Value2 = " << Get_Sum(val1, val2) << endl;
    cout << "Str1 + Str2 = " << Get_Sum(first_str, second_str);

    return 0;
}
