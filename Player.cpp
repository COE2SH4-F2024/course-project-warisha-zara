#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerDir = STOP;

    // more actions to be included

    playerPos.pos ->x = mainGameMechsRef -> getBoardSizeX() / 2;
    playerPos.pos->y = mainGameMechsRef -> getBoardSizeY() / 2;
    playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
    // no keyword new in the constructer (malloc - free, new - delete)
    //leave the destructor empty for now
}

objPos Player::getPlayerPos() const //objPos &returnPos, og void
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  

        char input = mainGameMechsRef -> getInput();
        if(input != 0)  // if not null character
    {
        if (input == ' ') {
            //exitFlag = 1;
        } else if (input == 'w' || input == 'W') 
        {
            if (playerDir == LEFT || playerDir == RIGHT || playerDir == STOP) {
                playerDir = UP;
            }
        } 
        else if (input == 's' || input == 'S') 
        {
            if (playerDir == LEFT || playerDir == RIGHT || playerDir == STOP) {
                playerDir = DOWN;
            }
        }
        else if (input == 'a' || input == 'A') 
        {
            if (playerDir == UP || playerDir == DOWN || playerDir == STOP) {
                playerDir = LEFT;
            }
        }
        else if (input == 'd' || input == 'D') 
        {
           if (playerDir == UP || playerDir == DOWN || playerDir == STOP) {
                playerDir = RIGHT;
            }
        }
        // else if (input == '+' || input== '=') {
        //     if (speed < 4) {
        //         speed++;
        //         delay = speedLevel[speed];
        //     }
        // } 
        // else if (input == '-') {
        //     if (speed > 0) {
        //         speed--;
        //         //delay = speedLevel[speed];
        //     }
        // }
        
    }        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    
}

// More methods to be added