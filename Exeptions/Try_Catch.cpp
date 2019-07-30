#include <iostream>

using namespace std;
/*Обработка исключений try/catch*/

int main()
{
    cout << "Enter the count of numbers: ";
    try{
        int input = 0;
        cin >> input;
        //Запрос области памяти и ее освобождение
        int* numArray = new int[input];
        delete[] numArray;
    }
    catch (...)//Описание исключений
    {
        cout << "Sorry, exeption!" << endl;
    }
    return 0;
}
