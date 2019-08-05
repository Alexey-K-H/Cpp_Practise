#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
/*Разработать программу, в которой будет организовано меню, выбор функций меню должно быть организовано по функциональной клавише. 
Вся информация должна храниться в массиве структур, с возможностью их записи в файл. 

функция для ввода данных пользователем;
функция для записи данных в файл;
чтение данных из файла;
вывод данных на экран;
дополнение данных;
удаление данных;
поиск информации по атрибуту;*/
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
void Save_data_to_file(vector<ID_worker>& workers);
void Load_form_file(vector<ID_worker>& workers);
void Show_all_workers(vector<ID_worker>& workers);

int main()
{
    vector<ID_worker> data_workers;
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
        Interface_menu();
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
                Save_data_to_file(workers);
                break;
            }
            case 'R': {
                Load_form_file(workers);
                break;
            }
            case 'V': {
                Show_all_workers(workers);
                break;
            }
            case 'C': {
                cout << "Not available at the moment. Sorry :( " << endl;
                break;
            }
            default: {
                if(user_choice != 'Q')
                cout << "Error input!" << endl;
            }
        }
    }
    cout << "End of the session. Goodbye!";
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
    cout << endl;
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
    cout << "Hours count: " << curr_Worker.hours_count << endl;
    cout << endl;
}

void EditData(vector<ID_worker>& worker){
    cout << "Enter surname of worker:";
    string curr_surname;
    cin >> curr_surname;
    int founded_worker = Search_worker(worker, curr_surname);
    if(founded_worker < 0)
    {
        cout << "Worker didn't found!" << endl;
        return;
    }
    else
        Display_current_worker(worker[founded_worker]);

    char finish_change = 'n';
    while (finish_change != 'y'){
        cout << "Choose the parameter to change:" << endl;
        cout << "i - ID" << endl;
        cout << "s - surname" << endl;
        cout << "n - name" << endl;
        cout << "p - patronymic" << endl;
        cout << "j - post" << endl;
        cout << "h - hour/pay" << endl;
        cout << "c - count of hours" << endl;
        cout << "f - cancel" << endl;
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
                if(chosen_param != 'f')
                cout << "Bad input" << endl;
            }
        }
        cout << "Want to finish changes? y/n: ";
        cin >> finish_change;
    }
}

void Delete_data(vector<ID_worker>& workers){
    cout << "Enter surname of worker to delete:";
    string curr_surname;
    cin >> curr_surname;
    int founded_worker = Search_worker(workers, curr_surname);
    if(founded_worker < 0)
        cout << "Worker didn't found!" << endl;
    else
        workers.erase(workers.begin() + founded_worker);
}

void Save_data_to_file(vector<ID_worker>& workers){
    ofstream workers_file_data;
    workers_file_data.open("Data.txt", ios_base:: out | ios_base:: trunc);
    if(!workers_file_data.is_open())
        cout << "Cannot open the file!" << endl;
    else {
        workers_file_data << "<Worker data>" << endl;
        workers_file_data << setw(12) << "ID";
        workers_file_data << setw(20) << "Surname";
        workers_file_data << setw(16) << "Name";
        workers_file_data << setw(28) << "Patronymic";
        workers_file_data << setw(24) << "Post";
        workers_file_data << setw(16) << "H/pay";
        workers_file_data << setw(20) << "Hours count";
        workers_file_data << setw(24) << "Salary";
        workers_file_data << endl;

        int line_count = 160;
        while (line_count > 0){
            workers_file_data << "-";
            line_count--;
        }
        workers_file_data << endl;

        for (int i = 0; i < workers.size() - 1; i++) {
            workers_file_data <<  setw(12) << workers[i].ID;
            workers_file_data <<  setw(20) << workers[i].surname;
            workers_file_data <<  setw(16) << workers[i].name;
            workers_file_data <<  setw(28) << workers[i].patronymic;
            workers_file_data <<  setw(24) << workers[i].post;
            workers_file_data <<  setw(16) << workers[i].hour_pay;
            workers_file_data <<  setw(20) << workers[i].hours_count;
            workers_file_data <<  setw(24) << workers[i].hour_pay * workers[i].hours_count;
            workers_file_data << endl;
        }
        workers_file_data.close();
    }
}

void Load_form_file(vector<ID_worker>& workers){
    ifstream new_File;
    new_File.open("Doc_workers.txt", ios_base::out);
    if(!new_File.is_open()){
        cout << "Cannot open the file!" << endl;
    }
    else
    {
        int id_Load = 0;
        string surname_Load;
        string name_Load;
        string patronymic_Load;
        string post_Load;
        int hour_pay_Load;
        int hour_count_Load;
        while (new_File.good())
        {
            new_File >> id_Load;
            new_File >> surname_Load;
            new_File >> name_Load;
            new_File >> patronymic_Load;
            new_File >> post_Load;
            new_File >> hour_pay_Load;
            new_File >> hour_count_Load;

            workers.emplace_back(ID_worker(
                    id_Load,
                    surname_Load,
                    name_Load,
                    patronymic_Load,
                    post_Load,
                    hour_pay_Load,
                    hour_count_Load
            ));
        }
        new_File.close();
    }
}

void Show_all_workers(vector<ID_worker>& workers){
    cout << "<Worker data>" << endl;
    cout << setw(12) << "ID";
    cout << setw(20) << "Surname";
    cout << setw(16) << "Name";
    cout << setw(28) << "Patronymic";
    cout << setw(24) << "Post";
    cout << setw(16) << "H/pay";
    cout << setw(20) << "Hours count";
    cout << setw(24) << "Salary";
    cout << endl;

    int line_count = 160;
    while (line_count > 0){
        cout << "-";
        line_count--;
    }
    cout << endl;

    for (int i = 0; i < workers.size() - 1; i++) {
        cout <<  setw(12) << workers[i].ID;
        cout <<  setw(20) << workers[i].surname;
        cout <<  setw(16) << workers[i].name;
        cout <<  setw(28) << workers[i].patronymic;
        cout <<  setw(24) << workers[i].post;
        cout <<  setw(16) << workers[i].hour_pay;
        cout <<  setw(20) << workers[i].hours_count;
        cout <<  setw(24) << workers[i].hour_pay * workers[i].hours_count;
        cout << endl;
    }
}
