#ifndef FOOD_H
#define FOOD_H
#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;
class Food
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;


        int boardSizeX;
        int boardSizeY;

        objPos food;
    
    public:
        Food();
        ~Food(); 
        
        void generateFood(objPos blockOff);
        objPos getFoodPos() const;
};
#endif