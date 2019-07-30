#include <iostream>
#include <exception>//для обработки исключения bad_alloc
using namespace std;
/*Обработка конкрентых исключений try/catch*/

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
    catch (bad_alloc& exp)//Выведет сообщение об ошибке выделения памяти
    {
        cout << "Exception located: " << exp.what() << endl;
        cout << "End of the program" << endl;
    }
    catch(...)
    {
        cout << "Sorry, exception located" << endl;
    }
    return 0;
}
