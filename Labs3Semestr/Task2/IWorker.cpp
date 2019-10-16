#include "IWorker.h"

int Readfile::Do_command() {
    input.open(input_file_name);
    if(!input.is_open())
    {
        std::cout << "Input file doesn't exist!" << std::endl;
        return 1;
    }
    else{
        char symbol;
        while(input.get(symbol))
        {
            text.push_back(symbol);
        }
    }
    input.close();
    return 0;
}

void Readfile::Print_text() {
    std::cout << "Text from file" << std::endl;
    for(char i : text)
    {
        std::cout << i;
    }
    std::cout << std::endl;
}

int Writefile::Do_command() {
    output.open(output_file_name);
    if(!output.is_open())
    {
        std::cout << "Output file doesn't exist!" << std::endl;
        return 1;
    }
    for(char i : text)
    {
        output << i;
    }
    std::cout << "Text saved to:" << output_file_name << std::endl;
    return 0;
}
