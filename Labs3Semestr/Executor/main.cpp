#include <iostream>
#include <cstring>
#include "Parser.h"

int main(int argc, char** argv) {
    try {
        if(argc < 2)
            throw std::invalid_argument("No workflow file!");
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 0;
    }

    std::string name_of_workflow = argv[1];

    Parser new_workflow;
    int read_block_scheme_status = new_workflow.Read_scheme(name_of_workflow);

    if(read_block_scheme_status == 9 || read_block_scheme_status == 8)
    {
        try {
            if(read_block_scheme_status == 9 && argc < 4)
                throw std::logic_error("No input file! Put it in the scheme or use key <-i>!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 0;
        }

        try {
            if(read_block_scheme_status == 8 && argc < 6)
                throw std::logic_error("No files for read and write. Check arguments or use keys!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 0;
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
                    new_workflow.Set_read_command(in);
                }
                try {
                    if(strcmp(argv[i+1], "-o") == 0)
                        throw std::logic_error("No argument after key <-i>! Please, put the name of file");
                }
                catch (std::exception &err)
                {
                    std::cerr << "Error:" << err.what() << std::endl;
                    return 0;
                }


            }
        }
        try {
            if(!is_input_argv)
                throw std::logic_error("No input file key!: <-i>");
        }
        catch(std::exception &err){
            std::cerr << "Error:" << err.what() << std::endl;
            return 0;
        }
    }

    if(read_block_scheme_status == 10 || read_block_scheme_status == 8)
    {
        try {
            if(read_block_scheme_status == 10 && argc < 4)
                throw std::logic_error("No output file! Put it in the scheme or use key <-o>!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 0;
        }

        try {
            if(read_block_scheme_status == 8 && argc < 6)
                throw std::logic_error("No files for read and write. Check arguments or use keys!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 0;
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
                    new_workflow.Set_write_command(out);
                }
                try {
                    if(strcmp(argv[i+1], "-i") == 0)
                        throw std::logic_error("No argument after key <-o>! Please, put the name of file");
                }
                catch (std::exception &err)
                {
                    std::cerr << "Error:" << err.what() << std::endl;
                    return 0;
                }
            }
        }
        try {
            if(!is_output_argv)
                throw std::logic_error("No output file key! <-o>");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 0;
        }
    }

    if (read_block_scheme_status != 0 && read_block_scheme_status != 10 && read_block_scheme_status != 9 && read_block_scheme_status != 8){
        return 0;
    }

    if(Execute_work(new_workflow)){
        return 0;
    }
    else{
        std::cout << "Successfully!" << std::endl;
    }

    return 0;
}