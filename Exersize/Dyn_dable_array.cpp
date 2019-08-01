#include <iostream>
#include <ctime>
#include <iomanip>
#include <cassert>
using namespace std;
/*Составить программу, которая будет генерировать случайные числа в интервале [a;b] и заполнять ими двумерный массив размером 10 на 10.
 *В массиве необходимо найти номер строки с минимальным элементом.
 *Поменять строки массива местами, строку с минимальным элементом и первую строку массива. Организовать удобный вывод на экран.*/

//Random_value creator
float RandomFloat(const float& a, const float& b){
    assert(b > a);
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void Display_array(float ** array)
{
    for(int count_row = 0; count_row < 10; count_row++)
    {
        for(int count_column = 0; count_column < 10; count_column++)
            cout << "<" << setw(4) << setprecision(3) << array[count_row][count_column] << ">  ";
        cout << endl;
    }
}

//Exchange 1st row and row with min element
void Exchange_first_and_min(int row_min, float ** array)
{
    auto *tmp_row = new float [10];
    for(int j = 0; j < 10; j++)
        tmp_row[j] = array[row_min][j];
    for(int f_row_ind = 0; f_row_ind < 10; f_row_ind++)
        array[row_min][f_row_ind] = array[0][f_row_ind];
    for(int f_row_ind = 0; f_row_ind < 10; f_row_ind++)
        array[0][f_row_ind] = tmp_row[f_row_ind];

    delete[](tmp_row);
}

void Find_min_and_exchange(float ** curr_array, const float b_value)
{
    float min = b_value;
    int min_index_row = 0;
    for(int count_row = 0; count_row < 10; count_row++)
        for(int count_column = 0; count_column < 10; count_column++)
        {
            if(min > curr_array[count_row][count_column])
            {
                min = curr_array[count_row][count_column];
                min_index_row = count_row;
            }
        }

    cout << "Row number with min element:" << min_index_row << endl;
    cout << "Min element:" << min << endl;

    Exchange_first_and_min(min_index_row, curr_array);

}

void Create_array(const float& num_a, const float& num_b)
{
    srand(time(nullptr));
    //Create array
    auto **ptr_array = new float* [10];
    for(int count = 0; count < 10; count++)
        ptr_array[count] = new float [10];

    //Fill array
    for(int count_row = 0; count_row < 10; count_row++)
        for(int count_column = 0; count_column < 10; count_column++)
            ptr_array[count_row][count_column] = RandomFloat(num_a, num_b);

    Display_array(ptr_array);

    //Find min
    Find_min_and_exchange(ptr_array, num_b);

    //After exchange
    Display_array(ptr_array);

    //Delete array
    for(int count = 0; count < 10; count++)
        delete[](ptr_array[count]);
}

int main()
{
    cout << "Enter number a:";
    float a = 0;
    cin >> a;
    cout << "Enter number b:";
    float b = 0;
    cin >> b;
    Create_array(a, b);
    return 0;
}
