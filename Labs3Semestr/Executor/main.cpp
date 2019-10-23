#include <iostream>

#include "Parser.h"
#include "Blocks.h"

int main() {
    std::list<std::string> arguments_list_readfile {"readfile", "in.txt"};
    std::list<std::string> arguments_list_writefile {"writefile", "out.txt"};
    std::list<std::string> arguments_list_grep {"grep", "friend"};
    std::list<std::string> arguments_list_replace {"replace", "Bierce", "Malak"};

    std::list<std::string> some_arguments {"some_command", "some_argument"};

    auto block0 = BlockFactory::Instance().Create(arguments_list_readfile);
    auto it0 = block0->Do_command();
    if(it0 == 0){
        std::cout << "Successfully!" << std::endl;
    }

    auto block1 = BlockFactory::Instance().Create(arguments_list_writefile);
    auto it1 = block1->Do_command();
    if(it1 == 0)
    {
        std::cout << "Successfully!" << std::endl;
    }

    auto block2 = BlockFactory::Instance().Create(arguments_list_grep);
    auto it2 = block2->Do_command();
    if(it2 == 0)
    {
        std::cout << "Successfully!" << std::endl;
    }

    auto block3 = BlockFactory::Instance().Create(arguments_list_replace);
    auto it3 = block3->Do_command();
    if(it3 == 0)
    {
        std::cout << "Successfully!" << std::endl;
    }

    //auto block4 = BlockFactory::Instance().Create(some_arguments);//Раскомментирование данной строки приведет к ошибке

    return 0;
}