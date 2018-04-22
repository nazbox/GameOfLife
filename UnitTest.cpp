
#include <gtest/gtest.h>

#include "Grid.h"
#include "Grid.cpp"
#include "Cell.h"
#include "Cell.cpp"

const uint g_size_y = 7;
const uint g_size_x = 8;
const char g_data_0[g_size_y][g_size_x] =
{
    {'*','*','*','*','*','*','*','*'},
    {'*','*','#','*','*','*','*','*'},
    {'*','*','*','#','*','*','*','*'},
    {'*','#','#','#','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'}
};

const char g_data_9[g_size_y][g_size_x] =
{
    {'*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'},
    {'*','*','*','#','*','#','*','*'},
    {'*','*','*','*','#','#','*','*'},
    {'*','*','*','*','#','*','*','*'}
};

TEST(TestGeneration, test)
{
    bool flag = true;

    vector< vector<char> > data;

    for(uint y = 0; y < g_size_y; y++)
    {
        data.push_back(vector<char>());
        for(uint x = 0; x < g_size_x; x++)
            data[y].push_back(g_data_0[y][x]);
    }

    Grid grid(data);

    for(int i = 0; i < 9; i++)
        grid.DefineNewGeneration();

    for(uint y = 0; y < g_size_y; y++)
        for(uint x = 0; x < g_size_x; x++)
            data[y][x] = g_data_9[y][x];

    flag = grid.TestCells(data);

    EXPECT_TRUE(flag);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
