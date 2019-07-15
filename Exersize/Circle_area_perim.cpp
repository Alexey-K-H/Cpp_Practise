#include <iostream>
#include <cmath>

using namespace std;
//Напишите класс Circle , который вычисляет площадь и периметр по радиусу,
//который передается классу в качестве параметра при создании экземпляра.

class Circle
{
private:
    double pi_Value;
    double radius;
public:
    Circle()
    {
        pi_Value = M_PI;
        radius = 0;
    }

    void Get_radius(double radius_value){
        radius = radius_value;
    }

    void Get_Area(){
        cout << "Area of the circle is: " << pow(radius, 2)*pi_Value << endl;
    }

    void Get_Perimeter(){
        cout << "Perimeter of the circle is: " << radius*2*pi_Value << endl;
    }
};

int main()
{
    cout << "Enter the radius of the circle:";
    double radius = 0;
    cin >> radius;

    Circle* newCircle = new Circle;
    newCircle -> Get_radius(radius);
    newCircle -> Get_Area();
    newCircle ->Get_Perimeter();

    delete(newCircle);
    return 0;
}
