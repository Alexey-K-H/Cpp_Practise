#ifndef SHIPBATTLE_PLAYER_H
#define SHIPBATTLE_PLAYER_H

#include "Ship.h"

#include <iostream>
#include <string>

enum Type_player{
    console_player,
    random_player,
    optimal_player
};

class Gamer
{
protected:
    const static int rows = 10;//Число строк поля
    const static int columns = 10;//Число столбцов поля
    int count_ships = 10;//Число кораблей (в классической игре - 10 шт)

    char gameBoard[rows][columns];
    char attackBoard[rows][columns];
    std::vector<Ship> player_ships;//Корабли игрока
    char shipDirection;//Положение конкретного корабля (вериткальное или горизонтальное)
    int shipRow;
    char shipColumn;
    std::vector<int> ship_size;//Содержит размеры кораблей и соответствующее им количество кораблей
public:
    Gamer();
    virtual ~Gamer()= default;;
    virtual Type_player return_type_player() = 0;

    int Get_count_of_ships();//Количество кораблей игрока
    virtual void Add_ships(int number_of_ships) = 0;//Добавить корабли на карту

    void PrintBoard();//Вывод поля игрока
    void Print_attack_board();//Вывод поля для противника(места куда он стреляет)
    virtual void Choose_coordinates_for_attack(int &coord_row, char &coord_column) = 0;//Коррдинаты, которые игрок выбирает при своем ходе

    virtual void Get_Fire(int row, char column, Gamer* enemy) = 0;//Принять огонь противника на свое поле
    char Find(int row, char column);//Поиск на поле введенных координат
    char Find_on_attack_board(int row, char column);//Поиск на поле противника


    bool ValidCoordinate(int curr_shipRow, char curr_shipColumn, char direction, int size_of_ship);//Проверка того, что координаты судна для расопложения на карте верны
    int ConvertColumn(char column);//По букве опрдеелить номер в массиве
    bool Check_for_win();//Проверить не является ли послдений ход победным для противника(т.е. если все корабли данного игрока уничтожены)
};




class ConsoleGamer : public Gamer
{
public:
    Type_player return_type_player() override;
    void Add_ships(int number_of_ships) override;
    void Choose_coordinates_for_attack(int &coord_row, char &coord_column) override;//Выбор координат для атаки
    void Row_coordinate(int &check_first_coordinate);//Ввод и проверка первой координаты при установке корабля
    void Column_coordinate(char &check_second_coordinate);//Ввод и проверка второй координаты при установке корабля
    void Get_Fire(int row, char column, Gamer* enemy) override;
};


class RandomGamer : public Gamer
{
public:
    Type_player return_type_player() override;
    void Add_ships(int number_of_ships) override;
    char Define_name_column_by_num(int &num);
    void Choose_coordinates_for_attack(int &coord_row, char &coord_column) override;
    void Get_Fire(int row, char column, Gamer* enemy) override;
};


class OptimalGamer : public Gamer
{
public:
    Type_player return_type_player() override;
    char Define_name_column_by_num(int &num);
    void Add_ships(int number_of_ships) override;
    void Choose_coordinates_for_attack(int &coord_row, char &coord_column) override;
    void Get_Fire(int row, char column, Gamer* enemy) override;
};

#endif
