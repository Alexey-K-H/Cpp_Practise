#ifndef SHIPBATTLE_PLAYER_H
#define SHIPBATTLE_PLAYER_H

#define ROWS 10
#define COLUMNS 10

#include "Ship.h"

#include <iostream>
#include <string>

enum Type_player{
    console_player,
    random_player,
    optimal_player
};

enum Result_of_attack
{
    hit,
    miss
};

char Define_name_column_by_num(int &num);
int ConvertColumn(char column);//По букве опрдеелить номер в массиве

class Gamer
{
protected:
    int count_ships = 10;
    char gameBoard[ROWS][COLUMNS];
    char attackBoard[ROWS][COLUMNS];
    std::vector<Ship> player_ships;//Корабли игрока
    std::vector<int> ship_size;//Содержит размеры кораблей и соответствующее им количество кораблей данного размера
public:
    Gamer();
    virtual ~Gamer()= default;;
    virtual Type_player return_type_player() = 0;
    int Get_count_of_ships();//Количество кораблей игрока
    virtual void Add_ships(int number_of_ships) = 0;//Добавить корабли на карту
    bool ValidCoordinate(int curr_shipRow, char curr_shipColumn, char direction, int size_of_ship);//Проверка того, что координаты судна для расопложения на карте верны
    virtual void Choose_coordinates_for_attack(int &coord_row, char &coord_column) = 0;//Коррдинаты, которые игрок выбирает при своем ходе

    friend class Game_Interface;
};

class ConsoleGamer : public Gamer
{
public:
    Type_player return_type_player() override;
    void PrintBoard();//Вывод поля игрока(Только для консольного при расстановке кораблей)
    void Add_ships(int number_of_ships) override;
    void Choose_coordinates_for_attack(int &coord_row, char &coord_column) override;
    static void Row_coordinate(int &check_first_coordinate);//Ввод и проверка первой координаты при установке корабля
    static void Column_coordinate(char &check_second_coordinate);//Ввод и проверка второй координаты при установке корабля
};

class RandomGamer : public Gamer
{
public:
    Type_player return_type_player() override;
    void Add_ships(int number_of_ships) override;
    void Choose_coordinates_for_attack(int &coord_row, char &coord_column) override;
};

class OptimalGamer : public Gamer
{
public:
    Type_player return_type_player() override;
    void Add_ships(int number_of_ships) override;
    void Choose_coordinates_for_attack(int &coord_row, char &coord_column) override;
};

#endif
