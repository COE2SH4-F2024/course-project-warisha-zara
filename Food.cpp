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
    //const char Str [] = "oooSooSoo"; //1-9
    boardSizeX = 10; //15
    boardSizeY = 20; //30
    food.setObjPos(5,5,'o');
}
Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    //only need to block off the player pos for now
    // ppa3 generate Items code
         
    //     // Check against snake's body
    //     for (int i = 0; i < size; i++) {
    //         objPos snake = blockOff->getElement(i);
    //         if (snake.pos->x == x && snake.pos->y == y) {
    //             unique = 0; // Not unique
    //             break;
    //         }
    //     }

    //srand(time(NULL));
    int symbolIndex;
    const char Str [] = "SooSooSoo"; //1-9

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
        symbolIndex = (rand() % 9);
        validPosition = !(foodX == blockOff.pos->x && foodY == blockOff.pos->y);
    } while (!validPosition);

    food.setObjPos(foodX, foodY, Str[symbolIndex]);
}

objPos Food::getFoodPos() const
{
    return food;
}