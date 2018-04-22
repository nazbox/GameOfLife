#pragma once

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
typedef unsigned int uint;
typedef unsigned char uchar;

class Cell
{
    uint cntrAliveNeighbors;

    char currentState;
    char nextState;

    Cell * neighbors[8];

    string name;
public:
    Cell(uint _y, uint _x);

    void SetInitState(char _state);
    void SetNeighbors(vector<Cell *> &_masNeighbors);

    string GetName();

    void IncrementAliveNeighbors();
    void DecrementAliveNeighbors();

    char GetCurrentState();
    void DefineNextState(map<string, Cell *> &changedCells);

    void SetNextState();

private:
    char GetOwnNextState();
};
