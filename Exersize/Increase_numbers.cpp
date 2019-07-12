#include <iostream>

using namespace std;
/*Составить алгоритм увеличения всех трех, 
введённых с клавиатуры, переменных на 5,
если среди них есть хотя бы две равные. 
В противном случае выдать ответ «равных нет».*/

int Is_there_the_same(int num_1, int num_2, int num_3){
    if((num_1 == num_2) || (num_1 == num_3) || (num_2 == num_3))
      return 1;
    return 0;
}

void Increase_if_need(int number_1, int number_2, int number_3){
    if(Is_there_the_same(number_1, number_2, number_3)){
        number_1 += 5;
        number_2 += 5;
        number_3 += 5;
        
        cout << "First number: " << number_1 << endl;
        cout << "Second number: " << number_2 << endl;
        cout << "Third number: " << number_3 << endl;
    }
}

int main()
{
    cout << "Print the first number: ";
    int first_num = 0;
    cin >> first_num;
    
    cout << "Print the second number: ";
    int second_number = 0;
    cin >> second_number;
    
    cout << "Print the third number: ";
    int third_number = 0;
    cin >> third_number;
    
    cout << endl;
    Increase_if_need(first_num, second_number, third_number);
    
    return 0;
}
