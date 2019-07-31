#include <iostream>
#include <vector>
using namespace std;
/*Заполнить динаимический массив*/
/*Ввод завершается как только получено отрицательное число*/
void Display_vector(vector<int>& vec){
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}

void Fill_vector(vector<int>& vec){
    int curr_value = 0;
    while (curr_value >= 0){
        cout << "Enter the value: ";
        cin >> curr_value;
        if(curr_value >= 0){
            vec.push_back(curr_value);
            Display_vector(vec);
        }
    }
}

int main()
{
    vector<int> user_vector;
    Fill_vector(user_vector);
    return 0;
}
