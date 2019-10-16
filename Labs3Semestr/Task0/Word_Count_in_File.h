#ifndef WORDCOUNTER_WORD_COUNT_IN_FILE_H
#define WORDCOUNTER_WORD_COUNT_IN_FILE_H

#include <iostream>
#include <string>//Работа со строками
#include <map>//Работа с множеством
#include <fstream>//Работа с файлами
#include <vector>//Работа с вектором
#include <algorithm>//Для реализации алгоритма sort
#include <iomanip>//Для корректировки ввода значений частоты в %


class Curr_file{
private:
    std::ifstream input_file;
    std::map<std::string, int> word_map;
    unsigned int count_words;
public:
    Curr_file();
    void Create_map(std::string& name_file);
    void Sort_map_by_value(std::ofstream& output);
};

bool cmp(const std::pair<std::string, int>& first, const std::pair<std::string, int>& second);

#endif
