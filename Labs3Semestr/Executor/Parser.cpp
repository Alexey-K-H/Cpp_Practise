#include "Parser.h"

Parser::Parser() {
    number_of_read_command = -1;
    number_of_write_command = -2;
}

int Parser::Check_curr_block(std::string &line_in_scheme) {
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
    auto it = arguments_of_command.find(number);
    try {
        if(it != arguments_of_command.end())
            throw std::ios_base::failure("This number is already used!");
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return 1;
    }

    std::list<std::string> curr_arguments;
    int j = 0;
    std::string curr_word;
    char symbol;



    for(unsigned long i = 4; i < line_in_scheme.size(); i++)
    {
        symbol = line_in_scheme[i];
        if(symbol != ' ')
        {
            curr_word.insert(j, 1, symbol);
            j++;
        }
        else
        {
            if(!curr_word.empty())
            {
                curr_arguments.push_back(curr_word);
                j = 0;
                curr_word.clear();
            }
        }
    }

    if(!curr_word.empty())
    {
        curr_arguments.push_back(curr_word);
        curr_word.clear();
    }

    if(*(curr_arguments.begin()) == "readfile"){
        number_of_read_command = number;
    }
    if(*(curr_arguments.begin()) == "writefile"){
        number_of_write_command = number;
    }

    arguments_of_command.insert(std::pair<int, std::list<std::string>>(number, curr_arguments));
    return 0;
}

int Parser::Check_order_of_blocks(std::string &order) {

    //Если задана лишь одна команда
    if(order.size() == 1)
    {
        try{
            if(!isdigit(order[0]))
            {
                throw std::ios_base::failure("No order of blocks!");
            }
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return -1;
        }
        order_of_commands.push_back(atoi(&order[0]));
    }

    //Если задано несколько команд, то число знаков -> долно быть size-1
    unsigned int count_nodes = 0;
    auto pos = order.find("->", 0);
    while (pos != std::string::npos)
    {
        count_nodes++;
        pos = order.find("->", pos + 1);
    }

    unsigned int count_commands = 0;
    for(char &i : order)
    {
        if(isdigit(i))
        {
            count_commands++;
            order_of_commands.push_back(atoi(&i));
        }
    }

    try {
        if(count_nodes != count_commands - 1)
            throw std::ios_base::failure("Incorrect order of blocks. Problems with nodes!");
    }
    catch (std::exception &err)
    {
        std::cerr << "Error:" << err.what() << std::endl;
        return -1;
    }

    if(number_of_read_command >= 0 && number_of_write_command >= 0)
    {
        try {
            if(order_of_commands[0] != number_of_read_command || order_of_commands[order_of_commands.size()-1] != number_of_write_command)
                throw std::ios_base::failure("Incorrect order of blocks");

            //Проверка того, что команды записи и чтения не встретились где то еще кроме концов цепи
            for(unsigned long i = 1; i < order_of_commands.size() - 1; i++)
            {
                if(order_of_commands[i] == number_of_write_command || order_of_commands[i] == number_of_read_command)
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

    if(number_of_read_command >= 0 && number_of_write_command < 0)
    {
        try {
            if(order_of_commands[0] != number_of_read_command)
            {
                throw std::ios_base::failure("Incorrect order of blocks");//Неправильный порядок
            }
            for(unsigned long i = 1; i < order_of_commands.size() - 1; i++)
            {
                if(order_of_commands[i] == number_of_read_command)
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

    if(number_of_read_command < 0 && number_of_write_command >= 0)
    {
        try {
            if(order_of_commands[order_of_commands.size() - 1] != number_of_write_command)
            {
                throw std::ios_base::failure("Incorrect order of blocks");
            }
            for(unsigned long i = 1; i < order_of_commands.size() - 1; i++)
            {
                if(order_of_commands[i] == number_of_write_command)
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

void Parser::Set_read_command(std::string &input_name) {
    order_of_commands.push_front(number_of_read_command);
    arguments_of_command.insert(std::pair<int, std::list<std::string>>(number_of_read_command, {"readfile", input_name}));
}

void Parser::Set_write_command(std::string &output_name) {
    order_of_commands.push_back(number_of_write_command);
    arguments_of_command.insert(std::pair<int, std::list<std::string>>(number_of_write_command, {"writefile", output_name}));
}

int Parser::Read_scheme(std::string &name_of_workflow) {
    workflow_file.open(name_of_workflow);

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

    std::string curr_str_in_scheme;
    while (getline(workflow_file, curr_str_in_scheme))
    {
        bool is_open_key_word = false;
        if(curr_str_in_scheme == "desc")
        {
            is_open_key_word = true;
            bool is_close_key_word = false;

            while(curr_str_in_scheme != "csed" && !workflow_file.eof())
            {
                getline(workflow_file, curr_str_in_scheme);

                if(curr_str_in_scheme == "csed")
                {
                    is_close_key_word = true;
                }
                else
                {
                    int set_arguments_of_command_status = Check_curr_block(curr_str_in_scheme);
                    if(set_arguments_of_command_status)
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

        //Если не оказалось порядка выполнения блоков
        try {
            if(!getline(workflow_file, curr_str_in_scheme))
            {
                throw std::ios_base::failure("No order of the blocks!");
            }
        }
        catch (std::exception &err)
        {
            std::cerr << "Error:" << err.what() << std::endl;
            return 2;
        }

        if(Check_order_of_blocks(curr_str_in_scheme))
        {
            return -1;
        }
    }

    if(number_of_write_command < 0 && number_of_read_command < 0){
        return 8;
    }
    else if(number_of_read_command < 0){
        return 9;
    }
    else if(number_of_write_command < 0){
        return 10;
    }

    workflow_file.close();
    return 0;
}

