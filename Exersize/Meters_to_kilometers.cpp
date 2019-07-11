#include <iostream>

using namespace std;
//Программа должна переводить число, введенное с клавиатуры в метрах, в километры.

void Converse_to_kilometers(float meters){
    float kilometers = 0;
    kilometers = meters/1000;
    cout << "Your count of meters: " << meters << endl;
    cout << "Your count in kilometers: " << kilometers;
}

int main() {
    cout << "Print the count of meters: ";
    float meters = 0;
    cin >> meters;
    Converse_to_kilometers(meters);
}
