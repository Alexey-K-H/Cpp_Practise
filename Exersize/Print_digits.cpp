#include <iostream>
#include <vector>

using namespace std;
//Составить программу, которая будет считывать введённое пятизначное число.
//После чего, каждую цифру этого числа необходимо вывести в новой строке.

void PrintDigits(vector<char> number){
    for(int index = 0, counter = 1; index < number.size(); index++, counter++){
        cout << counter << " digit of the number is: " << number[index] << endl;
    }
}

int main() {
    cout << "Print your number:" << endl;
    vector<char> dig;//Вектор содержит число
    int index = 0;
    while(index < 5){
        char character = '\0';
        cin >> character;
        dig.push_back(character);//Добавить цифру в конец вектора
        index++;
    }
    PrintDigits(dig);
    return 0;
}
