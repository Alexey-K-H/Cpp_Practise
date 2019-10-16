#include "Word_Count_in_File.h"

int main(int argc, char** argv) {
    if (argc < 3)
    {
        std::cout << "Not enough arguments!" << std::endl;
    }
    else if(argc > 3)
    {
        std::cout << "To many arguments!" << std::endl;
    }
    else
    {
        std::string name_file = argv[1];
        Curr_file new_file;

        std::ofstream output;
        output.open(argv[2]);

        new_file.Create_map(name_file);
        new_file.Sort_map_by_value(output);

        output.close();
    }
    return 0;
}