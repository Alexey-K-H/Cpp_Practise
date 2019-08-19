#include <iostream>

using namespace std;

#include "Square_matrix.h"

int main()
{
    ifstream input_1;
    input_1.open("input1.txt", ios_base:: in);
    ofstream log;
    log.open("log.txt", ios_base:: out);
    ofstream output_1;
    output_1.open("output1.txt", ios_base:: out);

    if(!input_1.is_open()){
        log << "Error! Cannot open input file!" << endl;
    }
    else
    {
        cout << "Enter the size of square matrix:";
        int size = 0;
        cin >> size;

        Square_matrix matrix(size);
        Fill_matrix(matrix, input_1);
        Display_matrix(matrix, output_1);

        int min_i = 0;
        int min_j = 0;

        int max_i = 0;
        int max_j = 0;

        Min_element_indexes(matrix, min_i, min_j);
        Max_element_indexes(matrix, max_i, max_j);

        output_1 << "min[" << min_i << "][" << min_j << "] = " << matrix.Element(min_i, min_j) << endl;
        output_1 << "max[" << max_i << "][" << max_j << "] = " << matrix.Element(max_i, max_j) << endl;

        Exchange(matrix, min_i, min_j, max_i, max_j);
        output_1 << endl;
        output_1 << "After exchange min and max:" << endl;
        Display_matrix(matrix, output_1);

        output_1 << "min[" << max_i << "][" << max_j << "] = " << matrix.Element(max_i, max_j) << endl;
        output_1 << "max[" << min_i << "][" << min_j << "] = " << matrix.Element(min_i, min_j) << endl;
    }

    input_1.close();
    log.close();
    output_1.close();
    return 0;
}
