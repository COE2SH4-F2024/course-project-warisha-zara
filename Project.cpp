#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; // global pointer meant to instantiate a player object on the heap
GameMechs *myGM; // global pointer meant to instantiate a gamemechs object on the heap
Food *myFood; // global pointer meant to instantiate a food object on the heap


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
    myPlayer = new Player(myGM); 
    myFood = new Food();
}

void GetInput(void)
{
    myGM-> collectAsyncInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    
    objPos playerHead =  myPlayer->getPlayerPosList()->getHeadElement(); //acess the head element
    objPosArrayList* snakeBody = myPlayer->getPlayerPosList();
    objPos foodPos = myFood->getFoodPos(); // Get the food position

    if (myPlayer->checkSelfCollision() == true) {
        MacUILib_printf("Game Over! The snake collided with itself.\n");
    }
        

    // Check if the player eats the food
    if (playerHead.pos->x == foodPos.pos->x && playerHead.pos->y == foodPos.pos->y) {
        if (foodPos.symbol == 'S'){
            myGM->specialIncrement(10);
            snakeBody->removeTail(5);
        }
        else{
            myGM->incrementScore();
            // Extend the snake body: Do not remove the tail in movePlayer()
            snakeBody->insertHead(playerHead); // Head already updated
            }
        myFood->generateFood(playerHead); // Generate new food at a random position
    }
}

void DrawScreen(void) {
    MacUILib_clearScreen();
    objPosArrayList* snakeBody = myPlayer->getPlayerPosList(); // Access the snake body
    objPos foodPos = myFood->getFoodPos();

    for (int i = 0; i < myGM->getBoardSizeX(); i++) {
        for (int j = 0; j < myGM->getBoardSizeY(); j++) {
            if (i == 0 || j == 0 || i == myGM->getBoardSizeX() - 1 || j == myGM->getBoardSizeY() - 1) {
                MacUILib_printf("#"); // Draw border
            } else {
                bool isSnake = false;
                for (int k = 0; k < snakeBody->getSize(); k++) {
                    objPos segment = snakeBody->getElement(k);
                    if (i == segment.pos->x && j == segment.pos->y) {
                        MacUILib_printf("%c", segment.symbol); // Draw snake segment
                        isSnake = true;
                        break;
                    }
                }
                if (!isSnake) {
                    if (i == foodPos.pos->x && j == foodPos.pos->y) {
                        MacUILib_printf("%c", foodPos.symbol); // Draw food
                    } else {
                        MacUILib_printf(" "); // Empty space
                    }
                }
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("\n"); // Move to the next line after each row
    MacUILib_printf("Score: %d\n", myGM->getScore());
    MacUILib_printf("Food [x,y,sym] = [%d,%d,%c]\n", foodPos.pos->x, foodPos.pos->y, foodPos.symbol); 
    MacUILib_printf("Snake length: %d\n", snakeBody->getSize());
    MacUILib_printf("Eat a 'S' to:\no Increase the score by 10 \no Decrease the snake length by 5");
    
}



void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();  
    if (myPlayer->checkSelfCollision() == true) {
        MacUILib_printf("\nGame Over! The snake collided with itself.\n");
    }

    delete myPlayer;  
    delete myGM;
    delete myFood;

    MacUILib_uninit();
}
