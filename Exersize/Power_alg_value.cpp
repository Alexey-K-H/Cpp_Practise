#include <iostream>
#include <cmath>
#include <vector>

//Найти алгебраическую сумму для выражения: 1k + 2k + 3k + … + Nk.
//N и степень k вводит пользователь.
using namespace std;

void FullFill_vector(vector<int>& numbers, int count, int k_pow){
    while(count > 0){
        int curr_num = pow(count, k_pow);
        numbers.push_back(curr_num);
        count--;
    }
}

void Sum_result(vector<int> numbers){
    int index = numbers.size()-1;
    int result = 0;
    while(index >= 0){
        result += numbers[index];
        index--;
    }
    cout << "Result is: " << result << endl;
}

int main()
{
    cout << "Print number N:";
    int number = 0;
    cin >> number;

    cout << "Print pow k:";
    int k_pow = 0;
    cin >> k_pow;

    vector<int> alg_nums;
    FullFill_vector(alg_nums, number, k_pow);
    Sum_result(alg_nums);
    return 0;
}
