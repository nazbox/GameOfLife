#pragma once

#include "SquareGrid.h"

class GameOfLiveApp
{
    SquareGrid squareGrid;
public:
    GameOfLiveApp(char** _masSquereArea, uint _sizeSquereArea);
    void Run();
};
