#include "Zoo.h"

void Interface(){
    cout << "Fill data from keyboard: press - k" << endl;
    cout << "Fill data from file: press - f" << endl;
    cout << "Choose action:";
}

Zoo_animal::Zoo_animal() {
    cout << "Create new animal" << endl;
    animal = "---";
    name = "---";
    male = "---";
    cost = 0;
    count = 0;
}

void Zoo_animal::Fill_from_keyboard(){
    cout << "Enter data od animal:" << endl;
    cout << "Kind of animal:";
    string curr_animal;
    cin >> curr_animal;
    animal = curr_animal;
    cout << "Name of animal:";
    string curr_name;
    cin >> curr_name;
    name = curr_name;
    cout << "Male/Female:";
    string curr_male;
    cin >> curr_male;
    male = curr_male;
    cout << "Cost of one animal:";
    float curr_cost = 0.0;
    cin >> curr_cost;
    cost = curr_cost;
    cout << "Count of this kind of animal:";
    unsigned int curr_count = 0;
    cin >> curr_count;
    count = curr_count;
}

void Zoo_animal::Fill_from_file(ifstream& input) {
    string curr_animal;
    input >> curr_animal;
    animal = curr_animal;

    string curr_name;
    input >> curr_name;
    name = curr_name;

    string curr_male;
    input >> curr_male;
    male = curr_male;

    float curr_cost = 0.0;
    input >> curr_cost;
    cost = curr_cost;

    unsigned int curr_count = 0;
    input >> curr_count;
    count = curr_count;
}

void Zoo_animal::Save_data_to_file(ofstream& output){
    output << "Animal data: " << animal << endl;
    output << "Name: " << name << endl;
    output << "Male/Female: " << male << endl;
    output << "Cost: " << cost << endl;
    output << "Count of this kind of animal: " << count << endl;
    output << "Summary cost: " << cost*(float)count << endl;
    output << endl;
}

Zoo_animal::~Zoo_animal(){
    cout << "Clear data of:" << animal << endl;
}
