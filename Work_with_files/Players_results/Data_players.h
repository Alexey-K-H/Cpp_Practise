#ifndef TEST_PROGRAMM_DATA_PLAYERS_H
#define TEST_PROGRAMM_DATA_PLAYERS_H
#include <memory>
#include <fstream>
#include <iomanip>
using namespace std;

class Table{
public:
    using arr_ptr_type = unique_ptr<float[]>;
private:
    int count_players;
    int count_try = 3;
    unique_ptr<arr_ptr_type []> table;
public:
    Table(int& count_participants): count_players(count_participants), table(make_unique<arr_ptr_type []>(count_players))
    {
        for(int i = 0; i < count_players; i++)
            table[i] = make_unique<float []>(count_try);
    }

    float& Element(int i, int j){
        return table[i][j];
    }

    int get_Count_players() { return count_players;}
    int get_try_count() { return count_try;}
};

void Fill_table(Table& result, ifstream& in, ofstream& out);
float Find_max(Table& result);
void Display_winners(Table& result, float& max_val, ofstream& out);
#endif
