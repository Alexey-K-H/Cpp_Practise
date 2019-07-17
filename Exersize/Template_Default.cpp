#include <iostream>

using namespace std;
//Шаблонны с параметрами по умолчанию

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

int main()
{
    HoldsPair<> pairIntDbl(56, 12.98);
    HoldsPair<short, const char*>pairShrtStr(21, "Some string");

    cout << "The first object contains:" << endl;
    cout << "Value 1: " << pairIntDbl.GetFirstValue() << endl;
    cout << "Value 2: " << pairIntDbl.GetSecondValue() << endl;

    cout << "The second object contains:" << endl;
    cout << "Value 1:" << pairShrtStr.GetFirstValue() << endl;
    cout << "Value 2:" << pairShrtStr.GetSecondValue() << endl;

    return 0;
}
