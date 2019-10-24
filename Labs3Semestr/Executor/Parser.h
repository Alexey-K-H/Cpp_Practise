#ifndef EXECUTOR_PARSER_H
#define EXECUTOR_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <map>
#include <list>
#include <deque>

class Parser
{
private:
    std::ifstream workflow_file;
    std::map<int, std::list<std::string>> arguments_of_command;
    std::deque<int> order_of_commands;

    int number_of_read_command;
    int number_of_write_command;

public:
    Parser();
    int Check_curr_block(std::string &line_in_scheme);
    int Check_order_of_blocks(std::string &order);
    int Read_scheme(std::string &name_of_workflow);
    void Set_read_command(std::string& input_name);
    void Set_write_command(std::string& output_name);

    friend int Execute_work(Parser& workflow);
};
#endif
