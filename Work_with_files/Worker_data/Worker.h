#ifndef TEST_WORKER_H
#define TEST_WORKER_H

#include <string>
using  std::string;

class Worker{
private:
    string name;
    int experience;
    int hourly_wage;
    int hours_worked;
    int salary;
    double premy;
public:
    void Set_data_worker();
    void Display_data_worker();
    void Save_data_to_file();
};
#endif
