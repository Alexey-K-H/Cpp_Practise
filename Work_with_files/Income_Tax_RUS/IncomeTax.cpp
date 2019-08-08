#include <iostream>

using namespace std;

void Tax_deductions(float& income, int& parameter){
    switch (parameter){
        case 1:{
            income -= 500;
            break;
        }
        case 2:{
            income -= 1400;
            break;
        }
        case 3:{
            income -= 3000;
            break;
        }
        default:{
            cout << "Wrong parameter!" << endl;
        }
    }
}

void Tax(float& income, bool& isResident){
    float tax = 0.0;
    float percent = 0.0;
    if(isResident){
        percent = 0.13;
        tax = income*percent;
    } else{
        percent = 0.30;
        tax = income*percent;
    }
    cout << "Tax is: " << tax << " RUB" << endl;
}

void Summary_Income(){
    cout << "Enter the monthly salary: ";
    float salary = 0.0;
    cin >> salary;

    cout << "Enter summary of prize: ";
    float prize = 0.0;
    cin >> prize;
    salary += prize;

    cout << "Enter additional income: ";
    float add_income = 0.0;
    cin >> add_income;
    salary += add_income;

    cout << "Choose parameter for tax deductions(1 - 500_RUB, 2 - 1400_RUB or 3 - 3000_RUB): ";
    int parameter = 0;
    cin >> parameter;

    Tax_deductions(salary, parameter);
    char choice = 'n';
    bool isResident = false;
    cout << "Is person resident of the country? y/n: ";
    cin >> choice;
    isResident = choice == 'y';
    Tax(salary, isResident);
}
