#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

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
            )
            {
            ID = curr_id;
            surname = curr_surname;
            name = curr_name;
            patronymic = curr_patronymic;
            post = curr_post;
            hour_pay = curr_hour_pay;
            hours_count = curr_hours_count;
            }
};

void Interface_menu();
void Check_input(vector<ID_worker>& workers);
void New_Worker(vector<ID_worker>& worker);
int Search_worker(vector<ID_worker>& workers, string& search_Surname);
void EditData(vector<ID_worker>& worker);
void Display_current_worker(ID_worker& curr_Worker);
void Delete_data(vector<ID_worker>& workers);


int main()
{
    fstream workers_file_data;
    workers_file_data.open("Data.txt", ios_base:: in | ios_base:: out | ios_base:: app);
    vector<ID_worker> data_workers;
    Interface_menu();
    Check_input(data_workers);
    return 0;
}

void Interface_menu(){
    cout << "Choose the action:" << endl;
    cout << "N : New worker." << endl;
    cout << "E : Edit data." << endl;
    cout << "F : Find worker." << endl;
    cout << "D : Delete data." << endl;
    cout << "S : Save to file." << endl;
    cout << "R : Load from file." << endl;
    cout << "V : Show all workers." << endl;
    cout << "C : Sort data." << endl;
    cout << "Q : Quit." << endl;
}

void Check_input(vector<ID_worker>& workers){
    char user_choice = 'U';//U - user_choice
    while (user_choice != 'Q') {
        cin >> user_choice;
        user_choice = toupper(user_choice);
        switch (user_choice) {
            case 'N': {
                New_Worker(workers);
                break;
            }
            case 'E': {
                EditData(workers);
                break;
            }
            case 'F': {
                cout << "Enter surname of worker:";
                string curr_surname;
                cin >> curr_surname;
                int founded_worker = Search_worker(workers, curr_surname);
                if(founded_worker < 0)
                    cout << "Worker didn't found!" << endl;
                else
                    Display_current_worker(workers[founded_worker]);
                break;
            }
            case 'D': {
                Delete_data(workers);
                break;
            }
            case 'S': {

                break;
            }
            case 'R': {

                break;
            }
            case 'V': {

                break;
            }
            case 'C': {

                break;
            }
            default: {
                cout << "Error input!" << endl;
            }
        }
    }
}

void New_Worker(vector<ID_worker>& worker){
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

    worker.emplace_back(ID_worker(
            worker_ID,
            worker_Surname,
            worker_Name,
            worker_Patronymic,
            worker_Post,
            worker_Hr_pay,
            worker_Hours
            ));
}

int Search_worker(vector<ID_worker>& workers, string& search_Surname){
    for(int i = 0; i < workers.size(); i++){
        if(workers.at(i).surname == search_Surname)
            return i;
    }
    return -1;
}

void Display_current_worker(ID_worker& curr_Worker){
    cout << "ID: " << curr_Worker.ID << endl;
    cout << "Surname: " << curr_Worker.surname << endl;
    cout << "Name: " << curr_Worker.name << endl;
    cout << "Patronymic: " << curr_Worker.patronymic << endl;
    cout << "Post: " << curr_Worker.post << endl;
    cout << "H/pay: " << curr_Worker.hour_pay << endl;
    cout << "Salary: " << curr_Worker.hours_count << endl;
}

void EditData(vector<ID_worker>& worker){
    cout << "Enter surname of worker:";
    string curr_surname;
    cin >> curr_surname;
    int founded_worker = Search_worker(worker, curr_surname);
    if(founded_worker < 0)
        cout << "Worker didn't found!" << endl;
    else
        Display_current_worker(worker[founded_worker]);

    char finish_change = 'n';
    while (finish_change != 'y'){
        cout << "Choose the parameter to change: ";
        cout << "i - ID" << endl;
        cout << "s - surname" << endl;
        cout << "n - name" << endl;
        cout << "p - patronymic" << endl;
        cout << "j - post" << endl;
        cout << "h - hour/pay" << endl;
        cout << "c - count of hours" << endl;
        char chosen_param;
        cin >> chosen_param;
        switch (chosen_param)
        {
            case 'i':{
                cout << "Enter new ID: ";
                int new_ID = 0;
                cin >> new_ID;
                worker[founded_worker].ID = new_ID;
                break;
            }
            case 's':{
                cout << "Enter new surname: ";
                string new_surname;
                cin >> new_surname;
                worker[founded_worker].surname = new_surname;
                break;
            }
            case 'n':{
                cout << "Enter new name: ";
                string new_name;
                cin >> new_name;
                worker[founded_worker].name = new_name;
                break;
            }
            case 'p':{
                cout << "Enter new patronymic: ";
                string new_patronymic;
                cin >> new_patronymic;
                worker[founded_worker].patronymic = new_patronymic;
                break;
            }
            case 'j':{
                cout << "Enter new post: ";
                string new_post;
                cin >> new_post;
                worker[founded_worker].post = new_post;
                break;
            }
            case 'h':{
                cout << "Enter new h/pay: ";
                int new_h_pay = 0;
                cin >> new_h_pay;
                worker[founded_worker].hour_pay = new_h_pay;
                break;
            }
            case 'c':{
                cout << "Enter new count of hours: ";
                int new_count_hours = 0;
                cin >> new_count_hours;
                worker[founded_worker].hours_count = new_count_hours;
                break;
            }
            default:{
                cout << "Bad input" << endl;
            }
        }
        cout << "Want to finish changes? y/n: ";
        cin >> finish_change;
    }
}

void Delete_data(vector<ID_worker>& workers){
    cout << "Enter surname of worker:";
    string curr_surname;
    cin >> curr_surname;
    int founded_worker = Search_worker(workers, curr_surname);
    if(founded_worker < 0)
        cout << "Worker didn't found!" << endl;
    else
        workers.erase(workers.begin() + founded_worker);
}
