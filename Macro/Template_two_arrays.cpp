#include <iostream>
#include <vector>
using namespace std;

/*Реализовать шаблон класса, хранящий 2 массива элементов с типами
 которые опередлены в списке параметров шаблона класса*/

template <typename Type_1, typename Type_2>
class Arrays
{
private:
    vector<Type_1> Array_1;
    vector<Type_2> Array_2;
public:
    void Fill_first_arr()//Поместить элемент в первый массив
    {
        int k = 0;
        while (k < 10){
            cout << "Enter the [" << k << "] element of array:";
            Type_1 value;
            cin >> value;
            Array_1.push_back(value);
            k++;
        }
        cout << endl;
    }
    void Fill_second_arr()//Поместить элемент во второй массив
    {
        for(int m = 0; m < 10; m++){
            cout << "Enter the [" << m << "] element of array:";
            Type_2 value;
            cin >> value;
            Array_2.push_back(value);
        }
        cout << endl;

    }
    void Print_arrays()//Вывести оба массива
    {
        cout << "Print array_1:" << endl;
        for(int i = 0; i < 10; i++)
            cout << "First_arr[" << i << "]: " << Array_1[i] << endl;
        cout << endl;

        cout << "Print array_2:" << endl;
        for(int j = 0; j < 10; j++)
            cout << "Second_arr[" << j << "]:" << Array_2[j] << endl;
        cout << endl;
    }
};


int main()
{
    //Размеры массивов равны 10
    Arrays<int, float> INt_Float_arrays;
    INt_Float_arrays.Fill_first_arr();
    INt_Float_arrays.Fill_second_arr();
    INt_Float_arrays.Print_arrays();

    Arrays<string, short> Str_Short_arrays;
    Str_Short_arrays.Fill_first_arr();
    Str_Short_arrays.Fill_second_arr();
    Str_Short_arrays.Print_arrays();

    return 0;
}
