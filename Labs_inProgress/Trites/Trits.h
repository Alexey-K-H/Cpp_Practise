#ifndef TRITS_TRITS_H
#define TRITS_TRITS_H

#include <iostream>
#include <cassert>


#include "Additional_functions.h"

using namespace std;

class Trit_Set{
private:
    int count_of_trits;//Кол-во трит
    unsigned int *trit_set;//На каждый элемент массива по 2 бита

public:
    enum Trit_val{
        False,
        Unknown,
        True
    };

    //Конструктор по умолчанию
    Trit_Set();

    //Конструктор с параметром
    Trit_Set(int& count);

    //Деструктор
    ~Trit_Set();

    //Возвращает длинну массива uint чтобы поместить туда триты
    void capacity();


};



#endif
