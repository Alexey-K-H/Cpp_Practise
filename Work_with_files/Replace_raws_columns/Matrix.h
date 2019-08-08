#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H
void Create_Matrix(int& size_matrix, ifstream& input, ofstream& output);
void Display_matrix(int **matrix, int& size_mtr, ofstream& output);
void Find_location_max_elem(int **matrix, int& size_matrix, int& raw_num, int& column_num, ofstream& out);
void Replace_raws(int **matrix, int& size_matrix, int& raw_num_max_val);
void Replace_column(int **matrix, int& size_matrix, int& column_num_max_val);
#endif
