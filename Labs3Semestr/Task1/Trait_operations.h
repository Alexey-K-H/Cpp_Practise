#ifndef LAB_1_1_TRAIT_OPERATIONS_H
#define LAB_1_1_TRAIT_OPERATIONS_H

#include "Traitset.h"

//Установить значение трита
void Set_Trait(std::vector<unsigned char> &vec_set, int position, int index_trait,  Trait value);
//Получить значение трита
Trait Get_Trait_value(const std::vector<unsigned char> &vec_set, int position, int index_trait, int size_set);
//Операция логического НЕ
Trait operator ~(Trait val_1);
//Операция логического ИЛИ
Trait operator | (Trait val_1, Trait val_2);
//Операции логического И
Trait operator &(Trait val_1, Trait val_2);

#endif