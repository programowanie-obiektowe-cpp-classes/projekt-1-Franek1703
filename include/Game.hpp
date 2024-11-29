#ifndef GAME_HPP
#define GAME_HPP

#include "Company.hpp"

class Game
{
    Company company;
    bool gameState;

public:
    Game();

    bool isRunning() const;

    void tick();

    void userAction();
};

#endif
