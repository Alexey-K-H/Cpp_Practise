#include <iostream>
#include <string>
using namespace std;
//Цикл for для диапозона
int main()
{
    int some_numbers[] = {1, -10, 5, 6, -22, 100};
    cout << "Elements of massive: " << endl;
    for(int elemOfArray : some_numbers)
        cout << elemOfArray << ' ';
    cout << endl;

    char char_symbols[] = {'a', 'b', 'c', 'd'};
    cout << "Elements of another massive: " << endl;
    for(auto aChar : char_symbols)
        cout << aChar << ' ';
    cout << endl;

    string sayHello {"Hello World!"};
    for(auto strElement : sayHello)
        cout << strElement;
    cout << endl;

    return 0;
}
