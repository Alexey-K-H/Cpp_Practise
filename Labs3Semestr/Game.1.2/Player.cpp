#include "Player.h"

char Define_name_column_by_num(int &num) {
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
        default:
            return 'Z';
    }
}

Gamer::Gamer() {
    for(int x = 0; x < ROWS; x++)
    {
        for(int y = 0; y < COLUMNS; y++)
        {
            gameBoard[x][y] = '*';
            attackBoard[x][y] = '*';
        }
    }

    ship_size.push_back(4);//ship_size[0] = 4
    ship_size.push_back(3);//ship_size[1] = 3
    ship_size.push_back(2);//ship_size[2] = 2
    ship_size.push_back(1);//ship_size[3] = 1
}

int Gamer::Get_count_of_ships() {
    return count_ships;
}

//Определить по букве положение в массиве
int ConvertColumn(char column) {
    switch (column){
        case 'A':{
            return 0;
        }
        case 'B':{
            return 1;
        }
        case 'C':{
            return 2;
        }
        case 'D':{
            return 3;
        }
        case 'E':{
            return 4;
        }
        case 'F':{
            return 5;
        }
        case 'G':{
            return 6;
        }
        case 'H':{
            return 7;
        }
        case 'I':{
            return 8;
        }
        case 'J':{
            return 9;
        }
        default:
            return 'Z';
    }
}

//Проверка возможности разместить корабль
bool Gamer::ValidCoordinate(const int curr_shipRow, const char curr_shipColumn, const char direction, const int size_of_ship) {
    int good_cords = 0;//Число правильных координат корабля, должно быть равно его размеру, если все корректно
    int tmp = int(curr_shipColumn);
    if((curr_shipRow >= 0 && curr_shipRow <= ROWS - 1) && (tmp >= 65 && tmp <= 74))
    {
        if(direction == 'H')
        {
            for (int i = 1; (i <= size_of_ship) && (ConvertColumn(curr_shipColumn) + i - 1 < COLUMNS); i++){
                if (gameBoard[curr_shipRow][(ConvertColumn(curr_shipColumn)) + i - 1] == '*')
                    good_cords++;

                if(curr_shipRow - 1 >= 0)
                {
                    if(gameBoard[curr_shipRow - 1][(ConvertColumn(curr_shipColumn)) + i - 1] != '*')
                        good_cords--;
                }

                if(curr_shipRow + 1 <= ROWS - 1)
                {
                    if(gameBoard[curr_shipRow + 1][(ConvertColumn(curr_shipColumn)) + i - 1] != '*')
                        good_cords--;
                }
            }

            if(ConvertColumn(curr_shipColumn) - 1 >= 0)
            {
                if(gameBoard[curr_shipRow][(ConvertColumn(curr_shipColumn)) - 1] != '*')
                    good_cords--;

                if(curr_shipRow - 1 >= 0)
                {
                    if(gameBoard[curr_shipRow - 1][(ConvertColumn(curr_shipColumn)) - 1] != '*')
                        good_cords--;
                }

                if(curr_shipRow + 1 <= ROWS - 1)
                {
                    if(gameBoard[curr_shipRow + 1][(ConvertColumn(curr_shipColumn)) - 1] != '*')
                        good_cords--;
                }
            }

            if(ConvertColumn(curr_shipColumn) + size_of_ship <= COLUMNS - 1)
            {
                if(gameBoard[curr_shipRow][(ConvertColumn(curr_shipColumn)) + size_of_ship] != '*')
                    good_cords--;

                if(curr_shipRow - 1 >= 0)
                {
                    if(gameBoard[curr_shipRow - 1][(ConvertColumn(curr_shipColumn)) + size_of_ship] != '*')
                        good_cords--;
                }

                if(curr_shipRow + 1 <= ROWS - 1)
                {
                    if(gameBoard[curr_shipRow + 1][(ConvertColumn(curr_shipColumn)) + size_of_ship] != '*')
                        good_cords--;
                }
            }
        }
        else if(direction == 'V')
        {
            for (int i = 1; (i <= size_of_ship) && curr_shipRow - i + 1 >= 0; i++){
                if (gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn)] == '*')
                    good_cords++;

                if(ConvertColumn(curr_shipColumn) - 1 >= 0)
                {
                    if (gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn) - 1] != '*')
                        good_cords--;
                }

                if(ConvertColumn(curr_shipColumn) + 1 <= COLUMNS - 1)
                {
                    if (gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn) + 1] != '*')
                        good_cords--;
                }
            }

            if(curr_shipRow - size_of_ship >= 0)
            {
                if (gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn)] != '*')
                    good_cords--;

                if(ConvertColumn(curr_shipColumn) - 1 >= 0)
                {
                    if (gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn) - 1] != '*')
                        good_cords--;
                }

                if(ConvertColumn(curr_shipColumn) + 1 <= COLUMNS - 1)
                {
                    if (gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn) + 1] != '*')
                        good_cords--;
                }
            }

            if(curr_shipRow + 1 <= ROWS - 1)
            {
                if (gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn)] != '*')
                    good_cords--;

                if(ConvertColumn(curr_shipColumn) - 1 >= 0)
                {
                    if (gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] != '*')
                        good_cords--;
                }

                if(ConvertColumn(curr_shipColumn) + 1 <= COLUMNS - 1)
                {
                    if (gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) + 1] != '*')
                        good_cords--;
                }
            }
        }
    }
    return good_cords == size_of_ship;
}