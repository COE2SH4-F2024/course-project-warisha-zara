#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerDir = STOP; // myDir in instructions i think
    //snakeBody = new objPosArrayList;

    // more actions to be included

    playerPosList = new objPosArrayList(); 
    objPos initialHead;
    initialHead.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    initialHead.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    initialHead.symbol = '@'; 
    playerPosList->insertHead(initialHead);

    // playerPos.pos ->x = mainGameMechsRef -> getBoardSizeX() / 2;
    // playerPos.pos->y = mainGameMechsRef -> getBoardSizeY() / 2;
    // playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
    // no keyword new in the constructer (malloc - free, new - delete)
    //leave the destructor empty for now
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
    objPos currentHead = playerPosList->getHeadElement();
    objPos newHead = currentHead;

    // PPA3 Finite State Machine logic
    switch(playerDir){
        // case STOP:
        //     break;
        case UP:
            newHead.pos->x = newHead.pos->x - 1;
            if (newHead.pos->x < 1){
                //playerPos.pos->x = 8;
                newHead.pos->x = mainGameMechsRef -> getBoardSizeX() -2;
            }
            break;
        case DOWN:
            newHead.pos->x = newHead.pos->x + 1;
            //if (playerPos.pos->x > 8){
            if (newHead.pos->x > (mainGameMechsRef -> getBoardSizeX() -2)){
                newHead.pos->x = 1;
            }
            break;
        case RIGHT:
            newHead.pos->y = newHead.pos->y +1;
            //if (playerPos.pos->y > 18)
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
    //objPos currentHead = playerPosList->getHeadElement();
    //Player *myPlayer;
    //GameMechs *myGM;
    //myGM = new GameMechs();
    //myPlayer = new Player(myGM);
    //cout << "check food consumption called";
    //objPosArrayList* snakeBody = getPlayerPosList();
    objPos playerHead = getPlayerPosList()->getHeadElement();
    objPos foodPos = mainGameMechsRef->getFoodPos();
 
    if (playerHead.pos->x == foodPos.pos->x && playerHead.pos->y == foodPos.pos->y) {
        //myGM->incrementScore();
        //myGM->generateFood(playerHead); // generate food randomly
        // increase snake length
        //snakeBody->insertHead(playerHead); // update head
        return true;
    }
    else {
        return false;
    }
   
}
 
void Player::increasePlayerLength(){
    //Player *myPlayer;
    //objPosArrayList* snakeBody = getPlayerPosList();
    objPos playerHead = getPlayerPosList()->getHeadElement();
    //cout << "check increase player length called";
   
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