#include <iostream>

using namespace std;
//Напишите программу, 
// которая позволяет пользователю ввести в консоли латинскую букву нижнего регистра,  
// переводит её в верхний регистр и результат выводит в консоль.

void To_upper(char symbol){
    if(symbol >= 'A' && symbol <= 'Z'){
        cout << "Your character in up register: " << symbol;
    }
    else if(symbol >= 'a' && symbol <= 'z'){
        symbol += 'A' - 'a';
        cout << "Your character in up register: " << symbol;
    } else{
        cout << "Bad input" << endl;
    }
}

int main() {
    cout << "Print your character: ";
    char symbol = '\0';
    cin >> symbol;
    To_upper(symbol);
    return 0;
}
