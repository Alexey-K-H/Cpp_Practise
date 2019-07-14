#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/*
Вычислить, не используя функцию pow, значения функции z(x,m) = x^m sin^m(xm), для значений аргументов:
x от -1.1 до 0.3 с шагом 0.2;
m от 1 до 5 с шагом 1.
*/

void Fill_x_Values(vector<float>& x_val);
void Fill_m_Values(vector<int>& m_val);
float Power(float x, int m);
void Get_curr_value(float x_value, vector<int>& m_value);
void Print_Values_function(vector<float>& x_numbs, vector<int>& m_numbs);

int main()
{
    vector<float> x_Values;
    vector<int> m_Values;
    Fill_x_Values(x_Values);
    Fill_m_Values(m_Values);
    Print_Values_function(x_Values, m_Values);

    return 0;
}

void Fill_x_Values(vector<float>& x_val){
    float curr_x_val = - 1.1;
    while(curr_x_val <= 0.3){
        x_val.push_back(curr_x_val);
        curr_x_val += 0.2;
    }
}

void Fill_m_Values(vector<int>& m_val) {
    int curr_m_val = 1;
    while (curr_m_val <= 5) {
        m_val.push_back(curr_m_val);
        curr_m_val++;
    }
}

float Power(float x, int m){
    float first_num_x = 0;
    float tmp_x = 1;
    int tmp = m;
    while(m > 0){
        tmp_x *= x;
        m--;
    }
    first_num_x = tmp_x;
    m = tmp;
    float sin_xm = sin(x*m);
    float tmp_sin = 1;
    while(m > 0){
        tmp_sin *= sin_xm;
        m--;
    }
    sin_xm = tmp_sin;

    return first_num_x*sin_xm;
}

void Get_curr_value(float x_value, vector<int>& m_value){
    for(int index_m = 0; index_m < m_value.size(); index_m++){
        float particular_value = Power(x_value, m_value[index_m]);
        cout << "Function value is: " << particular_value << " with m: " << m_value[index_m] << endl;
    }
}

void Print_Values_function(vector<float>& x_numbs, vector<int>& m_numbs){
        for(int index_for_x = 0; index_for_x < x_numbs.size(); index_for_x++)
        {
                Get_curr_value(x_numbs[index_for_x], m_numbs);
                cout << "Got with value of the X: " << x_numbs[index_for_x] << endl;
                cout << endl;
        }
}
