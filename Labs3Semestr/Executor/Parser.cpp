#include "Parser.h"

int Parser::Check_curr_block(std::string &line_in_scheme) {
    //Проверяем наличие пордякового номера
    int number = 0;
    int curr_char = 0;
    while (isdigit(line_in_scheme[curr_char])) {
        char num = line_in_scheme[curr_char];
        number += atoi(&num) * pow(10, curr_char);
        curr_char++;
    }

    if (!isdigit(line_in_scheme[0]) || (line_in_scheme[curr_char + 1] != '='))
        throw std::invalid_argument("Number of block didn't init!");

    //Если оказалось, что данный номер уже встречался раньше
    auto it = arguments_of_command.find(number);
    if (it != arguments_of_command.end())
        throw std::invalid_argument("Number of block is already used!");

    std::list<std::string> curr_arguments;
    int j = 0;
    std::string curr_word;
    char symbol;


    for (unsigned long i = 4; i < line_in_scheme.size(); i++) {
        symbol = line_in_scheme[i];
        if (symbol != ' ') {
            curr_word.insert(j, 1, symbol);
            j++;
        } else {
            if (!curr_word.empty()) {
                curr_arguments.push_back(curr_word);
                j = 0;
                curr_word.clear();
            }
        }
    }

    if (!curr_word.empty()) {
        curr_arguments.push_back(curr_word);
        curr_word.clear();
    }

    arguments_of_command.insert(std::pair<int, std::list<std::string>>(number, curr_arguments));
    return 0;
}

int Parser::Read_scheme(std::string &name_of_workflow){
    workflow_file.open(name_of_workflow);

    //В случае если файл не существует
    if(!workflow_file.is_open()){
        throw std::invalid_argument("file doesn't exist");
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
                    try {
                        Check_curr_block(curr_str_in_scheme);
                    }
                    catch (std::exception &err)
                    {
                        throw std::logic_error(err.what());
                    }
                }
            }

            //В случае если не было закрывающего ключевого слова
            if(!is_close_key_word)
            {
                throw std::invalid_argument("Incorrect workflow file!");
            }
        }
        if(!is_open_key_word)
            throw std::invalid_argument("Incorrect workflow file");

        //Если не оказалось порядка выполнения блоков
        if(!getline(workflow_file, curr_str_in_scheme)){
            throw std::logic_error("No order of the blocks!");
        }
        order = curr_str_in_scheme;
    }
    workflow_file.close();
    return 0;
}

