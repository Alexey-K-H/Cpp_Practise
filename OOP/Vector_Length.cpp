#include <iostream>
#include <cmath>
#include <vector>

// Напишите программу,
// которая позволяет пользователю ввести в консоль три координаты вектора x, y, и z, с основанием у начала координат.
// Вычислите длину этого вектора и выведите её обратно в консоль.
using namespace std;

class Vector
{
private:
    int metrik;//Размернсть
    vector<double> corDinate;//Координаты вектора
    double length_of_the_Vector;
public:
    Vector()
    {
        metrik = 0;
        length_of_the_Vector = 0;
    }

    void Set_Metrik_of_the_vector(int vector_metrik){
        metrik = vector_metrik;
    }

    void Set_Cordinates_of_the_Vector(){
        int index_coord = 0;
        while(metrik > 0){
            cout << "Print the " << index_coord << " coordinate of the vector: ";
            double curr_coordinate = 0;
            cin >> curr_coordinate;
            corDinate.push_back(pow(curr_coordinate, 2));
            metrik--;
            index_coord++;
        }
    }

    void Give_the_length_of_the_vector(){
        int index = corDinate.size() - 1;
        double result = 0;
        while (index >= 0){
            result += corDinate[index];
            index--;
        }
        length_of_the_Vector = sqrt(result);
        cout << "The length of the Vector is: " << length_of_the_Vector;
    }
};

int main()
{
    cout << "Enter the Metrik of your vector_space: ";
    int metrika = 0;
    cin >> metrika;

    Vector* user_Vector = new Vector;
    user_Vector->Set_Metrik_of_the_vector(metrika);
    user_Vector->Set_Cordinates_of_the_Vector();
    user_Vector->Give_the_length_of_the_vector();
    return 0;
}
