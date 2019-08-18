#include "Matrix_data.h"

void Interface(){
    cout << "<Menu>" << endl;
    cout << "Summary press: 1" << endl;
    cout << "Differ press: 2" << endl;
    cout << "Multiple press: 3" << endl;
}

void Fill_matrix(Matrix& curr_matrix, ifstream& in){
    cout << "Fill matrix...";
    for(int i = 0; i < curr_matrix.get_Raws_count(); i++){
        for(int j = 0; j < curr_matrix.get_Column_count(); j++){
            in >> curr_matrix.Element(i,j);
        }
    }
    cout << "...Done" << endl;
}

void Display_matrix(Matrix& curr_matrix, ofstream& out){
    for(int i = 0; i < curr_matrix.get_Raws_count(); i++){
        for(int j = 0; j < curr_matrix.get_Column_count(); j++){
            out << setw(3) << curr_matrix.Element(i,j) << " ";
        }
        out << endl;
    }
}

void Summary(Matrix& first_matrix, Matrix& second_matrix, Matrix& result){
    for(int i = 0; i < result.get_Raws_count(); i++){
        for(int j = 0; j < result.get_Column_count(); j++){
            result.Element(i,j) = first_matrix.Element(i,j) + second_matrix.Element(i,j);
        }
    }
}

void Differ(Matrix& first_matrix, Matrix& second_matrix, Matrix& result){
    for(int i = 0; i < result.get_Raws_count(); i++){
        for(int j = 0; j < result.get_Column_count(); j++){
            result.Element(i,j) = first_matrix.Element(i,j) - second_matrix.Element(i,j);
        }
    }
}

void Multiple(Matrix& first_matrix, Matrix& second_matrix, Matrix& result){
    for(int i = 0; i < first_matrix.get_Raws_count(); i++){
        for(int j = 0; j < second_matrix.get_Column_count(); j++){
            result.Element(i,j) = 0;
            for(int k = 0; k < first_matrix.get_Column_count(); k++){
                result.Element(i,j) += first_matrix.Element(i, k)*second_matrix.Element(k, j);
            }
        }
    }
}
