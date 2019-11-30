#ifndef CSV_PARSER_CSV_PARSER_H
#define CSV_PARSER_CSV_PARSER_H

#include "parser_error.h"
#include "tuple_fill.h"
#include "tuple_print.h"

#include <vector>
#include <sstream>

//Разбить строку на несколько строк с учетом символа-разделителя
std::vector<std::string> divideString(std::string &str, char column_delimiter){
    std::vector<std::string> result;
    size_t k = 0;
    size_t i;

    std::string sub_str;

    for(i = 0; i < str.length();i++)
    {
        if(str[i] == column_delimiter){
            result.push_back(str.substr(i - k, k));
            k = 0;
        }
        else
        {
            k++;
        }
    }

    if(k > 0){
        result.push_back(str.substr(i - k, k));
    }

    return result;
}


template <typename ... Args>
class CSV_parser{
private:
    std::string input_file_name;
    int count_of_str = 0;//Количество строк в файле
    char delimiter;
public:
    CSV_parser(std::string name, char character = ';'): input_file_name(name), delimiter(character){
        //Проверка существоания файла
        std::ifstream in;
        in.open(input_file_name);
        if(!in.is_open()){
            throw std::invalid_argument("File can't be open!");
        }
        //Счиатем количество строк файла
        std::string str;
        while (std::getline(in, str)){
            count_of_str++;
        }

        in.close();
    }

    class CSVIterator{
    private:
        std::string name;
        size_t index;
        char delimiter;

    public:
        CSVIterator(const std::string name_of_input, size_t ind, char character){
            index = ind;
            name = name_of_input;
            delimiter = character;
        }

        CSVIterator &operator++(){
            index++;
            return *this;
        }

        std::tuple<Args...> operator*() const {
            //Открываем файл
            std::ifstream in;
            in.open(name);

            //Переходим к строке файла с номером ind
            int curr_row = -1;
            std::string curr_str;
            std::vector<std::string> vector_of_str;
            std::tuple<Args...> tuple;


            while(std::getline(in, curr_str)){
                curr_row++;
                if(curr_row == index){
                    vector_of_str = divideString(curr_str, delimiter);
                    if(vector_of_str.size() != sizeof...(Args))
                        throw parser_exception("Invalid number of parameters per line\n");

                    makeTuple<Args...>(tuple, vector_of_str, curr_row);
                    break;
                }
            }

            in.close();
            return tuple;
        }

        friend bool operator== (const CSVIterator & first, const CSVIterator& second)
        {
            return (first.index == second.index);
        }

        friend bool operator!= (const CSVIterator &first, const CSVIterator &second){
            return !(first == second);
        }
    };

    CSVIterator begin()const{
        return CSVIterator(input_file_name, 0, delimiter);
    }

    CSVIterator end()const{
        return CSVIterator(input_file_name, count_of_str, delimiter);
    }
};

#endif
