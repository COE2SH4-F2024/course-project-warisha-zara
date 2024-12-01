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
void GameMechs::generateFood(objPos blockOff)
{
    //only need to block off the player pos for now
    // ppa3 generate Items code
    // int count = listSize;
    // int randNum;
    // int str_size = my_strlen(str);
    // // This is called "Bit-Vector" method of generating non-re
    // // so not to generate items right over the player
    // int* xRandList = (int*) calloc(xRange, sizeof(int));
    // int* yRandList = (int*) calloc(yRange, sizeof(int));
    // int* charRandList = (int*) calloc(str_size, sizeof(int));
    // xRandList[playerPos->x]++;
    // yRandList[playerPos->y]++; 

         
    //     // Check against snake's body
    //     for (int i = 0; i < size; i++) {
    //         objPos snake = blockOff->getElement(i);
    //         if (snake.pos->x == x && snake.pos->y == y) {
    //             unique = 0; // Not unique
    //             break;
    //         }
    //     }



    //srand(time(NULL));
    bool unique = false;
    //static bool unique = false;
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