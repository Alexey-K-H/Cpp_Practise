#include "GameInterface.h"

void Manual(){
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

Type_player define_type_of_player(const char *curr_type){

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

std::string Print_type(Type_player &type){
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

Gamer* createGamer(Type_player &type){
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

void Game_process(int &count_of_rounds, Type_player &first, Type_player &second){

    std::cout << "\t\t<Let's start!>" << std::endl;

    Gamer *first_player = createGamer(first);
    Gamer *second_player = createGamer(second);

    srand(time(nullptr));
    //Заполнение карт игроками
    std::cout << "\t\tPLAYER 1, ADD SHIPS ON YOUR MAP" << std::endl;
    first_player->Add_ships(first_player->Get_count_of_ships());

    std::cout << "\t\tPLAYER 2, ADD SHIPS ON YOUR MAP" << std::endl;
    second_player->Add_ships(second_player->Get_count_of_ships());


    //начало игры
    int curr_turn_row = 0;
    char curr_turn_column = 'Z';

    while (true)
    {
        std::cout << "\n=====================Player 1 turn=========================\n";
        std::cout << "============Player 2 don't look at the screen=================\n";
        std::cout << "\n\nPLAYER1'S ATTACK BOARD" << std::endl;
        second_player->Print_attack_board();
        std::cout << "\nPLAYER1'S BOARD" << std::endl;
        first_player->PrintBoard();

        first_player->Choose_coordinates_for_attack(curr_turn_row, curr_turn_column);
        second_player->Get_Fire(curr_turn_row, curr_turn_column, first_player);

        system("cls");

        if(second_player->Check_for_win())
        {
            system("cls");
            std::cout << "PLAYER1 SUNK ALL SHIPS OF PLAYER2! PLAYER1 WINS ROUND!!!\n";
            std::cout << "CONGRATULATIONS!\n";
            second_player->Print_attack_board();
            break;
        }



        curr_turn_row = 0;
        curr_turn_column = 'Z';

        std::cout << "\n=====================Player 2 turn=========================\n";
        std::cout << "============Player 1 don't look at the screen=================\n";
        std::cout << "\n\nPLAYER2'S ATTACK BOARD" << std::endl;
        first_player->Print_attack_board();
        std::cout << "\nPLAYER2'S BOARD" << std::endl;
        second_player->PrintBoard();

        second_player->Choose_coordinates_for_attack(curr_turn_row, curr_turn_column);
        first_player->Get_Fire(curr_turn_row, curr_turn_column, second_player);

        system("cls");

        if(first_player->Check_for_win())
        {
            system("cls");
            std::cout << "PLAYER2 SUNK ALL SHIPS OF PLAYER1! PLAYER2 WINS ROUND!!!\n";
            std::cout << "CONGRATULATIONS!\n";
            first_player->Print_attack_board();
            break;
        }

    }

    delete(first_player);
    delete(second_player);
}
