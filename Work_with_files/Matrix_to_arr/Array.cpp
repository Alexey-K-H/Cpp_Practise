#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Display_array(int *array, int& count){
    cout << "<Array>" << endl;
    for(int cnt = 0; cnt < count; cnt++){
        cout << array[cnt] << " ";
    }
}

void Create_array(int **matrix, int& raw_cnt, int& column_cnt){
    int count_elements = raw_cnt * column_cnt;
    auto *array = new int [count_elements];
    int count_arr = 0;
    for(int count_row = 0; count_row < raw_cnt; count_row++)
        for(int count_column = 0; count_column < column_cnt; count_column++){
            array[count_arr] = matrix[count_row][count_column];
            count_arr++;
        }

    Display_array(array, count_elements);

    delete[](array);
}

void Display_matrix(int **array, int& raw_cnt, int& column_cnt){
    cout << "<Matrix>" << endl;
    for(int count_row = 0; count_row < raw_cnt; count_row++)
    {
        for(int count_column = 0; count_column < column_cnt; count_column++)
            cout << setw(3) << array[count_row][count_column];
        cout << endl;
    }
}

void Create_matrix(int& raws_cnt, int& column_cnt)
{
    srand(time(nullptr));
    auto **ptr_array = new int* [raws_cnt];
    for(int count = 0; count < raws_cnt; count++)
        ptr_array[count] = new int [column_cnt];

    for(int count_row = 0; count_row < raws_cnt; count_row++)
        for(int count_column = 0; count_column < column_cnt; count_column++)
            ptr_array[count_row][count_column] = rand() % 20 + 1;

    Display_matrix(ptr_array, raws_cnt, column_cnt);
    Create_array(ptr_array, raws_cnt, column_cnt);

    for(int count = 0; count < raws_cnt; count++)
        delete[](ptr_array[count]);
}
