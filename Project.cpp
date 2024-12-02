#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; // global pointer meant to instantiate a player object on the heap
GameMechs *myGM;

//bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM -> getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    // placed object in heap, go delete it in cleanup

    myGM = new GameMechs();
    myPlayer = new Player(myGM); // nullptr is a placeholder
    //myGM->generateFood(myPlayer->getPlayerPos());
    //char Gameboard[30][15];
    //exitFlag = false;
}

void GetInput(void)
{
//    char userInput = myGM-> getInput();
//    if (userInput == ' '){
//         myGM->setExitTrue();
//    }
    myGM-> collectAsyncInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    
    objPosArrayList* snakeBody = myPlayer->getPlayerPosList();
    objPos playerHead =  myPlayer->getPlayerPosList()->getHeadElement();
    objPos foodPos = myGM->getFoodPos(); // Check for food consumption

    if (myPlayer->checkFoodConsumption() == true){
        myPlayer -> increasePlayerLength();
        myGM->incrementScore();
        myGM->generateFood(playerHead);
    }
    //objPos playerHead = myPlayer->getPlayerPos();
    
    
    //use to check is snake eats food
    if (playerHead.pos->x == foodPos.pos->x && playerHead.pos->y == foodPos.pos->y) {
        myGM->incrementScore(); 
        myGM->generateFood(playerHead); // generate food randomly
        // increase snake length
        snakeBody->insertHead(playerHead); // update head
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPosArrayList* snakeBody = myPlayer->getPlayerPosList(); 
    //objPos playerPos = myPlayer -> getPlayerPos();
    objPos foodPos = myGM->getFoodPos();
    
    
    
    //  1. clear the current screen contents
    //WILL NEED TP IMPLEMENT YOUR COPY ASSIGNMENT OPERATOR
    //TO MAKE THIS LINE WORK
    //MacUILib_clearScreen();
    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.
    int i; //==y
    int j; //==x
    int k;

    for (i = 0; i < myGM -> getBoardSizeX(); i++){
        for (j = 0; j < myGM -> getBoardSizeY(); j++){
            if (i == 0 || j == 0 || i == myGM -> getBoardSizeX() -1 || j ==  myGM -> getBoardSizeY()-1){
                // Gameboard[i][j] = '#';
                // MacUILib_printf("%c", board[i][j]);
                MacUILib_printf("#"); // Border symbol
            }
            // else if (i == playerPos.pos->x && j == playerPos.pos->y){
            //     //board[i][j]= playerPos.symbol;
            //     MacUILib_printf("%c", playerPos.symbol);
            // }
            // else if (i == foodPos.pos->x && j == foodPos.pos->y) {
            //     MacUILib_printf("%c", foodPos.symbol); // display the food
            // }
            // else {
            //     MacUILib_printf(" ");
            // }
            else {
                bool isSnake = false;
                for (int k = 0; k < snakeBody->getSize(); k++) {
                    objPos segment = snakeBody->getElement(k);
                    if (i == segment.pos->x && j == segment.pos->y) {
                        MacUILib_printf("%c", segment.symbol); // display snake 
                        isSnake = true;
                        break;
                    }
                }
                if (!isSnake) {
                    if (i == foodPos.pos->x && j == foodPos.pos->y) {
                        MacUILib_printf("%c", foodPos.symbol); // display food
                    } else {
                        MacUILib_printf(" "); 
                    }
                }
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("\n"); // Move to the next line after each row
    MacUILib_printf("Score: %d\n", myGM->getScore());
    //MacUILib_printf("Player [x,y,sym] = [%d,%d,%c]\n", playerPos.pos->x, playerPos.pos->y,playerPos.symbol);  
    MacUILib_printf("Food [x,y,sym] = [%d,%d,%c]\n", foodPos.pos->x, foodPos.pos->y, foodPos.symbol); 

    //     }
    //     MacUILib_printf("\n");
    // }
    // MacUILib_printf("\n"); //Move to next line after printed each row
    // MacUILib_printf("Player [x,y,sym] = [%d,%d,%c]\n", playerPos.pos->x, playerPos.pos->y,playerPos.symbol);    
    if (myPlayer->checkSelfCollision() == true) {
        MacUILib_printf("Game Over! The snake collided with itself.\n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    delete myPlayer;  
    delete myGM;

    MacUILib_uninit();
}
