#include "Player.h"

//Специфика случайного выбора выбора
char RandomGamer::Define_name_column_by_num(int &num) {
    switch (num)
    {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
        case 4:
            return 'E';
        case 5:
            return 'F';
        case 6:
            return 'G';
        case 7:
            return 'H';
        case 8:
            return 'I';
        case 9:
            return 'J';
    }
}


void RandomGamer::Add_ships(int number_of_ships) {
    std::cout << "Create random ships location..." << std::endl;
    for(int i = 0; i < number_of_ships; i++)
    {
        bool correct_input = false;
        while (!correct_input)
        {

            int size = 0;
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
            else
                shipDirection = 'V';


            if(shipDirection == 'H')
            {
                int Column = rand()%10;
                shipColumn = Define_name_column_by_num(Column);
                shipRow = rand()%10;

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
                int Column = rand()%10;
                shipColumn = Define_name_column_by_num(Column);
                shipRow = rand()%10;

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
    PrintBoard();
}


void RandomGamer::Choose_coordinates_for_attack(int &coord_row, char &coord_column) {
    coord_row = rand()%10;
    int Column_num = rand()%10;
    coord_column = Define_name_column_by_num(Column_num);
}

void RandomGamer::Fire(int row, char column) {
    bool retry = true;//Повторная попытка если пользователь ввел координаты, которые уже проверял ранее
    while (retry)
    {
        char PotentialRetry = Find_on_attack_board(row, column);//Ищем введенные координаты на поле противника
        if(PotentialRetry == '#')
        {
            //Если в данной координате уже был допущен промах
            Choose_coordinates_for_attack(row, column);
        }
        else if(PotentialRetry == 'H' || PotentialRetry == 'X')
        {
            //Если в данной позиции уже был нанесен удар или в ней обломки убитого корабля
            Choose_coordinates_for_attack(row, column);
        }
        else
            retry = false;
    }

    char location = Find(row, column);//Проверяем на карте с кораблями, куда попал удар
    if(location == '*')
    {
        //Пустая клетка
        std::cout << "CPU(Random) missed at position:[" << column << "][" << row << "]\n";
        attackBoard[row][ConvertColumn(column)] = '#';//M - missed промах
        return;
    }
    else if(location == 'S')
    {
        //Палуба корабля
        //Проверяем в какой из кораблей мы попали
        for(unsigned long i  = 0; i < player_ships.size(); i++)
        {
            if(player_ships[i].Check_for_hit(row, ConvertColumn(column)))
            {
                std::cout << "CPU(Random) have hit at location:[" << column << "][" << row << "]\n";
                attackBoard[row][ConvertColumn(column)] = 'H';//H - hit нанесен урон палубе
                gameBoard[row][ConvertColumn(column)] = 'H';
                //Если это была последняя палуба корабля
                if(player_ships[i].Get_length() == 0)
                {
                    count_ships--;
                    std::cout << "CPU(Random) sunk a ship!\n";
                    std::vector<std::pair<int, int>> ship_coords = player_ships[i].ReturnCoordinates();
                    for(unsigned long j = 0; j < ship_coords.size(); j++)
                    {
                        gameBoard[ship_coords[j].first][ship_coords[j].second] = 'X';
                        attackBoard[ship_coords[j].first][ship_coords[j].second] = 'X';
                    }
                }
            }
        }
    }

}