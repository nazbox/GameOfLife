#pragma once

#include "Cell.h"

class Grid
{
    vector< vector<Cell *> > cells;
    map<string, Cell *> aliveCells;
    map<string, Cell *> changedCells;

    uint size_y;
    uint size_x;

    bool isValidData;

    void InitCellsNeighbors();
    void SetFistCellsState();
    void CalcChangedCells();

public:
    Grid(vector< vector<char> > &_data);
    ~Grid();

    void DefineNewGeneration();
    void PrintCells();

    bool IsValidData();

    bool TestCells(vector< vector<char> > &_cells);
};
