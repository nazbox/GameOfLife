#include "GameOfLiveApp.h"

GameOfLiveApp::GameOfLiveApp(vector< vector<char> > &_data):grid(_data)
{
    //empty
}

void GameOfLiveApp::Run()
{
    if(grid.IsValidData() == true)
    {
        char outCh = 0;
        int i = 0;

        //Transition to a new generation or exit from the application
        while(true)
        {
            cout<<"Generation "<<i++<<"\n";
            grid.PrintCells();

            cout<<"Type 'c' to continue or 'e' for exit\n";
            cin>>outCh;
            if(outCh == 'e')
                break;

            grid.DefineNewGeneration();
        }
    }
}
