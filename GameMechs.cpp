#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 10; //15
    boardSizeY = 20; //30

    food.setObjPos(5, 5, 'o');
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
    food.setObjPos(-10, -10, 'o');
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
    
void GameMechs::collectAsyncInput(){

    if (MacUILib_hasChar()) //!= 0 (?)
    {
        input = MacUILib_getChar();
    }
    if (input == ' '){
        exitFlag = true;
    }

    //return input;
}

char GameMechs:: getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    ++score; // add one to score
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
    exitFlag = true; //set exitFlag to true
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
void GameMechs::generateFood(objPos blockOff)
{
    // similar to ppa3 generate Items code

    //srand(time(NULL));
    //static bool unique = false;
    bool unique = false;
    if (!unique) {
        srand((time(nullptr)));
        unique = true;
    }

    int foodX, foodY;
    bool validPosition;

    do {
        foodX = rand() % (boardSizeX - 3) + 1;
        foodY = rand() % (boardSizeY - 3) + 1;
        validPosition = !(foodX == blockOff.pos->x && foodY == blockOff.pos->y);
    } while (!validPosition);

    food.setObjPos(foodX, foodY, 'o');
}

objPos GameMechs::getFoodPos() const
{
    return food;
}