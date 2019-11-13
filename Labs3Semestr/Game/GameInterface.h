#ifndef SHIPBATTLE_GAMEINTERFACE_H
#define SHIPBATTLE_GAMEINTERFACE_H

#include "Player.h"

#include <iostream>
#include <cstring>
#include <ctime>

void Manual();
Type_player define_type_of_player(const char *curr_type);
std::string Print_type(Type_player &type);
Gamer* createGamer(Type_player &type);
void Game_process(int &count_of_rounds, Type_player &first, Type_player &second);

#endif
