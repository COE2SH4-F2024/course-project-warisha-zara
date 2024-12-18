#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();
        objPosArrayList* getPlayerPosList() const; 
        //was objPos getPlayerPos() const; but upgraded for I3.      
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here
        bool checkSelfCollision() const;
        bool checkFoodConsumption();
        void increasePlayerLength();

    private:
        objPosArrayList* playerPosList; //was objPos playerPos; but upgraded for I3.       
        enum Dir playerDir;//does this have to be named as myDir?

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef; //should this just be gameMechRef?
        Food* mainFood;
};

#endif