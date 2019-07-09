#include <iostream>

using namespace std;
//Заполнить два массива в обратном порядке
void Fullfill_array(int curr_array[], int array_size, int number_of_array)
{
    for(int i = array_size - 1; i >= 0; i--)
    {
        cout << "Enter the element with the number " << i << " of " << number_of_array << " array: ";
        cin >> curr_array[i];
    }
}

void Print_Array(int curr_array[], int size_of_array, int array_number)
{
    cout << "Array number " << array_number << endl;
    for(int index = 0; index < size_of_array; index++)
    {
        cout << curr_array[index] << " ";
    }
    cout << endl;
}
int main()
{
    const int array_length_1 = 4;
    const int array_length_2 = 3;

    int myNums1[array_length_1] = {0};
    int myNums2[array_length_2] = {0};

    Fullfill_array(myNums1, array_length_1, 1);
    Fullfill_array(myNums2, array_length_2, 2);

    Print_Array(myNums1, array_length_1, 1);
    Print_Array(myNums2, array_length_2, 2);

    return 0;
}
