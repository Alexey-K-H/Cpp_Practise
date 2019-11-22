#include <iostream>

#include "csv_parser.h"
#include "tuple_print.h"

int main() {

    std::ifstream inputFile("test.csv");
    if (!inputFile.is_open()) {
        std::cerr << "File can't be open!\n";
        return 0;
    }

    try {
        CSV_parser<int, std::string> parser(&inputFile);
        for(std::tuple<int, std::string> rs : parser){
            std::cout << rs << std::endl;
        }
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