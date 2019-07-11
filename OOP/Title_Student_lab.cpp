#include <iostream>
#include <string.h>

/*Напишите программу, запрашивающую имя, фамилия,
 отчество и номер группы студента и выводящую введённые данные в следующем виде:
   ********************************
   * Лабораторная работа № 1      *
   * Выполнил(а): ст. гр. ЗИ-123  *
   * Иванов Андрей Петрович       *
   ********************************
   Необходимо, чтобы программа сама определяла нужную длину рамки. 
   Сама же длина рамки зависит от длины наибольшей строки внутри рамки.
 */
using namespace std;

class Student_title
{
private:
    string surName;
    string name;
    string lastName;

    string number_of_lab;
    string number_of_group;

public:
    Student_title(){
        surName = "Surname";
        name = "Name";
        lastName = "Last_Name(if there is)";

        number_of_group = "Number of the group";
        number_of_lab = "Number of the lab_work";
    }

    void Set_name_of_student(string stud_surName, string stud_name, string stud_lastName)
    {
        surName = stud_surName;
        name = stud_name;
        lastName = stud_lastName;
    }

    void Set_number_of_lab(string number)
    {
        number_of_lab = number;
    }

    void Set_number_of_group(string stud_group_num)
    {
        number_of_group = stud_group_num;
    }

    string Get_first_string(string number_lab){
        string first_str = "Lab_work number ";
        first_str = first_str + number_lab;
        return first_str;
    }

    string Get_second_string(string number_group){
        string second_str = "Made by student of the group: ";
        second_str = second_str + number_group;
        return second_str;
    }

    string Get_third_string(string std_Surname, string std_Name, string std_Lastname){
        string third_str;
        third_str = std_Surname + ' ' + std_Name + ' ' + std_Lastname;
        return third_str;
    }

    int Find_max(int num_1, int num_2, int num_3){
        int max = num_1;
        if(max > num_2){
            max = num_2;
        }
        else if(max > num_3){
            max = num_3;
        }
        return max;
    }

    void Give_information_about_lab()
    {
        cout << endl << endl;
        string str_1 = Get_first_string(number_of_lab);
        string str_2 = Get_second_string(number_of_group);
        string str_3 = Get_third_string(surName, name, lastName);

        int max_length = 0;
        int str_1_length = str_1.length();
        int str_2_length = str_2.length();
        int str_3_length = str_3.length();

        max_length = Find_max(str_1_length, str_2_length, str_3_length);

        for(int i = 0; i < 9; i++)
        {
            if(i == 0)
            {
                for(int j = 0; j < max_length + 4; j++)
                {
                    cout << "* ";
                }
                //cout << endl;
            }

            if(i == 2)
            {
                cout << "* ";
                cout << str_1;
                for(int j = 0; j < max_length + 4; j++)
                {
                    if(j == (max_length - 3)){
                        cout << " *";
                    }
                }
            }

            if(i == 4)
            {
                cout << "* ";
                cout << str_2;
                for(int j = 0; j < max_length + 4; j++)
                {
                    if(j == (max_length - 3)){
                        cout << " *";
                    }
                }
            }

            if(i == 6)
            {
                cout << "* ";
                cout << str_3;
                for(int j = 0; j < max_length + 4; j++)
                {
                    if(j == (max_length - 3)){
                        cout << " *";
                    }
                }
            }

            if(i == 8)
            {
                for(int j = 0; j < max_length + 4; j++)
                {
                    cout << "* ";
                }
            }

            cout << endl;
        }
    }
};


int main()
{
    cout << "Enter the ID of the student" << endl;
    string surName;
    cout << "Enter the Surname:";
    cin >> surName;
    string name;
    cout << "Enter the Name:";
    cin >> name;
    string lastName;
    cout << "Enter the Lastname:";
    cin >> lastName;

    cout << "Enter the number of the group:";
    string number_Group;
    cin >> number_Group;

    cout << "Enter the number of the lab:";
    string number_LabWork;
    cin >> number_LabWork;

    Student_title* New_Title = new Student_title;
    New_Title -> Set_name_of_student(surName, name, lastName);
    New_Title -> Set_number_of_group(number_Group);
    New_Title -> Set_number_of_lab(number_LabWork);

    New_Title -> Give_information_about_lab();

    return 0;
}
