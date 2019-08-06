#include <iostream>
using namespace std;
#include "Worker.h"

int main()
{
    Worker curr_worker;
    curr_worker.Set_data_worker();
    cout << endl;
    curr_worker.Display_data_worker();
    curr_worker.Save_data_to_file();
    return 0;
}
