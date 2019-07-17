#include <iostream>

using namespace std;

class Spirit
{
public:
    virtual void SpiritLife()
    {
        cout << "Spirits live in Purgatory" << endl;
    }

    virtual ~Spirit() = default;//Виртуальный деструктор по умолчанию
};

class Angel: public Spirit
{
public:
    void SpiritLife() override
    {
        cout << "Angel lives in Paradise" << endl;
    }

    void BecomeSacrifice()
    {
        cout << "Angels must be sacrificed" << endl;
    }
};

class Demon: public Spirit
{
public:
    void SpiritLife() override
    {
        cout << "Demon lives in Inferno" << endl;
    }

    void BecomeFriend()
    {
        cout << "Demons are my friends!))" << endl;
    }
};

void Detected_kind_of_Spirit(Spirit* curr_spirit)
{
    Angel* curr_angel = dynamic_cast<Angel*>(curr_spirit);
    if(curr_angel)
    {
        cout << "Angel detected" << endl;
        curr_angel->BecomeSacrifice();
    }

    Demon* curr_demon = dynamic_cast<Demon*>(curr_spirit);
    if(curr_demon)
    {
        cout << "Demon detected" << endl;
        curr_demon->BecomeFriend();
    }

    curr_spirit->SpiritLife();//Вызов виртуальной функции
}

int main()
{
    Angel Joy;
    Demon Gomorrah;
    Detected_kind_of_Spirit(&Joy);
    cout << endl;
    Detected_kind_of_Spirit(&Gomorrah);
    return 0;
}
