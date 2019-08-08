#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void Exchange_symbols(string& user_str){
    srand(time(nullptr));
    
    for(int index = 0; index < user_str.length(); index++)
    {
        switch(user_str[index])
        {
            case ('A'): {
                cout << (int)user_str[index] << " ";
                break;
            }
            case ('a'): {
                cout << (int) user_str[index] << " ";
                break;
            }
            case ('E'): {
                cout << (int)user_str[index] << " ";
                break;
            }
            case ('e'):{
                cout << (int)user_str[index] << " ";
                break;
            }
            case ('I'): {
                cout << (int)user_str[index] << " ";
                break;
            }
            case ('i'): {
                cout << (int)user_str[index] << " ";
                break;
            }
            case ('O'): {
                cout << (int)user_str[index] << " ";
                break;
            }
            case ('o'):{
                cout << (int)user_str[index] << " ";
                break;
            }
            case ('U'): {
                cout << (int)user_str[index] << " ";
                break;
            }
            case ('u'):{
                cout << (int)user_str[index] << " ";
                break;
            }
            default:{
                int change = rand() % 10;
                switch (change){
                    case 0:
                        cout << "A ";
                        break;
                    case 1:
                        cout << "E ";
                        break;
                    case 2:
                        cout << "I ";
                        break;
                    case 3:
                        cout << "O ";
                        break;
                    case 4:
                        cout << "U ";
                        break;
                    case 5:
                        cout << "a ";
                        break;
                    case 6:
                        cout << "e ";
                        break;
                    case 7:
                        cout << "i ";
                        break;
                    case 8:
                        cout << "o ";
                        break;
                    case 9:
                        cout << "u ";
                        break;
                    default:{ cout << user_str[index] << " ";}
                }
            }
        }
    }
}

int main()
{
    cout << "Enter your string: ";
    string user_str;
    cin >> user_str;
    Exchange_symbols(user_str);
    return 0;
}
