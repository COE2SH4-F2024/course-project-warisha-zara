#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    Food* thisFood;
    mainGameMechsRef = thisGMRef;
    mainFood = thisFood; 
    playerDir = STOP;

    playerPosList = new objPosArrayList(); // Allocate the array list
    objPos initialHead;
    initialHead.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    initialHead.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    initialHead.symbol = '@'; // Snake head symbol
    playerPosList->insertHead(initialHead);
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
    return playerPosList; //->getHeadElement()
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

void Player::movePlayer() {
    // Get current head position
    objPos currentHead = playerPosList->getHeadElement();
    objPos newHead = currentHead; // Copy current head for modification

    // Update new head position based on direction
    switch (playerDir) {
        case UP:
            newHead.pos->x -= 1;
            if (newHead.pos->x < 1) {
                newHead.pos->x = mainGameMechsRef->getBoardSizeX() - 2; // Wrap around top edge
            }
            break;
        case DOWN:
            newHead.pos->x += 1;
            if (newHead.pos->x > mainGameMechsRef->getBoardSizeX() - 2) {
                newHead.pos->x = 1; // Wrap around bottom edge
            }
            break;
        case LEFT:
            newHead.pos->y -= 1;
            if (newHead.pos->y < 1) {
                newHead.pos->y = mainGameMechsRef->getBoardSizeY() - 2; // Wrap around left edge
            }
            break;
        case RIGHT:
            newHead.pos->y += 1;
            if (newHead.pos->y > mainGameMechsRef->getBoardSizeY() - 2) {
                newHead.pos->y = 1; // Wrap around right edge
            }
            break;
        default:
            return; // No movement if direction is STOP
    }

    // Insert the new head and remove the tail
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
    objPos foodPos = mainFood->getFoodPos();
    bool status = false;
    if (playerHead.pos->x == foodPos.pos->x && playerHead.pos->y == foodPos.pos->y) {
        //myGM->incrementScore();
        //myGM->generateFood(playerHead); // generate food randomly
        // increase snake length
        //snakeBody->insertHead(playerHead); // update head
        status = true;
        
    }
    else {
        status = false;
    }
   return status;
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