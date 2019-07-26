#include <iostream>
#include <string>
#include <list>

using namespace std;
/*Заполнить список звезд с параметрами и отосртировать по размеру*/

class Star
{
public:
    string name;
    string size;//размер звезды в км
    string relative_height;//относительная высота в световых годах
    string order_num;//номер появления
    string display_as;

    Star(const string& curr_name, const string& curr_size, const string& curr_height, const string& curr_ord_num)
    {
        name = curr_name;
        size = curr_size;
        relative_height = curr_height;
        order_num = curr_ord_num;
        display_as = ("Name:" + name + " size:" + size + "(km) height:" + relative_height + "(light years) number_appearance:" + order_num);
    }

    //для вывода в cout
    operator const char*() const {
        return display_as.c_str();
    }
};

bool Sort_on_size(const Star& star1, const Star& star2)
{
    return (star1.size > star2.size);
}

void Fill_list(list<Star>& user_list)
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

        cout << "Enter height:";
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

template<typename Type>
void Display_data(const Type& data_stars)
{
    for(auto element = data_stars.cbegin(); element != data_stars.cend(); ++element)
        cout << *element << endl;
}

int main()
{
    list<Star> data_Stars;
    Fill_list(data_Stars);
    data_Stars.sort(Sort_on_size);//Сортировка списка по умолчанию стабильная
    cout << "<List of stars>" << endl;
    Display_data(data_Stars);
}
