#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerDir = STOP; // myDir in instructions i think

    // more actions to be included

    playerPosList = new objPosArrayList(); 
    objPos initialHead;
    initialHead.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    initialHead.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    initialHead.symbol = '@'; 
    playerPosList->insertHead(initialHead);
}


Player::~Player()
{
    // delete any heap members here
    // no keyword new in the constructer (malloc - free, new - delete)
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPosList() const //objPos &returnPos, og void
{
    // return the value (reference) to the playerPos //--> not this for now, but later -->arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
    char input = mainGameMechsRef -> getInput();
    // // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below
   
    switch(input) 
    {                      
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
}

void Player::movePlayer()
{
    objPos currentHead = playerPosList->getHeadElement();
    objPos newHead = currentHead;

    // PPA3 Finite State Machine logic
    switch(playerDir){
        // case STOP:
        //     break;
        case UP:
            newHead.pos->x = newHead.pos->x - 1;
            if (newHead.pos->x < 1){
                newHead.pos->x = mainGameMechsRef -> getBoardSizeX() -2;
            }
            break;
        case DOWN:
            newHead.pos->x = newHead.pos->x + 1;
            if (newHead.pos->x > (mainGameMechsRef -> getBoardSizeX() -2)){
                newHead.pos->x = 1;
            }
            break;
        case RIGHT:
            newHead.pos->y = newHead.pos->y +1;
            if (newHead.pos->y > (mainGameMechsRef -> getBoardSizeY() -2))
            {
                newHead.pos->y = 1;
            }
            break;
        case LEFT:
            newHead.pos->y = newHead.pos->y -1;
            if (newHead.pos->y < 1){
                newHead.pos->y = mainGameMechsRef -> getBoardSizeY() -2;
            }
            break;
        default:
            return;
    }
    playerPosList->insertHead(newHead);
    playerPosList->removeTail();
    
    if (checkSelfCollision()) {
        mainGameMechsRef->setLoseFlag(); 
        mainGameMechsRef->setExitTrue(); 
    }
}

// More methods to be added
bool Player::checkFoodConsumption(){

    objPos playerHead = getPlayerPosList()->getHeadElement();
    objPos foodPos = mainGameMechsRef->getFoodPos();
 
    if (playerHead.pos->x == foodPos.pos->x && playerHead.pos->y == foodPos.pos->y) {
        return true;
    }
    else {
        return false;
    }
   
}
 
void Player::increasePlayerLength(){
    
    objPos playerHead = getPlayerPosList()->getHeadElement();
    getPlayerPosList()->insertHead(playerHead); // update head
 
}

bool Player::checkSelfCollision() const {
    objPos head = playerPosList->getHeadElement(); // get head of the snake

    for (int i = 1; i < playerPosList->getSize(); i++) {
        objPos bodySegment = playerPosList->getElement(i);

        // check if the head position matches any body segment
        if (head.pos->x == bodySegment.pos->x && head.pos->y == bodySegment.pos->y) {
            return true; 
        }
    }
    return false; 
}