#include <iostream>

using namespace std;
//Наличие цвета в радуге с помощбю перечисления

void Check_for_right_color(int number_color)
{
    enum color
    {
        Red = 0,
        Orange,
        Yellow,
        Green,
        Turquoise,
        Blue,
        Violet
    };

    switch(number_color)
    {
        case(Red):
            cout << "This color is Red. It from rainbow.";
            break;
        case(Orange):
            cout << "This color is Orange. It from rainbow.";
            break;
        case(Yellow):
            cout << "This color is Yellow. It from rainbow.";
            break;
        case(Green):
            cout << "This color is Green. It from rainbow.";
            break;
        case(Turquoise):
            cout << "This color is Turquoise. It from rainbow.";
            break;
        case(Blue):
            cout << "This color is Blue. It from rainbow.";
            break;
        case(Violet):
            cout << "This color is Violet. It from rainbow.";
            break;
        default: cout << "This color is not from rainbow";
    }
}


int main()
{
    int number_of_your_color = 0;
    cout << "Print any number: ";
    cin >> number_of_your_color;
    Check_for_right_color(number_of_your_color);
    return 0;
}
