#include "Data_players.h"

using namespace std;

void Fill_table(Table& result, ifstream& in, ofstream& out){
    out << "Enter competition's results" << endl;
    for(int i = 0; i < result.get_Count_players(); i++){
        out << "for " << i+1 << " player:";
        for(int j = 0; j < result.get_try_count(); j++){
            in >> result.Element(i,j);
            out << setw(5) << fixed << setprecision(2) << result.Element(i,j) << " ";
        }
        out << endl;
    }
}

float Find_max(Table& result){
    float max_value = 0;
    for(int i = 0; i < result.get_Count_players(); i++){
        for(int j = 0; j < result.get_try_count(); j++){
            if(max_value < result.Element(i, j)){
                max_value = result.Element(i, j);
            }
        }
    }

    return max_value;
}

void Display_winners(Table& result, float& max_val, ofstream& out){
    out << "The best result among athletes:" << endl;
    for(int i = 0; i < result.get_Count_players(); i++){
        for(int j = 0; j < result.get_try_count(); j++){
            if(result.Element(i, j) == max_val){
                out << "Number of athlete - " << i+1 << endl;
                out << "Turn number - " << j+1 << endl;
                out << endl;
            }
        }
    }
}
