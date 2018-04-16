#pragma once

#include "Cell.h"

class SquareGrid
{
    uint size;
    Cell ***cells;
    map<string, Cell *> aliveCells;
    map<string, Cell *> changedCells;

    void InitCells();
    void SetFistCellsState();
    void CalcChangedCells();

public:
    SquareGrid(char** _masSquereArea, uint _sizeSquereArea);
    ~SquareGrid();

    void DefineNewGeneration();
    void PrintCells();
};
