#include "Grid.h"

Grid::Grid(vector< vector<char> > &_data)
{
    //Create and initialize all cells

    isValidData = false;

    size_y = _data.size();
    if(size_y > 0)
    {
        size_x = _data[0].size();
        if(size_x > 0)
        {
            isValidData = true;

            for(uint y = 0; y < size_y; y++)
            {
                cells.push_back(vector<Cell *>());
                for(uint x = 0; x < size_x; x++)
                    cells[y].push_back(new Cell(y, x));
            }

            //The determinant of neighbors of each cell
            InitCellsNeighbors();

            //Set state of each cell for first generation and fill list of alive cells
            for(uint y = 0; y < size_y; y++)
            {
                for(uint x = 0; x < size_x; x++)
                {
                    if(_data[y][x] == '#')
                    {
                        cells[y][x]->SetInitState(_data[y][x]);
                        aliveCells.insert(pair<string, Cell*>(cells[y][x]->GetName(), cells[y][x]));
                    }
                }
            }
        }
    }
}

Grid::~Grid()
{
    //Memory deallocation for cells
    for(uint y = 0; y < size_y; y++)
        for(uint x = 0; x < size_x; x++)
            delete cells[y][x];
}

bool Grid::IsValidData()
{
    return isValidData;
}

void Grid::InitCellsNeighbors()
{
    vector<Cell *> neighbors(8);

    uint y_Leftmost = 0;
    uint y_Rightmost = 0;
    uint x_Uppermost = 0;
    uint x_Bottommost = 0;

    for(uint y = 0; y < size_y; y++)
    {
        for(uint x = 0; x < size_x; x++)
        {
            if(y == 0)
            {
                 y_Leftmost = size_y - 1;
                 y_Rightmost = 1;
            }
            else
            {
                if(y == (size_y - 1))
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
                 x_Uppermost = size_x - 1;
                 x_Bottommost = 1;
            }
            else
            {
                if(x == (size_x - 1))
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
}

void Grid::DefineNewGeneration()
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
void Grid::PrintCells()
{
    for(uint y = 0; y < size_y; y++)
    {
        for(uint x = 0; x < size_x; x++)
        {
            cout<<cells[y][x]->GetCurrentState();
            cout<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool Grid::TestCells(vector< vector<char> > &_cells)
{
    bool res = true;

    for(uint y = 0; y < size_y && res == true; y++)
    {
        for(uint x = 0; x < size_x && res == true; x++)
        {
            char ch1 = _cells[y][x];
            char ch2 = cells[y][x]->GetCurrentState();

            if(_cells[y][x] != cells[y][x]->GetCurrentState())
            {
                res = false;
            }
        }
    }

    return res;
}
