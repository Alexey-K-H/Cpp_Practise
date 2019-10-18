#include "IWorker.h"

int Readfile::Do_command() {
    input.open(input_file_name);
    if(!input.is_open())
    {
        std::cout << "Input file doesn't exist!" << std::endl;
        return 1;
    }
    else{
        std::string curr_line;
        while(getline(input, curr_line))
        {
            text.push_back(curr_line);
        }
    }
    input.close();
    return 0;
}

void Readfile::Print_text() {
    std::cout << "<Text from file>" << std::endl;
    for(const std::string& i : text)
    {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
}

int Writefile::Do_command() {
    output.open(read_blk->output_file_name);
    if(!output.is_open())
    {
        std::cout << "Output file doesn't exist!" << std::endl;
        return 1;
    }
    for(const std::string& i : read_blk->text)
    {
        output << i << std::endl;
    }
    std::cout << "Text saved to:" << read_blk->output_file_name << std::endl;
    output.close();
    return 0;
}

int Replace::Do_command() {
    for(std::string& i : read_blk->text)
    {
        int it_pos = i.find(read_blk->first_replace_arg, 0);
        while (it_pos != std::string::npos)
        {
            i.replace(it_pos, read_blk->first_replace_arg.size(), read_blk->second_replace_arg);
            it_pos = i.find(read_blk->first_replace_arg, it_pos);
        }
    }
    std::cout << "<After replace> str:" << read_blk->first_replace_arg << " to str:" << read_blk->second_replace_arg << std::endl;
    for(const std::string& i : read_blk->text)
    {
        std::cout << i << std::endl;
    }
    return 0;
}

int Grep::Do_command() {
    for(unsigned long long i = 0; i < read_blk->text.size(); i++)
    {
        int it_pos = read_blk->text[i].find(read_blk->grep_arg, 0);
        if(it_pos == std::string::npos)
        {
            read_blk->text.erase(read_blk->text.begin() + i);
        }
    }

    std::cout << "<After grep> arg:" << read_blk->grep_arg << std::endl;
    for(const std::string& i : read_blk->text)
    {
        std::cout << i << std::endl;
    }
    return 0;
}

int Dump::Do_command() {
    dump_out.open(read_blk->output_file_name);
    if(!dump_out.is_open())
    {
        std::cout << "Output file doesn't exist!" << std::endl;
        return 1;
    }
    for(const std::string& i : read_blk->text)
    {
        dump_out << i << std::endl;
    }
    std::cout << "Text saved to:" << read_blk->output_file_name << std::endl;
    dump_out.close();
    return 0;
}