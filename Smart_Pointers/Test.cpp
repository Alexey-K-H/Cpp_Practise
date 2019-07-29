#include <iostream>

using namespace std;
/*Класс умного укзателя*/
template <typename type>
class smart_pointer{
    type *m_object;
public:
    //Отдаем ему во владение некий объект
    smart_pointer(type *object)
    : m_object(object) {}
    //По выходу из области видимости этот объект уничтожается
    ~smart_pointer() {
        delete m_object;
    }
    //Перегруженные операторы
    //Селектор. Позволяет обращаться к объекту через ->
    type*operator->() { return  m_object;}
    //С помощью такого оператора мы можем разыменовать указатель и
    //получить ссылку на объект на который он хранит
    type&operator*(){ return *m_object;}
};

int test{
    //Отдаем myClass во владение умному укзаетлю
    smart_pointer<myClass> pMyClass(new myClass(/*params*/));
    //Обращение к методу класса по средством селектора
    pMyClass->something();
    //Так же можно вывести элмент на экран
    cout << *pMyClass << endl;
    //При выходе объект будет удален
}

int main()
{
  /*Something*/
}
