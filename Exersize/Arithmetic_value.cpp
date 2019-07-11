#include <iostream>

using namespace std;

//Запрограммировать следующее выражение: (а + b — f / а) + f * a * a — (a + b) Числа а, b, f вводятся с клавиатуры. 
//Организовать пользовательский интерфейс, таким образом, чтобы было понятно, в каком порядке должны вводиться числа.

void arithmetic_value(float x, float y, float z){
    cout << "Make operation: S =(x + y - z / x) + z * x * x - (x + y)" << endl;
    float result_value = 0;
    result_value = (x + y - z / x) + z * x * x - (x + y);
    cout << "Result of the operation is: " << result_value;
}

int main() {
    cout << "Print three numbers: " << endl;
    cout << "Print the first number x: ";
    float first_number = 0;
    cin >> first_number;
    cout << "Print the second number y: ";
    float second_number = 0;
    cin >> second_number;
    cout << "Print the third number z: ";
    float third_number = 0;
    cin >> third_number;

    arithmetic_value(first_number, second_number, third_number);

    return 0;
}
