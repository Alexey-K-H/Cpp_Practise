#include "Player.h"

//Специфика умного выбора
Type_player OptimalGamer::return_type_player() {
    return optimal_player;
}

void OptimalGamer::Add_ships(int number_of_ships) {
    /*Умный бот расстановит большие корабли по краям поля, чтобы получить максимальное число свободных
      клеток, для расстановки маленьких кораблей*/
    for(int i = 0; i < number_of_ships; i++)
    {
        bool correct_input = false;
        while (!correct_input)
        {
            int size = 0;
            char shipDirection = '-';
            int shipRow = 0;
            char shipColumn;

            //Задаем рамер добавляемого корабля
            while(true) {
                size = rand()%4 + 1;
                if (size > 0 && size <= 4) {
                    if (ship_size[size - 1] > 0){
                        ship_size[size - 1]--;
                        break;
                    }
                }
            }

            //Определяем в каком положени располагается корабль
            int dir = rand()%2 + 1;
            if(dir == 1)
                shipDirection = 'H';
            else if(dir == 2)
                shipDirection = 'V';


            if(shipDirection == 'H')
            {
                //Если корабль большой
                if(size > 1)
                {
                    int Column = rand()%10;
                    shipColumn = Define_name_column_by_num(Column);
                    int choose_limits = rand()%2 + 1;//Выбираем либо самую левую, либо самую правую
                    if(choose_limits == 1)
                        shipRow = 0;
                    else
                        shipRow = ROWS - 1;
                }
                else
                {
                    int Column = 2 + rand()%6;
                    shipColumn = Define_name_column_by_num(Column);
                    shipRow = 2 + rand()%6;
                }



                if(ValidCoordinate(shipRow, shipColumn, shipDirection, size))
                {
                    correct_input = true;
                    Ship tmp_ship(size);//Создаем наш корабль, чтобы поместить его на карту
                    for(int j = 1; j <= size; j++)
                    {
                        gameBoard[shipRow][(ConvertColumn(shipColumn))+ j - 1] = 'S';//S - палуба корабля
                        tmp_ship.Add_coordinate(shipRow, (ConvertColumn(shipColumn)) + j -1);
                    }
                    player_ships.push_back(tmp_ship);
                }
                else
                {
                    ship_size[size - 1]++;
                }
            }
            else if(shipDirection == 'V')
            {
                if(size > 1)
                {
                    shipRow = rand()%10;
                    int choose_limits = rand()%2 + 1;//Выбираем либо самую левую, либо самую правую
                    if(choose_limits == 1)
                        shipColumn = 'A';
                    else
                        shipColumn = (char)(65 + COLUMNS - 1);
                }
                else{
                    shipRow = 2 + rand()%6;
                    int Column = 2 + rand()%6;
                    shipColumn = Define_name_column_by_num(Column);
                }


                if(ValidCoordinate(shipRow, shipColumn, shipDirection, size))
                {
                    correct_input = true;
                    Ship tmp_ship(size);
                    for(int j = 1; j <= size; j++)
                    {
                        gameBoard[shipRow - j + 1][ConvertColumn(shipColumn)] = 'S';
                        tmp_ship.Add_coordinate(shipRow - j + 1, ConvertColumn(shipColumn));
                    }
                    player_ships.push_back(tmp_ship);
                }
                else
                {
                    ship_size[size - 1]++;
                }
            }
            else{
                ship_size[size - 1]++;
            }
        }
    }
}

void OptimalGamer::Choose_coordinates_for_attack(int &coord_row, char &coord_column) {
    coord_row = rand()%10;
    int Column_num = rand()%10;
    coord_column = Define_name_column_by_num(Column_num);

    bool retry = true;
    while (retry)
    {
        if(attackBoard[coord_row][ConvertColumn(coord_column)] == '#' ||
           attackBoard[coord_row][ConvertColumn(coord_column)] == 'O' ||
           attackBoard[coord_row][ConvertColumn(coord_column)] == 'X' ||
           attackBoard[coord_row][ConvertColumn(coord_column)] == 'H')
        {
            coord_row = rand()%10;
            Column_num = rand()%10;
            coord_column = Define_name_column_by_num(Column_num);
        }
        else
            retry = false;
    }
}