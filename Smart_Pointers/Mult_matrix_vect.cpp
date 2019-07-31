#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;
/*Нужно вычислить произведение матрицы на вектор. В полученном векторе найти макисмальный  элемент.*/

//Создание матрицы с помощью умных указаетлей
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

template <typename Matrix_type>
void Fill_matrix(Matrix<Matrix_type>& matrix){
    for(size_t i = 0; i < matrix.getRowCount(); i++){
        for(size_t j = 0; j < matrix.getColCount(); j++){
            matrix.Element(i,j) = rand() % 10;
        }
    }
}

template <typename Type_matrix>
void Display_Matrix(Matrix<Type_matrix>& matrix){
    cout << "<User matrix>" << endl;
    for(size_t i = 0; i < matrix.getRowCount(); i++){
        for(size_t j = 0; j < matrix.getColCount(); j++){
            cout << matrix.Element(i,j) << ' ';
        }
        cout << endl;
    }
}

template<typename Vector_type>
void Fill_vector(vector<Vector_type>& vector){
    for(int element = 0; element != vector.size(); element++)
    {
        cout << "Enter the [" << element + 1 << "] of the vector:";
        int curr_element = 0;
        cin >> curr_element;
        vector[element] = curr_element;
    }
}

template<typename Type_vec>
void Display_vector(vector<Type_vec>& vector){
    for(int element = 0; element != vector.size(); element++)
        cout << vector[element] << endl;
}

template <typename Type>
void Multiple(Matrix<Type>& user_matrix, vector<Type>& user_vector){
    vector<int> result(user_matrix.getRowCount(), 0);
        for(size_t i = 0; i < user_matrix.getRowCount(); i++){
            int curr_vector_val = 0;
            for(size_t j = 0; j < user_matrix.getColCount(); j++){
                curr_vector_val += user_matrix.Element(i,j)*user_vector[j];
            }
            result[i] = curr_vector_val;
        }
    cout << "<Result vector>" << endl;
    Display_vector(result);
    int max = *max_element(result.begin(), result.end());
    cout << "Max element in result vector: " << max << endl;
}

int main()
{
    cout << "Print count of raws:";
    int count_raw = 0;
    cin >> count_raw;
    cout << "Print count of columns:";
    int count_column = 0;
    cin >> count_column;
    Matrix<int> user_matrix(count_raw, count_column);
    Fill_matrix(user_matrix);

    vector<int> user_vector(count_column, 0);
    Fill_vector(user_vector);

    Display_Matrix(user_matrix);
    cout << "<User vector>" << endl;
    Display_vector(user_vector);

    Multiple(user_matrix, user_vector);
    return 0;
}
