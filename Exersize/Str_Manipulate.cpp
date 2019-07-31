#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
/*Манипулятор со строками*/

void To_up_each_First(string& user_str){
    auto curr_symbol = 0;
    user_str[curr_symbol] = toupper(user_str[curr_symbol]);
    for(curr_symbol = 1; curr_symbol < user_str.length(); curr_symbol++){
        if(user_str[curr_symbol] == ' '){
            user_str[curr_symbol+1] = toupper(user_str[curr_symbol+1]);
        }
    }
}

void To_low_each_First(string& user_str){
    auto curr_symbol = 0;
    user_str[curr_symbol] = tolower(user_str[curr_symbol]);
    for(curr_symbol = 1; curr_symbol < user_str.length(); curr_symbol++){
        if(user_str[curr_symbol] == ' '){
            user_str[curr_symbol+1] = tolower(user_str[curr_symbol+1]);
        }
    }
}

void Manipulator(char& choice, string& user_str){
    switch (choice){
        case '1':{
            transform(user_str.begin(), user_str.end(), user_str.begin(), ::toupper);
            cout << user_str << endl << endl;
            break;
        }
        case '2':{
            transform(user_str.begin(), user_str.end(), user_str.begin(), ::tolower);
            cout << user_str << endl << endl;
            break;
        }
        case '3':{
            transform(user_str.begin(), user_str.end(), user_str.begin(), ::tolower);
            To_up_each_First(user_str);
            cout << user_str << endl << endl;
            break;
        }
        case '4':{
            transform(user_str.begin(), user_str.end(), user_str.begin(), ::toupper);
            To_low_each_First(user_str);
            cout << user_str << endl << endl;
            break;
        }
        case '5':{
            transform(user_str.begin(), user_str.end(), user_str.begin(), ::tolower);
            auto first = 0;
            user_str[first] = toupper(user_str[first]);
            cout << user_str << endl << endl;
            break;
        }
        case 'f':{
            cout << "Finish of the program" << endl;
            break;
        }
        default:
            cout << "Bad input! Look at the hot key!" << endl << endl;
    }
}

int main()
{
    ifstream myFile;
    myFile.open("Example.txt", ios_base::out);
    cout << "Enter the string:" << endl;
    string user_str;
    getline(myFile, user_str);
    cout << user_str << endl;
    char user_choice = 's';
    while (user_choice != 'f') {
        cout << "To up case press: 1" << endl;
        cout << "To low case press: 2" << endl;
        cout << "Each first symbol to up press: 3" << endl;
        cout << "Each first symbol to low press: 4" << endl;
        cout << "Usual sentence press: 5" << endl;
        cout << "For exit press: f" << endl;
        cout << "Enter current action:";
        cin >> user_choice;
        Manipulator(user_choice, user_str);
    }
    return 0;
}
