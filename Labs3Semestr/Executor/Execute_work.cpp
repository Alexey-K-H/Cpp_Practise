#include "Parser.h"
#include "Blocks.h"

int Execute_work(Parser& workflow)
{
    std::vector<std::string> tmp_text;
    for(unsigned long i  = 0; i < workflow.order_of_commands.size(); i++)
    {
        auto it = workflow.arguments_of_command.find(workflow.order_of_commands[i]);

        auto curr_block = BlockFactory::Instance().Create(it->second, tmp_text);
        try {
            if(curr_block == nullptr)
                throw std::invalid_argument("Unexpected command!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return -1;
        }

        auto action_block = curr_block->Do_command();
        if(action_block)
            return -1;

        tmp_text = curr_block->Return_result_text();
    }
    return 0;
}

