#include <iostream>

#include "csv_parser.h"
#include "tuple_print.h"

int main()
{
    std::string input_file_name = "test.csv";
    try {
        CSV_parser<int, std::string> parser(input_file_name);
        for(std::tuple<int, std::string> rs : parser){
            std::cout << rs << std::endl;
        }
    }
    catch (std::invalid_argument &err){
        std::cerr << err.what() << std::endl;
    }
    catch (parser_exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return 0;
    }
    catch (type_mismatch &err)
    {
        std::cerr << err.what() << " row:" << err.get_row() << " column:" << err.get_column() << std::endl;
        return 0;
    }

    return 0;
}