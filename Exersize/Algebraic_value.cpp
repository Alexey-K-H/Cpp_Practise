#include <iostream>
#include <math.h>
#include <vector>

//Найти Y, если Y = X1 + X2 + … + Xn,   X = Z^3 - B + A^2 / tg^2?. 
//Количество X вводятся пользователем программы. 
//Для каждого X значения Z, B, А, ? разные (вводятся пользователем программы).
using namespace std;

float Create_curr_X(float z, float b, float z, float betta){
    float curr_x  = 0;
    curr_x = pow(z,3) - b + pow(a,2)/tg(2*(betta));
    return curr_x;
}

void FullFill_vector(vector<float>& sum_nums, int count){
    while(count > 0){
        cout << "Enter the values for X:" << endl;
        cout << "Enter the Z value: ";
        float z = 0;
        cin >> z;
        cout << "Enter the B value: ";
        float b = 0;
        cin >> b;
        cout << "Enter the A value: ";
        float a = 0;
        cin >> a;
        cout << "Enter Betta valur: ";
        float betta = 0;
        cin >> betta;
        
        sum_nums.push_back(Create_curr_X(z, b, a, betta));
    }
}

float Sum(vector<float> sum_nums, int count){
    float result = 0;
    int index = 0;
    while(count > 0){
        result += sum_nums[index];
        index++;
        cout--;
    }
}

int main()
{
    cout << "Enter the number of the X:";
    int count = 0;
    cin >> count;
    
    vector<float> sumary_num;
    FullFill_vector(sumary_num, count);
    Sum(sumary_num, count);
    return 0;
}
