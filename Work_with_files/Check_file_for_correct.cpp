#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
/*Проверка файла на корректность соответствия фигурных скобок*/
void Search_for_correct(ifstream& file)
{
    char key1 = '{';
    char key2 = '}';
    int count_key1 = 0;
    int count_key2 = 0;
    string fileContest;
    while(file.good())
    {
        getline(file, fileContest);
        count_key1 += count(fileContest.begin(), fileContest.end(), key1);
        count_key2 += count(fileContest.begin(), fileContest.end(), key2);
    }
    cout << "Count of symbol < { > :" << count_key1 << endl;
    cout << "Count of symbol < } > :" << count_key2 << endl;
    if(count_key1 == count_key2){
        cout << "File is correct" << endl;
    }
    else
        cout << "File isn't correct" << endl;
}

int main()
{
    ifstream fileExample;
    fileExample.open("Example.txt", ios_base::out);
    if(fileExample.is_open())
    {
        cout << "File successfully opened" << endl;
        cout << "Start check for correct" << endl;
        Search_for_correct(fileExample);
    }
    return 0;
}
