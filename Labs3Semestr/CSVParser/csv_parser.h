#ifndef CSV_PARSER_CSV_PARSER_H
#define CSV_PARSER_CSV_PARSER_H

#include "parser_error.h"
#include "tuple_fill.h"
#include "tuple_print.h"
#include "csv_iterator.h"

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
    std::ifstream *input;
    std::vector<std::tuple<Args...>> tuple_vector;
public:
    CSV_parser(std::ifstream *in, char character = ';'): input(in){
        int curr_row = 0;
        std::string curr_str;
        std::vector<std::string> vector_of_str;
        std::tuple<Args...> tuple;

        //Идём по файлу
        while (std::getline(*input, curr_str)){
            vector_of_str = divideString(curr_str, character);

            if(vector_of_str.size() != sizeof...(Args))
                throw parser_exception("Invalid number of parameters per line\n");

            try {
                makeTuple<Args...>(tuple, vector_of_str, curr_row);
                tuple_vector.push_back(tuple);
            }
            catch (type_mismatch &err){
                throw err;
            }

            curr_row++;
        }
    }

    CSVIterator<Args...>begin()const{
        return CSVIterator<Args...>(tuple_vector, 0);
    }

    CSVIterator<Args...>end()const{
        return CSVIterator<Args...>(tuple_vector, tuple_vector.size());
    }
};


#endif
