#include "Parser.h"

int main() {
    std::string name = "workflow.txt";
    Parser list_of_commands(name);
    int read_scheme_status = list_of_commands.Read_scheme();//Читаем схему
    if(Check_parser_for_errors(read_scheme_status)){
        return 0;
    }

    return 0;
}