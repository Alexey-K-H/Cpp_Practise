#include "GameInterface.h"

void Game_Interface::Manual(){
    std::cout << "\t\t<Manual>\t\t" << std::endl;
    std::cout << "There are three parameters that you can change:" << std::endl;
    std::cout << "Count of the rounds (Default:1)" << std::endl;
    std::cout << "Types of two players: console, random, optimal (Default:random)" << std::endl;
    std::cout << "Set these parameters or play default game.\n" << std::endl;
    std::cout << "\t<Main commands>" << std::endl;
    std::cout << "\t1)Manual: --h or --help" << std::endl;
    std::cout << "\t2)Count of rounds: --c number or --count number" << std::endl;
    std::cout << "\t3)Type of the first player: --f type or --first type" << std::endl;
    std::cout << "\t4)Type of the second player: --s type or --second type\n" << std::endl;
    std::cout << "<End of the tutorial>" << std::endl;
}

void Game_Interface::Print_stats(int &first_wins, int &second_wins, int &count_rounds){
    std::cout << "\n\n====================GENERAL STATISTICS=============================================\n";
    std::cout << "COUNT OF THE ROUNDS:" << count_rounds << "\n\n";
    std::cout << "PLAYER1: Rounds win <" << first_wins << ">; Rounds fail <" << count_rounds - first_wins << ">\n";
    std::cout << "PLAYER2: Rounds win <" << second_wins << ">; Rounds fail <" << count_rounds - second_wins << ">\n";

    if(first_wins > second_wins)
    {
        std::cout << "\n****************<<PLAYER1 WINS!>>*******************\n\n";
    }
    else if(first_wins < second_wins)
    {
        std::cout << "\n****************<<PLAYER2 WINS!>>*******************\n\n";
    }
    else
    {
        std::cout << "\n********************<<DRAW>>************************\n\n";
    }
}

Type_player Game_Interface::define_type_of_player(const char *curr_type){

    if(strcmp(curr_type, "random") == 0){
        return random_player;
    }

    if(strcmp(curr_type, "console") == 0){
        return console_player;
    }

    if(strcmp(curr_type, "optimal") == 0){
        return optimal_player;
    }

    return random_player;
}

std::string Game_Interface::Print_type(Type_player &type){
    switch (type)
    {
        case console_player:
            return "console";
        case random_player:
            return "random";
        case optimal_player:
            return "optimal";
    }
}

Gamer* Game_Interface::createGamer(Type_player &type){
    Gamer *p = nullptr;
    switch (type)
    {
        case console_player:
            p = new ConsoleGamer;
            break;
        case random_player:
            p = new RandomGamer;
            break;
        case optimal_player:
            p = new OptimalGamer;
            break;
    }
    return p;
}

