#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*написать бинарный предикат, который сравнивает две строки*/

bool Compare(string& str1, string &str2)
{
    string str1_low_case;
    str1_low_case.resize(str1.size());
    transform(str1.begin(), str1.end(), str1_low_case.begin(), :: tolower);

    string str2_low_case;
    str2_low_case.resize(str2.size());
    transform(str2.begin(), str2.end(), str2_low_case.begin(), :: tolower);

    return (str1_low_case < str2_low_case);
}

int main()
{
    cout << "Print the first string:";
    string str1;
    cin >> str1;
    cout << "Print the second string:";
    string str2;
    cin >> str2;

    if(Compare(str1, str2))
        cout << "The first string is lower" << endl;
    else
        cout << "The second string is lower" << endl;
}
