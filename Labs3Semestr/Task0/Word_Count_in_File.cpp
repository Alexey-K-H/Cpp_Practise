#include "Word_Count_in_File.h"

Curr_file::Curr_file() {
    count_words = 0;
}

void Curr_file::Create_map(std::string& name_file){
    input_file.open(name_file);
    if(!input_file.is_open())
    {
        std::cout << "Cannot open input file!" << std::endl;
        exit(0);
    } else{
    std::string curr_line_of_file;
    while(!input_file.eof())
    {
        getline(input_file, curr_line_of_file);
        std::string curr_word;
        int j = 0;
        char curr_symbol;
        for(char i : curr_line_of_file)
        {
            curr_symbol = tolower(i);//Считаем слова без учета регистра
            if(curr_symbol >= 'a' && curr_symbol <= 'z')
            {
                curr_word.insert(j, 1, curr_symbol);
                j++;
            }
            else
            if(curr_symbol >= '0' && curr_symbol <= '9')
            {
                curr_word.insert(j, 1, curr_symbol);
                j++;
            }
            else{
                if(!curr_word.empty())
                {
                    word_map[curr_word]++;
                    j = 0;
                    curr_word.clear();
                    count_words++;
                }
            }
        }
        //Чтобы вывести последнее слово из файла, в случае если нет разделителей в конце
        if(!curr_word.empty())
        {
            word_map[curr_word]++;
            curr_word.clear();
            count_words++;
        }
    }
    }
    input_file.close();
}

bool cmp(const std::pair<std::string, int>& first, const std::pair<std::string, int>& second)
{
    return first.second > second.second;
}

void Curr_file::Sort_map_by_value(std::ofstream& output){
    std::vector <std::pair <std::string, int>> vec(word_map.begin(), word_map.end());//Берем пары из множества map и помещаем их в вектор
    sort(vec.begin(), vec.end(), cmp);//Сортировка вектора с использованием предиката cmp
    output << "Word" << ";" << "Count" << ";" << "Frequency;" << std::endl;
    for(auto & it : vec){
        int freq = it.second;
        float percent = ((float)freq/(float)count_words)*100;//Частота в процентах
        output << it.first << ";" << it.second << ";" << std::fixed << std::setprecision(2) << percent << "%;" << std::endl;
    }
}

