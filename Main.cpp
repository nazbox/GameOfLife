
//The idea of the algorithm is to not check cells in which life can not appear or disappear

#include "GameOfLiveApp.h"

//Data for first generation
const uint sizeOutput = 8;
const char output[sizeOutput][sizeOutput] =
{
    {'.','.','.','.','.','.','.','.'},
    {'.','.','#','.','.','.','.','.'},
    {'.','.','.','#','.','.','.','.'},
    {'.','#','#','#','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'}
};

int main()
{
    //Memory allocation and copy data for first-generation
    char **initData;
    initData = new char*[sizeOutput];
    for(uint y = 0; y < sizeOutput; y++)
    {
        initData[y] = new char[sizeOutput];
        for(uint x = 0; x < sizeOutput; x++)
            initData[y][x] = output[y][x];
    }

    //Launch simulation of game
    GameOfLiveApp app(initData, sizeOutput);
    app.Run();

    //Deallocation memory for first-generation data
    for(uint y = 0; y < sizeOutput; y++)
        delete [] initData[y];
    delete [] initData;

    return 0;
}
