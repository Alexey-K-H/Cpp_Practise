#include <iostream>
using namespace std;
/*Результаты соревнований по прыжкам в длину представлены в виде матрицы 5х3
(5 спортсменов по 3 попытки у каждого).
Указать, какой спортсмен и в какой попытке показал наилучший результат.*/
#include "Data_players.h"

int main() {

    ifstream input;
    input.open("input.txt", ios_base:: in);
    ofstream output;
    output.open("output.txt", ios_base::out);
    if(!input.is_open()){
        output << "Cannot open input file!" << endl;
    } else{
        output << "Enter count of participants: ";
        int count_players = 0;
        input >> count_players;
        output << count_players << endl;
        Table competition_data(count_players);
        Fill_table(competition_data, input, output);
        float max_result = Find_max(competition_data);
        output << endl;
        Display_winners(competition_data, max_result, output);
    }
    return 0;
}
