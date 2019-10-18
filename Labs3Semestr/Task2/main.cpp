#include "Parser.h"
#include "IWorker.h"

int main() {
    std::string name = "workflow.txt";

    Readfile read_block(name);
    int read_scheme_status = read_block.Parser::Read_scheme();//Читаем схему
    if(Check_parser_for_errors(read_scheme_status))
    {
        return 0;
    }
    if(read_block.Do_command() == 0)
    {
        std::cout << "Successfully read" << std::endl;
    }

    Replace replace_block(&read_block);
    if(replace_block.Do_command() == 0)
    {
        std::cout << "Successfully replaced" << std::endl;
    }

    Grep grep_block(&read_block);
    if(grep_block.Do_command() == 0)
    {
        std::cout << "Successfully greped" << std::endl;
    }

    Sort sort_block(&read_block);
    if(sort_block.Do_command() == 0)
    {
        std::cout << "Successfully sorted" << std::endl;
    }

    Writefile write_block(&read_block);
    if(write_block.Do_command() == 0)
    {
        std::cout << "Text successfully saved" << std::endl;
    }

    return 0;
}