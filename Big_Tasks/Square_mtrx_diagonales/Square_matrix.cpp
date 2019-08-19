#include "Square_matrix.h"

void Fill_matrix(Square_matrix& curr_matrix, ifstream& in){
    for(int i = 0; i < curr_matrix.get_size_sqr_matrix(); i++){
        for(int j = 0; j < curr_matrix.get_size_sqr_matrix(); j++){
            in >> curr_matrix.Element(i,j);
        }
    }
}

void Display_matrix(Square_matrix& curr_matrix, ofstream& out){
    for(int i = 0; i < curr_matrix.get_size_sqr_matrix(); i++){
        for(int j = 0; j < curr_matrix.get_size_sqr_matrix(); j++){
            out << setw(3) << curr_matrix.Element(i,j) << " ";
        }
        out << endl;
    }
}

void Min_element_indexes(Square_matrix& curr_matrix, int& min_i, int& min_j){
    int min_elem = curr_matrix.Element(1,0);
    for(int i = 1; i < curr_matrix.get_size_sqr_matrix(); i++){
        for(int j = 0; j < i; j++){
            if(curr_matrix.Element(i,j) < min_elem)
            {
                min_elem = curr_matrix.Element(i,j);
                min_i = i;
                min_j = j;
            }
        }
    }
}

void Max_element_indexes(Square_matrix& curr_matrix, int& max_i, int& max_j){
    int max_element = curr_matrix.Element(0, 0);
    for(int i = 0; i < curr_matrix.get_size_sqr_matrix(); i++){
        for(int j = 0; j < curr_matrix.get_size_sqr_matrix() - i; j++){
            if(curr_matrix.Element(i,j) > max_element)
            {
                max_element = curr_matrix.Element(i,j);
                max_i = i;
                max_j = j;
            }
        }
    }
}

void Exchange(Square_matrix& curr_matrix, int& min_i, int& min_j, int& max_i, int& max_j){
    int tmp = curr_matrix.Element(min_i, min_j);
    curr_matrix.Element(min_i, min_j) = curr_matrix.Element(max_i, max_j);
    curr_matrix.Element(max_i, max_j) = tmp;
}
