#include <iostream>

#include "Zoo.h"
/*
Необходимо создать класс — зоомагазин. 
В классе должны быть следующие поля: животное ( напр. волк, пингвин, собака ), пол, имя , цена, количество. 
Включить в состав класса необходимый минимум методов, обеспечивающий полноценное функционирование объектов указанного класса:
    Конструкторы (по умолчанию, с параметрами, копирования);
    Деструктор;
    Переопределить возможные для класса операции, продумать порядок их выполнения;
    Добавить необходимые методы.
    Предоставить возможность вводить данные с клавиатуры или из файла (с помощью конструктора или операцией »).
*/
int main() {
    char finish_program = 'n';
    ifstream input;
    ofstream output;
    input.open("input.txt", ios_base::in);
    output.open("output.txt", ios_base::out | ios_base::app);
    while (finish_program != 'y'){
        Interface();
        char user_choice = 'c';
        cin >> user_choice;

        Zoo_animal curr_animal;

        if(user_choice == 'k'){
            curr_animal.Fill_from_keyboard();
            curr_animal.Save_data_to_file(output);
        }
        else if(user_choice == 'f'){
            if(!input.is_open())
            {
                cout << "Error! Cannot open input file!" << endl;
            }
            else{
                curr_animal.Fill_from_file(input);
                curr_animal.Save_data_to_file(output);
            }
        }
        cout << "Finish program? y/n:";
        cin >> finish_program;
    }
    input.close();
    output.close();
    return 0;
}
