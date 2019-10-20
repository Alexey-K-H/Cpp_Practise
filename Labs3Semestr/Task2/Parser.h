#ifndef LAB_2_PARSER_H
#define LAB_2_PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>

//Обрабатывает блок-схему, котроая подается в командной строке

class Parser
{
public:
    std::ifstream workflow_file;//Файл содержащий схему
    std::string workflow_file_name;//Имя файла со схемой

    std::string input_file_name;//Имя файла для чтения (получаем из аргументов команды readfile)
    std::string output_file_name;//Имя файла для записи(получаем из аргументов команды writefile)

    int number_of_read_command;
    int number_of_write_command;

    bool no_input_file;
    bool no_output_file;

    std::string first_replace_arg;//Первый аргумент команды replace
    std::string second_replace_arg;//Второй аргумент команды replace

    std::string grep_arg;//Аргумент команды grep

    std::string dump_file_name;//Аргуметн команды dump

    std::vector<int> order_commands;
    std::map<int, std::string> order_of_blocks;
    Parser(std::string &workflow_name);

    void Set_input_file(std::string &in_name);
    void Set_output_file(std::string &out_name);

    int Check_curr_block(std::string &line_in_scheme);//Обрабатывает данные для блока
    int Check_order_of_blocks(std::string &order);
    int Read_scheme();
};

//Проверка на наличие кодов ошибок которые могли прийти при чтении workflow
//int Check_parser_for_errors(int &returned_status);

#endif
