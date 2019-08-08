#include <iostream>
#include <fstream>
using namespace std;
#include "Matrix.h"
/*Выполнить преобразование матрицы, а именно — перестановку строк и столбцов.
 * Для  квадратной матрицы размером n переставляйте столбцы и строки таким образом,
 * чтобы элемент матрицы с наибольшим значением, по модулю, располагался в нижнем правом углу матрицы.*/
int main()
{
    ifstream input;
    input.open("Matrix_val", ios_base::in);

    ofstream output;
    output.open("Output", ios_base::out);

    if(!input.is_open())
    {
        output << "Error. File doesn't exist!" << endl;
    }
    else {
        output << "Enter the size of matrix: ";
        int size = 0;
        input >> size;
        output << size << endl;
        Create_Matrix(size, input, output);
    }
    input.close();
    return 0;
}
