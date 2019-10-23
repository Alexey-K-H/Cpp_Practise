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
    if(i == makers.end())
    {
        std::cout << "No this kind of block" << std::endl;
    }
    IBlockMaker* maker = i->second;
    return maker->Create(block_description);//IBlock maker сделает указатель на объект IBlock
}



//Блок READFILE
static BlockMaker<Readfile> maker_readfile("readfile");

Readfile::Readfile(std::list<std::string>& arguments) {
    auto it = arguments.begin();
    std::advance(it, 1);
    in_name = *it;
}

int Readfile::Do_command() {
    std::cout << "This is a readfile command!" << std::endl;
    std::cout << "Read from file:" << in_name << std::endl;
    return 0;
}

//Блок WRITEFILE
static BlockMaker<Writefile> make_writefile("writefile");

Writefile::Writefile(std::list<std::string> &arguments) {
    auto it = arguments.begin();
    std::advance(it, 1);
    out_name = *it;
}

int Writefile::Do_command() {
    std::cout << "This is a writefile command!" << std::endl;
    std::cout << "Write to file:" << out_name << std::endl;
    return 0;
}

//Блок GREP
static BlockMaker<Grep> makegrep("grep");

Grep::Grep(std::list<std::string> &arguments) {
    auto it = arguments.begin();
    std::advance(it, 1);
    argument_grep = *it;
}

int Grep::Do_command() {
    std::cout << "This is a grep command!" << std::endl;
    std::cout << "Choose strings with keyword:" << argument_grep << std::endl;
    return 0;
}

//Блок SORT


//Блок REPLACE
static BlockMaker<Replace> maker_replace("replace");

Replace::Replace(std::list<std::string> &arguments) {
    auto it = arguments.begin();
    std::advance(it, 1);
    first_replace_arg = *it;

    std::advance(it, 1);
    second_replace_arg = *it;
}

int Replace::Do_command() {
    std::cout << "This is replace command!" << std::endl;
    std::cout << "Replace str:" << first_replace_arg << " to str:" << second_replace_arg << std::endl;
    return 0;
}

//Блок DUMP
