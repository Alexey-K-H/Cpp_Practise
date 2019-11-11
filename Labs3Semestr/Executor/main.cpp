#include <iostream>
#include "Parser.h"
#include "Executor.h"

int main(int argc, char** argv) {
    try {
        if(argc < 2)
            throw std::invalid_argument("No workflow file!");
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 0;
    }
    std::string name_of_workflow = argv[1];
    Parser new_workflow;
    try {
        new_workflow.Read_scheme(name_of_workflow);
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 0;
    }
    Executor curr_executor(&new_workflow);
    try {
        curr_executor.Execute_work();
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 0;
    }
    std::cout << "Successfully!" << std::endl;
    return 0;
}