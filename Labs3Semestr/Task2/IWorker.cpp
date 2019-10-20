#include "IWorker.h"

int Readfile::Do_command() {
    input.open(input_file_name);

    //В случае если файл не существует
    try {
        if(!input.is_open())
        {
            throw std::ios_base::failure("file doesn't exist");
        }
    }
    catch (std::exception &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
        return 1;
    }

    std::string curr_line;
    while(getline(input, curr_line))
    {
        text.push_back(curr_line);
    }

    input.close();
    return 0;
}

int Writefile::Do_command() {
    output.open(read_blk->output_file_name);
    //В случае если файл не существует
    try {
        if(!output.is_open())
        {
            throw std::ios_base::failure("file doesn't exist");
        }
    }
    catch (std::exception &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
        return 1;
    }

    for(const std::string& i : read_blk->text)
    {
        output << i << std::endl;
    }
    output.close();
    return 0;
}

int Replace::Do_command() {
    for(std::string& i : read_blk->text)
    {
        int it_pos = i.find(read_blk->first_replace_arg, 0);
        while (it_pos != std::string::npos)
        {
            i.replace(it_pos, read_blk->first_replace_arg.size(), read_blk->second_replace_arg);
            it_pos = i.find(read_blk->first_replace_arg, it_pos);
        }
    }
    return 0;
}

int Grep::Do_command() {
    for(unsigned long long i = 0; i < read_blk->text.size(); i++)
    {
        int it_pos = read_blk->text[i].find(read_blk->grep_arg, 0);
        if(it_pos == std::string::npos)
        {
            read_blk->text.erase(read_blk->text.begin() + i);
        }
    }
    return 0;
}

int Dump::Do_command() {
    dump_out.open(read_blk->dump_file_name);
    //В случае если файл не существует
    try {
        if(!dump_out.is_open())
        {
            throw std::ios_base::failure("file doesn't exist");
        }
    }
    catch (std::exception &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
        return 1;
    }

    for(const std::string& i : read_blk->text)
    {
        dump_out << i << std::endl;
    }
    dump_out.close();
    return 0;
}

int Sort::Do_command() {
    std::sort(read_blk->text.begin(), read_blk->text.end());
    return 0;
}


int Define_command(std::string &curr_com_block)
{
    /*
      replace - 1
      grep - 2
      sort - 3
      dump - 4
      writefile - 5
    */
    if(curr_com_block == "replace")
    {
        return 1;
    }
    else if(curr_com_block == "grep")
    {
        return 2;
    }
    else if(curr_com_block == "sort")
    {
        return 3;
    }
    else if(curr_com_block == "dump")
    {
        return 4;
    }
    else if(curr_com_block == "writefile")
    {
        return 5;
    }
}

int Executor_work(Readfile &read_block_info)
{
    std::string curr_command;
    for(unsigned long i = 0; i < read_block_info.order_commands.size(); i++)
    {
        auto it = read_block_info.order_of_blocks.find(read_block_info.order_commands[i]);
        curr_command = it->second;

        switch (Define_command(curr_command))
        {
            case 1://-replace
            {
                Replace replace_block(&read_block_info);
                if(replace_block.Do_command() == 0)
                {
                    std::cout << "Successfully replaced" << std::endl;
                }
                else
                    return -1;
                break;
            }

            case 2://-grep
            {
                Grep grep_block(&read_block_info);
                if(grep_block.Do_command() == 0)
                {
                    std::cout << "Successfully greped" << std::endl;
                }
                else
                    return -1;
                break;
            }

            case 3://-sort
            {
                Sort sort_block(&read_block_info);
                if(sort_block.Do_command() == 0)
                {
                    std::cout << "Successfully sorted" << std::endl;
                }
                else
                    return -1;
                break;
            }

            case 4://-dump
            {
                Dump dump_block(&read_block_info);
                if(dump_block.Do_command() == 0)
                {
                    std::cout << "Successfully saved to dump-file" << std::endl;
                }
                else
                    return -1;
                break;
            }
            case 5://-writefile
            {
                Writefile write_block(&read_block_info);
                if(write_block.Do_command() == 0)
                {
                    std::cout << "Successfully saved" << std::endl;
                }
                else
                    return -1;
                break;
            }
        }
    }

    if(read_block_info.no_output_file)
    {
        Writefile write_block(&read_block_info);
        if(write_block.Do_command() == 0)
        {
            std::cout << "Successfully saved" << std::endl;
        }
        else
            return -1;
    }

    return 0;
}
