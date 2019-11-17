#include "Blocks.h"

//Создание нашей фабрики
BlockFactory& BlockFactory::Instance() {
    static BlockFactory factory;
    return factory;
}

void BlockFactory::RegisterMaker(const std::string &key, IBlockMaker *maker) {
    makers[key] = maker;
}

IBlock* BlockFactory::Create(std::list<std::string>& block_description) {
    std::string key = *(block_description.begin());//Предполагается что первая строка в списке - имя блока
    auto i = makers.find(key);
    //Если команда не была определена
    if(i == makers.end()){
        return nullptr;
    }
    IBlockMaker* maker = i->second;
    return maker->Create(block_description);//IBlock maker сделает указатель на объект IBlock
}

//Блок READFILE
static BlockMaker<Readfile> maker_readfile("readfile");

Readfile::Readfile(std::list<std::string>& arguments) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
        in_name = *it;
}

std::vector<std::string> Readfile::Do_command(std::vector<std::string>& some_text) {
    text = some_text;
    input_file.open(in_name);

    if(!input_file.is_open()){
            throw std::invalid_argument("file doesn't exist");
    }

    text.clear();
    std::string curr_line;
    while (getline(input_file, curr_line))
    {
        text.push_back(curr_line);
    }

    input_file.close();
    return text;
}

Type_block Readfile::Return_type_of_block() {
    return in;
}

//Блок WRITEFILE
static BlockMaker<Writefile> make_writefile("writefile");

Writefile::Writefile(std::list<std::string> &arguments) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
        out_name = *it;
}

std::vector<std::string> Writefile::Do_command(std::vector<std::string>& some_text) {
    text = some_text;
    output_file.open(out_name);

        if(!output_file.is_open())
            throw std::invalid_argument("file doesn't exist");

    for(const std::string& i : text){
        output_file << i << std::endl;
    }
    output_file.close();
    return text;
}


Type_block Writefile::Return_type_of_block() {
    return out;
}

//Блок GREP
static BlockMaker<Grep> makegrep("grep");

Grep::Grep(std::list<std::string> &arguments) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
    {
        argument_grep = *it;
    }
}

std::vector<std::string> Grep::Do_command(std::vector<std::string>& some_text) {
    text = some_text;

    if(argument_grep.empty())
        throw std::invalid_argument("No argument for command grep!");

    std::vector<std::string> new_text;
    for(auto & i : text)
    {
        int it_pos = i.find(argument_grep, 0);
        if(it_pos > 0)
        {
            new_text.push_back(i);
        }
    }
    text.resize(new_text.size());
    text = new_text;
    return text;
}

Type_block Grep::Return_type_of_block() {
    return in_out;
}

//Блок SORT
static BlockMaker<Sort> maker_sort("sort");

Sort::Sort(std::list<std::string> &arguments){}

std::vector<std::string> Sort::Do_command(std::vector<std::string>& some_text) {
    text = some_text;
    std::sort(text.begin(), text.end());
    return text;
}

Type_block Sort::Return_type_of_block() {
    return in_out;
}
//Блок REPLACE
static BlockMaker<Replace> maker_replace("replace");

Replace::Replace(std::list<std::string> &arguments) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
        first_replace_arg = *it;

    std::advance(it, 1);
    if(it != arguments.end())
        second_replace_arg = *it;

}

std::vector<std::string> Replace::Do_command(std::vector<std::string>& some_text) {
    text = some_text;

    if(first_replace_arg.empty() || second_replace_arg.empty())
        throw std::invalid_argument("Not enough argument for replace!");


    for(std::string& i : text)
    {
        int it_pos = i.find(first_replace_arg, 0);
        while (it_pos != std::string::npos)
        {
            i.replace(it_pos, first_replace_arg.size(), second_replace_arg);
            it_pos = i.find(first_replace_arg, it_pos);
        }
    }
    return text;
}

Type_block Replace::Return_type_of_block() {
    return in_out;
}

//Блок DUMP
static BlockMaker<Dump> maker_dump("dump");

Dump::Dump(std::list<std::string>& arguments) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
        log_name = *it;

}

std::vector<std::string> Dump::Do_command(std::vector<std::string>& some_text){
    text = some_text;
    log_file.open(log_name);

    if(!log_file.is_open())
            throw std::invalid_argument("file doesn't exist");

    for(const std::string& i : text)
    {
        log_file << i << std::endl;
    }
    log_file.close();
    return text;
}

Type_block Dump::Return_type_of_block() {
    return in_out;
}

