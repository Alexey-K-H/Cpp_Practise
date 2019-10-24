#include "Blocks.h"

//Создание нашей фабрики
BlockFactory& BlockFactory::Instance() {
    static BlockFactory factory;
    return factory;
}

void BlockFactory::RegisterMaker(const std::string &key, IBlockMaker *maker) {
    makers[key] = maker;
}

IBlock* BlockFactory::Create(std::list<std::string>& block_description, std::vector<std::string> & text) {
    std::string key = *(block_description.begin());//Предполагается что первая строка в списке - имя блока
    auto i = makers.find(key);
    //Если команда не была определена
    try {
        if(i == makers.end())
            throw std::invalid_argument("No such kind of command!");
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return nullptr;
    }
    IBlockMaker* maker = i->second;
    return maker->Create(block_description, text);//IBlock maker сделает указатель на объект IBlock
}



//Блок READFILE
static BlockMaker<Readfile> maker_readfile("readfile");

Readfile::Readfile(std::list<std::string>& arguments, std::vector<std::string>& some_text) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
      in_name = *it;
    text = some_text;
}

int Readfile::Do_command() {
    input_file.open(in_name);
    try {
        if(!input_file.is_open())
        {
            throw std::ios_base::failure("file doesn't exist");
        }
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 1;
    }

    text.clear();
    std::string curr_line;
    while (getline(input_file, curr_line))
    {
        text.push_back(curr_line);
    }

    input_file.close();
    return 0;
}

std::vector<std::string> Readfile::Return_result_text() {
    return text;
}

//Блок WRITEFILE
static BlockMaker<Writefile> make_writefile("writefile");

Writefile::Writefile(std::list<std::string> &arguments, std::vector<std::string>& some_text) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
      out_name = *it;
    text = some_text;
}

int Writefile::Do_command() {
    output_file.open(out_name);
    try {
        if(!output_file.is_open())
            throw std::ios_base::failure("file doesn't exist");
    }
    catch (std::exception& err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 1;
    }

    for(const std::string& i : text){
        output_file << i << std::endl;
    }
    output_file.close();
    return 0;
}

std::vector<std::string> Writefile::Return_result_text() {
    return text;
}

//Блок GREP
static BlockMaker<Grep> makegrep("grep");

Grep::Grep(std::list<std::string> &arguments, std::vector<std::string>& some_text) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
    {
        argument_grep = *it;
    }
    text = some_text;
}

int Grep::Do_command() {
    try {
        if(argument_grep.empty())
            throw std::invalid_argument("No argument for command grep!");
    }
    catch (std::exception& err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 1;
    }

    for(unsigned long long i = 0; i < text.size(); i++)
    {
        int it_pos = text[i].find(argument_grep, 0);
        if(it_pos == std::string::npos)
        {
            text.erase(text.begin() + i);
        }
    }
    return 0;
}

std::vector<std::string> Grep::Return_result_text() {
    return text;
}

//Блок SORT
static BlockMaker<Sort> maker_sort("sort");

Sort::Sort(std::list<std::string> &arguments, std::vector<std::string>& some_text):text(some_text){}

int Sort::Do_command() {
    std::sort(text.begin(), text.end());
    return 0;
}

std::vector<std::string> Sort::Return_result_text() {
    return text;
}

//Блок REPLACE
static BlockMaker<Replace> maker_replace("replace");

Replace::Replace(std::list<std::string> &arguments, std::vector<std::string>& some_text) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
       first_replace_arg = *it;

    std::advance(it, 1);
    if(it != arguments.end())
       second_replace_arg = *it;

    text = some_text;
}

int Replace::Do_command() {
    try{
        if(first_replace_arg.empty() || second_replace_arg.empty())
        throw std::invalid_argument("Not enough argument for replace!");
    }
    catch (std::exception& err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 1;
    }

    for(std::string& i : text)
    {
        int it_pos = i.find(first_replace_arg, 0);
        while (it_pos != std::string::npos)
        {
            i.replace(it_pos, first_replace_arg.size(), second_replace_arg);
            it_pos = i.find(first_replace_arg, it_pos);
        }
    }
    return 0;
}

std::vector<std::string> Replace::Return_result_text() {
    return text;
}

//Блок DUMP
static BlockMaker<Dump> maker_dump("dump");

Dump::Dump(std::list<std::string>& arguments, std::vector<std::string>& some_text) {
    auto it = arguments.begin();
    std::advance(it, 1);
    if(it != arguments.end())
       log_name = *it;
    text = some_text;
}

int Dump::Do_command() {
    log_file.open(log_name);
    try {
        if(!log_file.is_open())
            throw std::ios_base::failure("file doesn't exist");
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 1;
    }

    for(const std::string& i : text)
    {
        log_file << i << std::endl;
    }
    log_file.close();
    return 0;
}

std::vector<std::string> Dump::Return_result_text() {
    return text;
}