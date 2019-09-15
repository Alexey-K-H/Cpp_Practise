#include "Trits.h"

Trit_Set::Trit_Set() {
    count_of_trits = 0;
    trit_set = nullptr;
}

Trit_Set::Trit_Set(int &count) {
    count_of_trits = count;
    assert(count >= 0);
    if(count > 0) {
        int size_array = Get_size_array(count_of_trits);
        //cout << "Size_of_array:";
        //cout << size_array << endl;
        trit_set = new unsigned int[size_array];
    }
    else
        trit_set = nullptr;
}

Trit_Set::~Trit_Set() {
    delete[] trit_set;
}

void Trit_Set::capacity() {
    cout << "Capacity of the set:";
    cout << Get_size_array(count_of_trits) << endl;
