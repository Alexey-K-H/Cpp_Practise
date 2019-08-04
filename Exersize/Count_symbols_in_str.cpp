#include <iostream>
#include <string>
using namespace std;
/*Подсчитать количество повторений элементов, заданного множества символов, во введенной строке.*/

void Count_symbols(string& user_str)
{
    auto *alphabet = new int [256];
    for(auto str_Element : user_str)
        alphabet[str_Element]++;

    for(int alphabet_elem = 0; alphabet_elem < 256; alphabet_elem++){
        if(alphabet[alphabet_elem] != 0)
            cout << (char)alphabet_elem << ": " << alphabet[alphabet_elem] << endl;
    }

    delete[](alphabet);
}

int main()
{
    cout << "Enter the string:";
    string user_str;
    getline(cin, user_str);
    Count_symbols(user_str);
    return 0;
}
