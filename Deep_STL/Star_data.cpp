#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;
/*Заполнить список звезд с параметрами и отосртировать по размеру*/
/*Еще не готов*/
class Star
{
private:
    string name;
    string size;//размер звезды в км
    string relative_height;//относительная высота в световых годах
    string order_num;//номер появления
    string display_as;
public:
    Star(string& curr_name, string& curr_size, string& curr_height, string& curr_ord_num)
    {
        name = curr_name;
        size = curr_size;
        relative_height = curr_height;
        order_num = curr_ord_num;
        display_as = ("Name:" + name + " size:" + size + " height:" + relative_height + " number:" + order_num);
    }

    //оператор сравнения для сортировки
    bool operator <(const Star& star_to_compare) const {
        return (this->size < star_to_compare.size);
    }

    //для вывода в cout
    operator const char*() const {
        return display_as.c_str();
    }
};

void Fill_list(list<Star> user_list)
{
    char finish = 'n';
    while(finish != 'y')
    {
        cout << "Enter the name:";
        string star_name;
        cin >> star_name;

        cout << "Enter size:";
        string star_size;
        cin >> star_size;

        cout << "Enter height";
        string star_height;
        cin >> star_height;

        cout << "Enter order_num:";
        string star_num;
        cin >> star_num;

        //Функция emplace_back создает сам объект а не копирует его
        user_list.emplace_back(Star(star_name, star_size, star_height, star_num));
        
        cout << "Want to finish fill? Press y/n:";
        cin >> finish;
    }
}

int main()
{
    list<Star> data_Stars;
    
}
