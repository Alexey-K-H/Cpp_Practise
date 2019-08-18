#ifndef TESTPROGRAMMS_MATRIX_DATA_H
#define TESTPROGRAMMS_MATRIX_DATA_H

#include <iostream>
#include <memory>
#include <fstream>
#include <iomanip>

using namespace std;

class Matrix{
public:
    using arr_ptr_type = unique_ptr<float[]>;
private:
    int raws_count;
    int column_count;
    unique_ptr<arr_ptr_type []> matrix;
public:
    Matrix(int& count_raws, int& count_column): raws_count(count_raws), column_count(count_column), matrix(make_unique<arr_ptr_type []>(raws_count))
    {
        for(int i = 0; i < raws_count; i++)
            matrix[i] = make_unique<float []>(column_count);
    }

    float& Element(int i, int j){
        return matrix[i][j];
    }

    int get_Raws_count() {return raws_count;}
    int get_Column_count() {return column_count;}
};
void Interface();
void Fill_matrix(Matrix& curr_matrix, ifstream& in);
void Display_matrix(Matrix& curr_matrix, ofstream& out);
void Summary(Matrix& first_matrix, Matrix& second_matrix, Matrix& result);
void Differ(Matrix& first_matrix, Matrix& second_matrix, Matrix& result);
void Multiple(Matrix& first_matrix, Matrix& second_matrix, Matrix& result);
#endif
