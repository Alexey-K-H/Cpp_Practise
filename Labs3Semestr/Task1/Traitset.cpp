#include "Traitset.h"
#include "Trait_operations.h"

//Конструктор
Trait_set::Trait_set(int size) {
    size_of_set = size;
    if(size_of_set < 0)
        throw std::invalid_argument("Size cannot be a negative number!");
    if(size_of_set <= 4 && size_of_set > 0)
    {
        capacity = 1;
        set.resize(capacity);
    }
    else
    {
        if(size%4 == 0)
        {
            if(size == 0)
            {
                capacity = 0;
                set.resize(capacity);
            }
            else
            {
                capacity = size/4;
                set.resize(capacity);
            }
        }
        else
        {
            capacity = size/4 + 1;
            set.resize(capacity);
        }
    }
}

//Опреатор индексации
Trait_set::Reference Trait_set::operator[](int trait_index) {
    if(trait_index < 0)
        throw std::invalid_argument("Index cannot be a negative number!");
    return Reference(this, trait_index);
}

Trait Trait_set::operator[](int trait_index) const {
    if(trait_index < 0)
        throw std::invalid_argument("Index cannot be a negative!");
    return Get_Trait_value(this->set, trait_index%4, trait_index, size_of_set);
}

//Конструктор копирования
Trait_set::Trait_set(const Trait_set &trait_set) {
    set = trait_set.set;
    size_of_set = trait_set.size_of_set;
    capacity = trait_set.capacity;
}

//Логические операции
//Логическое ИЛИ
Trait_set Trait_set::operator|(const Trait_set &set_2) {
    int max_size = 0;
    if(this->size_of_set >= set_2.size_of_set)
    {
        max_size = size_of_set;
    }
    else
    {
        max_size = set_2.size_of_set;
    }

    Trait_set resultSet(max_size);
    Trait value_1;
    Trait value_2;

    for(int i = 0; i < max_size; i++)
    {
        value_1 = (*this)[i];
        value_2 = set_2[i];
        resultSet[i] = value_1 | value_2;
    }
    return resultSet;
}

//Логическое И
Trait_set Trait_set::operator&(const Trait_set &set_2) {
    int max_size = 0;
    if(this->size_of_set >= set_2.size_of_set)
    {
        max_size = size_of_set;
    }
    else
    {
        max_size = set_2.size_of_set;
    }

    Trait_set resultSet(max_size);
    Trait value_1;
    Trait value_2;

    for(int i = 0; i < max_size; i++)
    {
        value_1 = (*this)[i];
        value_2 = set_2[i];
        resultSet[i] = value_1 & value_2;
    }
    return resultSet;
}

//Логическое НЕ
Trait_set Trait_set::operator~() {
    Trait_set resultSet(size_of_set);
    Trait value;
    for(int i = 0; i < size_of_set; i++)
    {
        value = Get_Trait_value(this->set, i%4, i, this->size_of_set);
        resultSet[i] = ~(value);
    }
    return resultSet;
}

//Опреатор присваивания
Trait_set& Trait_set::operator=(Trait def_value) {
    for(int i = 0; i < size_of_set; i++)
    {
        Set_Trait(set, i%4, i, def_value);
    }
    return *this;
}

//Освобождение памяти до последнего установленного значения трита
void Trait_set::Shrink() {
    int index_exist = 0;
    Trait curr_trait;
    for(int i = 0; i < this->size_of_set; i++)
    {
        curr_trait = (*this)[i];
        if(curr_trait != Unknown)
        {
            index_exist = i;
        }
    }

    if(index_exist < this->size_of_set - 1)
    {
        if(index_exist < 4)
        {
            this->capacity = 1;
        }
        else
        {
            if(index_exist % 4 == 0)
            {
                this->capacity = index_exist/4 + 1;
            }
            else
             this->capacity = (int)ceil((double)index_exist/4);
        }
        this->size_of_set = index_exist + 1;
        this->set.resize(this->capacity);
    }
}

//Вернуть значение capacity
int Trait_set::Capacity() {
    return capacity;
}

//Вернуть значение size
int Trait_set::Size() {
    return size_of_set;
}

