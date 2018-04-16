#include "GameOfLiveApp.h"

GameOfLiveApp::GameOfLiveApp(char** _masSquereArea, uint _sizeSquereArea):squareGrid(_masSquereArea, _sizeSquereArea)
{
    //empty
}

void GameOfLiveApp::Run()
{
    char outCh = 0;
    int i = 0;

    //Transition to a new generation or exit from the application
    while(true)
    {
        cout<<"Generation "<<i++<<"\n";
        squareGrid.PrintCells();

        cout<<"Type 'c' to continue or 'e' for exit\n";
        cin>>outCh;
        if(outCh == 'e')
            break;

        squareGrid.DefineNewGeneration();
    }
}
