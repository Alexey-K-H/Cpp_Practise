#include <iostream>
#include <cmath>
/*вычислить объемы сферы и циилндра,
 используя перегруженные функции*/

using namespace std;

void Volume(double radius, double& result_sphere){
    result_sphere = (4*M_PI*radius*radius*radius)/3;
}

void Volume(double radius, double height, double& result_cylinder){
    result_cylinder = M_PI * radius * radius * height;
}

int main() {

    cout << "Enter the radius of sphere: ";
    double radius = 0;
    cin >> radius;

    if(radius <= 0){
        cout << "Bad input";
    }
    else{
        double sphere_valume = 0;
        Volume(radius, sphere_valume);
        cout << "Volume of the sphere is: " << sphere_valume << endl;
    }

    cout << "Enter the radius of the cylinder: ";
    double radius_2 = 0;
    cin >> radius_2;

    cout << "Enter the height of the cylinder: ";
    double height = 0;
    cin >> height;

    if(radius_2 <=0 && height <= 0){
        cout << "Bad input";
    }
    else{
        double cylinder_volume = 0;
        Volume(radius_2, height, cylinder_volume);
        cout << "Volume of the cylinder: " << cylinder_volume << endl;
    }
    
    return 0;
}
