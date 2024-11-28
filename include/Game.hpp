#ifndef GAME_HPP
#define GAME_HPP

#include "Company.hpp"

class Game
{
    Company company;

public:
    Game();

    void gameInit();
    void start();
};

#endif
