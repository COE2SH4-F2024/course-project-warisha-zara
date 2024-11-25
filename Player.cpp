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
    // return the value (reference) to the playerPos //--> not this for now, but later -->arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
    char input = mainGameMechsRef -> getInput();
    // if (playerDir != STOP){
    //     //moveCount++; ---> Figure out where to initialize & declare
    // }
    
    // // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below
    // if (((input >= 33 && input <= 46) || (input >= 58 && input <= 64) || (input >= 91 && input <= 96) || (input >= 123 && input <= 126)) && input != '+' && input != '-' && input != '_'){
    //     playerPos.symbol = input;
    //     input = 0;
    // }
 

    switch(input) 
    {                      
        // case ' ':  // exit
        //     exitFlag = 1;
        //     break;
        // case '+':
        //     if (gameSpeed < 5){
        //         gameSpeed ++;
        //         delayTime -=40000;
        //     }
        //     //input =0;
        //     break;
        // case '-':
        //     if (gameSpeed > 1){
        //         gameSpeed --;
        //         delayTime +=40000;
        //     }
        //     //input =0;
        //     break;
        case 'W':
        case 'w':
            if ((playerDir == LEFT || playerDir == RIGHT || playerDir == STOP)){
                playerDir = UP;
            }
            break;
        case 'S':
        case 's':
            if ((playerDir == LEFT || playerDir == RIGHT || playerDir == STOP)){
                playerDir = DOWN;
            }
            break;
        case 'D':
        case 'd':
            if ((playerDir == UP || playerDir == DOWN || playerDir == STOP)){
                playerDir = RIGHT;
            }
            break;
        case 'A':
        case 'a':
            if ((playerDir == UP || playerDir == DOWN || playerDir == STOP)){
                playerDir = LEFT;
            }
            break;
        default:
            break;
    }


    // if(input != 0)  // if not null character
    // {
    //     if (input == ' ') {
    //         //exitFlag = 1;
    //     } else if (input == 'w' || input == 'W') 
    //     {
    //         if (playerDir == LEFT || playerDir == RIGHT || playerDir == STOP) {
    //             playerDir = UP;
    //         }
    //     } 
    //     else if (input == 's' || input == 'S') 
    //     {
    //         if (playerDir == LEFT || playerDir == RIGHT || playerDir == STOP) {
    //             playerDir = DOWN;
    //         }
    //     }
    //     else if (input == 'a' || input == 'A') 
    //     {
    //         if (playerDir == UP || playerDir == DOWN || playerDir == STOP) {
    //             playerDir = LEFT;
    //         }
    //     }
    //     else if (input == 'd' || input == 'D') 
    //     {
    //        if (playerDir == UP || playerDir == DOWN || playerDir == STOP) {
    //             playerDir = RIGHT;
    //         }
    //     }
    //     input = 0;
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
        
    //}        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(playerDir){
        case STOP:
            break;
        case UP:
            playerPos.pos->x = playerPos.pos->x - 1;
            if (playerPos.pos->x < 1){
                //playerPos.pos->x = 8;
                playerPos.pos->x = mainGameMechsRef -> getBoardSizeX() -2;
            }
            break;
        case DOWN:
            playerPos.pos->x = playerPos.pos->x + 1;
            //if (playerPos.pos->x > 8){
            if (playerPos.pos->x > (mainGameMechsRef -> getBoardSizeX() -2)){
                playerPos.pos->x = 1;
            }
            break;
        case RIGHT:
            playerPos.pos->y = playerPos.pos->y +1;
            //if (playerPos.pos->y > 18)
            if (playerPos.pos->y > (mainGameMechsRef -> getBoardSizeY() -2))
            {
                playerPos.pos->y = 1;
            }
            break;
        case LEFT:
            playerPos.pos->y = playerPos.pos->y -1;
            if (playerPos.pos->y < 1){
                playerPos.pos->y = mainGameMechsRef -> getBoardSizeY() -2;
            }
            break;
        }
    
}

// More methods to be added