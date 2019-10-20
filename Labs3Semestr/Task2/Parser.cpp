#include "Parser.h"

Parser::Parser(std::string &workflow_name) {
    workflow_file_name = workflow_name;
    number_of_read_command = -1;
    number_of_write_command = -1;
    no_input_file = false;
    no_output_file = false;
}

void Parser::Set_input_file(std::string &in_name) {
    input_file_name = in_name;
}

void Parser::Set_output_file(std::string &out_name) {
    output_file_name = out_name;
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

        //Если номер оказался отрицательным
        try {
            if(number < 0)
            {
                throw std::invalid_argument("Wrong number of the command!");
            }
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 1;
        }
    }
    //Если вообще не оказался номером
    try {
        if(!isdigit(line_in_scheme[0]) || (line_in_scheme[2] != '='))
            throw std::invalid_argument("Number of block doesn't exist!");
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 1;
    }


    //Если оказалось, что данный номер уже встречался раньше
    auto it = order_of_blocks.find(number);
    try {
        if(it != order_of_blocks.end())
            throw std::ios_base::failure("This number is already used!");
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 1;
    }

    int read_pos = line_in_scheme.find(read_keyword);
    int write_pos = line_in_scheme.find(write_keyword);

    //Данные блоки могут встречаться, могут не встречаться
    int replace_pos = line_in_scheme.find(replace_keyword);
    int grep_pos = line_in_scheme.find(grep_keyword);
    int sort_pos = line_in_scheme.find(sort_keyword);
    int dump_pos = line_in_scheme.find(dump_keyword);

    //Если была введена неизветсная команда
    try {
        if(read_pos < 0 && write_pos < 0 && replace_pos < 0 && grep_pos < 0 && sort_pos < 0 && dump_pos < 0)
            throw std::ios_base::failure("Unknown command! What do you mean?");
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 1;
    }

    //Проверка для блока readfile///////////////////////////////////////////////////////////////////////////////////////
    if((read_pos >= 0) && (number >= 0))
    {
        int name_file_begin = 0;
        for(int i = read_pos; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++){
            name_file_begin = i;
        }
        name_file_begin += 2;

        //Если не был введен аргумент команды readfile
        try {
            if(name_file_begin > line_in_scheme.size())
                throw std::invalid_argument("No input file for command <read>!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 2;
        }

        for(unsigned long k = name_file_begin, u = 0; k < line_in_scheme.size(); k++)
        {
            input_file_name.insert(u, 1, line_in_scheme[k]);
            u++;
        }

        number_of_read_command = number;
        order_of_blocks.insert(std::make_pair(number, read_keyword));
    }

    //Проверка для блока writefile//////////////////////////////////////////////////////////////////////////////////////
    if((write_pos >= 0) && (number >= 0))
    {
        int name_file_begin = 0;
        for(int i = write_pos; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++){
            name_file_begin = i;
        }
        name_file_begin += 2;

        try {
            if(name_file_begin > line_in_scheme.size())
                throw std::invalid_argument("No output file for command <writefile>!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 3;//Нет указанного output файла для записи
        }

        for(unsigned long k = name_file_begin, u = 0; k < line_in_scheme.size(); k++)
        {
            output_file_name.insert(u, 1, line_in_scheme[k]);
            u++;
        }

        number_of_write_command = number;
        order_of_blocks.insert(std::make_pair(number, write_keyword));
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
        try {
            if(name_first_arg_begin > line_in_scheme.size())
                throw std::invalid_argument("No first argument for command <replace>!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 4;
        }

        for(int k = name_first_arg_begin, u = 0; (k < line_in_scheme.size()) && (line_in_scheme[k] != ' '); k++)
        {
            first_replace_arg.insert(u, 1, line_in_scheme[k]);
            u++;
        }

        //Проверяем наличие второго аргумента
        int name_second_arg_begin = 0;
        for(int i = name_first_arg_begin; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++)
        {
            name_second_arg_begin = i;
        }
        name_second_arg_begin += 2;
        try{
            if(name_second_arg_begin > line_in_scheme.size())
                throw std::invalid_argument("No second argument for command <replace>!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 4;
        }

        for(unsigned long k = name_second_arg_begin, u = 0; k < line_in_scheme.size(); k++)
        {
            second_replace_arg.insert(u, 1, line_in_scheme[k]);
            u++;
        }

        order_of_blocks.insert(std::make_pair(number, replace_keyword));
    }

    //Проверка для блока grep///////////////////////////////////////////////////////////////////////////////////////////
    if((grep_pos >= 0) && (number >= 0))
    {
        int name_grep_arg = 0;
        for(int i = grep_pos; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++){
            name_grep_arg = i;
        }
        name_grep_arg += 2;
        try {
            if(name_grep_arg > line_in_scheme.size())
                throw std::invalid_argument("No argument for command grep!");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 5;
        }

        for(unsigned long k = name_grep_arg, u = 0; k < line_in_scheme.size(); k++)
        {
            grep_arg.insert(u, 1, line_in_scheme[k]);
            u++;
        }

        order_of_blocks.insert(std::make_pair(number, grep_keyword));
    }

    //Проверка для блока sort///////////////////////////////////////////////////////////////////////////////////////////
    if((sort_pos >= 0) && (number >= 0))
    {
        order_of_blocks.insert(std::make_pair(number, sort_keyword));
    }

    //Проверка для блока dump///////////////////////////////////////////////////////////////////////////////////////////
    if((dump_pos >= 0) && (number >= 0))
    {
        int name_file_dump_begin = 0;
        for(int i = dump_pos; (line_in_scheme[i] != ' ') && (i < line_in_scheme.size()); i++){
            name_file_dump_begin = i;
        }
        name_file_dump_begin += 2;
        try {
            if(name_file_dump_begin > line_in_scheme.size())
                throw std::invalid_argument("No file for command <dump>!");
        }
        catch(std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 6;
        }

        for(unsigned long k = name_file_dump_begin, u = 0; k < line_in_scheme.size(); k++)
        {
            dump_file_name.insert(u, 1, line_in_scheme[k]);
            u++;
        }
        order_of_blocks.insert(std::make_pair(number, dump_keyword));
    }

    return 0;

}

int Parser::Check_order_of_blocks(std::string &order) {
    std::cout << "Order of blocks" << std::endl;
    std::cout << order << std::endl;

    for(char & i : order)
    {
        if(isdigit(i))
        {
            order_commands.push_back(atoi(&i));
        }
    }

    if(!no_input_file && !no_output_file)
    {
        try {
            if(order_commands[0] != number_of_read_command || order_commands[order_commands.size() - 1] != number_of_write_command)
            {
                throw std::ios_base::failure("Incorrect order of blocks");//Неправильный порядок
            }

            //Проверка того, что команды записи и чтения не встретились где то еще кроме концов цепи
            for(unsigned long i = 1; i < order_commands.size() - 1; i++)
            {
                if(order_commands[i] == number_of_write_command || order_commands[i] == number_of_read_command)
                {
                    throw std::ios_base::failure("Incorrect order of blocks");
                }
            }
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return -1;
        }

    }
    else if(!no_input_file && no_output_file)
    {
        try {
            if(order_commands[0] != number_of_read_command)
            {
                throw std::ios_base::failure("Incorrect order of blocks");//Неправильный порядок
            }
            for(unsigned long i = 1; i < order_commands.size() - 1; i++)
            {
                if(order_commands[i] == number_of_read_command)
                {
                    throw std::ios_base::failure("Incorrect order of blocks");
                }
            }
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return -1;
        }
    }
    else if(no_input_file && !no_output_file)
    {
        try {
            if(order_commands[order_commands.size() - 1] != number_of_write_command)
            {
                throw std::ios_base::failure("Incorrect order of blocks");
            }
            for(unsigned long i = 1; i < order_commands.size() - 1; i++)
            {
                if(order_commands[i] == number_of_write_command)
                {
                    throw std::ios_base::failure("Incorrect order of blocks");
                }
            }
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return -1;
        }
    }
    return 0;
}

int Parser::Read_scheme() {
    workflow_file.open(workflow_file_name);

    //В случае если файл не существует
    try {
        if(!workflow_file.is_open())
        {
            throw std::ios_base::failure("file doesn't exist");
        }
    }
    catch (std::exception &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
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
                    if(curr_block_check_status)
                        return 1;
                }
            }

            //В случае если не было закрывающего ключевого слова
            try {
                if(!is_close_key_word)
                {
                    throw std::ios_base::failure("Incorrect workflow file!");
                }
            }
            catch (std::exception &err)
            {
                std::cerr << "Error:" << err.what() << std::endl;
                return 2;
            }

            if(number_of_read_command < 0)
                no_input_file = true;
            if(number_of_write_command < 0)
                no_output_file = true;

        }

        try {
            if(!is_open_key_word)
                throw std::ios_base::failure("Incorrect workflow file");
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 2;
        }
        getline(workflow_file, curr_str_scheme);
        int pointer = curr_str_scheme.find("->");//Проверка наличия символа пререхода в строке с порядком

        try {
            if(pointer <= 0)
            {
                throw std::ios_base::failure("No order of the blocks!");
            }
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 2;
        }

        if(pointer > 0)
        {
            if(Check_order_of_blocks(curr_str_scheme))
            {
                return -1;
            }
        }

        if(no_input_file && no_output_file)
        {
            return 8;//Небоходима проверка наличи ключей для входного и выходного файла
        }
        else if(no_input_file)
        {
            return 9;//Проверка наличия ключа для входного файла
        }
        else if(no_output_file)
        {
            return 10;//Проврека наличия ключа для выходного файла
        }
    }
    workflow_file.close();
    return 0;
}