//Число установленных в данное значение трит
unsigned int Trait_set::Cardinality(Trait value) {
    Trait curr_val;
    unsigned int stat = 0;
    for(int i = 0; i < this->size_of_set; i++)
    {
        curr_val = (*this)[i];
        if(curr_val == value)
        {
            stat++;
        }
    }
    return stat;
}

//Общая статистика cardinality
std::unordered_map<Trait , int> Trait_set::Cardinality() {
    std::unordered_map<Trait,int> stat;
    stat[False] = 0;
    stat[True] = 0;
    stat[Unknown] = 0;
    Trait curr_value;
    for(int i = 0; i < this->size_of_set; i++)
    {
        curr_value = (*this)[i];
        switch (curr_value)
        {
            case Unknown:
            {
                stat[Unknown]++;
            }
                break;
            case False:
            {
                stat[False]++;
            }
                break;
            case True:
            {
                stat[True]++;
            }
                break;
        }
    }
    return stat;
}

//Оператор вывода трита
std::ostream& operator<<(std::ostream &out, Trait_set &set) {
    for(int i = 0; i < set.size_of_set; i++)
    {
        out << "[" << i << "]:" <<set[i] << std::endl;
    }
    return out;
}

//Забыть содержимое от last_index и дальше
void Trait_set::Trim(int last_index) {
    int new_size = this->size_of_set - (this->size_of_set - last_index);
    this->size_of_set = new_size;
    if(new_size <= 4)
    {
        this->capacity = 1;
    }
    else
    {
        int new_capacity = (int)ceil((double)new_size/4);
        this->set.resize(new_capacity);
    }
}

//Логическая длинна тритсета
unsigned int Trait_set::Logical_length() {
    unsigned int last_index = -1;
    Trait curr_val;
    for(int i = 0; i < this->size_of_set; i++)
    {
        curr_val = (*this)[i];
        if(curr_val != Unknown)
        {
            last_index = i;
        }
    }
    return last_index + 1;
}

//Reference methods
Trait_set::Reference::Reference(Trait_set *curr_trait_set, int index) {
    trait_set = curr_trait_set;
    index_trait = index;
}

//Опрератор присваивания
Trait_set::Reference& Trait_set::Reference::operator=(Trait trait) {
    if((index_trait >= trait_set->size_of_set) && (trait != Unknown))//Если мы вышли за пределы массива и значение не Unknown
    {
        int new_capacity = 0;
        if(index_trait%4 == 0 && index_trait > 4)
        {
            new_capacity = index_trait/4 + 1;
        }
        else
        {
            new_capacity = (int)ceil((double)index_trait/4);
        }
        trait_set->set.resize(new_capacity);//Расширяем вектор
        trait_set->size_of_set = index_trait + 1;
        trait_set->capacity = new_capacity;
        Set_Trait(trait_set->set, index_trait%4, index_trait, trait);
    }
    else//Если выхода за гарницы не было то добавляем в соответствующую ячейку
    {
        Set_Trait(trait_set->set, index_trait%4, index_trait, trait);
    }
    //В противном случае ничего никуда не добавляется
    return *this;
}

Trait_set::Reference& Trait_set::Reference::operator=(const Reference &ref) {
    *this = (Trait)ref;
     return *this;
}

//Оператор приведения типов
Trait_set::Reference::operator Trait () const{
    return Get_Trait_value(trait_set->set, index_trait%4, index_trait, trait_set->size_of_set);
}

//Оператор вывода трит
std::ostream& operator<< (std::ostream& out, const Trait_set::Reference& ref) {
    Trait value = Get_Trait_value(ref.trait_set->set, ref.index_trait%4, ref.index_trait, ref.trait_set->size_of_set);
    if(value == True)
    {
        out << "True";
    }
    else if(value == False)
    {
        out << "False";
    }
    else
    {
        out << "Unknown";
    }
    return out;
}

//Оператор для более удобного вывода значений enum
std::ostream& operator<< (std::ostream& out, Trait value){
    if(value == True)
    {
        out << "True";
    }
    else if(value == False)
    {
        out << "False";
    }
    else
        out << "Unknown";

    return out;
}
