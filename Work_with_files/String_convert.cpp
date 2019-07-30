#include <iostream>
#include <fstream>
#include <sstream>//Для преобразования

using namespace std;
/*Преобрахование стрококвого значения в целое и обратно*/

int main()
{
    cout << "Enter your value:";
    int user_val = 0;
    cin >> user_val;

    stringstream converterStream;
    converterStream << user_val;
    string strINput;
    converterStream >> strINput;

    cout << "Entered value: " << user_val << endl;
    cout << "Converted to string: " << strINput << endl;

    stringstream anotherStream;
    anotherStream << strINput;
    int copy = 0;
    anotherStream >> copy;
    cout << "Converted to value: " << copy << endl;
    return 0;
}
