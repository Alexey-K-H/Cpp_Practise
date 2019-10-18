#include "Parser.h"

Parser::Parser(std::string &workflow_name) {
    workflow_file_name = workflow_name;
    number_of_read_command = -1;
    number_of_write_command = -1;
}

Parser::~Parser() {
    //std::cout << "destructor" << std::endl;
}

int Parser::Check_curr_block(std::string &line_in_scheme) {
    //Набор ключевых слов блоков
    std::string read_keyword = "readfile";
    std::string write_keyword = "writefile";

    std::string replace_keyword = "replace";
    std::string grep_keyword = "grep";
    std::string sort_keyword = "sort";
    std::string dump_keyword = "dump";

    //Проверяем наличие пордякового номера
    int number = 0;
    if(isdigit(line_in_scheme[0]))
    {
        char num = line_in_scheme[0];
        number = atoi(&num);
        if(number < 0)
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }


    //Делаем проверку на то, что данный номер уже не встречался раньше
    auto it = order_of_blocks.find(number);
    if(it != order_of_blocks.end()){
        return 1;
    }

    //Эти два блока обязательно должны быть описаны
    int read_pos = line_in_scheme.find(read_keyword);
    int write_pos = line_in_scheme.find(write_keyword);

    //Данные блоки могут встречаться, могут не встречаться
    int replace_pos = line_in_scheme.find(replace_keyword);
    int grep_pos = line_in_scheme.find(grep_keyword);
    int sort_pos = line_in_scheme.find(sort_keyword);
    int dump_pos = line_in_scheme.find(dump_keyword);

    //std::cout << read_pos << ' ' << write_pos << ' ' << replace_pos << ' ' << grep_pos << ' ' << sort_pos << ' ' << dump_pos << '\n';

    //Проверка для блока readfile///////////////////////////////////////////////////////////////////////////////////////
    if((read_pos >= 0) && (number >= 0))
    {
        int name_file_begin = 0;
        for(int i = read_pos; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++){
            name_file_begin = i;
        }
        name_file_begin += 2;
        if(name_file_begin > line_in_scheme.size())
        {
            return 2;//Нет указанного input файла для чтения
        }
        else
        {
            for(int k = name_file_begin, u = 0; k < line_in_scheme.size(); k++)
            {
                input_file_name.insert(u, 1, line_in_scheme[k]);
                u++;
            }

            //std::cout << "Input file:" << input_file_name << std::endl;
        }
        number_of_read_command = number;
        order_of_blocks.insert(std::make_pair(number, read_keyword));
    }
    else if(number < 0)
    {
        return 1;
    }

    //Проверка для блока writefile//////////////////////////////////////////////////////////////////////////////////////
    if((write_pos >= 0) && (number >= 0))
    {
        int name_file_begin = 0;
        for(int i = write_pos; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++){
            name_file_begin = i;
        }
        name_file_begin += 2;
        if(name_file_begin > line_in_scheme.size())
        {
            return 3;//Нет указанного output файла для записи
        }
        else
        {
            for(int k = name_file_begin, u = 0; k < line_in_scheme.size(); k++)
            {
                output_file_name.insert(u, 1, line_in_scheme[k]);
                u++;
            }

            //std::cout << "Output file:" << output_file_name << std::endl;
        }
        number_of_write_command = number;
        order_of_blocks.insert(std::make_pair(number, write_keyword));
    }
    else if(number < 0)
    {
        return 1;
    }

    //Проверка для блока replace////////////////////////////////////////////////////////////////////////////////////////
    if((replace_pos >= 0) && (number >= 0))
    {
        //Проверяем наличие первого аргумента
        int name_first_arg_begin = 0;
        for(int i = replace_pos; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++)
        {
            name_first_arg_begin = i;
        }
        name_first_arg_begin += 2;
        if(name_first_arg_begin > line_in_scheme.size())
        {
            return 4;//Некорректное задание команды replace
        }
        else
        {
            for(int k = name_first_arg_begin, u = 0; (k < line_in_scheme.size()) && (line_in_scheme[k] != ' '); k++)
            {
                first_replace_arg.insert(u, 1, line_in_scheme[k]);
                u++;
            }
            //std::cout << "First arg for replace command:" << first_replace_arg << std::endl;
        }

        //Проверяем наличие второго аргумента
        int name_second_arg_begin = 0;
        for(int i = name_first_arg_begin; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++)
        {
            name_second_arg_begin = i;
        }
        name_second_arg_begin += 2;
        if(name_second_arg_begin > line_in_scheme.size())
        {
            return 4;
        }
        else
        {
            for(int k = name_second_arg_begin, u = 0; k < line_in_scheme.size(); k++)
            {
                second_replace_arg.insert(u, 1, line_in_scheme[k]);
                u++;
            }
            //std::cout << "Second arg for replace command:" << second_replace_arg << std::endl;
        }
        order_of_blocks.insert(std::make_pair(number, replace_keyword));
    }
    else if(number < 0)
    {
        return 1;
    }

    //Проверка для блока grep///////////////////////////////////////////////////////////////////////////////////////////
    if((grep_pos >= 0) && (number >= 0))
    {
        int name_grep_arg = 0;
        for(int i = grep_pos; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++){
            name_grep_arg = i;
        }
        name_grep_arg += 2;
        if(name_grep_arg > line_in_scheme.size())
        {
            return 5;//Нет аргумента для команды grep
        }
        else
        {
            for(int k = name_grep_arg, u = 0; k < line_in_scheme.size(); k++)
            {
                grep_arg.insert(u, 1, line_in_scheme[k]);
                u++;
            }

            //std::cout << "Grep arg:" << grep_arg << std::endl;
        }
        order_of_blocks.insert(std::make_pair(number, grep_keyword));
    }
    else if(number < 0)
    {
        return 1;
    }

    //Проверка для блока sort///////////////////////////////////////////////////////////////////////////////////////////
    if((sort_pos >= 0) && (number >= 0))
    {
        order_of_blocks.insert(std::make_pair(number, sort_keyword));
    }
    else if(number < 0)
    {
        return 1;
    }

    //Проверка для блока dump///////////////////////////////////////////////////////////////////////////////////////////
    if((dump_pos >= 0) && (number >= 0))
    {
        int name_file_dump_begin = 0;
        for(int i = dump_pos; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++){
            name_file_dump_begin = i;
        }
        name_file_dump_begin += 2;
        if(name_file_dump_begin > line_in_scheme.size())
        {
            return 6;//Нет указанного dump файла
        }
        else
        {
            for(int k = name_file_dump_begin, u = 0; k < line_in_scheme.size(); k++)
            {
                dump_file_name.insert(u, 1, line_in_scheme[k]);
                u++;
            }

            //std::cout << "Dump file:" << dump_file_name << std::endl;
        }
        order_of_blocks.insert(std::make_pair(number, dump_keyword));
    }
    else if(number < 0)
    {
        return 1;
    }

    /*std::cout << "Commands and their indexes" << std::endl;
    for(auto & order_of_block : order_of_blocks)
    {
        std::cout << order_of_block.first << ' ' << order_of_block.second << '\n';
    }*/
    return 0;

}

