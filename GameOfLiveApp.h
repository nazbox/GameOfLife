#pragma once

#include "Grid.h"

class GameOfLiveApp
{
    Grid grid;
public:
    GameOfLiveApp(vector< vector<char> > &_data);
    void Run();
};
