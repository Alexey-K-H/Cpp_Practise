#include <iostream>
#include <cmath>

using namespace std;
// Напишите программу ,
// в которой по извесной начальной скорости V и времени полета тела T определяется угол aльфа,
// под которым тело брошено по отношению к горизонту (воспользуйтесь соотношением a = arcsin(gT/2V) ).

void Get_value_of_Ugol(float speed, float time){
    float ugol_Value = 0;
    float g_value = 9.8;
    ugol_Value = asin((g_value*time)/(2*speed));
    cout << "Result is: " << ugol_Value * 180/M_PI;
}

int main()
{
    cout << "Enter the speed of the object:";
    float speed = 0;
    cin >> speed;

    cout << "Enter the time of the way:";
    float time = 0;
    cin >> time;

    Get_value_of_Ugol(speed, time);

    return 0;
}
