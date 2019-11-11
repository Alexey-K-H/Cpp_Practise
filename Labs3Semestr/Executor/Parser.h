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
    std::string order;
public:
    int Check_curr_block(std::string &line_in_scheme);
    int Read_scheme(std::string &name_of_workflow);
    friend class Executor;
};
#endif
