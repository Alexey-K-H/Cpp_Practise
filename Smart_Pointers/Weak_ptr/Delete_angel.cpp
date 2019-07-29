#include <iostream>
#include <memory>//Используется для укзателей
#include <string>
using namespace std;
/*Уничтожить ангела, который указывает сам на себя. Использовать weak-ptr*/

class Spirit
{
public:
    weak_ptr<Spirit> angel_ptr;
    Spirit(){
        cout << "Angel created\n";
    }
    ~Spirit(){
        cout << "Angel destroyed\n";
    }
};

int main()
{
    auto angel = make_shared<Spirit>();
    angel->angel_ptr = angel;//В случае с shared ангел только создается но не уничтожается
    return 0;
}
