#include <iostream>
#include <fstream>
using namespace std;
/*Создание файла и запись в него*/

int main()
{
    ofstream myFile;
    myFile.open("HelloFile.txt", ios_base::out);

    if(myFile.is_open())
    {
        cout << "File successfully opened" << endl;
        myFile << "My first text file!" << endl;
        myFile << "Hello, file!";

        cout << "Close file" << endl;
        myFile.close();
    }
}
