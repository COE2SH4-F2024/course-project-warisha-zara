#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    // speed = 0;
    // speedLevel[0] = 500000;
    // speedLevel[1] = 350000;
    // speedLevel[2] = 200000;
    // speedLevel[3] = 100000;
    // speedLevel[4] = 10000;
    // //speedLevel[4] = {500000, 350000, 200000, 100000, 10000};
    // delay = speedLevel[speed];

    boardSizeX = 10; //15
    boardSizeY = 20; //30
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // don't need it as of 1B
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() 
{
    if (MacUILib_hasChar()) //!= 0 (?)
    {
        input = MacUILib_getChar();
    }

    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    ++score;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here
// void GameMechs::incrementSpeed() {
//     if (speed < 4) {
//         speed++;
//         delay = speedLevel[speed];
//     }
// }

// void GameMechs::decrementSpeed() {
//     if (speed > 0) {
//         speed--;
//         delay = speedLevel[speed];
//     }
// }

// int GameMechs::getSpeed() const {
//     return speed;
// }