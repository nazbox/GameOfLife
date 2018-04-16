#include "SquareGrid.h"

SquareGrid::SquareGrid(char **_masSquereArea, uint _sizeSquereArea)
{
    //Memory allocation for playing field
    size = _sizeSquereArea;
    cells = new Cell**[size];
    for(uint y = 0; y < size; y++)
    {
        cells[y] = new Cell*[size];
        for(uint x = 0; x < size; x++)
            cells[y][x] = new Cell(y, x);
    }

    //Determinate neighbors of each cell
    InitCells();

    //Set state of each cell for first generation and fill list of alive cells
    for(uint y = 0; y < size; y++)
    {
        for(uint x = 0; x < size; x++)
        {
            if(_masSquereArea[y][x] == '#')
            {
                cells[y][x]->SetInitState(_masSquereArea[y][x]);
                aliveCells.insert(pair<string, Cell*>(cells[y][x]->GetName(), cells[y][x]));
            }
        }
    }
}

SquareGrid::~SquareGrid()
{
    //Memory deallocation for playing field
    for(uint y = 0; y < size; y++)
    {
        for(uint x = 0; x < size; x++)
            delete cells[y][x];
        delete [] cells[y];
    }
    delete [] cells;
}

void SquareGrid::InitCells()
{
    Cell** neighbors = new Cell*[8];

    uint y_Leftmost = 0;
    uint y_Rightmost = 0;
    uint x_Uppermost = 0;
    uint x_Bottommost = 0;

    for(uint y = 0; y < size; y++)
    {
        for(uint x = 0; x < size; x++)
        {
            if(y == 0)
            {
                 y_Leftmost = size - 1;
                 y_Rightmost = 1;
            }
            else
            {
                if(y == (size - 1))
                {
                    y_Leftmost = y - 1;
                    y_Rightmost = 0;
                }
                else
                {
                    y_Leftmost = y - 1;
                    y_Rightmost = y + 1;
                }
            }

            if(x == 0)
            {
                 x_Uppermost = size - 1;
                 x_Bottommost = 1;
            }
            else
            {
                if(x == (size - 1))
                {
                    x_Uppermost = x - 1;
                    x_Bottommost = 0;
                }
                else
                {
                    x_Uppermost = x + 1;
                    x_Bottommost = x - 1;
                }
            }

            neighbors[0] = cells[y_Leftmost][x_Uppermost];
            neighbors[1] = cells[y_Leftmost][x];
            neighbors[2] = cells[y_Leftmost][x_Bottommost];

            neighbors[3] = cells[y_Rightmost][x_Uppermost];
            neighbors[4] = cells[y_Rightmost][x];
            neighbors[5] = cells[y_Rightmost][x_Bottommost];

            neighbors[6] = cells[y][x_Uppermost];
            neighbors[7] = cells[y][x_Bottommost];

            cells[y][x]->SetNeighbors(neighbors);
        }
    }

    delete [] neighbors;
}

void SquareGrid::DefineNewGeneration()
{
    changedCells.clear();
    for(std::map<string,Cell*>::iterator it=aliveCells.begin(); it!=aliveCells.end(); ++it)
        it->second->DefineNextState(changedCells);

    for(std::map<string,Cell*>::iterator it=changedCells.begin(); it!=changedCells.end(); ++it)
    {
        it->second->SetNextState();

        if(it->second->GetCurrentState() == '#')
            aliveCells.insert(pair<string, Cell*>(it->second->GetName(), it->second));
        else
            aliveCells.erase(it->second->GetName());
    }
}

//Print current generation
void SquareGrid::PrintCells()
{
    for(uint y = 0; y < size; y++)
    {
        for(uint x = 0; x < size; x++)
        {
            cout<<cells[y][x]->GetCurrentState();
            cout<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
