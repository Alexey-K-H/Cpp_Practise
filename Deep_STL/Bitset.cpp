#include <iostream>
#include <bitset>

using namespace std;
/*реализовать операции с наборами бит*/
void Summary(bitset<4>& val1, bitset<4>& val2){
    bitset<4> result = val1 | val2;
    cout << val1 << " + " << val2 << " = " << result << endl;
    cout << "Inverted result: " << result.flip();
}

int main()
{
    cout << "Enter your value:";
    int user_val = 0;
    cin >> user_val;
    bitset<4> fourBits = user_val;
    cout << "First value:" << fourBits << endl;
    cout << "Enter the second value:";
    int user_val_sec = 0;
    cin >> user_val_sec;
    bitset<4> fourBits2 = user_val_sec;
    Summary(fourBits, fourBits2);
}
