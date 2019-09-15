#include "Additional_functions.h"

int Get_size_array(int &count_trits)
{
    int size_arr = 0;
    if(count_trits == 0){
        return 0;
    }

    size_arr = (int)(count_trits*2/8/sizeof(unsigned int)) + 1;
    if(size_arr == 0){
        return 1;
    }
    return size_arr;
}
