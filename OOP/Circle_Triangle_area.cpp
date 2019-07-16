#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
//Вы моделируете формы (круг и треугольник) и хотите, чтобы каждый из этих
//классов обязательно реализовывал функции A r e a () и P r i n t ().

class Shape
{
public:
    virtual void Area() = 0;
    virtual void Print() = 0;
};

class Circle final: public Shape
{
private:
    double pi_value = M_PI;
    double radius = 0;
public:
    void Get_radius(double circle_rad){
        radius = circle_rad;
    }

    void Print() override {
        cout << "Your shape is Circle" << endl;
    }

    void Area() override {
        cout << "Enter your radius:";
        double radius_Circle = 0;
        cin >> radius_Circle;
        if(radius_Circle < 0){
            cout << "Bad input" << endl;
        }
        else {
            Get_radius(radius_Circle);
            double area = 0;
            area = radius * radius * pi_value;
            cout << "Area of the Circle is: " << area << endl;
        }
    }
};

class Polygon: public Shape{};

class Triangle final: public Polygon
{
private:
    vector<double> sides_Triangle = vector<double> (3,0);
public:
    void Print() override {
        cout << "Your polygon is Triangle:" << endl;
    }

    static int Is_Triangle_viable(vector<double>& sides_triangle){
        if(sides_triangle[0] > sides_triangle[1] + sides_triangle[2])
            return 0;
        if(sides_triangle[1] > sides_triangle[0] + sides_triangle[2])
            return 0;
        if(sides_triangle[2] > sides_triangle[0] + sides_triangle[1])
            return 0;
        return 1;
    }

    static void Get_sides_of_triangle(vector<double>& sides){
        for(int index = 0, number = 1; index < 3; index++, number++){
            double curr_side = 0;
            cout << "Print the " << number << " side:";
            cin >> curr_side;
            if(curr_side < 0){
                cout << "Bad input" << endl;
                break;
            }
            sides[index] = curr_side;
        }
    }

    void Area() override {
        cout << "Enter the sides of your triangle:" << endl;
        Get_sides_of_triangle(sides_Triangle);
        if(!Is_Triangle_viable(sides_Triangle)){
            cout << "Triangle with this sides is not viable!" << endl;
        }
        else{
            double half_Perimeter = 0;
            for(int i = 0; i < 3; i++)
                half_Perimeter += (sides_Triangle[i]/2);
            double tmp_area = half_Perimeter;
            for(int j = 0; j < 3; j++)
                tmp_area *= (half_Perimeter - sides_Triangle[j]);
            double area = 0;
            area = sqrt(tmp_area);
            cout << "The area of your triangle is: " << area << endl;
        }
    }
};

void Get_Information(Shape& inputShape){
    inputShape.Print();
    inputShape.Area();
}

int main()
{
    Circle myShape_1;
    Triangle myPolygon_1;

    Get_Information(myShape_1);
    Get_Information(myPolygon_1);

    return 0;
}
