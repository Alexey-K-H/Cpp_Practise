#include "Matrix.h"

using namespace std;

void Interface_menu(){
    cout << "<Menu>" << endl;
    cout << "Load matrix from file: 1" << endl;
    cout << "Display matrix in file: 2" << endl;
    cout << "Summary of two matrix: 3" << endl;
    cout << "Multiple of two matrix: 4" << endl;
}

void Display_matrix_from_input_file(ifstream& in, ofstream& out){
    int count_raws = 0;
    in >> count_raws;
    int count_columns = 0;
    in >> count_columns;

    out << "Matrix from file \"input.txt\"" << endl;
    int curr_element = 0;
    for(int i = 0; i < count_raws; i++){
        for(int j = 0; j < count_columns; j++){
            in >> curr_element;
            out << setw(2) << curr_element;
        }
        out << endl;
    }
}

void Multiple_matrix(ifstream& in, ofstream& out){
    out << "Enter the first matrix" << endl;

    out << "Enter count of raws:";
    int first_matrix_raws_count = 0;
    in >> first_matrix_raws_count;
    out << first_matrix_raws_count << endl;

    out << "Enter count of columns:";
    int first_matrix_columns_count = 0;
    in >> first_matrix_columns_count;
    out << first_matrix_columns_count << endl;

    Matrix<int> first_matrix(first_matrix_raws_count, first_matrix_columns_count);
    Fill_Matrix(first_matrix, in, out);
    out << endl;
    out << "Enter the second matrix" << endl;

    out << "Attention! Count of raws of the second matrix should be the same as count of columns of the first matrix" << endl;
    out << "Count of raws will be setup automatically" << endl;
    out << "Count of raws:";
    out << first_matrix_columns_count << endl;

    out << "Enter count of columns:";
    int second_matrix_columns_count = 0;
    in >> second_matrix_columns_count;
    out << second_matrix_columns_count << endl;

    Matrix<int> second_matrix(first_matrix_columns_count, second_matrix_columns_count);
    Fill_Matrix(second_matrix, in, out);
    out << endl;

    Matrix<int> result_matrix(first_matrix_raws_count, second_matrix_columns_count);
    out << "Result of multiple is:" << endl;
    for(size_t i = 0; i < first_matrix.getRowCount(); ++i){
        for(size_t j = 0; j < second_matrix.getColCount(); ++j){
            result_matrix.Element(i, j) = 0;
            for(size_t k = 0; k < first_matrix.getColCount(); k++){
                result_matrix.Element(i,j) += first_matrix.Element(i, k)*second_matrix.Element(k, j);
            }
        }
    }
    Display_matrix(result_matrix, out);
}
