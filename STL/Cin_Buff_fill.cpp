#include <iostream>
using namespace std;
/*Использование вставки в символьный буфер*/

int main()
{
    cout << "Enter string: " << endl;
    char charBuff[10] = {0};
    cin.get(charBuff, 9);//get() не позволяет выходить за пределы массива
    cout << "CharBuffer: " << charBuff << endl;
    return 0;
}