void Game_Interface::Print_player_and_attack_board(Gamer *player) {
    std::cout << "\t<ENEMY BOARD>\t\t\t<YOUR BOARD>" << std::endl;
    std::cout << "   ";
    int name_column = 0;
    for(int i = 0; i < COLUMNS; i++){
        std::cout << "[" << (char)(name_column + 65 + i) << "]";
    }
    std::cout << "      ";
    for(int i = 0; i < COLUMNS; i++){
        std::cout << "[" << (char)(name_column + 65 + i) << "]";
    }
    std::cout << std::endl;

    for(int x = 0; x < ROWS; x++)
    {
        std::cout << "[" <<  x << "]";
        for(int y = 0; y < COLUMNS; y++)
        {
            std::cout << " " << player->attackBoard[x][y] << " ";
        }
        std::cout << "   [" << x << "]";
        for(int y = 0; y < COLUMNS; y++)
        {
            std::cout << " " << player->gameBoard[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

char Game_Interface::Find_on_board(Gamer *player, const int row, const char column) {
    int column_board = ConvertColumn(column);
    return (player->gameBoard[row][column_board]);
}

Result_of_attack Game_Interface::get_fire(Gamer *player, Gamer *enemy, int row, char column) {
    char location = Find_on_board(player, row, column);
    system("clear");
    if(location == '*')
    {
        //Пустая клетка
        if(enemy->return_type_player() == console_player)
        {
            std::cout << "YOU HAVE MISSED AT POSITION:[" << column << "][" << row << "]\n";
        }
        else if(enemy->return_type_player() == random_player)
        {
            std::cout << "CPU(RANDOM) HAVE MISSED AT POSITION:[" << column << "][" << row << "]\n";
        }
        else if(enemy->return_type_player() == optimal_player)
        {
            std::cout << "CPU(OPTIMAL) HAVE MISSED AT POSITION:[" << column << "][" << row << "]\n";
        }
        enemy->attackBoard[row][ConvertColumn(column)] = '#';//M - missed промах
    }
    else if(location == 'S')
    {
        //Палуба корабля
        //Проверяем в какой из кораблей мы попали
        for(auto & player_ship : player->player_ships)
        {
            if(player_ship.Check_for_hit(row, ConvertColumn(column)))
            {
                if(enemy->return_type_player() == console_player)
                {
                    std::cout << "YOU HIT AT LOCATION:[" << column << "][" << row << "]\n";
                }
                else if(enemy->return_type_player() == random_player)
                {
                    std::cout << "CPU(RANDOM) HIT AT LOCATION:[" << column << "][" << row << "]\n";
                }
                else if(enemy->return_type_player() == optimal_player)
                {
                    std::cout << "CPU(OPTIMAL) HIT AT LOCATION:[" << column << "][" << row << "]\n";
                }

                enemy->attackBoard[row][ConvertColumn(column)] = 'H';//H - hit нанесен урон палубе
                player->gameBoard[row][ConvertColumn(column)] = 'H';
                //Если это была последняя палуба корабля
                if(player_ship.Get_length() == 0)
                {
                    player->count_ships--;

                    if(enemy->return_type_player() == console_player)
                    {
                        std::cout << "YOU SUNK A SHIP!\n";
                    }
                    else if(enemy->return_type_player() == random_player)
                    {
                        std::cout << "CPU(RANDOM) SUNK A SHIP!\n";
                    }
                    else if(enemy->return_type_player() == optimal_player)
                    {
                        std::cout << "CPU(OPTIMAL) SUNK A SHIP!\n";
                    }

                    std::vector<std::pair<int, int>> ship_coords = player_ship.ReturnCoordinates();
                    for(auto & ship_coord : ship_coords)
                    {
                        player->gameBoard[ship_coord.first][ship_coord.second] = 'X';
                        enemy->attackBoard[ship_coord.first][ship_coord.second] = 'X';

                        if(enemy->return_type_player() == optimal_player)
                        {
                            //Клетки окружения уничтоженного корабля рассматриваться не будут в дальнейшем (если противник наносивший удар умный ИИ)
                            if(ship_coord.first - 1 >= 0 && enemy->attackBoard[ship_coord.first - 1][ship_coord.second] != 'X')
                            {
                                enemy->attackBoard[ship_coord.first - 1][ship_coord.second] = 'O';

                                if(ship_coord.second + 1 <= COLUMNS - 1 && enemy->attackBoard[ship_coord.first - 1][ship_coord.second + 1] != 'X')
                                    enemy->attackBoard[ship_coord.first - 1][ship_coord.second + 1] = 'O';

                                if(ship_coord.second - 1 >= 0 && enemy->attackBoard[ship_coord.first - 1][ship_coord.second - 1] != 'X')
                                    enemy->attackBoard[ship_coord.first - 1][ship_coord.second - 1] = 'O';
                            }

                            if(ship_coord.first + 1 <= ROWS - 1 && enemy->attackBoard[ship_coord.first + 1][ship_coord.second] != 'X')
                            {
                                enemy->attackBoard[ship_coord.first + 1][ship_coord.second] = 'O';

                                if(ship_coord.second + 1 <= COLUMNS - 1 && enemy->attackBoard[ship_coord.first][ship_coord.second + 1] != 'X')
                                    enemy->attackBoard[ship_coord.first + 1][ship_coord.second + 1] = 'O';

                                if(ship_coord.second - 1 >= 0 && enemy->attackBoard[ship_coord.first][ship_coord.second - 1] != 'X')
                                    enemy->attackBoard[ship_coord.first + 1][ship_coord.second - 1] = 'O';
                            }

                            if(ship_coord.second + 1 <= COLUMNS - 1 && enemy->attackBoard[ship_coord.first][ship_coord.second + 1] != 'X')
                                enemy->attackBoard[ship_coord.first][ship_coord.second + 1] = 'O';

                            if(ship_coord.second - 1 >= 0 && enemy->attackBoard[ship_coord.first][ship_coord.second - 1] != 'X')
                                enemy->attackBoard[ship_coord.first][ship_coord.second - 1] = 'O';
                        }
                    }
                }
            }
        }
    }
    if(location == '*')
        return miss;
    else
        return hit;
}

bool Game_Interface::Check_for_defeat(Gamer *curr_player) {
    return curr_player->Get_count_of_ships() == 0;
}

void Game_Interface::Game_process(int &count_of_rounds, Type_player &first, Type_player &second){
    std::cout << "\t\t<Let's start!>" << std::endl;
    srand(time(nullptr));
    int counter = 1;
    int first_player_streak = 0;
    int second_player_streak = 0;
    //Пока не хакончились все раунды

    while (count_of_rounds > 0)
    {
        Gamer *first_player = createGamer(first);
        Gamer *second_player = createGamer(second);
        //начало игры
        int curr_turn_row = 0;
        char curr_turn_column = 'Z';
        char next_turn = 'n';
        std::cout << "\t\tROUND<" << counter << ">\n";

        //Заполнение карт игроками
        std::cout << "\t\tPLAYER 1, ADD SHIPS ON YOUR MAP" << std::endl;
        first_player->Add_ships(first_player->Get_count_of_ships());

        system("clear");

        std::cout << "\t\tPLAYER 2, ADD SHIPS ON YOUR MAP" << std::endl;
        second_player->Add_ships(second_player->Get_count_of_ships());

        while (true)
        {
            system("clear");
            bool retry_for_first = true;//Повторный ход, в случае если игрок нанес удар по кораблю или потопил его
            while (retry_for_first)
            {
                std::cout << "\n=====================Player 1 turn=========================\n";
                if(first_player->return_type_player() == console_player){
                    std::cout << "============Player 2 don't look at the screen=================\n";
                    Print_player_and_attack_board(first_player);
                }

                first_player->Choose_coordinates_for_attack(curr_turn_row, curr_turn_column);
                if(get_fire(second_player, first_player, curr_turn_row, curr_turn_column) == miss || Check_for_defeat(second_player)){
                    retry_for_first = false;
                }
            }

            if(Check_for_defeat(second_player))
            {
                system("clear");
                std::cout << "PLAYER1 SUNK ALL SHIPS OF PLAYER2! PLAYER1 WINS ROUND" << counter << "!!!\n";
                counter++;
                first_player_streak++;
                std::cout << "CONGRATULATIONS!\n";
                Print_player_and_attack_board(first_player);
                break;
            }

            if(first_player->return_type_player() == console_player)
            {
                std::cout << "Turn of the next player. Enter any key to continue:";
                std::cin >> next_turn;
            }

            system("clear");
            curr_turn_row = 0;
            curr_turn_column = 'Z';


            bool retry_for_second = true;
            while (retry_for_second)
            {
                std::cout << "\n=====================Player 2 turn=========================\n";
                if(second_player->return_type_player() == console_player)
                {
                    std::cout << "============Player 1 don't look at the screen=================\n";
                    Print_player_and_attack_board(second_player);
                }

                second_player->Choose_coordinates_for_attack(curr_turn_row, curr_turn_column);
                if(get_fire(first_player, second_player, curr_turn_row, curr_turn_column) == miss || Check_for_defeat(first_player))
                {
                    retry_for_second = false;
                }
            }

            if(Check_for_defeat(first_player))
            {
                system("clear");
                std::cout << "PLAYER2 SUNK ALL SHIPS OF PLAYER1! PLAYER2 WINS ROUND" << counter << "!!!\n";
                counter++;
                second_player_streak++;
                std::cout << "CONGRATULATIONS!\n";
                Print_player_and_attack_board(second_player);
                break;
            }

            if(second_player->return_type_player() == console_player)
            {
                std::cout << "Turn of the next player. Enter any key to continue:";
                std::cin >> next_turn;
            }
        }
        delete(first_player);
        delete(second_player);
        count_of_rounds--;
    }
    std::cout << "\n\tEND OF THE GAME!\n";
    counter--;
    Print_stats(first_player_streak, second_player_streak, counter);
}
