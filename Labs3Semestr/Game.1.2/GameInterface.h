#ifndef SHIPBATTLE_GAMEINTERFACE_H
#define SHIPBATTLE_GAMEINTERFACE_H

#include "Player.h"

#include <iostream>
#include <cstring>
#include <ctime>

class Game_Interface{
public:
    void Manual();
    Type_player define_type_of_player(const char *curr_type);
    std::string Print_type(Type_player &type);
    Gamer* createGamer(Type_player &type);
    void Print_player_and_attack_board(Gamer *player);

    char Find_on_board(Gamer* player, int row, char column);
    Result_of_attack get_fire(Gamer *player, Gamer *enemy, int row, char column);
    void Game_process(int &count_of_rounds, Type_player &first, Type_player &second);
    bool Check_for_defeat(Gamer *curr_player);//Проверяет, не потерпел ли конкретный игрок поражение
    void Print_stats(int &first_wins, int &second_wins, int &count_rounds);
};

#endif
