#include <iostream>

using namespace std;
/*Разработать программу для обработки матриц. 
Программа должна выполнять следующие действия: суммы, вычитания, умножения двух матриц. 
Матрицы должны храниться в двух разных файлах. 
То есть, при запуске программы, необходимо считать из файлов две матрицы и уже после этого производить вычисления. 
Результат вывести на экран.*/
/*При выборе дейсвтия использовалось умножение считанных матриц*/
#include "Matrix_data.h"

int main()
{
    ifstream input_1;
    input_1.open("input1.txt", ios_base:: in);
    ifstream input_2;
    input_2.open("input2.txt", ios_base:: in);

    ofstream log_file;
    log_file.open("log.txt", ios_base:: out);

    ofstream output_1;
    output_1.open("output1.txt", ios_base:: out);

    if(!input_1.is_open()){
        log_file << "Cannot open input_1 file!" << endl;
    }else if(!input_2.is_open()){
        log_file << "Cannot open input_2 file!" << endl;
    }else{
        cout << "<Enter the first matrix>" << endl;
        cout << "Enter count of raws:";
        int first_raws_count = 0;
        cin >> first_raws_count;
        cout << "Enter count of columns:";
        int first_columns_count = 0;
        cin >> first_columns_count;
        Matrix first_matrix(first_raws_count, first_columns_count);
        Fill_matrix(first_matrix, input_1);

        cout << "<Enter the second matrix>" << endl;
        cout << "Enter count of raws:";
        int second_raws_count = 0;
        cin >> second_raws_count;
        cout << "Enter count of columns:";
        int second_columns_count = 0;
        cin >> second_columns_count;
        Matrix second_matrix(second_raws_count, second_columns_count);
        Fill_matrix(second_matrix, input_2);

        Interface();
        cout << "Choose action:";
        int choice = 0;
        cin >> choice;
        switch (choice){
            case 1:{
                if(first_matrix.get_Raws_count() != second_matrix.get_Raws_count()
                || first_matrix.get_Column_count() != second_matrix.get_Column_count()){
                    cout << "Error! More information if log file" << endl;
                    log_file << "You cannot sum matrix with different size!" << endl;
                }else{
                    Matrix result(first_raws_count, first_columns_count);
                    Summary(first_matrix, second_matrix, result);
                    Display_matrix(result, output_1);
                }
                break;
            }
            case 2:{
                if(first_matrix.get_Raws_count() != second_matrix.get_Raws_count()
                   || first_matrix.get_Column_count() != second_matrix.get_Column_count()){
                    cout << "Error! More information if log file" << endl;
                    log_file << "You cannot differ matrix with different size!" << endl;
                }else{
                    Matrix result(first_raws_count, first_columns_count);
                    Differ(first_matrix, second_matrix, result);
                    Display_matrix(result, output_1);
                }
                break;
            }
            case 3:{
                if(first_matrix.get_Column_count() != second_matrix.get_Raws_count()){
                    cout << "Error! More information in log file" << endl;
                    log_file << "The number of columns of the first matrix should be equal to the number of rows of the second" << endl;
                }else{
                    Matrix result(first_raws_count, second_columns_count);
                    Multiple(first_matrix, second_matrix, result);
                    Display_matrix(result, output_1);
                }
                break;
            }
            default:{
                cout << "Bad input!" << endl;
            }
        }
    }
    return 0;
}
