#include <iostream>
#include <memory>
using namespace std;
/*Создание матрицы путем умных указаетлей*/

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

int main()
{
    Matrix<int> user_matrix(5,5);//матрица 5x5
    //Заполняем матрицу значениями равными сумме индексов ячеек
    for(size_t i = 0; i < user_matrix.getRowCount(); i++){
        for(size_t j = 0; j < user_matrix.getColCount(); j++){
            user_matrix.Element(i,j) = i+j;
            cout << user_matrix.Element(i,j) << ' ';
        }
        cout << endl;
    }
}
