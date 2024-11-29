#include "Employee.hpp"
#include "WarehouseWorker.hpp"
#include <Engineer.hpp>
#include <Game.hpp>
int main()
{
    Game game;

    while (game.isRunning())
    {
        game.tick();
    }
    return 0;
}
