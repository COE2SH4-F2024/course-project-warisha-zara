#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

Food::Food()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 10; //15
    boardSizeY = 20; //30
    food.setObjPos(5,5,'o');
}
Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    int symbolIndex; // index for selecting food
    const char Str [] = "SooSooSoo"; //array of food, S is special food (bonus)

    bool unique = false;
    if (!unique) {
        srand((time(nullptr))); //random 
        unique = true; // set unique to true
    }

    int foodX, foodY; // new food coordinates
    bool validPosition; // to check no food overlap with position

    do {
        foodX = rand() % (boardSizeX - 3) + 1; // random x value that is on game board
        foodY = rand() % (boardSizeY - 3) + 1;
        symbolIndex = (rand() % 9); // randomly select number from the string
        validPosition = !(foodX == blockOff.pos->x && foodY == blockOff.pos->y); // no overlap
    } while (!validPosition);

    food.setObjPos(foodX, foodY, Str[symbolIndex]); // food position
}

objPos Food::getFoodPos() const
{
    return food;
}