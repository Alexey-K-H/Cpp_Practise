#include <iostream>
#include <algorithm>
#include <vector>
//Сортировка массива в порядке убывания
//Лямбда функции
//Стандартные алгоритмы

using namespace std;

void DisplayNums(vector<int>& dynArray){
    for_each(dynArray.begin(), dynArray.end(), [](int e){
        cout << e << " ";
    });

    cout << endl;
}

int main() {
    vector<int> myNums;
    myNums.push_back(501);
    myNums.push_back(-1);
    myNums.push_back(25);
    myNums.push_back(-35);

    DisplayNums(myNums);

    cout << "Sorting from max to min" << endl;
    //Лямбда функция сортировки
    sort(myNums.begin(), myNums.end(), [](int num1, int num2) {return (num2 < num1);});
    DisplayNums(myNums);
    return 0;
}
