#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H
#include <fstream>
#include <memory>
#include <iomanip>
#include <iostream>
using namespace std;

void Interface_menu();

template<class Type>
class Matrix{
public:
    using num_type = Type;//using - идентифиатор типа
    using size_type = size_t;
    using arr_ptr_type = unique_ptr<num_type[]>;
private:
    size_type n;//Количество строк
    size_type m;//Количество столбцов
    unique_ptr<arr_ptr_type []> a;//Указатель на матрицу
public:
    Matrix(size_type n, size_type m): n(n), m(m), a(make_unique<arr_ptr_type []>(n))
    {
        for(size_type i = 0; i < n; i++)
            a[i] = make_unique<num_type []>(m);
    }
    //Функция, возвращающее значение в матрице
    num_type& Element(size_type i, size_type j){
        return a[i][j];
    }

    size_type getRowCount(){ return n;}
    size_type getColCount(){ return m;}
};

void Display_matrix_from_input_file(ifstream& in, ofstream& out);

//Выносить реализацию шаблонов из header-файла нельзя!
template <typename Type>
void Fill_Matrix(Matrix<Type>& matrix, ifstream& in, ofstream& out){
    for(size_t i = 0; i < matrix.getRowCount(); i++){
        for(size_t j = 0; j < matrix.getColCount(); j++){
            out << "Enter matrix element [" << i << "][" << j << "] :";
            in >> matrix.Element(i,j);
            out << setw(2) <<  matrix.Element(i,j) << endl;
        }
    }
}

template <typename Matrix_type>
void Display_matrix(Matrix<Matrix_type>& matrix, ofstream& out){
    for(int i =  0; i < matrix.getRowCount(); i++){
        for(int j = 0; j < matrix.getColCount(); j++){
            out << setw(2) << matrix.Element(i,j) << " ";
        }
        out << endl;
    }
}

template  <typename Type_matrix>
void Summary(Matrix<Type_matrix>& first_matrix, Matrix<Type_matrix>& second_matrix, Matrix<Type_matrix>& result_matrix,
        ofstream& out){
    for(int i = 0; i < result_matrix.getRowCount(); i++){
        for(int j = 0; j < result_matrix.getColCount(); j++){
            result_matrix.Element(i,j) = first_matrix.Element(i,j) + second_matrix.Element(i, j);
        }
    }
    out << endl;
    out << "Result of summary is:" << endl;
    Display_matrix(result_matrix, out);
}

void Multiple_matrix(ifstream& in, ofstream& out);
#endif
