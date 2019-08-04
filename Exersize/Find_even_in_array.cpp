#include <iostream>
#include <string>
#include <ctime>
using namespace std;
/*Дан массив размера n, заполнить его случайными числами, Найти все нечётные числа массива.*/

void Find_even_elements(int *array, int& count_of_elements);
void Create_array(int& count_of_elements);

int main()
{
    cout << "Enter the count of elements:";
    int n = 0;
    cin >> n;
    Create_array(n);
    return 0;
}

void Create_array(int& count_of_elements){
    cout << "Array: ";
    srand(time(nullptr));
    auto user_array = new int[count_of_elements];
    for(int i = 0; i < count_of_elements; i ++){
        user_array[i] = rand() % 50;
        cout << user_array[i] << " ";
    }
    cout << endl;
    Find_even_elements(user_array, count_of_elements);
    delete[](user_array);
}

void Find_even_elements(int *array, int& count_of_elements){
    cout << "Result: ";
    for(int i = 0; i < count_of_elements; i++){
        if(array[i] % 2 != 0)
            cout << array[i] << " ";
    }
    cout << endl;
}
