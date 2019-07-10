#include <iostream>
#include <cmath>
//Передача аргументов по ссылке
//Вычисление площади круга
using namespace std;

//Выходной параметр result передается по ссылке
void Area(double radius, double& result){
    result = M_1_PI * pow(radius, 2);
}

int main() {
    cout << "Enter the radius: ";
    double radius = 0;
    cin >> radius;

    double area = 0;
    Area(radius, area);

    cout << "Area is: " << area << endl;
    return 0;
}
