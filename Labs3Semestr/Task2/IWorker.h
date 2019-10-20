#ifndef LAB_2_IWORKER_H
#define LAB_2_IWORKER_H

#include "Parser.h"

class IWorker{
public:
    virtual int Do_command() = 0;
};

//Наследник двух классов, которые задаются в первую очередь
class Readfile: public IWorker, public Parser{
private:
    std::ifstream input;
    std::vector<std::string> text;
public:
    Readfile(std::string &workflow_file):
            Parser(workflow_file){}

    int Do_command() override;
    //void Print_text();


    //Остальные блоки - его друзья
    friend class Writefile;
    friend class Replace;
    friend class Grep;
    friend class Sort;
    friend class Dump;
};

//Классы остальных блоков - прямые наследники класса Readfile
class Writefile: public IWorker
{
private:
    std::ofstream output;
    Readfile *read_blk;
public:
    Writefile(Readfile *read_block):
            read_blk(read_block){}

    int Do_command() override;
};

class Replace: public IWorker
{
private:
    Readfile *read_blk;
public:
    Replace(Readfile *read_block):
            read_blk(read_block){}

    int Do_command() override;
};

class Grep: public IWorker
{
private:
    Readfile *read_blk;
public:
    Grep(Readfile *read_block):
            read_blk(read_block){}

    int Do_command() override;
};

class Sort: public IWorker
{
private:
    Readfile *read_blk;
public:
    Sort(Readfile *read_block):
            read_blk(read_block){}

    int Do_command() override;
};

class Dump: public IWorker
{
private:
    std::ofstream dump_out;
    Readfile *read_blk;
public:
    Dump(Readfile *read_block):
            read_blk(read_block){}

    int Do_command() override;
};


int Define_command(std::string &curr_com_block);
int Executor_work(Readfile &read_block_info);

#endif
