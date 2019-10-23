#ifndef EXECUTOR_BLOCKS_H
#define EXECUTOR_BLOCKS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <stdexcept>


//Базовый интерфейс для блока (определенные нами блоки являются его наследниками)
class IBlock
{
public:
    virtual int Do_command() = 0;
    virtual ~IBlock() = default;
};

//Класс интерфейс для создателей блоков
class IBlockMaker
{
public:
    virtual IBlock* Create(std::list<std::string>& block_description) = 0;
    virtual ~IBlockMaker() = default;
};

//Класс-синглтон, который реализует фабрику по созданию блоков
class BlockFactory
{
public:
    void RegisterMaker(const std::string& key, IBlockMaker * maker);
    static BlockFactory& Instance();//Создает один объект класса и возвращает ссылку на него
    IBlock* Create(std::list<std::string>& block_description);

private:
    std::map<std::string, IBlockMaker*> makers;
};

//Шаблонный класс, который будет создавать блок с конкретным именем
template <typename T>
class BlockMaker : public IBlockMaker
{
public:
    BlockMaker(const std::string& key)
    {
        BlockFactory::Instance().RegisterMaker(key, this);
    }
    IBlock* Create(std::list<std::string>& block_description) override
    {
        return new T(block_description);
    }
};

//Блок READFILE
class Readfile : public IBlock {
public:
    Readfile(std::list<std::string>& arguments);
    int Do_command() override;

private:
    std::string in_name;//Содержит имя файла, который мы подаем в наш блок из списка аргументов
    std::ifstream input_file;//Файл для чтения и получения из него текста
    std::vector<std::string> text;//Текст который мы считаем из нашего файла
};

//Блок WRITEFILE
class Writefile : public IBlock{
public:
    Writefile(std::list<std::string>& arguments);
    int Do_command() override;

private:
    std::string out_name;
    std::ofstream output_file;
};

//Блок GREP
class Grep : public IBlock{
public:
    Grep(std::list<std::string>& arguments);
    int Do_command() override;

private:
    std::string argument_grep;
};

//Блок REPLACE
class Replace: public IBlock{
public:
    Replace(std::list<std::string>& arguments);
    int Do_command() override;

private:
    std::string first_replace_arg;
    std::string second_replace_arg;
};
#endif
