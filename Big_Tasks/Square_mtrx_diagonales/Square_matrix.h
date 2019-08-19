#ifndef TESTPROGRAMMS_SQUARE_MATRIX_H
#define TESTPROGRAMMS_SQUARE_MATRIX_H

#include <memory>
#include <fstream>
#include <iomanip>
using namespace std;

class Square_matrix{
public:
    using arr_ptr_type = unique_ptr<int[]>;
private:
    int size_matrix;
    unique_ptr<arr_ptr_type []> sqr_matrix;
public:
    Square_matrix(int& curr_size): size_matrix(curr_size), sqr_matrix(make_unique<arr_ptr_type []>(size_matrix))
    {
        for(int i = 0; i < size_matrix; i++)
            sqr_matrix[i] = make_unique<int []>(size_matrix);
    }

    int& Element(int i, int j){
        return sqr_matrix[i][j];
    }

    int get_size_sqr_matrix() {return size_matrix;}
};

void Fill_matrix(Square_matrix& curr_matrix, ifstream& in);
void Display_matrix(Square_matrix& curr_matrix, ofstream& out);
void Min_element_indexes(Square_matrix& curr_matrix, int& min_i, int& min_j);
void Max_element_indexes(Square_matrix& curr_matrix, int& max_i, int& max_j);
void Exchange(Square_matrix& curr_matrix, int& min_i, int& min_j, int& max_i, int& max_j);
#endif
