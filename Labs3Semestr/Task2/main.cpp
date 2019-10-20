#include "Parser.h"
#include "IWorker.h"

#include <cstring>

int main(int argc, char** argv) {
    if(argc < 2)
    {
        std::cout << "Not enough arguments!" << std::endl;
        return 0;
    }
    std::string name_of_workflow_file = argv[1];

    Readfile read_block(name_of_workflow_file);
    int read_scheme_status = read_block.Parser::Read_scheme();//Читаем схему
    
    if(Check_parser_for_errors(read_scheme_status) == 9 || Check_parser_for_errors(read_scheme_status) == 8)
    {
        //Если не был указан input-файл в схеме
        if(Check_parser_for_errors(read_scheme_status) == 9)
        {
            if(argc < 4)
            {
                std::cout << "No input file! Put it in the scheme or use key <-i>!" << std::endl;
                return 0;
            }
        }

        if(Check_parser_for_errors(read_scheme_status) == 8)
        {
            if(argc < 6)
            {
                std::cout << "No files for read and write. Check arguments or use keys!" << std::endl;
                return 0;
            }
        }

        //Проверяем наличие аргумента с соотвествующим ключом -i
        bool is_input_argv = false;
        for(int i = 2; i < argc - 1; i++)
        {
            if(strcmp(argv[i], "-i") == 0)
            {
                is_input_argv = true;
                if(strcmp(argv[i+1], "-o") != 0)
                {
                            //Функция которая установит имя input файла в список аргументов
                            std::string in = argv[i+1];
                            read_block.Parser::Set_input_file(in);
                }
                else
                {
                    std::cout << "No argument after key <-i>! Please, put the name of file" << std::endl;
                    return 0;
                }

            }
        }
        if(!is_input_argv)
        {
            std::cout << "No input file key!: <-i>" << std::endl;
            return 0;
        }
    }

    if(Check_parser_for_errors(read_scheme_status) == 10 || Check_parser_for_errors(read_scheme_status) == 8)
    {
        //Если не был укзаан out-файл в схеме
        if(Check_parser_for_errors(read_scheme_status) == 10)
        {
            if(argc < 4){
                std::cout << "No output file! Put it in the scheme or use key <-o>!" << std::endl;
                return 0;
            }
        }

        if(Check_parser_for_errors(read_scheme_status) == 8)
        {
            if(argc < 6)
            {
                std::cout << "No files for read and write. Check arguments or use keys!" << std::endl;
                return 0;
            }
        }

        bool is_output_argv = false;
        for(int i = 2; i < argc - 1; i++)
        {
            if(strcmp(argv[i], "-o") == 0)
            {
                is_output_argv = true;
                if(strcmp(argv[i+1], "-i") != 0)
                {
                    //Функция которая установит имя output файла в список аргументов
                    std::string out = argv[i+1];
                    read_block.Parser::Set_output_file(out);
                }
                else
                {
                    std::cout << "No argument after key <-o>! Please, put the name of file" << std::endl;
                    return 0;
                }
            }
        }
        if(!is_output_argv)
        {
            std::cout << "No output file key! <-o>" << std::endl;
            return 0;
        }
    }

    if (Check_parser_for_errors(read_scheme_status)!= 0 &&
      Check_parser_for_errors(read_scheme_status) != 10 &&
      Check_parser_for_errors(read_scheme_status) != 9 &&
      Check_parser_for_errors(read_scheme_status) != 8)
    {
        return 0;
    }

    if(read_block.Do_command() == 0)
    {
        std::cout << "Successfully read" << std::endl;
    } else
        return 0;

/*Выполняем команды в заданном порядке*/

    if(Executor_work(read_block))
    {
        std::cout << "Runtime error!" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Executor work complete" << std::endl;
    }

    return 0;
}