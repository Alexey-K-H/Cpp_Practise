#include "Trait_operations.h"

//Установить значение
void Set_Trait(std::vector<unsigned char> &vec_set, int position, int index_trait, Trait value){
    auto mask_1_bite = (unsigned int) pow(2, 6 - 2*(position % 4) + 1);
    auto mask_2_bite = (unsigned int) pow(2, 6 - 2*(position % 4));

    int char_elem = index_trait/4;

    if(value == Unknown){
        vec_set[char_elem] &= ~(mask_1_bite + mask_2_bite);
    }
    else if(value == True)
    {
        vec_set[char_elem] |= mask_1_bite;
        vec_set[char_elem] &= ~mask_2_bite;
    }
    else
    {
        vec_set[char_elem] |= mask_2_bite;
        vec_set[char_elem] &= ~mask_1_bite;
    }
}

//Получить значение
Trait Get_Trait_value(const std::vector<unsigned char> &vec_set, int position, int index_trait, int size_set){
    //True - 10; False - 01; Unknown - 00;
    if(index_trait > size_set)
    {
        return Unknown;
    }
    else {
        auto mask_1_bit = (unsigned int) pow(2, 6 - 2 * (position % 4) + 1);
        auto mask_2_bit = (unsigned int) pow(2, 6 - 2 * (position % 4));

        int char_elem = index_trait / 4;

        if ((vec_set[char_elem] & mask_1_bit) == 0) {
            if ((vec_set[char_elem] & mask_2_bit) == 0) {
                return Unknown;
            } else
                return False;
        }
        return True;
    }
}

//Логическое НЕ
Trait operator ~(Trait val_1){
    if(val_1 == True)
        return False;
    else if(val_1 == False)
        return True;
    else
        return Unknown;
}

//Логическое ИЛИ
Trait operator | (Trait val_1, Trait val_2){
    if((val_1 == True) || (val_2 == True))
        return True;
    else if((val_1 == Unknown) || (val_2 == Unknown))
        return Unknown;
    else
        return False;
}

//Логическое И
Trait operator &(Trait val_1, Trait val_2){
    if((val_1 == False) || (val_2 == False))
        return False;
    else if((val_1 == Unknown) || (val_2 == Unknown))
        return Unknown;
    else
        return True;
}
