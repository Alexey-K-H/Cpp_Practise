#ifndef EXECUTOR_EXECUTOR_H
#define EXECUTOR_EXECUTOR_H

#include "Parser.h"

class Executor
{
private:
    Parser *workflow;
    std::deque<int> order_of_commands;
public:
    Executor(Parser *curr_parser);
    void Check_order_of_blocks(std::string &order);
    int Execute_work();
};

#endif
