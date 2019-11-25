#ifndef CSV_PARSER_TUPLE_FILL_H
#define CSV_PARSER_TUPLE_FILL_H

#include <tuple>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#include "parser_error.h"

template<typename T> T from_string(const std::string &str, int N, int curr_row)
{
    std::stringstream ss;
    ss << str;
    T t;
    ss >> t;
    
    if(ss.fail()){
        throw type_mismatch("Type mismatch, problems in position", N, curr_row);
    }
    return t;
}

template<> std::string from_string(const std::string &str, int N, int curr_row)
{
    return str;
}

//Заполнение последовательности N - индекс элемента последовательности (0 < N < Size(Argc))
template <typename Tuple, unsigned N, unsigned Size>
struct fillTuple{
    static void fill(Tuple &tuple, const std::vector<std::string> &vector, int curr_row){
        try {
            std::get<N>(tuple) = from_string<int>(vector[N], N, curr_row);
            //Проверяем следующий шаг
            fillTuple<Tuple, N + 1, Size>::fill(tuple, vector, curr_row);
        }
        catch (type_mismatch &err){
            throw err;
        }
    }
};

//Случай когда N = Size(дошли до конца)
template <typename Tuple, unsigned N>
struct fillTuple<Tuple, N, N>{
    static void fill(Tuple &tuple, const std::vector<std::string> &vector, int curr_row){
        std::get<N>(tuple) = from_string<std::string>(vector[N], N, curr_row);
    }
};

//Слуйчай если размер последовательности равен 0
template <typename Tuple, unsigned N>
struct fillTuple<Tuple, N, 0>{
    static void fill(Tuple &tuple, const std::vector<std::string> &vector, int curr_row){}
};

//Создание последовательности из данных CSV файла
template <typename...Argc>
void makeTuple(std::tuple<Argc...> &arg, std::vector<std::string> &vector_of_str, int curr_row){
    try {
        fillTuple<std::tuple<Argc...>, 0, sizeof...(Argc) - 1>::fill(arg, vector_of_str, curr_row);
    }
    catch (type_mismatch &err){
        throw err;
    }
}

#endif
