#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

void Display_matrix(int **matrix, int& size_mtr, ofstream& output){
    for(int raw_cnt = 0; raw_cnt < size_mtr; raw_cnt++)
    {
        for(int column_cnt = 0; column_cnt < size_mtr; column_cnt++)
            output << setw(2) << matrix[raw_cnt][column_cnt];
        output << endl;
    }
}

void Find_location_max_elem(int **matrix, int& size_matrix, int& raw_num, int& column_num, ofstream& out){
    int max_value = 0;
    for(int raw_cnt = 0; raw_cnt < size_matrix; raw_cnt++) {
        for (int column_cnt = 0; column_cnt < size_matrix; column_cnt++) {
            if (abs(matrix[raw_cnt][column_cnt]) > max_value)
            {
                max_value = matrix[raw_cnt][column_cnt];
                raw_num = raw_cnt;
                column_num = column_cnt;
            }
        }
    }
    out << "Max ABS value: " << max_value << " Located in position: [" << raw_num << "][" << column_num << "]" << endl;
}

void Replace_raws(int **matrix, int& size_matrix, int& raw_num_max_val){
    if(raw_num_max_val == size_matrix - 1)
        return;
    else{
        auto *tmp_raw = new int [size_matrix];
        for(int i = 0; i < size_matrix; i++){
            tmp_raw[i] = matrix[raw_num_max_val][i];
        }

        for(int i = 0; i < size_matrix; i++){
            matrix[raw_num_max_val][i] = matrix[size_matrix - 1][i];
        }

        for(int i = 0; i < size_matrix; i++){
            matrix[size_matrix- 1][i] = tmp_raw[i];
        }

        delete[](tmp_raw);
    }
}

void Replace_column(int **matrix, int& size_matrix, int& column_num_max_val){
    if(column_num_max_val == size_matrix - 1)
        return;
    else{
        auto *tmp_column = new int [size_matrix];
        for(int i = 0; i < size_matrix; i++){
            tmp_column[i] = matrix[i][column_num_max_val];
        }

        for(int i = 0; i < size_matrix; i++){
            matrix[i][column_num_max_val] = matrix[i][size_matrix - 1];
        }

        for(int i = 0; i < size_matrix; i++){
            matrix[i][size_matrix - 1] = tmp_column[i];
        }

        delete[](tmp_column);
    }
}

void Create_Matrix(int& size_matrix, ifstream& input, ofstream& output){
    auto **matrix = new int* [size_matrix];
    for(int i = 0; i < size_matrix; i++)
        matrix[i] = new int [size_matrix];

    for(int raw_cnt = 0; raw_cnt < size_matrix; raw_cnt++)
        for(int column_cnt = 0; column_cnt < size_matrix; column_cnt++)
        {
            output << "Enter current value of the matrix [" << raw_cnt << "][" << column_cnt << "]: ";
            int curr_num = 0;
            input >> curr_num;
            output << curr_num << endl;
            matrix[raw_cnt][column_cnt] = curr_num;
        }

    output << "Primal matrix" << endl;
    Display_matrix(matrix, size_matrix, output);

    int raw_num_max_val = 0;
    int column_num_max_val = 0;
    Find_location_max_elem(matrix, size_matrix, raw_num_max_val, column_num_max_val, output);

    output << "First iteration" << endl;
    Replace_raws(matrix, size_matrix, raw_num_max_val);
    Display_matrix(matrix, size_matrix, output);

    output << "Second iteration" << endl;
    Replace_column(matrix, size_matrix, column_num_max_val);
    Display_matrix(matrix, size_matrix, output);
    output << "Task complete" << endl;
    for(int count = 0; count < size_matrix; count++)
        delete[](matrix[count]);
}
