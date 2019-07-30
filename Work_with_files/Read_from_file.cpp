#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*Чтение файла*/

int main()
{
    ifstream myFile;
    myFile.open("HelloFile.txt", ios_base::out);

    if(myFile.is_open())
    {
        cout << "File successfully opened" << endl;
        cout << "It contains:" << endl;
        string fileContents;

        while (myFile.good())//Пока файл не закончен
        {
            getline(myFile, fileContents);
            cout << fileContents << endl;
        }
        cout << "Close file" << endl;
        myFile.close();
    }
    else
        cout << "Can't open file!" << endl;
    return 0;
}
