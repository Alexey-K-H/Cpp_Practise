#include <iostream>
#include <set>
#include <string>
#include <fstream>
using namespace std;
/*Дан массив размера n, заполнить его случайными числами, Найти все нечётные числа массива.*/

struct ID_worker
{
    int ID;
    string surname;
    string name;
    string patronymic;
    string post;
    int hour_pay;
    int hours_count;

    ID_worker(
            int& curr_id,
            string& curr_surname,
            string& curr_name,
            string& curr_patronymic,
            string& curr_post,
            int& curr_hour_pay,
            int& curr_hours_count
            ):
            ID(curr_id),
            surname(curr_surname),
            name(curr_name),
            patronymic(curr_patronymic),
            post(curr_post),
            hour_pay(curr_hour_pay),
            hours_count(curr_hours_count)
            {}
};

char Interface_menu();
void Check_input(char& user_choice, set<ID_worker>& workers);
void New_Worker(set<ID_worker>& worker);

int main()
{
    fstream workers_file_data;
    workers_file_data.open("Data.txt", ios_base:: in | ios_base:: out | ios_base:: app);
    set<ID_worker> set_workers;
    char user_choice = Interface_menu();
    Check_input(user_choice, set_workers);
    return 0;
}

char Interface_menu(){
    cout << "Choose the action:" << endl;
    char user_choice;
    cout << "N : New worker." << endl;
    cout << "E : Edit data." << endl;
    cout << "F : Find worker." << endl;
    cout << "D : Delete data." << endl;
    cout << "S : Save to file." << endl;
    cout << "R : Load from file." << endl;
    cout << "V : Show all workers." << endl;
    cout << "C : Sort data." << endl;
    cout << "Q : Quit." << endl;
    cin >> user_choice;
    return user_choice;
}

void Check_input(char& user_choice, set<ID_worker>& workers){
    user_choice = toupper(user_choice);
    switch (user_choice){
        case 'N':{
            New_Worker(workers);
            break;
        }
        case 'E':{

            break;
        }
        case 'F':{

            break;
        }
        case 'D':{

            break;
        }
        case 'S':{

            break;
        }
        case 'R':{

            break;
        }
        case 'V':{

            break;
        }
        case 'C':{

            break;
        }
        case 'Q':{

            break;
        }
        default:{
            cout << "Error input!" << endl;
        }
    }
}

void New_Worker(set<ID_worker>& worker){
    cout << "Enter data:" << endl;
    cout << "ID: ";
    int worker_ID = 0;
    cin >> worker_ID;
    cout << "Surname: ";
    string worker_Surname;
    cin >> worker_Surname;
    cout << "Name: ";
    string worker_Name;
    cin >> worker_Name;
    cout << "Patronymic(--- if not): ";
    string worker_Patronymic;
    cin >> worker_Patronymic;
    cout << "Post: ";
    string worker_Post;
    cin >> worker_Post;
    cout << "Hr. pay: ";
    int worker_Hr_pay = 0;
    cin >> worker_Hr_pay;
    cout << "Hours: ";
    int worker_Hours = 0;
    cin >> worker_Hours;

    worker.insert(ID_worker(
            worker_ID,
            worker_Surname,
            worker_Name,
            worker_Patronymic,
            worker_Post,
            worker_Hr_pay,
            worker_Hours
            ));
}
