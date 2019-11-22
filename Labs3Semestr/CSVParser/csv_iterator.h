#ifndef CSV_PARSER_CSV_ITERATOR_H
#define CSV_PARSER_CSV_ITERATOR_H

#include <tuple>
#include <fstream>
#include <iostream>
#include <vector>
#include "tuple_fill.h"

template <typename...Argc>
class CSVIterator{
private:
    const std::vector<std::tuple<Argc...>> & tuple_vector;
    size_t index;
public:
    CSVIterator(const std::vector<std::tuple<Argc...>> & tuple_vec, size_t ind):
    tuple_vector(tuple_vec){
        index = ind;
    }

    CSVIterator &operator++(){
        index++;
        return *this;
    }

    std::tuple<Argc...> operator*() const {
        return tuple_vector[index];
    }

    friend bool operator== (const CSVIterator & first, const CSVIterator& second)
    {
        return (&first.tuple_vector == &second.tuple_vector) && (first.index == second.index);
    }

    friend bool operator!= (const CSVIterator &first, const CSVIterator &second){
        return !(first == second);
    }
};

#endif
