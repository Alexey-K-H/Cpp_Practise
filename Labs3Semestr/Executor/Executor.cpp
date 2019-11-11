#include "Parser.h"
#include "Blocks.h"
#include "Executor.h"

Executor::Executor(Parser *curr_parser) {
    workflow = curr_parser;
}

void Executor::Check_order_of_blocks(std::string &order) {
    //Если задана лишь одна команда
    if(order.size() == 1)
    {
        if(!isdigit(order[0])){
            throw std::ios_base::failure("No order of blocks!");
        }
        order_of_commands.push_back(atoi(&order[0]));
    }

    //Если задано несколько команд, то число знаков -> долно быть size-1
    unsigned int count_nodes = 0;
    auto pos = order.find("->", 0);
    while (pos != std::string::npos)
    {
        count_nodes++;
        pos = order.find("->", pos + 1);
    }

    unsigned int count_commands = 0;
    for(char &i : order)
    {
        if(isdigit(i))
        {
            count_commands++;
            order_of_commands.push_back(atoi(&i));
        }
    }

    if(count_nodes != count_commands - 1)
        throw std::ios_base::failure("Incorrect order of blocks. Problems with nodes!");
}

int Executor::Execute_work()
{
    std::vector<std::string> tmp_text;

    try {
        Check_order_of_blocks(workflow->order);
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return -1;
    }


    for(unsigned long i  = 0; i < order_of_commands.size(); i++)
    {
        auto it = workflow->arguments_of_command.find(order_of_commands[i]);

        auto curr_block = BlockFactory::Instance().Create(it->second);
        if(curr_block == nullptr)
            throw std::invalid_argument("Unexpected command!");

        if(i == 0 && curr_block->Return_type_of_block() != in)
            throw std::logic_error("Incorrect order!");

        if(i == order_of_commands.size() - 1 && curr_block->Return_type_of_block() != out)
            throw std::logic_error("Incorrect order");

        if(curr_block->Return_type_of_block() != in_out && (i>0 && i < order_of_commands.size() - 1))
            throw std::logic_error("Incorrect order");

        try{
            tmp_text = curr_block->Do_command(tmp_text);
        }
        catch (std::exception &err)
        {
            throw std::ios_base::failure(err.what());
        }
    }
    return 0;
}


