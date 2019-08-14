#include "Matrix.h"
using namespace std;

int main()
{
    Interface_menu();
    cout << "Choose action:";
    int user_choice = 0;
    cin >> user_choice;

    ifstream in;
    in.open("input.txt", ios_base:: in);
    ofstream out;
    out.open("output.txt", ios_base:: out);
    if(!in.is_open()){
        out << "Cannot open input file" << endl;
    }
    else{

        switch (user_choice){
            case 1:{
                out << "Enter count of raws: ";
                int raws_count = 0;
                in >> raws_count;
                out << raws_count << endl;

                out << "Enter count of columns: ";
                int column_count = 0;
                in >> column_count;
                out << column_count << endl;

                Matrix<int> user_matrix(raws_count, column_count);
                Fill_Matrix(user_matrix, in, out);
                break;
            }
            case 2:{
                Display_matrix_from_input_file(in, out);
                break;
            }
            case 3:{
                out << "Enter the first matrix" << endl;
                out << endl;
                int first_matrix_raws_count = 0;
                in >> first_matrix_raws_count;
                int first_matrix_columns_count = 0;
                in >> first_matrix_columns_count;

                Matrix<int> first_matrix(first_matrix_raws_count, first_matrix_columns_count);
                Fill_Matrix(first_matrix, in, out);
                out << endl;
                out << "Addition is possible only with a matrix of the same size" << endl;
                out << endl;
                out << "Enter the second matrix" << endl;
                out << endl;
                Matrix<int> second_matrix(first_matrix_raws_count, first_matrix_columns_count);
                Fill_Matrix(second_matrix, in, out);

                Matrix<int> result_matrix(first_matrix_raws_count, first_matrix_columns_count);
                Summary(first_matrix, second_matrix, result_matrix, out);
                break;
            }
            case 4:{
                Multiple_matrix(in, out);
                break;
            }
            default:{
                cout << "Wrong input!" << endl;
            }
        }
    }
    in.close();
    out.close();
    return 0;
}
