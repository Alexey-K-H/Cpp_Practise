#ifndef WORDEXECUTOR_IWORKER_H
#define WORDEXECUTOR_IWORKER_H

#include "Parser.h"

class IWorker{
public:
    virtual int Do_command() = 0;
};


class Readfile: public IWorker, public Parser{
protected:
    std::ifstream input;
    std::vector<char> text;
public:
    Readfile(std::string &workflow_file):
    Parser(workflow_file){
        Read_scheme();
    }

    int Do_command() override;
    void Print_text();
};

class Writefile: public Readfile
{
private:
    std::ofstream output;
public:
    Writefile(std::string &workflow_file):
    Readfile(workflow_file){
        Readfile::Do_command();
    }

    int Do_command() override;
};


#endif
