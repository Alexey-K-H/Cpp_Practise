#include <iostream>

using namespace std;
//Использование шаблона с переменным числом параметров

//Шаблон для вариадической функции
template <typename Res, typename ValType>
void Sum(Res& result, ValType& val)
{
    result = result + val;
}

//Вариадическая функция
template <typename Res, typename First, typename... Rest>
void Sum(Res& result, First val1, Rest... valN)
{
    result = result + val1;
    return Sum(result, valN ...);
}

int main()
{
    double dResult = 0;
    Sum(dResult, 3.14, 4.56, 1.1111);
    cout << "dResult = " << dResult << endl;

    string strResult;
    Sum(strResult, "Hello ", "World");
    cout << "strResult = " << strResult.c_str() << endl;
    return 0;
}
