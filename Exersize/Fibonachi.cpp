#include <iostream>

using namespace std;
//Числа Фибонначи
//На вход подается количество чисел которые нужно вывести

void Print_Fibonachi(int count_of_numbers)
{
    int num1 = 0;
    int num2 = 1;
    char wantMore = '\0';
    cout << num1 << " " << num2 << " ";

    int counter = count_of_numbers - 2;//Так как первые два числа уже выведены

    do{
        while(counter != 0)
        {
        cout << num1 + num2 << " ";
        int num2Temp = num2;
        num2 = num1 + num2;
        num1 = num2Temp;
        counter--;
        }

        cout << endl << "Continue? Press n if agree: ";
        cin >> wantMore;
        if(wantMore == 'n'){
            cout << "Press new count of numbers: ";
            cin >> counter;
        }
      }while(wantMore == 'n');

      cout << "Finish of the programm" << endl;
}

int main()
{
    int count_of_numbers = 0;
    cout << "Enter count of numbers: ";
    cin >> count_of_numbers;

    if(count_of_numbers <= 0)
        {
            cout << "Error! Bad input!";
            return 0;
        }

    Print_Fibonachi(count_of_numbers);

    return 0;
}
