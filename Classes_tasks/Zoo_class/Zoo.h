#ifndef PROJECT_ZOO_H
#define PROJECT_ZOO_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void Interface();

class Zoo_animal{
private:
    string animal;
    string name;
    string male;
    float cost;
    unsigned int count;
public:
    Zoo_animal();
    void Fill_from_keyboard();
    void Fill_from_file(ifstream& input);
    void Save_data_to_file(ofstream& output);
    ~Zoo_animal();
};

#endif
