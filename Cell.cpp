#include "Cell.h"

Cell::Cell(uint _y, uint _x)
{
    char temp_str[32] = {0};
    snprintf(temp_str, (sizeof(temp_str) - 1), "%u:%u", _x, _y);
    name = temp_str;

    cntrAliveNeighbors = 0;
    currentState = '*';
    nextState = '*';
    for(uint i = 0; i < 8; i++)
        neighbors[i] = 0;
}

void Cell::SetInitState(char _state)
{
    if(currentState != _state)
    {
        currentState = _state;
        nextState = _state;
        for(int i = 0; i < 8; i++)
        {
            if(currentState == '#')
                neighbors[i]->IncrementAliveNeighbors();
            else
                neighbors[i]->DecrementAliveNeighbors();
        }
    }
}

void Cell::SetNeighbors(vector<Cell *> &_masNeighbors)
{
    for(uint i = 0; i < 8; i++)
        neighbors[i] = _masNeighbors[i];
}

string Cell::GetName()
{
    return name;
}

void Cell::IncrementAliveNeighbors()
{
    cntrAliveNeighbors++;
}

void Cell::DecrementAliveNeighbors()
{
    cntrAliveNeighbors--;
}

char Cell::GetCurrentState()
{
    return currentState;
}

void Cell::DefineNextState(map<string, Cell *> &changedCells)
{
    if(GetOwnNextState() == '*')
        changedCells.insert(pair<string, Cell *>(name, this));

    char stateLoc = '*';
    for(int i = 0; i < 8; i++)
    {
        stateLoc = neighbors[i]->GetCurrentState();
        if(stateLoc != neighbors[i]->GetOwnNextState())
            changedCells.insert(pair<string, Cell *>(neighbors[i]->name, neighbors[i]));
    }
}

char Cell::GetOwnNextState()
{
    nextState = currentState;
    if(currentState == '*')
    {
        if(cntrAliveNeighbors == 3)
            nextState = '#';
    }
    else
    {
        if(cntrAliveNeighbors < 2 || cntrAliveNeighbors > 3)
             nextState = '*';
    }
    return nextState;
}

void Cell::SetNextState()
{
    if(currentState != nextState)
    {
        currentState = nextState;
        for(int i = 0; i < 8; i++)
        {
            if(nextState == '#')
                neighbors[i]->IncrementAliveNeighbors();
            else
                neighbors[i]->DecrementAliveNeighbors();
        }
    }
}
