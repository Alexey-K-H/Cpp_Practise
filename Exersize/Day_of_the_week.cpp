#include <iostream>

using namespace std;
//Суть задачи: по введенному номеру дня недели вывести его название, используя оператор множественного выбора.
// Нумерация дней недели начинается с 1 – понедельник, 2 — вторник и т. д.

void Get_Information_about_number(int number){
    enum day{
        Monday = 1,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };

    switch(number)
    {
        case(Monday):
            cout << "Your number of the day rely to Monday";
            break;
        case(Tuesday):
            cout << "Your number of the day rely to Tuesday";
            break;
        case(Wednesday):
            cout << "Your number of the day rely to Wednesday";
            break;
        case(Thursday):
            cout << "Your number of the day rely to Thursday";
            break;
        case(Friday):
            cout << "Your number of the day rely to Friday";
            break;
        case(Saturday):
            cout << "Your number of the day rely to Saturday";
            break;
        case(Sunday):
            cout << "Your number of the day rely to Sunday";
            break;
        default: cout << "Your number of the day is not rely to any day";
    }
}

int main()
{
    cout << "Enter the number of the day of the week:";
    int number = 0;
    cin >> number;
    Get_Information_about_number(number);
    return 0;
}
