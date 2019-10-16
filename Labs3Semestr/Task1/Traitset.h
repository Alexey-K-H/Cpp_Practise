#ifndef LAB_1_1_TRAITSET_H
#define LAB_1_1_TRAITSET_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

enum Trait{
    Unknown,//00
    False,//01
    True//10
};


class Trait_set{
public:
    //Вложенный класс Reference
    class Reference{
        friend class Trait_set;
    private:
        Trait_set *trait_set;
        int index_trait;//Индекс текущего трита
    public:
        Reference(Trait_set *curr_trait_set, int index);
        Reference& operator=(Trait trait);
        Reference& operator=(const Reference& ref);
        operator Trait () const;
        friend std::ostream& operator<< (std::ostream& out, const Reference& ref);
    };
private:
    int capacity;
public:
    std::vector<unsigned char> set;
    int size_of_set;
    //Методы основного класса
    Trait_set(int size);

    //Оператор индексации
    Reference operator[] (int trait_index);
    Trait operator[](int trait_index)const;

    //Конструктор копирования
    Trait_set(const Trait_set &trait_set);

    //Логические операторы для тритсетов
    Trait_set operator |(const Trait_set &set_2);
    Trait_set operator &(const Trait_set &set_2);
    Trait_set operator ~();

    //Опреатор присваивания всему тритсету(задать начальное значение для всех тритов)
    Trait_set& operator =(Trait def_value);

    //Освободить память до последнего установленного трита
    void Shrink();

    //Вернуть вместимость тритсета
    int Capacity();

    //Вернуть размер тритсета
    int Size();

    //Число установленных в данное значение трнитов
    unsigned int Cardinality(Trait value);

    //Общая статистика
    std::unordered_map<Trait , int> Cardinality();

    //Опреатор вывода трита
    friend std::ostream& operator<< (std::ostream& out, Trait_set &set);

    //Забыть содержимое от last index и дальше
    void Trim(int last_index);

    //Логическая длинна
    unsigned int Logical_length();
};

//Оператор вывода для случая если в качетсве аргумента передается значение enum
std::ostream& operator<< (std::ostream& out, Trait value);

#endif
