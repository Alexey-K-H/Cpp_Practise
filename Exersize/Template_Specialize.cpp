#include <iostream>

using namespace std;
//Специализация шаблонов для опреденного набора значений 
//переменных типов

template <typename T1 = int , typename T2 = double>
class HoldsPair
{
private:
    T1 value1;
    T2 value2;
public:
    HoldsPair(const T1& val1, const T2& val2)
    : value1(val1), value2(val2){}

    const T1 & GetFirstValue() const
    {
        return value1;
    }

    const T2 & GetSecondValue() const
    {
        return value2;
    }
};

//Специализация для двух значений int
template<> class HoldsPair<int, int>
{
private:
    int value1;
    int value2;
    string strFun;
public:
    HoldsPair(const int& val1, const int& val2)
    : value1(val1), value2(val2) {}

    const int & GetSumValue() const
    {
        cout << "Return: " << value1 + value2 << endl;
        return value1;
    }
};

int main()
{
    HoldsPair<int, int> pairIntInt(222, 444);
    pairIntInt.GetSumValue();

    return 0;
}
