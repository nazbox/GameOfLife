
//The idea of the algorithm is to not check cells in which life can not appear or disappear

#include "GameOfLiveApp.h"


//Data for first generation

const uint g_size_y = 7;
const uint g_size_x = 8;
const char g_data[g_size_y][g_size_x] =
{
    {'*','*','*','*','*','*','*','*'},
    {'*','*','#','*','*','*','*','*'},
    {'*','*','*','#','*','*','*','*'},
    {'*','#','#','#','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'}
};

int main()
{
    vector< vector<char> > data;

    //Copy data for first-generation
    for(uint y = 0; y < g_size_y; y++)
    {
        data.push_back(vector<char>());
        for(uint x = 0; x < g_size_x; x++)
            data[y].push_back(g_data[y][x]);
    }

    //Launch simulation of game
    GameOfLiveApp app(data);
    app.Run();

    return 0;
}
