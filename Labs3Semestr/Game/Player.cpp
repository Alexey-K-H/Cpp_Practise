#include "Player.h"

Gamer::Gamer() {
    //Создаем поле для игрока
    for(int x = 0; x < rows; x++)
    {
        for(int y = 0; y < columns; y++)
        {
            gameBoard[x][y] = '*';
            attackBoard[x][y] = '*';
        }
    }

    ship_size.push_back(4);//ship_size[0] = 4
    ship_size.push_back(3);//ship_size[1] = 3
    ship_size.push_back(2);//ship_size[2] = 2
    ship_size.push_back(1);//ship_size[3] = 1

    shipRow = 0;
    shipColumn = '-';
    shipDirection = '-';
}

int Gamer::Get_count_of_ships() {
    return count_ships;
}

void Gamer::PrintBoard() {
    std::cout << "\t\t<YOUR BOARD>" << std::endl;
    std::cout << "   [A][B][C][D][E][F][G][H][I][J]\n";

    for(int x = 0; x < rows; x++)
    {
        std::cout << "[" <<  x << "]";
        for(int y = 0; y < columns; y++)
        {
            std::cout << " " << gameBoard[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

void Gamer::Print_attack_board() {
    std::cout << "\t\t<ENEMY BOARD>" << std::endl;
    std::cout << "   [A][B][C][D][E][F][G][H][I][J]\n";

    for(int x = 0; x < rows; x++)
    {
        std::cout << "[" <<  x << "]";
        for(int y = 0; y < columns; y++)
        {
            std::cout << " " << attackBoard[x][y] << " ";
        }
        std::cout << std::endl;
    }
}


//Определить по букве положение в массиве
int Gamer::ConvertColumn(char column) {
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
        }
}


//Проверка ввозможности разместить корабль
bool Gamer::ValidCoordinate(int curr_shipRow, char curr_shipColumn, char direction, int size_of_ship) {
    int good_cords = 0;//Число правильных координат корабля, должно быть равно его размеру, если все корректно
    int tmp = int(curr_shipColumn);
    if((curr_shipRow >= 0 && curr_shipRow <= 9) && (tmp >= 65 && tmp <= 74))
    {
        if(direction == 'H')
        {
            if(curr_shipRow == 0)
            {
                for (int i = 1; (i <= size_of_ship) && (ConvertColumn(curr_shipColumn) + i - 1 < 10); i++){
                    if (gameBoard[curr_shipRow][(ConvertColumn(curr_shipColumn)) + i - 1] == '*'
                    && gameBoard[curr_shipRow+1][ConvertColumn(curr_shipColumn) + i - 1] == '*')
                        good_cords++;
                }
                if(ConvertColumn(curr_shipColumn) == 0)
                {
                    if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                        && gameBoard[curr_shipRow+1][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'))
                        good_cords--;
                }
                else if(ConvertColumn(curr_shipColumn) == 9)
                {
                    if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn)-1] == '*'
                       && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                        good_cords--;
                }
                else
                {
                    if(ConvertColumn(curr_shipColumn) + size_of_ship <= 9)
                    {
                        if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                             && gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn)-1] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                    else
                    {
                        if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn)-1] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                }
            }
            else if(curr_shipRow > 0 && curr_shipRow < 9)
            {
                for (int i = 1; (i <= size_of_ship) && (ConvertColumn(curr_shipColumn) + i - 1 < 10); i++){
                    if (gameBoard[curr_shipRow][(ConvertColumn(curr_shipColumn)) + i - 1] == '*'
                        && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) + i - 1] == '*'
                        && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) + i - 1] == '*')
                        good_cords++;
                }
                if(ConvertColumn(curr_shipColumn) == 0)
                {
                    if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                         && gameBoard[curr_shipRow+1][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                         && gameBoard[curr_shipRow-1][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'))
                        good_cords--;
                }
                else if(ConvertColumn(curr_shipColumn) == 9)
                {
                    if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn)-1] == '*'
                         && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'
                         && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                        good_cords--;
                }
                else
                {
                    if(ConvertColumn(curr_shipColumn) + size_of_ship <= 9)
                    {
                        if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                             && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                             && gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn)-1] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'
                             && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                    else
                    {
                        if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn)-1] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'
                             && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                }
            }
            else if(curr_shipRow == 9)
            {
                for (int i = 1; (i <= size_of_ship) && (ConvertColumn(curr_shipColumn) + i - 1 < 10); i++){
                    if (gameBoard[curr_shipRow][(ConvertColumn(curr_shipColumn)) + i - 1] == '*'
                        && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) + i - 1] == '*')
                        good_cords++;
                }
                if(ConvertColumn(curr_shipColumn) == 0)
                {
                    if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                         && gameBoard[curr_shipRow-1][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'))
                        good_cords--;
                }
                else if(ConvertColumn(curr_shipColumn) == 9)
                {
                    if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn)-1] == '*'
                         && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                        good_cords--;
                }
                else
                {
                    if(ConvertColumn(curr_shipColumn) + size_of_ship <= 9)
                    {
                        if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                             && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) + size_of_ship] == '*'
                             && gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn)-1] == '*'
                             && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                    else
                    {
                        if(!(gameBoard[curr_shipRow][ConvertColumn(curr_shipColumn)-1] == '*'
                             && gameBoard[curr_shipRow - 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                }
            }
        }
        else if(direction == 'V')
        {
            if(ConvertColumn(curr_shipColumn) == 0)
            {
                for (int i = 1; (i <= size_of_ship) && curr_shipRow - i + 1 >= 0; i++){
                    if (gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn)] == '*'
                        && gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn)+1] == '*')
                        good_cords++;
                }
                if(curr_shipRow == 0)
                {
                    if(!(gameBoard[curr_shipRow + size_of_ship][ConvertColumn(curr_shipColumn)] == '*'
                         && gameBoard[curr_shipRow+size_of_ship][ConvertColumn(curr_shipColumn) + 1] == '*'))
                        good_cords--;
                }
                else if(curr_shipRow == 9)
                {
                    if(!(gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn)] == '*'
                         && gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn) + 1] == '*'))
                        good_cords--;
                }
                else
                {
                    if(curr_shipRow - size_of_ship >= 0)
                    {
                        if(!(gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn)] == '*'
                             && gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn) + 1] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn)] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) + 1] == '*'))
                            good_cords--;
                    }
                    else
                    {
                        if(!(gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn)] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) + 1] == '*'))
                            good_cords--;
                    }

                }
            }
            else if(ConvertColumn(curr_shipColumn) > 0 && ConvertColumn(curr_shipColumn) < 9)
            {
                for (int i = 1; (i <= size_of_ship) && curr_shipRow - i + 1 >= 0; i++){
                    if (gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn)] == '*'
                        && gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn)+1] == '*'
                        && gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn)-1] == '*')
                        good_cords++;
                }
                if(curr_shipRow == 0)
                {
                    if(!(gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn)] == '*'
                         && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) + 1] == '*'
                         && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                        good_cords--;
                }
                else if(curr_shipRow == 9)
                {
                    if(!(gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn)] == '*'
                         && gameBoard[curr_shipRow -size_of_ship][ConvertColumn(curr_shipColumn) + 1] == '*'
                         && gameBoard[curr_shipRow -size_of_ship][ConvertColumn(curr_shipColumn) - 1] == '*'))
                        good_cords--;
                }
                else
                {
                    if(curr_shipRow - size_of_ship >= 0)
                    {
                        if(!((gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn)] == '*')
                             && gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn) + 1] == '*'
                             && gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn) - 1] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn)] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) + 1] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                    else
                    {
                        if(!(gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) + 1] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                }
            }
            else if(ConvertColumn(curr_shipColumn) == 9)
            {
                for (int i = 1; (i <= size_of_ship) && curr_shipRow - i + 1 >= 0; i++){
                    if (gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn)] == '*'
                        && gameBoard[curr_shipRow-i+1][ConvertColumn(curr_shipColumn)-1] == '*')
                        good_cords++;
                }
                if(curr_shipRow == 0)
                {
                    if(!(gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn)] == '*'
                         && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                        good_cords--;
                }
                else if(curr_shipRow == 9)
                {
                    if(!(gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn)] == '*'
                         && gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn) - 1] == '*'))
                        good_cords--;
                }
                else
                {
                    if(curr_shipRow - size_of_ship >= 0)
                    {
                        if(!(gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn)] == '*'
                             && gameBoard[curr_shipRow - size_of_ship][ConvertColumn(curr_shipColumn) - 1] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn)] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                    else
                    {
                        if(!(gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn)] == '*'
                             && gameBoard[curr_shipRow + 1][ConvertColumn(curr_shipColumn) - 1] == '*'))
                            good_cords--;
                    }
                }
            }
        }
    }
    return good_cords == size_of_ship;
}


char Gamer::Find_on_attack_board(int row, char column) {
    int column_num = ConvertColumn(column);
    return (attackBoard[row][column_num]);
}

char Gamer::Find(int row, char column) {
    int column_num = ConvertColumn(column);
    return (gameBoard[row][column_num]);
}

bool Gamer::Check_for_win() {
    return count_ships == 0;
}


