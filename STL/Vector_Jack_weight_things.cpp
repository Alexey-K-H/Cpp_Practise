#include <iostream>
#include <vector>

using namespace std;
//Джек продает кувшины на eBay. Чтобы помочь ему с упаковкой и отгрузкой,
//напишите программу, в которой он может вводить размеры каждого из изделий,
//сохранять их в векторе и выводить на экран.

void Fill_vector(vector<float>& Weight_thing)
{
    char finish_fill = 'n';
    while(finish_fill != 'y') {
        cout << "Enter the weight of your thing:";
        float curr_weight = 0;
        cin >> curr_weight;
        Weight_thing.push_back(curr_weight);
        cout << "Finish enter the values? Press 'y' - Yes or 'n' - No:";
        cin >> finish_fill;
    }
}

void Print_weight_values(vector<float>& Weight_thing)
{
    for(int index = 0; index < Weight_thing.size(); index++)
    {
        cout << "The weight of thing [" << index << "] is: " << Weight_thing.at(index) << endl;
    }
}

int main() {
    vector<float> Jack_values;
    cout << "Hello Jack, you have to enter the weight values of your things" << endl;
    Fill_vector(Jack_values);
    cout << "Print your values" << endl;
    Print_weight_values(Jack_values);
    return 0;
}
