#include <iostream>
using namespace std;
/*Вычислить цепную дробь*/
/*Пользователь задает точность дроби, вводя число знаков после запятой*/
/*1+1/(1+....+1/(1+1))....) - цепная дробь*/
float Chain_shot(int& user_value, float& result)
{
    for(int i = 0; i < user_value; i++)
    {
        result = 1 + 1/result;
    }
    return result;
}

int main()
{
    cout << "Enter user number:";
    int user_num = 0;
    cin >> user_num;
    float result = 1.0;
    result = Chain_shot(user_num, result);
    cout << "Result is: " << result << endl;
    return 0;
}
