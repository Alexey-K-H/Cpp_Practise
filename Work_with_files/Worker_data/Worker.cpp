#include "Worker.h"
#include <iostream>
#include <fstream>
using namespace std;
void Worker::Set_data_worker()
{
    cout << "Enter worker's name: ";
    string curr_name;
    cin >> curr_name;
    name = curr_name;
    cout << "Enter worker's experience: ";
    int curr_exp;
    cin >> curr_exp;
    experience = curr_exp;
    cout << "Enter worker's hourly wag: ";
    int curr_h_wag = 0;
    cin >> curr_h_wag;
    hourly_wage = curr_h_wag;
    cout << "Enter how much hours Denis has worked: ";
    int curr_h_worked = 0;
    cin >> curr_h_worked;
    hours_worked = curr_h_worked;

    salary = hourly_wage*hours_worked;

    if(experience <= 1){
        premy = 0;
    }
    else if(experience > 1 && experience <= 3){
        premy = (double)salary*0.05;
    }
    else if(experience > 3 && experience <= 5){
        premy = (double)salary*0.08;
    }
    else if(experience > 5){
        premy = (double)salary*0.15;
    }
}

void Worker::Display_data_worker()
{
    cout << name << endl;
    cout << "Experience is " << experience << endl;
    cout << "Hourly wag is " << hourly_wage << endl;
    cout << name << " has worked " << hours_worked << " hours" << endl;
    cout << "Premy is " << premy << endl;
    cout << "Information about Denis was written in file 'Workers.txt'" << endl;
}

void Worker:: Save_data_to_file(){
    ofstream data_File;
    data_File.open("Workers.txt", ios_base::out | ios_base::app | ios_base::ate);
    data_File << name << endl;
    data_File << "Experience is " << experience << endl;
    data_File << "Hourly wag is " << hourly_wage << endl;
    data_File << name << " has worked " << hours_worked << " hours" << endl;
    data_File << "Premy is " << premy << endl;
    data_File << endl;
    data_File.close();
}