int Parser::Check_order_of_blocks(std::string &order) {
    std::cout << "Order of blocks" << std::endl;
    std::cout << order << std::endl;

    /*std::cout << "Number of read command:" << number_of_read_command << std::endl;
    std::cout << "Number of write command:" << number_of_write_command << std::endl;*/

    for(char & i : order)
    {
        if(isdigit(i))
        {
            order_commands.push_back(atoi(&i));
        }
    }

    if(order_commands[0] != number_of_read_command || order_commands[order_commands.size() - 1] != number_of_write_command)
    {
        return -1;//Неправильный порядок
    }

    //Проверка того, что команды записи и чтения не встретились где то еще кроме концов цепи
    for(int i = 1; i < order_commands.size() - 1; i++)
    {
        if(order_commands[i] == number_of_write_command || order_commands[i] == number_of_read_command)
        {
            return -1;
        }
    }

    /*std::cout << "Vector order:" << std::endl;
    for(int order_command : order_commands)
    {
        std::cout << order_command << " ";
    }*/

    return 0;
}

int Parser::Read_scheme() {
    workflow_file.open(workflow_file_name);

    //Проверка того, что файл существует
    if(!workflow_file.is_open())
    {
        return 1;
    }

    //Идем по файлу
    std::string curr_str_scheme;
    while (getline(workflow_file, curr_str_scheme))
    {
        bool is_open_key_word = false;//Наличие открывающего слова dsec
        if(curr_str_scheme == "desc")
        {
            is_open_key_word = true;
            bool is_close_key_word = false;//Наличие зкрывающего слова csed
            while(curr_str_scheme != "csed" && !workflow_file.eof())
            {
                getline(workflow_file, curr_str_scheme);

                if(curr_str_scheme == "csed"){
                    is_close_key_word = true;
                }
                else
                {
                    int curr_block_check_status = Check_curr_block(curr_str_scheme);
                    switch (curr_block_check_status)
                    {
                        case 1: {
                            return 2;
                        }
                        case 2:{
                            return 3;
                        }
                        case 3:{
                            return 4;
                        }
                        case 4:{
                            return 5;
                        }
                        case 5:{
                            return 6;
                        }
                        case 6:{
                            return 7;
                        }
                    }

                }
            }

            if(!is_close_key_word)
            {
                return 2;
            }
        }

        if(!is_open_key_word && workflow_file.eof())
        {
            return 2;
        }

        getline(workflow_file, curr_str_scheme);
        bool is_order_of_blocks = false;//Наличие порядка выполнения блоков
        auto pointer = curr_str_scheme.find("->");//Проверка наличия символа пререхода в строке с порядком
        if(pointer)
        {
            is_order_of_blocks = true;
            if(Check_order_of_blocks(curr_str_scheme))
            {
                return -1;
            }
        }

        if(!is_order_of_blocks)
        {
            return 2;
        }
    }
    workflow_file.close();
    return 0;
}

int Check_parser_for_errors(int &returned_status)
{
    switch (returned_status)
    {
        case 1:{
            std::cout << "Workflow file doesn't exist!" << std::endl;
            return 1;
        }
        case 2:{
            std::cout << "Incorrect workflow file!" << std::endl;
            return 2;
        }
        case 3:{
            std::cout << "No input file for command <read>!" << std::endl;
            return 3;
        }
        case 4:{
            std::cout << "No output file for command <write>!" << std::endl;
            return 4;
        }
        case 5:{
            std::cout << "Incorrect definition for command <replace>!" << std::endl;
            return 5;
        }
        case 6:{
            std::cout << "Incorrect definition for command <grep>!" << std::endl;
            return 6;
        }
        case 7:{
            std::cout << "Incorrect definition for command <dump>!" << std::endl;
            return 7;
        }
        case -1:{
            std::cout << "Incorrect order of the commands!" << std::endl;
            return -1;
        }
        default:
            return 0;
    }
}

