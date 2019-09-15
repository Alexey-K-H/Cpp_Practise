#include "Trits.h"

int main() {
    cout << "Enter the count of trits:";
    int user_count = 0;
    cin >> user_count;

    Trit_Set set(user_count);
    set.capacity();

    return 0;
}
